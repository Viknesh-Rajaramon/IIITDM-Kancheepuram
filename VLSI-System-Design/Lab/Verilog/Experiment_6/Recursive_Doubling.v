`include "Parallel_Prefix.v"

module recursive_doubling(
	input [31:0] x0,
	input [31:0] x1,
	output [31:0] r0,
	output [31:0] r1
	);
	
	wire [31:0] y0,y1;
	wire [31:0] z0,z1;
	wire [31:0] p0,p1;
	wire [31:0] q0,q1;
	
	parallelprefix kpg0(x0[31],x1[31],x0[30],x1[30],y0[31],y1[31]);
	parallelprefix kpg1(x0[30],x1[30],x0[29],x1[29],y0[30],y1[30]);
	parallelprefix kpg2(x0[29],x1[29],x0[28],x1[28],y0[29],y1[29]);
	parallelprefix kpg3(x0[28],x1[28],x0[27],x1[27],y0[28],y1[28]);
	parallelprefix kpg4(x0[27],x1[27],x0[26],x1[26],y0[27],y1[27]);
	parallelprefix kpg5(x0[26],x1[26],x0[25],x1[25],y0[26],y1[26]);
	parallelprefix kpg6(x0[25],x1[25],x0[24],x1[24],y0[25],y1[25]);
	parallelprefix kpg7(x0[24],x1[24],x0[23],x1[23],y0[24],y1[24]);
	parallelprefix kpg8(x0[23],x1[23],x0[22],x1[22],y0[23],y1[23]);
	parallelprefix kpg9(x0[22],x1[22],x0[21],x1[21],y0[22],y1[22]);
	parallelprefix kpg10(x0[21],x1[21],x0[20],x1[20],y0[21],y1[21]);
	parallelprefix kpg11(x0[20],x1[20],x0[19],x1[19],y0[20],y1[20]);
	parallelprefix kpg12(x0[19],x1[19],x0[18],x1[18],y0[19],y1[19]);
	parallelprefix kpg13(x0[18],x1[18],x0[17],x1[17],y0[18],y1[18]);
	parallelprefix kpg14(x0[17],x1[17],x0[16],x1[16],y0[17],y1[17]);
	parallelprefix kpg15(x0[16],x1[16],x0[15],x1[15],y0[16],y1[16]);
	parallelprefix kpg16(x0[15],x1[15],x0[14],x1[14],y0[15],y1[15]);
	parallelprefix kpg17(x0[14],x1[14],x0[13],x1[13],y0[14],y1[14]);
	parallelprefix kpg18(x0[13],x1[13],x0[12],x1[12],y0[13],y1[13]);
	parallelprefix kpg19(x0[12],x1[12],x0[11],x1[11],y0[12],y1[12]);
	parallelprefix kpg20(x0[11],x1[11],x0[10],x1[10],y0[11],y1[11]);
	parallelprefix kpg21(x0[10],x1[10],x0[9],x1[9],y0[10],y1[10]);
	parallelprefix kpg22(x0[9],x1[9],x0[8],x1[8],y0[9],y1[9]);
	parallelprefix kpg23(x0[8],x1[8],x0[7],x1[7],y0[8],y1[8]);
	parallelprefix kpg24(x0[7],x1[7],x0[6],x1[6],y0[7],y1[7]);
	parallelprefix kpg25(x0[6],x1[6],x0[5],x1[5],y0[6],y1[6]);
	parallelprefix kpg26(x0[5],x1[5],x0[4],x1[4],y0[5],y1[5]);
	parallelprefix kpg27(x0[4],x1[4],x0[3],x1[3],y0[4],y1[4]);
	parallelprefix kpg28(x0[3],x1[3],x0[2],x1[2],y0[3],y1[3]);
	parallelprefix kpg29(x0[2],x1[2],x0[1],x1[1],y0[2],y1[2]);
	parallelprefix kpg30(x0[1],x1[1],x0[0],x1[0],y0[1],y1[1]);
	parallelprefix kpg31(x0[0],x1[0],1'b0,1'b0,y0[0],y1[0]);
	
	
	parallelprefix kpg32(y0[31],y1[31],y0[29],y1[29],z0[31],z1[31]);
	parallelprefix kpg33(y0[30],y1[30],y0[28],y1[28],z0[30],z1[30]);
	parallelprefix kpg34(y0[29],y1[29],y0[27],y1[27],z0[29],z1[29]);
	parallelprefix kpg35(y0[28],y1[28],y0[26],y1[26],z0[28],z1[28]);
	parallelprefix kpg36(y0[27],y1[27],y0[25],y1[25],z0[27],z1[27]);
	parallelprefix kpg37(y0[26],y1[26],y0[24],y1[24],z0[26],z1[26]);
	parallelprefix kpg38(y0[25],y1[25],y0[23],y1[23],z0[25],z1[25]);
	parallelprefix kpg39(y0[24],y1[24],y0[22],y1[22],z0[24],z1[24]);
	parallelprefix kpg40(y0[23],y1[23],y0[21],y1[21],z0[23],z1[23]);
	parallelprefix kpg41(y0[22],y1[22],y0[20],y1[20],z0[22],z1[22]);
	parallelprefix kpg42(y0[21],y1[21],y0[19],y1[19],z0[21],z1[21]);
	parallelprefix kpg43(y0[20],y1[20],y0[18],y1[18],z0[20],z1[20]);
	parallelprefix kpg44(y0[19],y1[19],y0[17],y1[17],z0[19],z1[19]);
	parallelprefix kpg45(y0[18],y1[18],y0[16],y1[16],z0[18],z1[18]);
	parallelprefix kpg46(y0[17],y1[17],y0[15],y1[15],z0[17],z1[17]);
	parallelprefix kpg47(y0[16],y1[16],y0[14],y1[14],z0[16],z1[16]);
	parallelprefix kpg48(y0[15],y1[15],y0[13],y1[13],z0[15],z1[15]);
	parallelprefix kpg49(y0[14],y1[14],y0[12],y1[12],z0[14],z1[14]);
	parallelprefix kpg50(y0[13],y1[13],y0[11],y1[11],z0[13],z1[13]);
	parallelprefix kpg51(y0[12],y1[12],y0[10],y1[10],z0[12],z1[12]);
	parallelprefix kpg52(y0[11],y1[11],y0[9],y1[9],z0[11],z1[11]);
	parallelprefix kpg53(y0[10],y1[10],y0[8],y1[8],z0[10],z1[10]);
	parallelprefix kpg54(y0[9],y1[9],y0[7],y1[7],z0[9],z1[9]);
	parallelprefix kpg55(y0[8],y1[8],y0[6],y1[6],z0[8],z1[8]);
	parallelprefix kpg56(y0[7],y1[7],y0[5],y1[5],z0[7],z1[7]);
	parallelprefix kpg57(y0[6],y1[6],y0[4],y1[4],z0[6],z1[6]);
	parallelprefix kpg58(y0[5],y1[5],y0[3],y1[3],z0[5],z1[5]);
	parallelprefix kpg59(y0[4],y1[4],y0[2],y1[2],z0[4],z1[4]);
	parallelprefix kpg60(y0[3],y1[3],y0[1],y1[1],z0[3],z1[3]);
	parallelprefix kpg61(y0[2],y1[2],y0[0],y1[0],z0[2],z1[2]);
	parallelprefix kpg62(y0[1],y1[1],1'b0,1'b0,z0[1],z1[1]);
	parallelprefix kpg63(y0[0],y1[0],y0[0],y1[0],z0[0],z1[0]);
	
	
	parallelprefix kpg64(z0[31],z1[31],z0[27],z1[27],p0[31],p1[31]);
	parallelprefix kpg65(z0[30],z1[30],z0[26],z1[26],p0[30],p1[30]);
	parallelprefix kpg66(z0[29],z1[29],z0[25],z1[25],p0[29],p1[29]);
	parallelprefix kpg67(z0[28],z1[28],z0[24],z1[24],p0[28],p1[28]);
	parallelprefix kpg68(z0[27],z1[27],z0[23],z1[23],p0[27],p1[27]);
	parallelprefix kpg69(z0[26],z1[26],z0[22],z1[22],p0[26],p1[26]);
	parallelprefix kpg70(z0[25],z1[25],z0[21],z1[21],p0[25],p1[25]);
	parallelprefix kpg71(z0[24],z1[24],z0[20],z1[20],p0[24],p1[24]);
	parallelprefix kpg72(z0[23],z1[23],z0[19],z1[19],p0[23],p1[23]);
	parallelprefix kpg73(z0[22],z1[22],z0[18],z1[18],p0[22],p1[22]);
	parallelprefix kpg74(z0[21],z1[21],z0[17],z1[17],p0[21],p1[21]);
	parallelprefix kpg75(z0[20],z1[20],z0[16],z1[16],p0[20],p1[20]);
	parallelprefix kpg76(z0[19],z1[19],z0[15],z1[15],p0[19],p1[19]);
	parallelprefix kpg77(z0[18],z1[18],z0[14],z1[14],p0[18],p1[18]);
	parallelprefix kpg78(z0[17],z1[17],z0[13],z1[13],p0[17],p1[17]);
	parallelprefix kpg79(z0[16],z1[16],z0[12],z1[12],p0[16],p1[16]);
	parallelprefix kpg80(z0[15],z1[15],z0[11],z1[11],p0[15],p1[15]);
	parallelprefix kpg81(z0[14],z1[14],z0[10],z1[10],p0[14],p1[14]);
	parallelprefix kpg82(z0[13],z1[13],z0[9],z1[9],p0[13],p1[13]);
	parallelprefix kpg83(z0[12],z1[12],z0[8],z1[8],p0[12],p1[12]);
	parallelprefix kpg84(z0[11],z1[11],z0[7],z1[7],p0[11],p1[11]);
	parallelprefix kpg85(z0[10],z1[10],z0[6],z1[6],p0[10],p1[10]);
	parallelprefix kpg86(z0[9],z1[9],z0[5],z1[5],p0[9],p1[9]);
	parallelprefix kpg87(z0[8],z1[8],z0[4],z1[4],p0[8],p1[8]);
	parallelprefix kpg88(z0[7],z1[7],z0[3],z1[3],p0[7],p1[7]);
	parallelprefix kpg89(z0[6],z1[6],z0[2],z1[2],p0[6],p1[6]);
	parallelprefix kpg90(z0[5],z1[5],z0[1],z1[1],p0[5],p1[5]);
	parallelprefix kpg91(z0[4],z1[4],z0[0],z1[0],p0[4],p1[4]);
	parallelprefix kpg92(z0[3],z1[3],1'b0,1'b0,p0[3],p1[3]);
	parallelprefix kpg93(z0[2],z1[2],z0[2],z1[2],p0[2],p1[2]);
	parallelprefix kpg94(z0[1],z1[1],z0[1],z1[1],p0[1],p1[1]);
	parallelprefix kpg95(z0[0],z1[0],z0[0],z1[0],p0[0],p1[0]);
	
	
	parallelprefix kpg96(p0[31],p1[31],p0[23],p1[23],q0[31],q1[31]);
	parallelprefix kpg97(p0[30],p1[30],p0[22],p1[22],q0[30],q1[30]);
	parallelprefix kpg98(p0[29],p1[29],p0[21],p1[21],q0[29],q1[29]);
	parallelprefix kpg99(p0[28],p1[28],p0[20],p1[20],q0[28],q1[28]);
	parallelprefix kpg100(p0[27],p1[27],p0[19],p1[19],q0[27],q1[27]);
	parallelprefix kpg101(p0[26],p1[26],p0[18],p1[18],q0[26],q1[26]);
	parallelprefix kpg102(p0[25],p1[25],p0[17],p1[17],q0[25],q1[25]);
	parallelprefix kpg103(p0[24],p1[24],p0[16],p1[16],q0[24],q1[24]);
	parallelprefix kpg104(p0[23],p1[23],p0[15],p1[15],q0[23],q1[23]);
	parallelprefix kpg105(p0[22],p1[22],p0[14],p1[14],q0[22],q1[22]);
	parallelprefix kpg106(p0[21],p1[21],p0[13],p1[13],q0[21],q1[21]);
	parallelprefix kpg107(p0[20],p1[20],p0[12],p1[12],q0[20],q1[20]);
	parallelprefix kpg108(p0[19],p1[19],p0[11],p1[11],q0[19],q1[19]);
	parallelprefix kpg109(p0[18],p1[18],p0[10],p1[10],q0[18],q1[18]);
	parallelprefix kpg110(p0[17],p1[17],p0[9],p1[9],q0[17],q1[17]);
	parallelprefix kpg111(p0[16],p1[16],p0[8],p1[8],q0[16],q1[16]);
	parallelprefix kpg112(p0[15],p1[15],p0[7],p1[7],q0[15],q1[15]);
	parallelprefix kpg113(p0[14],p1[14],p0[6],p1[6],q0[14],q1[14]);
	parallelprefix kpg114(p0[13],p1[13],p0[5],p1[5],q0[13],q1[13]);
	parallelprefix kpg115(p0[12],p1[12],p0[4],p1[4],q0[12],q1[12]);
	parallelprefix kpg116(p0[11],p1[11],p0[3],p1[3],q0[11],q1[11]);
	parallelprefix kpg117(p0[10],p1[10],p0[2],p1[2],q0[10],q1[10]);
	parallelprefix kpg118(p0[9],p1[9],p0[1],p1[1],q0[9],q1[9]);
	parallelprefix kpg119(p0[8],p1[8],p0[0],p1[0],q0[8],q1[8]);
	parallelprefix kpg120(p0[7],p1[7],1'b0,1'b0,q0[7],q1[7]);
	parallelprefix kpg121(p0[6],p1[6],p0[6],p1[6],q0[6],q1[6]);
	parallelprefix kpg122(p0[5],p1[5],p0[5],p1[5],q0[5],q1[5]);
	parallelprefix kpg123(p0[4],p1[4],p0[4],p1[4],q0[4],q1[4]);
	parallelprefix kpg124(p0[3],p1[3],p0[3],p1[3],q0[3],q1[3]);
	parallelprefix kpg125(p0[2],p1[2],p0[2],p1[2],q0[2],q1[2]);
	parallelprefix kpg126(p0[1],p1[1],p0[1],p1[1],q0[1],q1[1]);
	parallelprefix kpg127(p0[0],p1[0],p0[0],p1[0],q0[0],q1[0]);
	
	
	parallelprefix kpg128(q0[31],q1[31],q0[15],q1[15],r0[31],r1[31]);
	parallelprefix kpg129(q0[30],q1[30],q0[14],q1[14],r0[30],r1[30]);
	parallelprefix kpg130(q0[29],q1[29],q0[13],q1[13],r0[29],r1[29]);
	parallelprefix kpg131(q0[28],q1[28],q0[12],q1[12],r0[28],r1[28]);
	parallelprefix kpg132(q0[27],q1[27],q0[11],q1[11],r0[27],r1[27]);
	parallelprefix kpg133(q0[26],q1[26],q0[10],q1[10],r0[26],r1[26]);
	parallelprefix kpg134(q0[25],q1[25],q0[9],q1[9],r0[25],r1[25]);
	parallelprefix kpg135(q0[24],q1[24],q0[8],q1[8],r0[24],r1[24]);
	parallelprefix kpg136(q0[23],q1[23],q0[7],q1[7],r0[23],r1[23]);
	parallelprefix kpg137(q0[22],q1[22],q0[6],q1[6],r0[22],r1[22]);
	parallelprefix kpg138(q0[21],q1[21],q0[5],q1[5],r0[21],r1[21]);
	parallelprefix kpg139(q0[20],q1[20],q0[4],q1[4],r0[20],r1[20]);
	parallelprefix kpg140(q0[19],q1[19],q0[3],q1[3],r0[19],r1[19]);
	parallelprefix kpg141(q0[18],q1[18],q0[2],q1[2],r0[18],r1[18]);
	parallelprefix kpg142(q0[17],q1[17],q0[1],q1[1],r0[17],r1[17]);
	parallelprefix kpg143(q0[16],q1[16],q0[0],q1[0],r0[16],r1[16]);
	parallelprefix kpg144(q0[15],q1[15],1'b0,1'b0,r0[15],r1[15]);
	parallelprefix kpg145(q0[14],q1[14],q0[14],q1[14],r0[14],r1[14]);
	parallelprefix kpg146(q0[13],q1[13],q0[13],q1[13],r0[13],r1[13]);
	parallelprefix kpg147(q0[12],q1[12],q0[12],q1[12],r0[12],r1[12]);
	parallelprefix kpg148(q0[11],q1[11],q0[11],q1[11],r0[11],r1[11]);
	parallelprefix kpg149(q0[10],q1[10],q0[10],q1[10],r0[10],r1[10]);
	parallelprefix kpg150(q0[9],q1[9],q0[9],q1[9],r0[9],r1[9]);
	parallelprefix kpg151(q0[8],q1[8],q0[8],q1[8],r0[8],r1[8]);
	parallelprefix kpg152(q0[7],q1[7],q0[7],q1[7],r0[7],r1[7]);
	parallelprefix kpg153(q0[6],q1[6],q0[6],q1[6],r0[6],r1[6]);
	parallelprefix kpg154(q0[5],q1[5],q0[5],q1[5],r0[5],r1[5]);
	parallelprefix kpg155(q0[4],q1[4],q0[4],q1[4],r0[4],r1[4]);
	parallelprefix kpg156(q0[3],q1[3],q0[3],q1[3],r0[3],r1[3]);
	parallelprefix kpg157(q0[2],q1[2],q0[2],q1[2],r0[2],r1[2]);
	parallelprefix kpg158(q0[1],q1[1],q0[1],q1[1],r0[1],r1[1]);
	parallelprefix kpg159(q0[0],q1[0],q0[0],q1[0],r0[0],r1[0]);

endmodule
