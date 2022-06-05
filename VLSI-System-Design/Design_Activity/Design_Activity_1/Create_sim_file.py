from Infix_to_Postfix_Conversion import *

def NOT(input,count):
	return "p %s Vdd %s 2 9\nn %s Gnd %s 2 9\n\n"%(input,"out_"+str(count),input,"out_"+str(count))

def AND(a,b,count):
	i=a+"_nand_"+b+"_int"
	p1="p %s %s %s 2 9\n"%(a,"Vdd","nand"+str(count))
	p2="p %s %s %s 2 9\n"%(b,"Vdd","nand"+str(count))
	n1="n %s %s %s 2 9\n"%(a,"nand"+str(count),i)
	n2="n %s %s %s 2 9\n\n"%(b,i,"Gnd")
	f=NOT("nand"+str(count),count)
	return p1+p2+n1+n2+f
	
def OR(a,b,count):
	i=a+"_nor_"+b+"_int"
	p1="p %s %s %s 2 9\n"%(a,"Vdd",i)
	p2="p %s %s %s 2 9\n"%(b,i,"nor"+str(count))
	n1="n %s %s %s 2 9\n"%(a,"nor"+str(count),"Gnd")
	n2="n %s %s %s 2 9\n\n"%(b,"nor"+str(count),"Gnd")
	f=NOT("nor"+str(count),count)
	return p1+p2+n1+n2+f
	
space=[]
output=""

def create(expression,count,space,output):
	for i in range(len(expression)):
		if(expression[i]=='~'):
			output=output+(NOT(space.pop(-1),count))
			space.append("out_"+str(count))
			count+=1
		elif(expression[i]=='&'):
			output=output+(AND(space.pop(-1),space.pop(-1),count))
			space.append("out_"+str(count))
			count+=1
		elif(expression[i]=='|'):
			output=output+(OR(space.pop(-1),space.pop(-1),count))
			space.append("out_"+str(count))
			count+=1
		else:
			space.append(expression[i])
	return output


print("\nUse ~ for NOT; | for OR ; & for AND ; Use Brackets () for all operations to establish precedence\n")
expression=input("Enter the expression : ")
sim_filename=input("\nEnter the filename of the sim file that you want to save as(without .sim extension) : ")
obj=Convert(len(expression))
a=obj.Infix_to_Postfix(expression)
print("\nEquivalent Postfix Expression : "+a+"\n")
output=create(a,0,space,output)
sim_filename=sim_filename+".sim"
print("Last CMOS expression in %s file is the output - \"out_num\" where num is a number\n"%(sim_filename))
fptr=open(sim_filename,"w")
fptr.write(output)
print("%s file created\n\nRun command \"irsim %s\" to view output\n"%(sim_filename,sim_filename))
