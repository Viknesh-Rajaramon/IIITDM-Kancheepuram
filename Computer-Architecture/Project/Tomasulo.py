import os, sys, random
from Python_to_Verilog import generate_verilog_test_bench, convert_to_hex
from subprocess import call
from texttable import Texttable

def check_if_number(x):
	return isinstance(x, int)

""" Function to return key for any value """
def get_key(value, d):
	for key in d:
		if(d[key] == value):
			return key
	
	return None


class RESERVATION_STATION:
	""" Instruction Attributes """
	def __init__(self):
		self.operation = None 
		self.destination = None
		self.operand1 = None
		self.operand2 = None
		self.age = 0 # Number of Clock Cycles the Instruction waits for the ALU
		self.executing = False # False if it is in ALU
		self.cc_rem = 0 # Number of Clock Cycles remaining
		self.free = True # True if Reservation Station is free
		self.tag = None
	
	""" Check if Instruction is ready to be dispatched """
	def check_if_ready(self):
		return (check_if_number(self.operand2) and check_if_number(self.operand1))
	
	""" Update age """
	def update_age(self):
		self.age += 1

	""" Generate Verilog Test Bench based on Input Operation """
	def evaluate(self):
		if(self.operation == 'ADD'):
			# op1 + op2 - Integer Addition
			return generate_verilog_test_bench('ADD', int(self.operand1), int(self.operand2))
			
		elif(self.operation == 'SUB'):
			# op1 - op2 - Integer Subtraction
			return generate_verilog_test_bench('SUB', int(self.operand1), int(self.operand2))
		
		elif(self.operation == 'MUL'):
			# op1 * op2 - Integer Multiplication
			return generate_verilog_test_bench('MULT', int(self.operand1), int(self.operand2))
		
		elif(self.operation == 'FADD'):
			# op1 + op2 - Floating Point Addition
			return generate_verilog_test_bench('FADD', int(self.operand1), int(self.operand2))
		
		elif(self.operation == 'FSUB'):
			# op1 - op2 - Floating Point Subtraction
			return generate_verilog_test_bench('FSUB', int(self.operand1), int(self.operand2))
		
		elif( self.operation == 'FMUL'):
			# op1 * op2 - Floating Point Multiplication
			return generate_verilog_test_bench('FMULT', int(self.operand1), int(self.operand2))
		
		elif(self.operation in ['AND', 'OR', 'NOR', 'NAND', 'XOR', 'XNOR', 'NOT']):
			# Logical Operations
			return generate_verilog_test_bench(self.operation, int(self.operand1), int(self.operand2))

	def __str__(self):
		if(self.free):
			return ('---\tFree\n')
		
		op1 = convert_to_hex(self.operand1) if check_if_number(self.operand1) else self.operand1
		op2 = convert_to_hex(self.operand2) if check_if_number(self.operand2) else self.operand2
		
		status = 'Dispatched' if self.executing else 'Issued'

		return ('{}\t{}'.format(self.operation, status))

	def run(self):
		if((self.executing) and (self.cc_rem != -1)):
			self.cc_rem -= 1


class LOAD_STORE_BUFFER:
	def __init__(self):
		self.ls_queue = []
		self.mem = [99, 24, 59, 98, 37, 42, 25, 42, 55, 76, 73, 31, 53, 67, 75, 35, 89, 48, 89]
		self.index = 0

	def check_if_ready(self):
		if(self.ls_queue):
			if(self.ls_queue[0][0] == 'STR'):
				return (check_if_number(self.ls_queue[0][1]) and check_if_number(self.ls_queue[0][2][0]))
			
			else:
				return check_if_number(self.ls_queue[0][2][0])
		
		return False

	def run(self, reg):
		inst = self.ls_queue.pop(0)
		
		if(inst[0] == 'LDR'):
			return ('ldr', self.mem[int(sum(inst[2])) % len(self.mem)], inst[3])
		
		else:
			self.mem[int(sum(inst[2]))] = reg[inst[1] % len(self.mem)]
			return (None, None, None)

class TOMASULO:
	def __init__(self, file_name, clock_cycles_per_instruction):
		self.cycles = 0
		self.cc = clock_cycles_per_instruction

		with open(file_name) as f:
			self.instr_queue = f.read().splitlines()

		self.registers = dict([(f'R{i}', i) for i in range(8)])
		self.register_status = dict([ (f'R{i}',f'R{i}') for i in range(8)])

		self.rs_add = [RESERVATION_STATION(), RESERVATION_STATION(), RESERVATION_STATION()]
		self.rs_mul = [RESERVATION_STATION(), RESERVATION_STATION()]
		self.rs_fadd = [RESERVATION_STATION(), RESERVATION_STATION(), RESERVATION_STATION()]
		self.rs_fmul = [RESERVATION_STATION(), RESERVATION_STATION()]
		self.rs_shift = [RESERVATION_STATION(), RESERVATION_STATION()]
		self.ls_buffer = LOAD_STORE_BUFFER()
		self.rs_logic = [RESERVATION_STATION(), RESERVATION_STATION()]

	def execute(self):
		self.cycles += 1
		broadcast_candidates = []

		# Execute Load or Store Here
		if(self.ls_buffer.check_if_ready()):
			inst, value, tag = self.ls_buffer.run(self.registers)
			
			if(inst):
				broadcast_candidates.append((value, tag))

		def dispatch(rs):
			next_inst = None
			curr_age = 0
			for i, inst in enumerate(rs):
				if((inst.check_if_ready()) and (inst.age >= curr_age) and (not(inst.free))):
					next_inst = i
					curr_age = inst.age
			
			alu_is_free = not any([inst.executing for inst in rs])
			
			if((next_inst is not None) and (alu_is_free)):
				x = rs[next_inst] if next_inst is not None else 'None'
				rs[next_inst].executing = True
				
				if(rs[next_inst].operation in ['AND','OR','NOR','NAND','XOR','XNOR','NOT']):
					rs[next_inst].cc_rem = self.cc['Logic']
				
				else:
					rs[next_inst].cc_rem = self.cc[rs[next_inst].operation]

		dispatch(self.rs_add)
		dispatch(self.rs_mul)
		dispatch(self.rs_fadd)
		dispatch(self.rs_fmul)
		dispatch(self.rs_logic)

		# Issue
		def issue(rs, rat_label):
			for i in range(len(rs)):
				if(rs[i].free):
					rs[i].free = False
					rs[i].age = 0
					rs[i].operation = issue_inst[0]
					rs[i].destination = issue_inst[1]
					rs[i].operand1 = self.register_status[issue_inst[2]]

					if(issue_inst[0] != 'NOT'):
						rs[i].operand2 = self.register_status[issue_inst[3]]
					
					if(rs[i].operand1 in self.registers):
						rs[i].operand1 = self.registers[rs[i].operand1]
					
					if((issue_inst[0] != 'NOT') and (rs[i].operand2 in self.registers)):
						rs[i].operand2 = self.registers[rs[i].operand2]
					
					if(issue_inst[0] == 'NOT'):
						rs[i].operand2 = 0
					
					rs[i].tag = rat_label + str(i)
					
					self.register_status[rs[i].destination] = rs[i].tag
					self.instr_queue.pop(0)
					return

		def issue_ls(register_status, ls_buffer):			
			operation = issue_inst[0]
			a1 = issue_inst[1]
			x = issue_inst[2].split('+')
			
			if(len(x) == 1):
				a2 = [x[0], 0]
			
			else:
				a2 = [x[0], int(x[1])]

			a1 = self.register_status[a1] if operation == 'STR' else a1
			a2[0] = self.register_status[a2[0]]
			
			if((a1 in self.registers) and (operation == 'STR')):
				a1 = self.registers[a1]
			
			if(a2[0] in self.registers):
				a2[0] = self.registers[a2[0]]

			if(operation == 'LDR'):
				tag = 'ldr' + str(ls_buffer.index)
				self.ls_buffer.ls_queue.append([operation, a1, a2, tag])
				self.register_status[a1] = tag
				ls_buffer.index += 1
			
			else:
				self.ls_buffer.ls_queue.append([operation, a1, a2])

			self.instr_queue.pop(0)
			
		if(self.instr_queue):
			issue_inst = self.instr_queue[0].split()
			
			if(issue_inst[0] in ['ADD', 'SUB']):
				issue(self.rs_add, 'RS_A_')
			
			elif(issue_inst[0] in ['MUL', 'DIV']):
				issue(self.rs_mul, 'RS_M_')
			
			elif(issue_inst[0] in ['FADD', 'FSUB']):
				issue(self.rs_fadd, 'RS_FA_')
			
			elif(issue_inst[0] in ['FMUL']):
				issue(self.rs_fmul, 'RS_FM_')
			
			elif(issue_inst[0] in ['LDR', 'STR']):
				issue_ls(self.register_status, self.ls_buffer)
			
			elif(issue_inst[0] in ['AND', 'OR', 'NOR', 'NAND', 'XOR', 'XNOR', 'NOT']):
				issue(self.rs_logic, 'RS_L_')

		# Execute
		rs_list = [self.rs_fmul, self.rs_fadd, self.rs_mul, self.rs_add, self.rs_shift, self.rs_logic]

		for i, rs in enumerate(rs_list):
			for j, inst in enumerate(rs):
				rs_list[i][j].update_age()
				
				if(inst.executing):
					inst.run()
					
					if(inst.cc_rem == -1):
						broadcast_candidates.append((i,j))

		# Write Back
		if(broadcast_candidates):
			if(check_if_number(broadcast_candidates[0][1])):
				# broadcasting from some reservation station
				station, cell = broadcast_candidates[0]
				result = rs_list[station][cell].evaluate()
				tag = rs_list[station][cell].tag
				
				# broadcast to reservation stations
				for rs in rs_list:
					for rs_cell_ in rs:
						if(rs_cell_.operand1 == tag):
							rs_cell_.operand1 = result
						
						if(rs_cell_.operand2 == tag):
							rs_cell_.operand2 = result
				
				# check register_status and update register file
				key = get_key(tag, self.register_status)
				
				if(key is not None):
					self.registers[key] = result
					self.register_status[key] = key
				
				# free reservation station
				rs_list[station][cell].free = True
				rs_list[station][cell].executing = False
			
			else:
				# broadcasting from load operation
				value, tag = broadcast_candidates[0]
				
				# broadcast to reservation stations
				for rs in rs_list:
					for rs_cell_ in rs:
						if(rs_cell_.operand1 == tag):
							rs_cell_.operand1 = value
						
						if(rs_cell_.operand2 == tag):
							rs_cell_.operand2 = value
				
				# check register_status and update register file
				key = get_key(tag, self.register_status)
				
				if( key is not None):
					self.registers[key] = value
					self.register_status[key] = key

	def print_table(self, data):
		t1 = []
		t2 = []

		for i in data:
			t1.append(i)
			v = convert_to_hex(data[i]) if check_if_number(data[i]) else data[i]
			t2.append(v)

		table = Texttable()
		table.add_rows([t1, t2])

		print(table.draw() + "\n")
	
	def print_reservation_station(self, rs, label, temp):
		t1 = []
		t1.append(label)
		t1.append("FREE = {}".format(temp))

		t = []
		t.append(t1)

		for inst in rs:
			s = "{}".format(inst)
			t.append(s.split())
		
		table = Texttable()
		table.add_rows(t)

		print(table.draw() + "\n")


	def print_status(self):
		print("CLOCK CYCLE : {}".format(self.cycles))

		print("INSTRUCTION QUEUE : {}\n".format(self.instr_queue))

		print("REGISTER STATUS")
		self.print_table(self.register_status)

		print("REGISTER FILE")
		self.print_table(self.registers)

		print("RESERVATION STATIONS")

		program_over = True

		for label, rs in zip(['ADD', 'MUL', 'FADD', 'FMUL', 'LOGIC'], [self.rs_add, self.rs_mul, self.rs_fadd, self.rs_fmul, self.rs_logic]):
			temp = not any([inst.executing for inst in rs])
			program_over = program_over and temp
			
			self.print_reservation_station(rs, label, temp)
		
		return program_over

def main():
	if(len(sys.argv) != 2):
		print("Invalid usage : {}".format(sys.argv[0]))

		print("\nCorrect Usage : {} filename".format(sys.argv[0]))

		sys.exit()

	filename = sys.argv[1]
	
	clock_cycles_per_instruction = {'ADD' : 6, 'MUL' : 11, 'SUB' : 6, 'DIV' : 11, 'FADD' : 21, 'FMUL' : 24, 'FSUB' : 21, 'Logic' : 1, 'Shift': 4, 'STR' : 2, 'LDR' : 2}
	
	tomasulo = TOMASULO(filename, clock_cycles_per_instruction)
	program_over = tomasulo.print_status()

	print('#' * 200)
	
	while((len(tomasulo.instr_queue) != 0) or (not(program_over))):
		tomasulo.execute()
		program_over = tomasulo.print_status()
		print('#' * 200)
	
if __name__=="__main__":
	main()