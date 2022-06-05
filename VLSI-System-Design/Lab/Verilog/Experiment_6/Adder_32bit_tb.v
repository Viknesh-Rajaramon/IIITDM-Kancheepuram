`include "Adder_32bit.v"

module Rec_Doub_CLA_bit;
	
	reg [31:0] a,b;
	wire [31:0] sum;
	wire cout;
	
	initial
		begin
			$dumpfile("Adder_32bit.vcd");
			$dumpvars(0,Rec_Doub_CLA_bit);
		end
	
	initial
		begin
			a = 32'b11011010101111001001100001110101;
			b = 32'b11101111101111001001011000010101;
		end
	
	Adder_32bit CLA(a,b,sum,cout);
	
	initial
		$monitor("\ta = %h, b = %h, Sum = %h, cout = %b" ,a,b,sum,cout);
	
endmodule
