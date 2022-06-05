`include "Recursive_Doubling.v"

module Adder_32bit(
	input [31:0] a,
	input [31:0] b,
	output [31:0] sum
	);
	
	wire [31:0] sum_without_carry,carry;
	wire [31:0] x0,x1;
	wire [31:0] r0,r1;

	assign sum_without_carry = a ^ b;

	assign x0 = a | b;
	assign x1 = a & b;
	
	recursive_doubling rd1(x0[31:0],x1[31:0],r0[31:0],r1[31:0]);

	assign carry = r1 & r0;

	assign sum[0] = sum_without_carry[0];
	assign sum[31:1] = sum_without_carry[31:1] ^ carry[30:0];
	
endmodule
