import os
from subprocess import call

def convert_to_hex(x):
	s = hex(x)[2:]
	return (8 - len(s)) * '0' + s


def generate_verilog_test_bench(operation, op1, op2):
    current_working_dir = os.getcwd()

    if(operation in ['ADD', 'SUB']):
        os.chdir(current_working_dir + "/Int_Add")

        filedata = 0

        if(operation == 'ADD'):
            with open("CLA_32_bit_tb_Python_Add.v", 'r') as file:
                filedata = file.read()
        
        else:
            with open("CLA_32_bit_tb_Python_Sub.v", 'r') as file:
                filedata = file.read()
        
        op1 = convert_to_hex(op1)
        op2 = convert_to_hex(op2)
        
        filedata = filedata.replace('&', str(op1))
        filedata = filedata.replace('!', str(op2))

        with open("CLA_32_bit_tb.v", 'w') as files:
            files.write(filedata)
            
        with open("verilog_output.txt", 'w') as fp:
            call(["iverilog", "CLA_32_bit_tb.v"])
            call(["./a.out"], stdout = fp)
    
    if(operation == 'MULT'):
        os.chdir(current_working_dir + "/Int_Mult")

        filedata = 0
        
        with open("Wallace_32_bit_Python.v", 'r') as file:
            filedata = file.read()
        
        op1 = convert_to_hex(op1)
        op2 = convert_to_hex(op2)
        
        filedata = filedata.replace('&', str(op1))
        filedata = filedata.replace('!', str(op2))

        with open("Wallace_32_bit_tb.v", 'w') as files:
            files.write(filedata)
            
        with open("verilog_output.txt", 'w') as fp:
            call(["iverilog", "Wallace_32_bit_tb.v"])
            call(["./a.out"], stdout = fp)
    
    if(operation in ['FADD', 'FSUB']):
        os.chdir(current_working_dir + "/FP_Add")

        filedata = 0

        with open("FP_Add_tb_Python.v", 'r') as file:
            filedata = file.read()
        
        op1 = convert_to_hex(op1)
        op2 = convert_to_hex(op2)
        
        filedata = filedata.replace('&', str(op1))

        if(operation == 'FADD'):
            filedata = filedata.replace('!', str(op2))
        
        else:
            filedata = filedata.replace('!', str(op2^1))
        
        with open("FP_Add_tb.v", 'w') as files:
            files.write(filedata)
            
        with open("verilog_output.txt", 'w') as fp:
            call(["iverilog", "FP_Add_tb.v"])
            call(["./a.out"], stdout = fp)

    if(operation == 'FMULT'):
        os.chdir(current_working_dir + "/FP_Mult")
        
        with open("FP_Mult_tb_Python.v", 'r') as file:
            filedata = file.read()
        
        op1 = convert_to_hex(op1)
        op2 = convert_to_hex(op2)
        
        filedata = filedata.replace('&', str(op1))
        filedata = filedata.replace('!', str(op2))

        with open("FP_Mult_tb.v", 'w') as files:
            files.write(filedata)
            
        with open("verilog_output.txt", 'w') as fp:
            call(["iverilog", "FP_Mult_tb.v"])
            call(["./a.out"], stdout = fp)


    if(operation in ['AND', 'OR', 'NOR', 'NAND', 'XOR', 'XNOR', 'NOT']):
        d = {'AND' : '000', 'OR' : '001', 'NOR' : '010', 'NAND' : '011', 'XOR': '100', 'XNOR': '101', 'NOT': '110'}

        os.chdir(current_working_dir + "/Logic_Unit")

        with open("Logic_Unit_tb_Python.v", 'r') as file:
            filedata = file.read()
        
        sel = d[operation]
        
        if(operation == 'NOT'):
            op2 = '0'
        
        op1 = convert_to_hex(op1)
        op2 = convert_to_hex(op2)
        
        filedata = filedata.replace('^', str(sel))
        filedata = filedata.replace('&', op1)
        filedata = filedata.replace('!', op2)

        with open("Logic_Unit_tb.v", 'w') as files:
            files.write(filedata)
            
        with open("verilog_output.txt", 'w') as fp:
            call(["iverilog", "Logic_Unit_tb.v"])
            call(["./a.out"], stdout = fp)

    f = open("verilog_output.txt", "r")
    
    op = f.readline().split(' ')[-2]
    os.remove("verilog_output.txt")
    os.chdir("..")
    return int(op)