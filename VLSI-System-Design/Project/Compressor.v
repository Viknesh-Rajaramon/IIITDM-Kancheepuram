`include "Adder.v"

module compressor_4_2(
	input a,
	input b,
	input c,
	input d,
	input cin,
	output sum,
	output cout,
	output carry
	);
	
	wire w;
	
	full_adder F1 (a,b,c,w,cout);
	full_adder F2 (w,d,cin,sum,carry);

endmodule
