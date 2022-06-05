module mux(
	input in0,
	input in1,
	input s0,
	output out
	);
	
	assign out=(s0)?in1:in0;

endmodule

module barrel_shifter_right(
	input [23:0] in,
	input [7:0] shift,
	output [23:0] out
	);
	
	wire [23:0] x,y,z,p;
	
	//16 bit shift right
	mux mux0_23(in[23],1'b0,shift[4],x[23]);
	mux mux0_22(in[22],1'b0,shift[4],x[22]);
	mux mux0_21(in[21],1'b0,shift[4],x[21]);
	mux mux0_20(in[20],1'b0,shift[4],x[20]);
	mux mux0_19(in[19],1'b0,shift[4],x[19]);
	mux mux0_18(in[18],1'b0,shift[4],x[18]);
	mux mux0_17(in[17],1'b0,shift[4],x[17]);
	mux mux0_16(in[16],1'b0,shift[4],x[16]);
	mux mux0_15(in[15],1'b0,shift[4],x[15]);
	mux mux0_14(in[14],1'b0,shift[4],x[14]);
	mux mux0_13(in[13],1'b0,shift[4],x[13]);
	mux mux0_12(in[12],1'b0,shift[4],x[12]);
	mux mux0_11(in[11],1'b0,shift[4],x[11]);
	mux mux0_10(in[10],1'b0,shift[4],x[10]);
	mux mux0_09(in[9],1'b0,shift[4],x[9]);
	mux mux0_08(in[8],1'b0,shift[4],x[8]);
	mux mux0_07(in[7],in[23],shift[4],x[7]);
	mux mux0_06(in[6],in[22],shift[4],x[6]);
	mux mux0_05(in[5],in[21],shift[4],x[5]);
	mux mux0_04(in[4],in[20],shift[4],x[4]);
	mux mux0_03(in[3],in[19],shift[4],x[3]);
	mux mux0_02(in[2],in[18],shift[4],x[2]);
	mux mux0_01(in[1],in[17],shift[4],x[1]);
	mux mux0_00(in[0],in[16],shift[4],x[0]);
	
	//8 bit shift right
	mux mux1_23(x[23],1'b0,shift[3],y[23]);
	mux mux1_22(x[22],1'b0,shift[3],y[22]);
	mux mux1_21(x[21],1'b0,shift[3],y[21]);
	mux mux1_20(x[20],1'b0,shift[3],y[20]);
	mux mux1_19(x[19],1'b0,shift[3],y[19]);
	mux mux1_18(x[18],1'b0,shift[3],y[18]);
	mux mux1_17(x[17],1'b0,shift[3],y[17]);
	mux mux1_16(x[16],1'b0,shift[3],y[16]);
	mux mux1_15(x[15],x[23],shift[3],y[15]);
	mux mux1_14(x[14],x[22],shift[3],y[14]);
	mux mux1_13(x[13],x[21],shift[3],y[13]);
	mux mux1_12(x[12],x[20],shift[3],y[12]);
	mux mux1_11(x[11],x[19],shift[3],y[11]);
	mux mux1_10(x[10],x[18],shift[3],y[10]);
	mux mux1_09(x[9],x[17],shift[3],y[9]);
	mux mux1_08(x[8],x[16],shift[3],y[8]);
	mux mux1_07(x[7],x[15],shift[3],y[7]);
	mux mux1_06(x[6],x[14],shift[3],y[6]);
	mux mux1_05(x[5],x[13],shift[3],y[5]);
	mux mux1_04(x[4],x[12],shift[3],y[4]);
	mux mux1_03(x[3],x[11],shift[3],y[3]);
	mux mux1_02(x[2],x[10],shift[3],y[2]);
	mux mux1_01(x[1],x[9],shift[3],y[1]);
	mux mux1_00(x[0],x[8],shift[3],y[0]);
	
	//4 bit shift right
	mux mux2_23(y[23],1'b0,shift[2],z[23]);
	mux mux2_22(y[22],1'b0,shift[2],z[22]);
	mux mux2_21(y[21],1'b0,shift[2],z[21]);
	mux mux2_20(y[20],1'b0,shift[2],z[20]);
	mux mux2_19(y[19],y[23],shift[2],z[19]);
	mux mux2_18(y[18],y[22],shift[2],z[18]);
	mux mux2_17(y[17],y[21],shift[2],z[17]);
	mux mux2_16(y[16],y[20],shift[2],z[16]);
	mux mux2_15(y[15],y[19],shift[2],z[15]);
	mux mux2_14(y[14],y[18],shift[2],z[14]);
	mux mux2_13(y[13],y[17],shift[2],z[13]);
	mux mux2_12(y[12],y[16],shift[2],z[12]);
	mux mux2_11(y[11],y[15],shift[2],z[11]);
	mux mux2_10(y[10],y[14],shift[2],z[10]);
	mux mux2_09(y[9],y[13],shift[2],z[9]);
	mux mux2_08(y[8],y[12],shift[2],z[8]);
	mux mux2_07(y[7],y[11],shift[2],z[7]);
	mux mux2_06(y[6],y[10],shift[2],z[6]);
	mux mux2_05(y[5],y[9],shift[2],z[5]);
	mux mux2_04(y[4],y[8],shift[2],z[4]);
	mux mux2_03(y[3],y[7],shift[2],z[3]);
	mux mux2_02(y[2],y[6],shift[2],z[2]);
	mux mux2_01(y[1],y[5],shift[2],z[1]);
	mux mux2_00(y[0],y[4],shift[2],z[0]);
	
	//2 bit shift right
	mux mux3_23(z[23],1'b0,shift[1],p[23]);
	mux mux3_22(z[22],1'b0,shift[1],p[22]);
	mux mux3_21(z[21],z[23],shift[1],p[21]);
	mux mux3_20(z[20],z[22],shift[1],p[20]);
	mux mux3_19(z[19],z[21],shift[1],p[19]);
	mux mux3_18(z[18],z[20],shift[1],p[18]);
	mux mux3_17(z[17],z[19],shift[1],p[17]);
	mux mux3_16(z[16],z[18],shift[1],p[16]);
	mux mux3_15(z[15],z[17],shift[1],p[15]);
	mux mux3_14(z[14],z[16],shift[1],p[14]);
	mux mux3_13(z[13],z[15],shift[1],p[13]);
	mux mux3_12(z[12],z[14],shift[1],p[12]);
	mux mux3_11(z[11],z[13],shift[1],p[11]);
	mux mux3_10(z[10],z[12],shift[1],p[10]);
	mux mux3_09(z[9],z[11],shift[1],p[9]);
	mux mux3_08(z[8],z[10],shift[1],p[8]);
	mux mux3_07(z[7],z[9],shift[1],p[7]);
	mux mux3_06(z[6],z[8],shift[1],p[6]);
	mux mux3_05(z[5],z[7],shift[1],p[5]);
	mux mux3_04(z[4],z[6],shift[1],p[4]);
	mux mux3_03(z[3],z[5],shift[1],p[3]);
	mux mux3_02(z[2],z[4],shift[1],p[2]);
	mux mux3_01(z[1],z[3],shift[1],p[1]);
	mux mux3_00(z[0],z[2],shift[1],p[0]);
	
	//1 bit shift right
	mux mux4_23(p[23],1'b0,shift[0],out[23]);
	mux mux4_22(p[22],p[23],shift[0],out[22]);
	mux mux4_21(p[21],p[22],shift[0],out[21]);
	mux mux4_20(p[20],p[21],shift[0],out[20]);
	mux mux4_19(p[19],p[20],shift[0],out[19]);
	mux mux4_18(p[18],p[19],shift[0],out[18]);
	mux mux4_17(p[17],p[18],shift[0],out[17]);
	mux mux4_16(p[16],p[17],shift[0],out[16]);
	mux mux4_15(p[15],p[16],shift[0],out[15]);
	mux mux4_14(p[14],p[15],shift[0],out[14]);
	mux mux4_13(p[13],p[14],shift[0],out[13]);
	mux mux4_12(p[12],p[13],shift[0],out[12]);
	mux mux4_11(p[11],p[12],shift[0],out[11]);
	mux mux4_10(p[10],p[11],shift[0],out[10]);
	mux mux4_09(p[9],p[10],shift[0],out[9]);
	mux mux4_08(p[8],p[9],shift[0],out[8]);
	mux mux4_07(p[7],p[8],shift[0],out[7]);
	mux mux4_06(p[6],p[7],shift[0],out[6]);
	mux mux4_05(p[5],p[6],shift[0],out[5]);
	mux mux4_04(p[4],p[5],shift[0],out[4]);
	mux mux4_03(p[3],p[4],shift[0],out[3]);
	mux mux4_02(p[2],p[3],shift[0],out[2]);
	mux mux4_01(p[1],p[2],shift[0],out[1]);
	mux mux4_00(p[0],p[1],shift[0],out[0]);

endmodule

module barrel_shifter_left(
	input [23:0] in,
	input [7:0] shift,
	output [23:0] out
	);
	
	wire [23:0] x,y,z,p;
	
	//16 bit shift left
	mux mux0_00(in[0],1'b0,shift[4],x[0]);
	mux mux0_01(in[1],1'b0,shift[4],x[1]);
	mux mux0_02(in[2],1'b0,shift[4],x[2]);
	mux mux0_03(in[3],1'b0,shift[4],x[3]);
	mux mux0_04(in[4],1'b0,shift[4],x[4]);
	mux mux0_05(in[5],1'b0,shift[4],x[5]);
	mux mux0_06(in[6],1'b0,shift[4],x[6]);
	mux mux0_07(in[7],1'b0,shift[4],x[7]);
	mux mux0_08(in[8],1'b0,shift[4],x[8]);
	mux mux0_09(in[9],1'b0,shift[4],x[9]);
	mux mux0_10(in[10],1'b0,shift[4],x[10]);
	mux mux0_11(in[11],1'b0,shift[4],x[11]);
	mux mux0_12(in[12],1'b0,shift[4],x[12]);
	mux mux0_13(in[13],1'b0,shift[4],x[13]);
	mux mux0_14(in[14],1'b0,shift[4],x[14]);
	mux mux0_15(in[15],1'b0,shift[4],x[15]);
	mux mux0_16(in[16],in[0],shift[4],x[16]);
	mux mux0_17(in[17],in[1],shift[4],x[17]);
	mux mux0_18(in[18],in[2],shift[4],x[18]);
	mux mux0_19(in[19],in[3],shift[4],x[19]);
	mux mux0_20(in[20],in[4],shift[4],x[20]);
	mux mux0_21(in[21],in[5],shift[4],x[21]);
	mux mux0_22(in[22],in[6],shift[4],x[22]);
	mux mux0_23(in[23],in[7],shift[4],x[23]);
	
	//8 bit shift left
	mux mux1_00(x[0],1'b0,shift[3],y[0]);
	mux mux1_01(x[1],1'b0,shift[3],y[1]);
	mux mux1_02(x[2],1'b0,shift[3],y[2]);
	mux mux1_03(x[3],1'b0,shift[3],y[3]);
	mux mux1_04(x[4],1'b0,shift[3],y[4]);
	mux mux1_05(x[5],1'b0,shift[3],y[5]);
	mux mux1_06(x[6],1'b0,shift[3],y[6]);
	mux mux1_07(x[7],1'b0,shift[3],y[7]);
	mux mux1_08(x[8],x[0],shift[3],y[8]);
	mux mux1_09(x[9],x[1],shift[3],y[9]);
	mux mux1_10(x[10],x[2],shift[3],y[10]);
	mux mux1_11(x[11],x[3],shift[3],y[11]);
	mux mux1_12(x[12],x[4],shift[3],y[12]);
	mux mux1_13(x[13],x[5],shift[3],y[13]);
	mux mux1_14(x[14],x[6],shift[3],y[14]);
	mux mux1_15(x[15],x[7],shift[3],y[15]);
	mux mux1_16(x[16],x[8],shift[3],y[16]);
	mux mux1_17(x[17],x[9],shift[3],y[17]);
	mux mux1_18(x[18],x[10],shift[3],y[18]);
	mux mux1_19(x[19],x[11],shift[3],y[19]);
	mux mux1_20(x[20],x[12],shift[3],y[20]);
	mux mux1_21(x[21],x[13],shift[3],y[21]);
	mux mux1_22(x[22],x[14],shift[3],y[22]);
	mux mux1_23(x[23],x[15],shift[3],y[23]);
	
	//4 bit shift left
	mux mux2_00(y[0],1'b0,shift[2],z[0]);
	mux mux2_01(y[1],1'b0,shift[2],z[1]);
	mux mux2_02(y[2],1'b0,shift[2],z[2]);
	mux mux2_03(y[3],1'b0,shift[2],z[3]);
	mux mux2_04(y[4],y[0],shift[2],z[4]);
	mux mux2_05(y[5],y[1],shift[2],z[5]);
	mux mux2_06(y[6],y[2],shift[2],z[6]);
	mux mux2_07(y[7],y[3],shift[2],z[7]);
	mux mux2_08(y[8],y[4],shift[2],z[8]);
	mux mux2_09(y[9],y[5],shift[2],z[9]);
	mux mux2_10(y[10],y[6],shift[2],z[10]);
	mux mux2_11(y[11],y[7],shift[2],z[11]);
	mux mux2_12(y[12],y[8],shift[2],z[12]);
	mux mux2_13(y[13],y[9],shift[2],z[13]);
	mux mux2_14(y[14],y[10],shift[2],z[14]);
	mux mux2_15(y[15],y[11],shift[2],z[15]);
	mux mux2_16(y[16],y[12],shift[2],z[16]);
	mux mux2_17(y[17],y[13],shift[2],z[17]);
	mux mux2_18(y[18],y[14],shift[2],z[18]);
	mux mux2_19(y[19],y[15],shift[2],z[19]);
	mux mux2_20(y[20],y[16],shift[2],z[20]);
	mux mux2_21(y[21],y[17],shift[2],z[21]);
	mux mux2_22(y[22],y[18],shift[2],z[22]);
	mux mux2_23(y[23],y[19],shift[2],z[23]);
	
	//2 bit shift left
	mux mux3_00(z[0],1'b0,shift[1],p[0]);
	mux mux3_01(z[1],1'b0,shift[1],p[1]);
	mux mux3_02(z[2],z[0],shift[1],p[2]);
	mux mux3_03(z[3],z[2],shift[1],p[3]);
	mux mux3_04(z[4],z[2],shift[1],p[4]);
	mux mux3_05(z[5],z[3],shift[1],p[5]);
	mux mux3_06(z[6],z[4],shift[1],p[6]);
	mux mux3_07(z[7],z[5],shift[1],p[7]);
	mux mux3_08(z[8],z[6],shift[1],p[8]);
	mux mux3_09(z[9],z[7],shift[1],p[9]);
	mux mux3_10(z[10],z[8],shift[1],p[10]);
	mux mux3_11(z[11],z[9],shift[1],p[11]);
	mux mux3_12(z[12],z[10],shift[1],p[12]);
	mux mux3_13(z[13],z[11],shift[1],p[13]);
	mux mux3_14(z[14],z[12],shift[1],p[14]);
	mux mux3_15(z[15],z[13],shift[1],p[15]);
	mux mux3_16(z[16],z[14],shift[1],p[16]);
	mux mux3_17(z[17],z[15],shift[1],p[17]);
	mux mux3_18(z[18],z[16],shift[1],p[18]);
	mux mux3_19(z[19],z[17],shift[1],p[19]);
	mux mux3_20(z[20],z[18],shift[1],p[20]);
	mux mux3_21(z[21],z[19],shift[1],p[21]);
	mux mux3_22(z[22],z[20],shift[1],p[22]);
	mux mux3_23(z[23],z[21],shift[1],p[23]);
	
	//1 bit shift left
	mux mux4_00(p[0],1'b0,shift[0],out[0]);
	mux mux4_01(p[1],p[0],shift[0],out[1]);
	mux mux4_02(p[2],p[1],shift[0],out[2]);
	mux mux4_03(p[3],p[2],shift[0],out[3]);
	mux mux4_04(p[4],p[3],shift[0],out[4]);
	mux mux4_05(p[5],p[4],shift[0],out[5]);
	mux mux4_06(p[6],p[5],shift[0],out[6]);
	mux mux4_07(p[7],p[6],shift[0],out[7]);
	mux mux4_08(p[8],p[7],shift[0],out[8]);
	mux mux4_09(p[9],p[8],shift[0],out[9]);
	mux mux4_10(p[10],p[9],shift[0],out[10]);
	mux mux4_11(p[11],p[10],shift[0],out[11]);
	mux mux4_12(p[12],p[11],shift[0],out[12]);
	mux mux4_13(p[13],p[12],shift[0],out[13]);
	mux mux4_14(p[14],p[13],shift[0],out[14]);
	mux mux4_15(p[15],p[14],shift[0],out[15]);
	mux mux4_16(p[16],p[15],shift[0],out[16]);
	mux mux4_17(p[17],p[16],shift[0],out[17]);
	mux mux4_18(p[18],p[17],shift[0],out[18]);
	mux mux4_19(p[19],p[18],shift[0],out[19]);
	mux mux4_20(p[20],p[19],shift[0],out[20]);
	mux mux4_21(p[21],p[20],shift[0],out[21]);
	mux mux4_22(p[22],p[21],shift[0],out[22]);
	mux mux4_23(p[23],p[22],shift[0],out[23]);

endmodule



