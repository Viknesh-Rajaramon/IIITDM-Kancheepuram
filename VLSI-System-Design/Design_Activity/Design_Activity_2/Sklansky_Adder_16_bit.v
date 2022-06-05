module initialize_g_p(
	input a,
	input b,
	output g,
	output p
	);
	
	assign g=a&b;
	assign p=a^b;

endmodule

module merge(
	input g_in1,
	input p_in1,
	input g_in2,
	input p_in2,
	output g_out,
	output p_out
	);
	
	wire w;
	
	assign w=p_in1&g_in2;
	assign g_out=w|g_in1;
	
	assign p_out=p_in1&p_in2;

endmodule

module feedthrough(
	input g_in1,
	input p_in1,
	input g_in2,
	output g_out
	);
	
	wire w;
	
	assign w=p_in1&g_in2;
	assign g_out=w|g_in1;

endmodule

module sklansky(
	input [15:0] a,
	input [15:0] b,
	input cin,
	output [15:0] sum,
	output cout
	);
	
	wire [16:0] [16:0] g;
	wire [16:0] [16:0] p;
	
	assign g[0][0]=cin;
	assign p[0][0]=1'b0;
	
	initialize_g_p GP_00(a[0],b[0],g[1][1],p[1][1]);
	initialize_g_p GP_01(a[1],b[1],g[2][2],p[2][2]);
	initialize_g_p GP_02(a[2],b[2],g[3][3],p[3][3]);
	initialize_g_p GP_03(a[3],b[3],g[4][4],p[4][4]);
	initialize_g_p GP_04(a[4],b[4],g[5][5],p[5][5]);
	initialize_g_p GP_05(a[5],b[5],g[6][6],p[6][6]);
	initialize_g_p GP_06(a[6],b[6],g[7][7],p[7][7]);
	initialize_g_p GP_07(a[7],b[7],g[8][8],p[8][8]);
	initialize_g_p GP_08(a[8],b[8],g[9][9],p[9][9]);
	initialize_g_p GP_09(a[9],b[9],g[10][10],p[10][10]);
	initialize_g_p GP_10(a[10],b[10],g[11][11],p[11][11]);
	initialize_g_p GP_11(a[11],b[11],g[12][12],p[12][12]);
	initialize_g_p GP_12(a[12],b[12],g[13][13],p[13][13]);
	initialize_g_p GP_13(a[13],b[13],g[14][14],p[14][14]);
	initialize_g_p GP_14(a[14],b[14],g[15][15],p[15][15]);
	initialize_g_p GP_15(a[15],b[15],g[16][16],p[16][16]);
	
	feedthrough cell_1_1(g[1][1],p[1][1],g[0][0],g[1][0]);
	merge cell_1_3(g[3][3],p[3][3],g[2][2],p[2][2],g[3][2],p[3][2]);
	merge cell_1_5(g[5][5],p[5][5],g[4][4],p[4][4],g[5][4],p[5][4]);
	merge cell_1_7(g[7][7],p[7][7],g[6][6],p[6][6],g[7][6],p[7][6]);
	merge cell_1_9(g[9][9],p[9][9],g[8][8],p[8][8],g[9][8],p[9][8]);
	merge cell_1_11(g[11][11],p[11][11],g[10][10],p[10][10],g[11][10],p[11][10]);
	merge cell_1_13(g[13][13],p[13][13],g[12][12],p[12][12],g[13][12],p[13][12]);
	merge cell_1_15(g[15][15],p[15][15],g[14][14],p[14][14],g[15][14],p[15][14]);
	
	
	feedthrough cell_2_2(g[2][2],p[2][2],g[1][0],g[2][0]);
	feedthrough cell_2_3(g[3][2],p[3][2],g[1][0],g[3][0]);
	merge cell_2_6(g[6][6],p[6][6],g[5][4],p[5][4],g[6][4],p[6][4]);
	merge cell_2_7(g[7][6],p[7][6],g[5][4],p[5][4],g[7][4],p[7][4]);
	merge cell_2_10(g[10][10],p[10][10],g[9][8],p[9][8],g[10][8],p[10][8]);
	merge cell_2_11(g[11][10],p[11][10],g[9][8],p[9][8],g[11][8],p[11][8]);
	merge cell_2_14(g[14][14],p[14][14],g[13][12],p[13][12],g[14][12],p[14][12]);
	merge cell_2_15(g[15][14],p[15][14],g[13][12],p[13][12],g[15][12],p[15][12]);
	
	
	feedthrough cell_3_4(g[4][4],p[4][4],g[3][0],g[4][0]);
	feedthrough cell_3_5(g[5][4],p[5][4],g[3][0],g[5][0]);
	feedthrough cell_3_6(g[6][4],p[6][4],g[3][0],g[6][0]);
	feedthrough cell_3_7(g[7][4],p[7][4],g[3][0],g[7][0]);
	merge cell_3_12(g[12][12],p[12][12],g[11][8],p[11][8],g[12][8],p[12][8]);
	merge cell_3_13(g[13][12],p[13][12],g[11][8],p[11][8],g[13][8],p[13][8]);
	merge cell_3_14(g[14][12],p[14][12],g[11][8],p[11][8],g[14][8],p[14][8]);
	merge cell_3_15(g[15][12],p[15][12],g[11][8],p[11][8],g[15][8],p[15][8]);
	
	
	feedthrough cell_4_8(g[8][8],p[8][8],g[7][0],g[8][0]);
	feedthrough cell_4_9(g[9][8],p[9][8],g[7][0],g[9][0]);
	feedthrough cell_4_10(g[10][8],p[10][8],g[7][0],g[10][0]);
	feedthrough cell_4_11(g[11][8],p[11][8],g[7][0],g[11][0]);
	feedthrough cell_4_12(g[12][8],p[12][8],g[7][0],g[12][0]);
	feedthrough cell_4_13(g[13][8],p[13][8],g[7][0],g[13][0]);
	feedthrough cell_4_14(g[14][8],p[14][8],g[7][0],g[14][0]);
	feedthrough cell_4_15(g[15][8],p[15][8],g[7][0],g[15][0]);
	
	
	
	assign sum[0]=g[0][0]^p[1][1];
	assign sum[1]=g[1][0]^p[2][2];
	assign sum[2]=g[2][0]^p[3][3];
	assign sum[3]=g[3][0]^p[4][4];
	assign sum[4]=g[4][0]^p[5][5];
	assign sum[5]=g[5][0]^p[6][6];
	assign sum[6]=g[6][0]^p[7][7];
	assign sum[7]=g[7][0]^p[8][8];
	assign sum[8]=g[8][0]^p[9][9];
	assign sum[9]=g[9][0]^p[10][10];
	assign sum[10]=g[10][0]^p[11][11];
	assign sum[11]=g[11][0]^p[12][12];
	assign sum[12]=g[12][0]^p[13][13];
	assign sum[13]=g[13][0]^p[14][14];
	assign sum[14]=g[14][0]^p[15][15];
	assign sum[15]=g[15][0]^p[16][16];
	
	assign cout=(g[15][0]&p[16][16])|g[16][16];
	
endmodule


