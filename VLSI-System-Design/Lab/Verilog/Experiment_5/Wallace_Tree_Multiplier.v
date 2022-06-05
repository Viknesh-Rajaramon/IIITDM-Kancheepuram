`include "Adder.v"
`include "Partial_Product.v"

module WTM(
	input [31:0] a,
	input [31:0] b,
	output [63:0] out
	);
	
	wire [31:0][63:0] ppt;
	reg [31:0][63:0] pp;
	reg [63:0] sum;
	reg [63:0] carry;
	
	integer i=0;
	integer size=32;
	integer j=0;
	
	Partial_Product PP_1(a,b,ppt);
	
	always @(a,b)
	begin
		pp=ppt;
		
		while(size>2)
			begin
				for(i=0;i<(size/3);++i)
					begin
						sum=(pp[3*i]^pp[3*i+1])^(pp[3*i+2]);
						carry=(pp[3*i]&pp[3*i+1]) | (pp[3*i+1]&pp[3*i+2]) | (pp[3*i]&pp[3*i+2]);
						carry=carry<<1;
						pp[j]=sum;
						j=j+1;
						pp[j]=carry;
						j=j+1;
					end
				
				if((size-(3*(size/3)))==1)
					begin
						pp[j]=pp[size-1];
						j=j+1;
					end				
				
				else if((size-(3*(size/3)))==2)
					begin
						pp[j]=pp[size-2];
						j=j+1;
						pp[j]=pp[size-1];
						j=j+1;
					end
				
				else
				;	
				j=0;
				size=size-(3*(size/3))+(2*(size/3));
			end
	end
	
	Adder_64bit a_0(pp[0],pp[1],out);

endmodule
