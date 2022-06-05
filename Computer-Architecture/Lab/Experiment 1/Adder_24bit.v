`include "Recursive_Doubling.v"

module Adder_24bit(
	input [23:0] a,
	input [23:0] b,
	output [23:0] sum,
	output cout
	);
	
	wire [23:0] sum_without_carry,carry;
	wire [23:0] x0,x1;
	wire [23:0] r0,r1;
	
	assign sum_without_carry[0]=a[0]^b[0];
	assign sum_without_carry[1]=a[1]^b[1];
	assign sum_without_carry[2]=a[2]^b[2];
	assign sum_without_carry[3]=a[3]^b[3];
	assign sum_without_carry[4]=a[4]^b[4];
	assign sum_without_carry[5]=a[5]^b[5];
	assign sum_without_carry[6]=a[6]^b[6];
	assign sum_without_carry[7]=a[7]^b[7];
	assign sum_without_carry[8]=a[8]^b[8];
	assign sum_without_carry[9]=a[9]^b[9];
	assign sum_without_carry[10]=a[10]^b[10];
	assign sum_without_carry[11]=a[11]^b[11];
	assign sum_without_carry[12]=a[12]^b[12];
	assign sum_without_carry[13]=a[13]^b[13];
	assign sum_without_carry[14]=a[14]^b[14];
	assign sum_without_carry[15]=a[15]^b[15];
	assign sum_without_carry[16]=a[16]^b[16];
	assign sum_without_carry[17]=a[17]^b[17];
	assign sum_without_carry[18]=a[18]^b[18];
	assign sum_without_carry[19]=a[19]^b[19];
	assign sum_without_carry[20]=a[20]^b[20];
	assign sum_without_carry[21]=a[21]^b[21];
	assign sum_without_carry[22]=a[22]^b[22];
	assign sum_without_carry[23]=a[23]^b[23];
	
	assign x0[0]=a[0]|b[0];
	assign x1[0]=a[0]&b[0];
	assign x0[1]=a[1]|b[1];
	assign x1[1]=a[1]&b[1];
	assign x0[2]=a[2]|b[2];
	assign x1[2]=a[2]&b[2];
	assign x0[3]=a[3]|b[3];
	assign x1[3]=a[3]&b[3];
	assign x0[4]=a[4]|b[4];
	assign x1[4]=a[4]&b[4];
	assign x0[5]=a[5]|b[5];
	assign x1[5]=a[5]&b[5];
	assign x0[6]=a[6]|b[6];
	assign x1[6]=a[6]&b[6];
	assign x0[7]=a[7]|b[7];
	assign x1[7]=a[7]&b[7];
	assign x0[8]=a[8]|b[8];
	assign x1[8]=a[8]&b[8];
	assign x0[9]=a[9]|b[9];
	assign x1[9]=a[9]&b[9];
	assign x0[10]=a[10]|b[10];
	assign x1[10]=a[10]&b[10];
	assign x0[11]=a[11]|b[11];
	assign x1[11]=a[11]&b[11];
	assign x0[12]=a[12]|b[12];
	assign x1[12]=a[12]&b[12];
	assign x0[13]=a[13]|b[13];
	assign x1[13]=a[13]&b[13];
	assign x0[14]=a[14]|b[14];
	assign x1[14]=a[14]&b[14];
	assign x0[15]=a[15]|b[15];
	assign x1[15]=a[15]&b[15];
	assign x0[16]=a[16]|b[16];
	assign x1[16]=a[16]&b[16];
	assign x0[17]=a[17]|b[17];
	assign x1[17]=a[17]&b[17];
	assign x0[18]=a[18]|b[18];
	assign x1[18]=a[18]&b[18];
	assign x0[19]=a[19]|b[19];
	assign x1[19]=a[19]&b[19];
	assign x0[20]=a[20]|b[20];
	assign x1[20]=a[20]&b[20];
	assign x0[21]=a[21]|b[21];
	assign x1[21]=a[21]&b[21];
	assign x0[22]=a[22]|b[22];
	assign x1[22]=a[22]&b[22];
	assign x0[23]=a[23]|b[23];
	assign x1[23]=a[23]&b[23];
	
	recursive_doubling rd1(x0[23:0],x1[23:0],r0[23:0],r1[23:0]);
	
	assign carry[0]=r1[0]&r0[0];
	assign carry[1]=r1[1]&r0[1];
	assign carry[2]=r1[2]&r0[2];
	assign carry[3]=r1[3]&r0[3];
	assign carry[4]=r1[4]&r0[4];
	assign carry[5]=r1[5]&r0[5];
	assign carry[6]=r1[6]&r0[6];
	assign carry[7]=r1[7]&r0[7];
	assign carry[8]=r1[8]&r0[8];
	assign carry[9]=r1[9]&r0[9];
	assign carry[10]=r1[10]&r0[10];
	assign carry[11]=r1[11]&r0[11];
	assign carry[12]=r1[12]&r0[12];
	assign carry[13]=r1[13]&r0[13];
	assign carry[14]=r1[14]&r0[14];
	assign carry[15]=r1[15]&r0[15];
	assign carry[16]=r1[16]&r0[16];
	assign carry[17]=r1[17]&r0[17];
	assign carry[18]=r1[18]&r0[18];
	assign carry[19]=r1[19]&r0[19];
	assign carry[20]=r1[20]&r0[20];
	assign carry[21]=r1[21]&r0[21];
	assign carry[22]=r1[22]&r0[22];
	assign carry[23]=r1[23]&r0[23];
	
	assign sum[0]=sum_without_carry[0];
	assign sum[1]=sum_without_carry[1]^carry[0];
	assign sum[2]=sum_without_carry[2]^carry[1];
	assign sum[3]=sum_without_carry[3]^carry[2];
	assign sum[4]=sum_without_carry[4]^carry[3];
	assign sum[5]=sum_without_carry[5]^carry[4];
	assign sum[6]=sum_without_carry[6]^carry[5];
	assign sum[7]=sum_without_carry[7]^carry[6];
	assign sum[8]=sum_without_carry[8]^carry[7];
	assign sum[9]=sum_without_carry[9]^carry[8];
	assign sum[10]=sum_without_carry[10]^carry[9];
	assign sum[11]=sum_without_carry[11]^carry[10];
	assign sum[12]=sum_without_carry[12]^carry[11];
	assign sum[13]=sum_without_carry[13]^carry[12];
	assign sum[14]=sum_without_carry[14]^carry[13];
	assign sum[15]=sum_without_carry[15]^carry[14];
	assign sum[16]=sum_without_carry[16]^carry[15];
	assign sum[17]=sum_without_carry[17]^carry[16];
	assign sum[18]=sum_without_carry[18]^carry[17];
	assign sum[19]=sum_without_carry[19]^carry[18];
	assign sum[20]=sum_without_carry[20]^carry[19];
	assign sum[21]=sum_without_carry[21]^carry[20];
	assign sum[22]=sum_without_carry[22]^carry[21];
	assign sum[23]=sum_without_carry[23]^carry[22];
	
	assign cout=carry[23];
	
endmodule
