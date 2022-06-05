class Convert:
	
	def __init__(self, capacity):
		self.top=-1
		self.capacity=capacity
		self.array=[]
		self.output=[]
		self.precedence={'+':1, '-':1, '*':2, '/':2, '^':3}
		
	def isEmpty(self):
		if self.top==-1:
			return True
		else:
			return False
		
	def peek(self):
		return self.array[-1]
	
	def pop(self):
		if not self.isEmpty():
			self.top=self.top-1
			return self.array.pop()
		else:
			return "$"
	
	def push(self,op):
		self.top=self.top+1
		self.array.append(op)
		
	def isOperand(self,char):
		return char.isalpha()
		
	def notGreater(self,i):
		try:
			a=self.precedence[i]
			b=self.precedence[self.peek()]
			if a<=b:
				return True
			else:
				return False
		except KeyError:
			return False
			
	def Infix_to_Postfix(self,exp):
		for i in exp:
			if self.isOperand(i):
				self.output.append(i)
			elif i=='(':
				self.push(i)
			elif i==')':
				while((not self.isEmpty()) and self.peek()!='('):
					self.output.append(self.pop())
				if(not self.isEmpty() and self.peek()!='('):
					return -1
				else:
					self.pop()
			else:
				while(not self.isEmpty() and self.notGreater(i)):
					self.output.append(self.pop())
				self.push(i)
		while not self.isEmpty():
			self.output.append(self.pop())
			
		return "".join(self.output)
