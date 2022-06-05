`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    10:31:12 10/16/2020 
// Design Name: 
// Module Name:    array_multiplier_16_bit 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module full_adder(
	input a,
	input b,
	input cin,
	output sum,
	output cout
	);
	
	assign sum=(a^b^cin);
	assign cout=((a&b)|(b&cin)|(a&cin));

endmodule

module MUL(
	input multiplicand,
	input multiplier,
	input sum_in,
	input carry_in,
	output sum_out,
	output carry_out
	);
	
	wire w;
	
	and and_0(w,multiplicand,multiplier);
	
	full_adder FA(sum_in,w,carry_in,sum_out,carry_out);
	
endmodule

module array_multiplier_16_bit(
    input [15:0] a,
    input [15:0] b,
    output [31:0] product
    );
	
	wire [15:0] sum0,sum1,sum2,sum3,sum4,sum5,sum6,sum7,sum8,sum9,sum10,sum11,sum12,sum13,sum14,sum15,sum16;
	wire [15:0] carry0,carry1,carry2,carry3,carry4,carry5,carry6,carry7,carry8,carry9,carry10,carry11,carry12,carry13,carry14,carry15,carry16;
	
	MUL M0_00(a[0],b[0],1'b0,1'b0,sum0[0],carry0[0]);
	MUL M0_01(a[1],b[0],1'b0,1'b0,sum0[1],carry0[1]);
	MUL M0_02(a[2],b[0],1'b0,1'b0,sum0[2],carry0[2]);
	MUL M0_03(a[3],b[0],1'b0,1'b0,sum0[3],carry0[3]);
	MUL M0_04(a[4],b[0],1'b0,1'b0,sum0[4],carry0[4]);
	MUL M0_05(a[5],b[0],1'b0,1'b0,sum0[5],carry0[5]);
	MUL M0_06(a[6],b[0],1'b0,1'b0,sum0[6],carry0[6]);
	MUL M0_07(a[7],b[0],1'b0,1'b0,sum0[7],carry0[7]);
	MUL M0_08(a[8],b[0],1'b0,1'b0,sum0[8],carry0[8]);
	MUL M0_09(a[9],b[0],1'b0,1'b0,sum0[9],carry0[9]);
	MUL M0_10(a[10],b[0],1'b0,1'b0,sum0[10],carry0[10]);
	MUL M0_11(a[11],b[0],1'b0,1'b0,sum0[11],carry0[11]);
	MUL M0_12(a[12],b[0],1'b0,1'b0,sum0[12],carry0[12]);
	MUL M0_13(a[13],b[0],1'b0,1'b0,sum0[13],carry0[13]);
	MUL M0_14(a[14],b[0],1'b0,1'b0,sum0[14],carry0[14]);
	MUL M0_15(a[15],b[0],1'b0,1'b0,sum0[15],carry0[15]);
	
	
	MUL M1_00(a[0],b[1],sum0[1],carry0[0],sum1[0],carry1[0]);
	MUL M1_01(a[1],b[1],sum0[2],carry0[1],sum1[1],carry1[1]);
	MUL M1_02(a[2],b[1],sum0[3],carry0[2],sum1[2],carry1[2]);
	MUL M1_03(a[3],b[1],sum0[4],carry0[3],sum1[3],carry1[3]);
	MUL M1_04(a[4],b[1],sum0[5],carry0[4],sum1[4],carry1[4]);
	MUL M1_05(a[5],b[1],sum0[6],carry0[5],sum1[5],carry1[5]);
	MUL M1_06(a[6],b[1],sum0[7],carry0[6],sum1[6],carry1[6]);
	MUL M1_07(a[7],b[1],sum0[8],carry0[7],sum1[7],carry1[7]);
	MUL M1_08(a[8],b[1],sum0[9],carry0[8],sum1[8],carry1[8]);
	MUL M1_09(a[9],b[1],sum0[10],carry0[9],sum1[9],carry1[9]);
	MUL M1_10(a[10],b[1],sum0[11],carry0[10],sum1[10],carry1[10]);
	MUL M1_11(a[11],b[1],sum0[12],carry0[11],sum1[11],carry1[11]);
	MUL M1_12(a[12],b[1],sum0[13],carry0[12],sum1[12],carry1[12]);
	MUL M1_13(a[13],b[1],sum0[14],carry0[13],sum1[13],carry1[13]);
	MUL M1_14(a[14],b[1],sum0[15],carry0[14],sum1[14],carry1[14]);
	MUL M1_15(a[15],b[1],1'b0,carry0[15],sum1[15],carry1[15]);
	
	
	MUL M2_00(a[0],b[2],sum1[1],carry1[0],sum2[0],carry2[0]);
	MUL M2_01(a[1],b[2],sum1[2],carry1[1],sum2[1],carry2[1]);
	MUL M2_02(a[2],b[2],sum1[3],carry1[2],sum2[2],carry2[2]);
	MUL M2_03(a[3],b[2],sum1[4],carry1[3],sum2[3],carry2[3]);
	MUL M2_04(a[4],b[2],sum1[5],carry1[4],sum2[4],carry2[4]);
	MUL M2_05(a[5],b[2],sum1[6],carry1[5],sum2[5],carry2[5]);
	MUL M2_06(a[6],b[2],sum1[7],carry1[6],sum2[6],carry2[6]);
	MUL M2_07(a[7],b[2],sum1[8],carry1[7],sum2[7],carry2[7]);
	MUL M2_08(a[8],b[2],sum1[9],carry1[8],sum2[8],carry2[8]);
	MUL M2_09(a[9],b[2],sum1[10],carry1[9],sum2[9],carry2[9]);
	MUL M2_10(a[10],b[2],sum1[11],carry1[10],sum2[10],carry2[10]);
	MUL M2_11(a[11],b[2],sum1[12],carry1[11],sum2[11],carry2[11]);
	MUL M2_12(a[12],b[2],sum1[13],carry1[12],sum2[12],carry2[12]);
	MUL M2_13(a[13],b[2],sum1[14],carry1[13],sum2[13],carry2[13]);
	MUL M2_14(a[14],b[2],sum1[15],carry1[14],sum2[14],carry2[14]);
	MUL M2_15(a[15],b[2],1'b0,carry1[15],sum2[15],carry2[15]);
	
	
	MUL M3_00(a[0],b[3],sum2[1],carry2[0],sum3[0],carry3[0]);
	MUL M3_01(a[1],b[3],sum2[2],carry2[1],sum3[1],carry3[1]);
	MUL M3_02(a[2],b[3],sum2[3],carry2[2],sum3[2],carry3[2]);
	MUL M3_03(a[3],b[3],sum2[4],carry2[3],sum3[3],carry3[3]);
	MUL M3_04(a[4],b[3],sum2[5],carry2[4],sum3[4],carry3[4]);
	MUL M3_05(a[5],b[3],sum2[6],carry2[5],sum3[5],carry3[5]);
	MUL M3_06(a[6],b[3],sum2[7],carry2[6],sum3[6],carry3[6]);
	MUL M3_07(a[7],b[3],sum2[8],carry2[7],sum3[7],carry3[7]);
	MUL M3_08(a[8],b[3],sum2[9],carry2[8],sum3[8],carry3[8]);
	MUL M3_09(a[9],b[3],sum2[10],carry2[9],sum3[9],carry3[9]);
	MUL M3_10(a[10],b[3],sum2[11],carry2[10],sum3[10],carry3[10]);
	MUL M3_11(a[11],b[3],sum2[12],carry2[11],sum3[11],carry3[11]);
	MUL M3_12(a[12],b[3],sum2[13],carry2[12],sum3[12],carry3[12]);
	MUL M3_13(a[13],b[3],sum2[14],carry2[13],sum3[13],carry3[13]);
	MUL M3_14(a[14],b[3],sum2[15],carry2[14],sum3[14],carry3[14]);
	MUL M3_15(a[15],b[3],1'b0,carry2[15],sum3[15],carry3[15]);
	
	
	MUL M4_00(a[0],b[4],sum3[1],carry3[0],sum4[0],carry4[0]);
	MUL M4_01(a[1],b[4],sum3[2],carry3[1],sum4[1],carry4[1]);
	MUL M4_02(a[2],b[4],sum3[3],carry3[2],sum4[2],carry4[2]);
	MUL M4_03(a[3],b[4],sum3[4],carry3[3],sum4[3],carry4[3]);
	MUL M4_04(a[4],b[4],sum3[5],carry3[4],sum4[4],carry4[4]);
	MUL M4_05(a[5],b[4],sum3[6],carry3[5],sum4[5],carry4[5]);
	MUL M4_06(a[6],b[4],sum3[7],carry3[6],sum4[6],carry4[6]);
	MUL M4_07(a[7],b[4],sum3[8],carry3[7],sum4[7],carry4[7]);
	MUL M4_08(a[8],b[4],sum3[9],carry3[8],sum4[8],carry4[8]);
	MUL M4_09(a[9],b[4],sum3[10],carry3[9],sum4[9],carry4[9]);
	MUL M4_10(a[10],b[4],sum3[11],carry3[10],sum4[10],carry4[10]);
	MUL M4_11(a[11],b[4],sum3[12],carry3[11],sum4[11],carry4[11]);
	MUL M4_12(a[12],b[4],sum3[13],carry3[12],sum4[12],carry4[12]);
	MUL M4_13(a[13],b[4],sum3[14],carry3[13],sum4[13],carry4[13]);
	MUL M4_14(a[14],b[4],sum3[15],carry3[14],sum4[14],carry4[14]);
	MUL M4_15(a[15],b[4],1'b0,carry3[15],sum4[15],carry4[15]);
	
	
	MUL M5_00(a[0],b[5],sum4[1],carry4[0],sum5[0],carry5[0]);
	MUL M5_01(a[1],b[5],sum4[2],carry4[1],sum5[1],carry5[1]);
	MUL M5_02(a[2],b[5],sum4[3],carry4[2],sum5[2],carry5[2]);
	MUL M5_03(a[3],b[5],sum4[4],carry4[3],sum5[3],carry5[3]);
	MUL M5_04(a[4],b[5],sum4[5],carry4[4],sum5[4],carry5[4]);
	MUL M5_05(a[5],b[5],sum4[6],carry4[5],sum5[5],carry5[5]);
	MUL M5_06(a[6],b[5],sum4[7],carry4[6],sum5[6],carry5[6]);
	MUL M5_07(a[7],b[5],sum4[8],carry4[7],sum5[7],carry5[7]);
	MUL M5_08(a[8],b[5],sum4[9],carry4[8],sum5[8],carry5[8]);
	MUL M5_09(a[9],b[5],sum4[10],carry4[9],sum5[9],carry5[9]);
	MUL M5_10(a[10],b[5],sum4[11],carry4[10],sum5[10],carry5[10]);
	MUL M5_11(a[11],b[5],sum4[12],carry4[11],sum5[11],carry5[11]);
	MUL M5_12(a[12],b[5],sum4[13],carry4[12],sum5[12],carry5[12]);
	MUL M5_13(a[13],b[5],sum4[14],carry4[13],sum5[13],carry5[13]);
	MUL M5_14(a[14],b[5],sum4[15],carry4[14],sum5[14],carry5[14]);
	MUL M5_15(a[15],b[5],1'b0,carry4[15],sum5[15],carry5[15]);
	
	
	MUL M6_00(a[0],b[6],sum5[1],carry5[0],sum6[0],carry6[0]);
	MUL M6_01(a[1],b[6],sum5[2],carry5[1],sum6[1],carry6[1]);
	MUL M6_02(a[2],b[6],sum5[3],carry5[2],sum6[2],carry6[2]);
	MUL M6_03(a[3],b[6],sum5[4],carry5[3],sum6[3],carry6[3]);
	MUL M6_04(a[4],b[6],sum5[5],carry5[4],sum6[4],carry6[4]);
	MUL M6_05(a[5],b[6],sum5[6],carry5[5],sum6[5],carry6[5]);
	MUL M6_06(a[6],b[6],sum5[7],carry5[6],sum6[6],carry6[6]);
	MUL M6_07(a[7],b[6],sum5[8],carry5[7],sum6[7],carry6[7]);
	MUL M6_08(a[8],b[6],sum5[9],carry5[8],sum6[8],carry6[8]);
	MUL M6_09(a[9],b[6],sum5[10],carry5[9],sum6[9],carry6[9]);
	MUL M6_10(a[10],b[6],sum5[11],carry5[10],sum6[10],carry6[10]);
	MUL M6_11(a[11],b[6],sum5[12],carry5[11],sum6[11],carry6[11]);
	MUL M6_12(a[12],b[6],sum5[13],carry5[12],sum6[12],carry6[12]);
	MUL M6_13(a[13],b[6],sum5[14],carry5[13],sum6[13],carry6[13]);
	MUL M6_14(a[14],b[6],sum5[15],carry5[14],sum6[14],carry6[14]);
	MUL M6_15(a[15],b[6],1'b0,carry5[15],sum6[15],carry6[15]);
	
	
	MUL M7_00(a[0],b[7],sum6[1],carry6[0],sum7[0],carry7[0]);
	MUL M7_01(a[1],b[7],sum6[2],carry6[1],sum7[1],carry7[1]);
	MUL M7_02(a[2],b[7],sum6[3],carry6[2],sum7[2],carry7[2]);
	MUL M7_03(a[3],b[7],sum6[4],carry6[3],sum7[3],carry7[3]);
	MUL M7_04(a[4],b[7],sum6[5],carry6[4],sum7[4],carry7[4]);
	MUL M7_05(a[5],b[7],sum6[6],carry6[5],sum7[5],carry7[5]);
	MUL M7_06(a[6],b[7],sum6[7],carry6[6],sum7[6],carry7[6]);
	MUL M7_07(a[7],b[7],sum6[8],carry6[7],sum7[7],carry7[7]);
	MUL M7_08(a[8],b[7],sum6[9],carry6[8],sum7[8],carry7[8]);
	MUL M7_09(a[9],b[7],sum6[10],carry6[9],sum7[9],carry7[9]);
	MUL M7_10(a[10],b[7],sum6[11],carry6[10],sum7[10],carry7[10]);
	MUL M7_11(a[11],b[7],sum6[12],carry6[11],sum7[11],carry7[11]);
	MUL M7_12(a[12],b[7],sum6[13],carry6[12],sum7[12],carry7[12]);
	MUL M7_13(a[13],b[7],sum6[14],carry6[13],sum7[13],carry7[13]);
	MUL M7_14(a[14],b[7],sum6[15],carry6[14],sum7[14],carry7[14]);
	MUL M7_15(a[15],b[7],1'b0,carry6[15],sum7[15],carry7[15]);
	
	
	MUL M8_00(a[0],b[8],sum7[1],carry7[0],sum8[0],carry8[0]);
	MUL M8_01(a[1],b[8],sum7[2],carry7[1],sum8[1],carry8[1]);
	MUL M8_02(a[2],b[8],sum7[3],carry7[2],sum8[2],carry8[2]);
	MUL M8_03(a[3],b[8],sum7[4],carry7[3],sum8[3],carry8[3]);
	MUL M8_04(a[4],b[8],sum7[5],carry7[4],sum8[4],carry8[4]);
	MUL M8_05(a[5],b[8],sum7[6],carry7[5],sum8[5],carry8[5]);
	MUL M8_06(a[6],b[8],sum7[7],carry7[6],sum8[6],carry8[6]);
	MUL M8_07(a[7],b[8],sum7[8],carry7[7],sum8[7],carry8[7]);
	MUL M8_08(a[8],b[8],sum7[9],carry7[8],sum8[8],carry8[8]);
	MUL M8_09(a[9],b[8],sum7[10],carry7[9],sum8[9],carry8[9]);
	MUL M8_10(a[10],b[8],sum7[11],carry7[10],sum8[10],carry8[10]);
	MUL M8_11(a[11],b[8],sum7[12],carry7[11],sum8[11],carry8[11]);
	MUL M8_12(a[12],b[8],sum7[13],carry7[12],sum8[12],carry8[12]);
	MUL M8_13(a[13],b[8],sum7[14],carry7[13],sum8[13],carry8[13]);
	MUL M8_14(a[14],b[8],sum7[15],carry7[14],sum8[14],carry8[14]);
	MUL M8_15(a[15],b[8],1'b0,carry7[15],sum8[15],carry8[15]);
	
	
	MUL M9_00(a[0],b[9],sum8[1],carry8[0],sum9[0],carry9[0]);
	MUL M9_01(a[1],b[9],sum8[2],carry8[1],sum9[1],carry9[1]);
	MUL M9_02(a[2],b[9],sum8[3],carry8[2],sum9[2],carry9[2]);
	MUL M9_03(a[3],b[9],sum8[4],carry8[3],sum9[3],carry9[3]);
	MUL M9_04(a[4],b[9],sum8[5],carry8[4],sum9[4],carry9[4]);
	MUL M9_05(a[5],b[9],sum8[6],carry8[5],sum9[5],carry9[5]);
	MUL M9_06(a[6],b[9],sum8[7],carry8[6],sum9[6],carry9[6]);
	MUL M9_07(a[7],b[9],sum8[8],carry8[7],sum9[7],carry9[7]);
	MUL M9_08(a[8],b[9],sum8[9],carry8[8],sum9[8],carry9[8]);
	MUL M9_09(a[9],b[9],sum8[10],carry8[9],sum9[9],carry9[9]);
	MUL M9_10(a[10],b[9],sum8[11],carry8[10],sum9[10],carry9[10]);
	MUL M9_11(a[11],b[9],sum8[12],carry8[11],sum9[11],carry9[11]);
	MUL M9_12(a[12],b[9],sum8[13],carry8[12],sum9[12],carry9[12]);
	MUL M9_13(a[13],b[9],sum8[14],carry8[13],sum9[13],carry9[13]);
	MUL M9_14(a[14],b[9],sum8[15],carry8[14],sum9[14],carry9[14]);
	MUL M9_15(a[15],b[9],1'b0,carry8[15],sum9[15],carry9[15]);
	
	
	MUL M10_00(a[0],b[10],sum9[1],carry9[0],sum10[0],carry10[0]);
	MUL M10_01(a[1],b[10],sum9[2],carry9[1],sum10[1],carry10[1]);
	MUL M10_02(a[2],b[10],sum9[3],carry9[2],sum10[2],carry10[2]);
	MUL M10_03(a[3],b[10],sum9[4],carry9[3],sum10[3],carry10[3]);
	MUL M10_04(a[4],b[10],sum9[5],carry9[4],sum10[4],carry10[4]);
	MUL M10_05(a[5],b[10],sum9[6],carry9[5],sum10[5],carry10[5]);
	MUL M10_06(a[6],b[10],sum9[7],carry9[6],sum10[6],carry10[6]);
	MUL M10_07(a[7],b[10],sum9[8],carry9[7],sum10[7],carry10[7]);
	MUL M10_08(a[8],b[10],sum9[9],carry9[8],sum10[8],carry10[8]);
	MUL M10_09(a[9],b[10],sum9[10],carry9[9],sum10[9],carry10[9]);
	MUL M10_10(a[10],b[10],sum9[11],carry9[10],sum10[10],carry10[10]);
	MUL M10_11(a[11],b[10],sum9[12],carry9[11],sum10[11],carry10[11]);
	MUL M10_12(a[12],b[10],sum9[13],carry9[12],sum10[12],carry10[12]);
	MUL M10_13(a[13],b[10],sum9[14],carry9[13],sum10[13],carry10[13]);
	MUL M10_14(a[14],b[10],sum9[15],carry9[14],sum10[14],carry10[14]);
	MUL M10_15(a[15],b[10],1'b0,carry9[15],sum10[15],carry10[15]);
	
	
	MUL M11_00(a[0],b[11],sum10[1],carry10[0],sum11[0],carry11[0]);
	MUL M11_01(a[1],b[11],sum10[2],carry10[1],sum11[1],carry11[1]);
	MUL M11_02(a[2],b[11],sum10[3],carry10[2],sum11[2],carry11[2]);
	MUL M11_03(a[3],b[11],sum10[4],carry10[3],sum11[3],carry11[3]);
	MUL M11_04(a[4],b[11],sum10[5],carry10[4],sum11[4],carry11[4]);
	MUL M11_05(a[5],b[11],sum10[6],carry10[5],sum11[5],carry11[5]);
	MUL M11_06(a[6],b[11],sum10[7],carry10[6],sum11[6],carry11[6]);
	MUL M11_07(a[7],b[11],sum10[8],carry10[7],sum11[7],carry11[7]);
	MUL M11_08(a[8],b[11],sum10[9],carry10[8],sum11[8],carry11[8]);
	MUL M11_09(a[9],b[11],sum10[10],carry10[9],sum11[9],carry11[9]);
	MUL M11_10(a[10],b[11],sum10[11],carry10[10],sum11[10],carry11[10]);
	MUL M11_11(a[11],b[11],sum10[12],carry10[11],sum11[11],carry11[11]);
	MUL M11_12(a[12],b[11],sum10[13],carry10[12],sum11[12],carry11[12]);
	MUL M11_13(a[13],b[11],sum10[14],carry10[13],sum11[13],carry11[13]);
	MUL M11_14(a[14],b[11],sum10[15],carry10[14],sum11[14],carry11[14]);
	MUL M11_15(a[15],b[11],1'b0,carry10[15],sum11[15],carry11[15]);
	
	
	MUL M12_00(a[0],b[12],sum11[1],carry11[0],sum12[0],carry12[0]);
	MUL M12_01(a[1],b[12],sum11[2],carry11[1],sum12[1],carry12[1]);
	MUL M12_02(a[2],b[12],sum11[3],carry11[2],sum12[2],carry12[2]);
	MUL M12_03(a[3],b[12],sum11[4],carry11[3],sum12[3],carry12[3]);
	MUL M12_04(a[4],b[12],sum11[5],carry11[4],sum12[4],carry12[4]);
	MUL M12_05(a[5],b[12],sum11[6],carry11[5],sum12[5],carry12[5]);
	MUL M12_06(a[6],b[12],sum11[7],carry11[6],sum12[6],carry12[6]);
	MUL M12_07(a[7],b[12],sum11[8],carry11[7],sum12[7],carry12[7]);
	MUL M12_08(a[8],b[12],sum11[9],carry11[8],sum12[8],carry12[8]);
	MUL M12_09(a[9],b[12],sum11[10],carry11[9],sum12[9],carry12[9]);
	MUL M12_10(a[10],b[12],sum11[11],carry11[10],sum12[10],carry12[10]);
	MUL M12_11(a[11],b[12],sum11[12],carry11[11],sum12[11],carry12[11]);
	MUL M12_12(a[12],b[12],sum11[13],carry11[12],sum12[12],carry12[12]);
	MUL M12_13(a[13],b[12],sum11[14],carry11[13],sum12[13],carry12[13]);
	MUL M12_14(a[14],b[12],sum11[15],carry11[14],sum12[14],carry12[14]);
	MUL M12_15(a[15],b[12],1'b0,carry11[15],sum12[15],carry12[15]);
	
	
	MUL M13_00(a[0],b[13],sum12[1],carry12[0],sum13[0],carry13[0]);
	MUL M13_01(a[1],b[13],sum12[2],carry12[1],sum13[1],carry13[1]);
	MUL M13_02(a[2],b[13],sum12[3],carry12[2],sum13[2],carry13[2]);
	MUL M13_03(a[3],b[13],sum12[4],carry12[3],sum13[3],carry13[3]);
	MUL M13_04(a[4],b[13],sum12[5],carry12[4],sum13[4],carry13[4]);
	MUL M13_05(a[5],b[13],sum12[6],carry12[5],sum13[5],carry13[5]);
	MUL M13_06(a[6],b[13],sum12[7],carry12[6],sum13[6],carry13[6]);
	MUL M13_07(a[7],b[13],sum12[8],carry12[7],sum13[7],carry13[7]);
	MUL M13_08(a[8],b[13],sum12[9],carry12[8],sum13[8],carry13[8]);
	MUL M13_09(a[9],b[13],sum12[10],carry12[9],sum13[9],carry13[9]);
	MUL M13_10(a[10],b[13],sum12[11],carry12[10],sum13[10],carry13[10]);
	MUL M13_11(a[11],b[13],sum12[12],carry12[11],sum13[11],carry13[11]);
	MUL M13_12(a[12],b[13],sum12[13],carry12[12],sum13[12],carry13[12]);
	MUL M13_13(a[13],b[13],sum12[14],carry12[13],sum13[13],carry13[13]);
	MUL M13_14(a[14],b[13],sum12[15],carry12[14],sum13[14],carry13[14]);
	MUL M13_15(a[15],b[13],1'b0,carry12[15],sum13[15],carry13[15]);
	

	MUL M14_00(a[0],b[14],sum13[1],carry13[0],sum14[0],carry14[0]);
	MUL M14_01(a[1],b[14],sum13[2],carry13[1],sum14[1],carry14[1]);
	MUL M14_02(a[2],b[14],sum13[3],carry13[2],sum14[2],carry14[2]);
	MUL M14_03(a[3],b[14],sum13[4],carry13[3],sum14[3],carry14[3]);
	MUL M14_04(a[4],b[14],sum13[5],carry13[4],sum14[4],carry14[4]);
	MUL M14_05(a[5],b[14],sum13[6],carry13[5],sum14[5],carry14[5]);
	MUL M14_06(a[6],b[14],sum13[7],carry13[6],sum14[6],carry14[6]);
	MUL M14_07(a[7],b[14],sum13[8],carry13[7],sum14[7],carry14[7]);
	MUL M14_08(a[8],b[14],sum13[9],carry13[8],sum14[8],carry14[8]);
	MUL M14_09(a[9],b[14],sum13[10],carry13[9],sum14[9],carry14[9]);
	MUL M14_10(a[10],b[14],sum13[11],carry13[10],sum14[10],carry14[10]);
	MUL M14_11(a[11],b[14],sum13[12],carry13[11],sum14[11],carry14[11]);
	MUL M14_12(a[12],b[14],sum13[13],carry13[12],sum14[12],carry14[12]);
	MUL M14_13(a[13],b[14],sum13[14],carry13[13],sum14[13],carry14[13]);
	MUL M14_14(a[14],b[14],sum13[15],carry13[14],sum14[14],carry14[14]);
	MUL M14_15(a[15],b[14],1'b0,carry13[15],sum14[15],carry14[15]);
	
	
	MUL M15_00(a[0],b[15],sum14[1],carry14[0],sum15[0],carry15[0]);
	MUL M15_01(a[1],b[15],sum14[2],carry14[1],sum15[1],carry15[1]);
	MUL M15_02(a[2],b[15],sum14[3],carry14[2],sum15[2],carry15[2]);
	MUL M15_03(a[3],b[15],sum14[4],carry14[3],sum15[3],carry15[3]);
	MUL M15_04(a[4],b[15],sum14[5],carry14[4],sum15[4],carry15[4]);
	MUL M15_05(a[5],b[15],sum14[6],carry14[5],sum15[5],carry15[5]);
	MUL M15_06(a[6],b[15],sum14[7],carry14[6],sum15[6],carry15[6]);
	MUL M15_07(a[7],b[15],sum14[8],carry14[7],sum15[7],carry15[7]);
	MUL M15_08(a[8],b[15],sum14[9],carry14[8],sum15[8],carry15[8]);
	MUL M15_09(a[9],b[15],sum14[10],carry14[9],sum15[9],carry15[9]);
	MUL M15_10(a[10],b[15],sum14[11],carry14[10],sum15[10],carry15[10]);
	MUL M15_11(a[11],b[15],sum14[12],carry14[11],sum15[11],carry15[11]);
	MUL M15_12(a[12],b[15],sum14[13],carry14[12],sum15[12],carry15[12]);
	MUL M15_13(a[13],b[15],sum14[14],carry14[13],sum15[13],carry15[13]);
	MUL M15_14(a[14],b[15],sum14[15],carry14[14],sum15[14],carry15[14]);
	MUL M15_15(a[15],b[15],1'b0,carry14[15],sum15[15],carry15[15]);
	
	MUL M16_00(1'b1,1'b0,sum15[1],carry15[0],sum16[0],carry16[0]);
	MUL M16_01(1'b1,carry16[0],sum15[2],carry15[1],sum16[1],carry16[1]);
	MUL M16_02(1'b1,carry16[1],sum15[3],carry15[2],sum16[2],carry16[2]);
	MUL M16_03(1'b1,carry16[2],sum15[4],carry15[3],sum16[3],carry16[3]);
	MUL M16_04(1'b1,carry16[3],sum15[5],carry15[4],sum16[4],carry16[4]);
	MUL M16_05(1'b1,carry16[4],sum15[6],carry15[5],sum16[5],carry16[5]);
	MUL M16_06(1'b1,carry16[5],sum15[7],carry15[6],sum16[6],carry16[6]);
	MUL M16_07(1'b1,carry16[6],sum15[8],carry15[7],sum16[7],carry16[7]);
	MUL M16_08(1'b1,carry16[7],sum15[9],carry15[8],sum16[8],carry16[8]);
	MUL M16_09(1'b1,carry16[8],sum15[10],carry15[9],sum16[9],carry16[9]);
	MUL M16_10(1'b1,carry16[9],sum15[11],carry15[10],sum16[10],carry16[10]);
	MUL M16_11(1'b1,carry16[10],sum15[12],carry15[11],sum16[11],carry16[11]);
	MUL M16_12(1'b1,carry16[11],sum15[13],carry15[12],sum16[12],carry16[12]);
	MUL M16_13(1'b1,carry16[12],sum15[14],carry15[13],sum16[13],carry16[13]);
	MUL M16_14(1'b1,carry16[13],sum15[15],carry15[14],sum16[14],carry16[14]);
	
	assign product[31]=carry16[14];
	assign product[30]=sum16[14];
	assign product[29]=sum16[13];
	assign product[28]=sum16[12];
	assign product[27]=sum16[11];
	assign product[26]=sum16[10];
	assign product[25]=sum16[9];
	assign product[24]=sum16[8];
	assign product[23]=sum16[7];
	assign product[22]=sum16[6];
	assign product[21]=sum16[5];
	assign product[20]=sum16[4];
	assign product[19]=sum16[3];
	assign product[18]=sum16[2];
	assign product[17]=sum16[1];
	assign product[16]=sum16[0];
	assign product[15]=sum15[0];
	assign product[14]=sum14[0];
	assign product[13]=sum13[0];
	assign product[12]=sum12[0];
	assign product[11]=sum11[0];
	assign product[10]=sum10[0];
	assign product[9]=sum9[0];
	assign product[8]=sum8[0];
	assign product[7]=sum7[0];
	assign product[6]=sum6[0];
	assign product[5]=sum5[0];
	assign product[4]=sum4[0];
	assign product[3]=sum3[0];
	assign product[2]=sum2[0];
	assign product[1]=sum1[0];
	assign product[0]=sum0[0];

endmodule
