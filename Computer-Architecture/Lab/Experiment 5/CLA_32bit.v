`include "Clock_Delay.v"

module pgk_1_jump(
	input clock,
	input [32:1][1:0] pgk,
	output [32:1][1:0] buffer
	);

	wire [32:1][1:0] temp_pgk;

	assign temp_pgk[1][0]=pgk[1][0];
	assign temp_pgk[1][1]=pgk[1][1];
	
	assign temp_pgk[2][0]=(pgk[2][0])|(pgk[2][1]&pgk[1][0]);
	assign temp_pgk[2][1]=(pgk[2][0])|(pgk[2][1]&pgk[1][1]);

	assign temp_pgk[3][0]=(pgk[3][0])|(pgk[3][1]&pgk[2][0]);
	assign temp_pgk[3][1]=(pgk[3][0])|(pgk[3][1]&pgk[2][1]);

	assign temp_pgk[4][0]=(pgk[4][0])|(pgk[4][1]&pgk[3][0]);
	assign temp_pgk[4][1]=(pgk[4][0])|(pgk[4][1]&pgk[3][1]);

	assign temp_pgk[5][0]=(pgk[5][0])|(pgk[5][1]&pgk[4][0]);
	assign temp_pgk[5][1]=(pgk[5][0])|(pgk[5][1]&pgk[4][1]);

	assign temp_pgk[6][0]=(pgk[6][0])|(pgk[6][1]&pgk[5][0]);
	assign temp_pgk[6][1]=(pgk[6][0])|(pgk[6][1]&pgk[5][1]);

	assign temp_pgk[7][0]=(pgk[7][0])|(pgk[7][1]&pgk[6][0]);
	assign temp_pgk[7][1]=(pgk[7][0])|(pgk[7][1]&pgk[6][1]);

	assign temp_pgk[8][0]=(pgk[8][0])|(pgk[8][1]&pgk[7][0]);
	assign temp_pgk[8][1]=(pgk[8][0])|(pgk[8][1]&pgk[7][1]);

	assign temp_pgk[9][0]=(pgk[9][0])|(pgk[9][1]&pgk[8][0]);
	assign temp_pgk[9][1]=(pgk[9][0])|(pgk[9][1]&pgk[8][1]);

	assign temp_pgk[10][0]=(pgk[10][0])|(pgk[10][1]&pgk[9][0]);
	assign temp_pgk[10][1]=(pgk[10][0])|(pgk[10][1]&pgk[9][1]);

	assign temp_pgk[11][0]=(pgk[11][0])|(pgk[11][1]&pgk[10][0]);
	assign temp_pgk[11][1]=(pgk[11][0])|(pgk[11][1]&pgk[10][1]);

	assign temp_pgk[12][0]=(pgk[12][0])|(pgk[12][1]&pgk[11][0]);
	assign temp_pgk[12][1]=(pgk[12][0])|(pgk[12][1]&pgk[11][1]);

	assign temp_pgk[13][0]=(pgk[13][0])|(pgk[13][1]&pgk[12][0]);
	assign temp_pgk[13][1]=(pgk[13][0])|(pgk[13][1]&pgk[12][1]);

	assign temp_pgk[14][0]=(pgk[14][0])|(pgk[14][1]&pgk[13][0]);
	assign temp_pgk[14][1]=(pgk[14][0])|(pgk[14][1]&pgk[13][1]);

	assign temp_pgk[15][0]=(pgk[15][0])|(pgk[15][1]&pgk[14][0]);
	assign temp_pgk[15][1]=(pgk[15][0])|(pgk[15][1]&pgk[14][1]);

	assign temp_pgk[16][0]=(pgk[16][0])|(pgk[16][1]&pgk[15][0]);
	assign temp_pgk[16][1]=(pgk[16][0])|(pgk[16][1]&pgk[15][1]);

	assign temp_pgk[17][0]=(pgk[17][0])|(pgk[17][1]&pgk[16][0]);
	assign temp_pgk[17][1]=(pgk[17][0])|(pgk[17][1]&pgk[16][1]);

	assign temp_pgk[18][0]=(pgk[18][0])|(pgk[18][1]&pgk[17][0]);
	assign temp_pgk[18][1]=(pgk[18][0])|(pgk[18][1]&pgk[17][1]);

	assign temp_pgk[19][0]=(pgk[19][0])|(pgk[19][1]&pgk[18][0]);
	assign temp_pgk[19][1]=(pgk[19][0])|(pgk[19][1]&pgk[18][1]);

	assign temp_pgk[20][0]=(pgk[20][0])|(pgk[20][1]&pgk[19][0]);
	assign temp_pgk[20][1]=(pgk[20][0])|(pgk[20][1]&pgk[19][1]);

	assign temp_pgk[21][0]=(pgk[21][0])|(pgk[21][1]&pgk[20][0]);
	assign temp_pgk[21][1]=(pgk[21][0])|(pgk[21][1]&pgk[20][1]);

	assign temp_pgk[22][0]=(pgk[22][0])|(pgk[22][1]&pgk[21][0]);
	assign temp_pgk[22][1]=(pgk[22][0])|(pgk[22][1]&pgk[21][1]);

	assign temp_pgk[23][0]=(pgk[23][0])|(pgk[23][1]&pgk[22][0]);
	assign temp_pgk[23][1]=(pgk[23][0])|(pgk[23][1]&pgk[22][1]);

	assign temp_pgk[24][0]=(pgk[24][0])|(pgk[24][1]&pgk[23][0]);
	assign temp_pgk[24][1]=(pgk[24][0])|(pgk[24][1]&pgk[23][1]);

	assign temp_pgk[25][0]=(pgk[25][0])|(pgk[25][1]&pgk[24][0]);
	assign temp_pgk[25][1]=(pgk[25][0])|(pgk[25][1]&pgk[24][1]);

	assign temp_pgk[26][0]=(pgk[26][0])|(pgk[26][1]&pgk[25][0]);
	assign temp_pgk[26][1]=(pgk[26][0])|(pgk[26][1]&pgk[25][1]);

	assign temp_pgk[27][0]=(pgk[27][0])|(pgk[27][1]&pgk[26][0]);
	assign temp_pgk[27][1]=(pgk[27][0])|(pgk[27][1]&pgk[26][1]);

	assign temp_pgk[28][0]=(pgk[28][0])|(pgk[28][1]&pgk[27][0]);
	assign temp_pgk[28][1]=(pgk[28][0])|(pgk[28][1]&pgk[27][1]);

	assign temp_pgk[29][0]=(pgk[29][0])|(pgk[29][1]&pgk[28][0]);
	assign temp_pgk[29][1]=(pgk[29][0])|(pgk[29][1]&pgk[28][1]);

	assign temp_pgk[30][0]=(pgk[30][0])|(pgk[30][1]&pgk[29][0]);
	assign temp_pgk[30][1]=(pgk[30][0])|(pgk[30][1]&pgk[29][1]);

	assign temp_pgk[31][0]=(pgk[31][0])|(pgk[31][1]&pgk[30][0]);
	assign temp_pgk[31][1]=(pgk[31][0])|(pgk[31][1]&pgk[30][1]);

	assign temp_pgk[32][0]=(pgk[32][0])|(pgk[32][1]&pgk[31][0]);
	assign temp_pgk[32][1]=(pgk[32][0])|(pgk[32][1]&pgk[31][1]);

    D_flip_flop #(64) dff(clock,temp_pgk,buffer);
    
endmodule

module pgk_2_jump(
    input clock,
    input [32:1][1:0] pgk,
    output [32:1][1:0] buffer
    );

    wire [32:1][1:0] temp_pgk;

    assign temp_pgk[1][0]=pgk[1][0];
	assign temp_pgk[1][1]=pgk[1][1];

	assign temp_pgk[2][0]=pgk[2][0];
	assign temp_pgk[2][1]=pgk[2][1];

	assign temp_pgk[3][0]=(pgk[3][0])|(pgk[3][1]&pgk[1][0]);
	assign temp_pgk[3][1]=(pgk[3][0])|(pgk[3][1]&pgk[1][1]);

	assign temp_pgk[4][0]=(pgk[4][0])|(pgk[4][1]&pgk[2][0]);
	assign temp_pgk[4][1]=(pgk[4][0])|(pgk[4][1]&pgk[2][1]);

	assign temp_pgk[5][0]=(pgk[5][0])|(pgk[5][1]&pgk[3][0]);
	assign temp_pgk[5][1]=(pgk[5][0])|(pgk[5][1]&pgk[3][1]);

	assign temp_pgk[6][0]=(pgk[6][0])|(pgk[6][1]&pgk[4][0]);
	assign temp_pgk[6][1]=(pgk[6][0])|(pgk[6][1]&pgk[4][1]);

	assign temp_pgk[7][0]=(pgk[7][0])|(pgk[7][1]&pgk[5][0]);
	assign temp_pgk[7][1]=(pgk[7][0])|(pgk[7][1]&pgk[5][1]);

	assign temp_pgk[8][0]=(pgk[8][0])|(pgk[8][1]&pgk[6][0]);
	assign temp_pgk[8][1]=(pgk[8][0])|(pgk[8][1]&pgk[6][1]);

	assign temp_pgk[9][0]=(pgk[9][0])|(pgk[9][1]&pgk[7][0]);
	assign temp_pgk[9][1]=(pgk[9][0])|(pgk[9][1]&pgk[7][1]);

	assign temp_pgk[10][0]=(pgk[10][0])|(pgk[10][1]&pgk[8][0]);
	assign temp_pgk[10][1]=(pgk[10][0])|(pgk[10][1]&pgk[8][1]);

	assign temp_pgk[11][0]=(pgk[11][0])|(pgk[11][1]&pgk[9][0]);
	assign temp_pgk[11][1]=(pgk[11][0])|(pgk[11][1]&pgk[9][1]);

	assign temp_pgk[12][0]=(pgk[12][0])|(pgk[12][1]&pgk[10][0]);
	assign temp_pgk[12][1]=(pgk[12][0])|(pgk[12][1]&pgk[10][1]);

	assign temp_pgk[13][0]=(pgk[13][0])|(pgk[13][1]&pgk[11][0]);
	assign temp_pgk[13][1]=(pgk[13][0])|(pgk[13][1]&pgk[11][1]);

	assign temp_pgk[14][0]=(pgk[14][0])|(pgk[14][1]&pgk[12][0]);
	assign temp_pgk[14][1]=(pgk[14][0])|(pgk[14][1]&pgk[12][1]);

	assign temp_pgk[15][0]=(pgk[15][0])|(pgk[15][1]&pgk[13][0]);
	assign temp_pgk[15][1]=(pgk[15][0])|(pgk[15][1]&pgk[13][1]);

	assign temp_pgk[16][0]=(pgk[16][0])|(pgk[16][1]&pgk[14][0]);
	assign temp_pgk[16][1]=(pgk[16][0])|(pgk[16][1]&pgk[14][1]);

	assign temp_pgk[17][0]=(pgk[17][0])|(pgk[17][1]&pgk[15][0]);
	assign temp_pgk[17][1]=(pgk[17][0])|(pgk[17][1]&pgk[15][1]);

	assign temp_pgk[18][0]=(pgk[18][0])|(pgk[18][1]&pgk[16][0]);
	assign temp_pgk[18][1]=(pgk[18][0])|(pgk[18][1]&pgk[16][1]);

	assign temp_pgk[19][0]=(pgk[19][0])|(pgk[19][1]&pgk[17][0]);
	assign temp_pgk[19][1]=(pgk[19][0])|(pgk[19][1]&pgk[17][1]);

	assign temp_pgk[20][0]=(pgk[20][0])|(pgk[20][1]&pgk[18][0]);
	assign temp_pgk[20][1]=(pgk[20][0])|(pgk[20][1]&pgk[18][1]);

	assign temp_pgk[21][0]=(pgk[21][0])|(pgk[21][1]&pgk[19][0]);
	assign temp_pgk[21][1]=(pgk[21][0])|(pgk[21][1]&pgk[19][1]);

	assign temp_pgk[22][0]=(pgk[22][0])|(pgk[22][1]&pgk[20][0]);
	assign temp_pgk[22][1]=(pgk[22][0])|(pgk[22][1]&pgk[20][1]);

	assign temp_pgk[23][0]=(pgk[23][0])|(pgk[23][1]&pgk[21][0]);
	assign temp_pgk[23][1]=(pgk[23][0])|(pgk[23][1]&pgk[21][1]);

	assign temp_pgk[24][0]=(pgk[24][0])|(pgk[24][1]&pgk[22][0]);
	assign temp_pgk[24][1]=(pgk[24][0])|(pgk[24][1]&pgk[22][1]);

	assign temp_pgk[25][0]=(pgk[25][0])|(pgk[25][1]&pgk[23][0]);
	assign temp_pgk[25][1]=(pgk[25][0])|(pgk[25][1]&pgk[23][1]);

	assign temp_pgk[26][0]=(pgk[26][0])|(pgk[26][1]&pgk[24][0]);
	assign temp_pgk[26][1]=(pgk[26][0])|(pgk[26][1]&pgk[24][1]);

	assign temp_pgk[27][0]=(pgk[27][0])|(pgk[27][1]&pgk[25][0]);
	assign temp_pgk[27][1]=(pgk[27][0])|(pgk[27][1]&pgk[25][1]);

	assign temp_pgk[28][0]=(pgk[28][0])|(pgk[28][1]&pgk[26][0]);
	assign temp_pgk[28][1]=(pgk[28][0])|(pgk[28][1]&pgk[26][1]);

	assign temp_pgk[29][0]=(pgk[29][0])|(pgk[29][1]&pgk[27][0]);
	assign temp_pgk[29][1]=(pgk[29][0])|(pgk[29][1]&pgk[27][1]);

	assign temp_pgk[30][0]=(pgk[30][0])|(pgk[30][1]&pgk[28][0]);
	assign temp_pgk[30][1]=(pgk[30][0])|(pgk[30][1]&pgk[28][1]);

	assign temp_pgk[31][0]=(pgk[31][0])|(pgk[31][1]&pgk[29][0]);
	assign temp_pgk[31][1]=(pgk[31][0])|(pgk[31][1]&pgk[29][1]);

	assign temp_pgk[32][0]=(pgk[32][0])|(pgk[32][1]&pgk[30][0]);
	assign temp_pgk[32][1]=(pgk[32][0])|(pgk[32][1]&pgk[30][1]);

    D_flip_flop #(64) dff(clock,temp_pgk,buffer);
    
endmodule

module pgk_4_jump(
    input clock,
    input [32:1][1:0] pgk,
    output [32:1][1:0] buffer
    );

    wire [32:1][1:0] temp_pgk;

    assign temp_pgk[1][0]=pgk[1][0];
	assign temp_pgk[1][1]=pgk[1][1];

	assign temp_pgk[2][0]=pgk[2][0];
	assign temp_pgk[2][1]=pgk[2][1];

	assign temp_pgk[3][0]=pgk[3][0];
	assign temp_pgk[3][1]=pgk[3][1];

	assign temp_pgk[4][0]=pgk[4][0];
	assign temp_pgk[4][1]=pgk[4][1];

	assign temp_pgk[5][0]=(pgk[5][0])|(pgk[5][1]&pgk[1][0]);
	assign temp_pgk[5][1]=(pgk[5][0])|(pgk[5][1]&pgk[1][1]);

	assign temp_pgk[6][0]=(pgk[6][0])|(pgk[6][1]&pgk[2][0]);
	assign temp_pgk[6][1]=(pgk[6][0])|(pgk[6][1]&pgk[2][1]);

	assign temp_pgk[7][0]=(pgk[7][0])|(pgk[7][1]&pgk[3][0]);
	assign temp_pgk[7][1]=(pgk[7][0])|(pgk[7][1]&pgk[3][1]);

	assign temp_pgk[8][0]=(pgk[8][0])|(pgk[8][1]&pgk[4][0]);
	assign temp_pgk[8][1]=(pgk[8][0])|(pgk[8][1]&pgk[4][1]);

	assign temp_pgk[9][0]=(pgk[9][0])|(pgk[9][1]&pgk[5][0]);
	assign temp_pgk[9][1]=(pgk[9][0])|(pgk[9][1]&pgk[5][1]);

	assign temp_pgk[10][0]=(pgk[10][0])|(pgk[10][1]&pgk[6][0]);
	assign temp_pgk[10][1]=(pgk[10][0])|(pgk[10][1]&pgk[6][1]);

	assign temp_pgk[11][0]=(pgk[11][0])|(pgk[11][1]&pgk[7][0]);
	assign temp_pgk[11][1]=(pgk[11][0])|(pgk[11][1]&pgk[7][1]);

	assign temp_pgk[12][0]=(pgk[12][0])|(pgk[12][1]&pgk[8][0]);
	assign temp_pgk[12][1]=(pgk[12][0])|(pgk[12][1]&pgk[8][1]);

	assign temp_pgk[13][0]=(pgk[13][0])|(pgk[13][1]&pgk[9][0]);
	assign temp_pgk[13][1]=(pgk[13][0])|(pgk[13][1]&pgk[9][1]);

	assign temp_pgk[14][0]=(pgk[14][0])|(pgk[14][1]&pgk[10][0]);
	assign temp_pgk[14][1]=(pgk[14][0])|(pgk[14][1]&pgk[10][1]);

	assign temp_pgk[15][0]=(pgk[15][0])|(pgk[15][1]&pgk[11][0]);
	assign temp_pgk[15][1]=(pgk[15][0])|(pgk[15][1]&pgk[11][1]);

	assign temp_pgk[16][0]=(pgk[16][0])|(pgk[16][1]&pgk[12][0]);
	assign temp_pgk[16][1]=(pgk[16][0])|(pgk[16][1]&pgk[12][1]);

	assign temp_pgk[17][0]=(pgk[17][0])|(pgk[17][1]&pgk[13][0]);
	assign temp_pgk[17][1]=(pgk[17][0])|(pgk[17][1]&pgk[13][1]);

	assign temp_pgk[18][0]=(pgk[18][0])|(pgk[18][1]&pgk[14][0]);
	assign temp_pgk[18][1]=(pgk[18][0])|(pgk[18][1]&pgk[14][1]);

	assign temp_pgk[19][0]=(pgk[19][0])|(pgk[19][1]&pgk[15][0]);
	assign temp_pgk[19][1]=(pgk[19][0])|(pgk[19][1]&pgk[15][1]);

	assign temp_pgk[20][0]=(pgk[20][0])|(pgk[20][1]&pgk[16][0]);
	assign temp_pgk[20][1]=(pgk[20][0])|(pgk[20][1]&pgk[16][1]);

	assign temp_pgk[21][0]=(pgk[21][0])|(pgk[21][1]&pgk[17][0]);
	assign temp_pgk[21][1]=(pgk[21][0])|(pgk[21][1]&pgk[17][1]);

	assign temp_pgk[22][0]=(pgk[22][0])|(pgk[22][1]&pgk[18][0]);
	assign temp_pgk[22][1]=(pgk[22][0])|(pgk[22][1]&pgk[18][1]);

	assign temp_pgk[23][0]=(pgk[23][0])|(pgk[23][1]&pgk[19][0]);
	assign temp_pgk[23][1]=(pgk[23][0])|(pgk[23][1]&pgk[19][1]);

	assign temp_pgk[24][0]=(pgk[24][0])|(pgk[24][1]&pgk[20][0]);
	assign temp_pgk[24][1]=(pgk[24][0])|(pgk[24][1]&pgk[20][1]);

	assign temp_pgk[25][0]=(pgk[25][0])|(pgk[25][1]&pgk[21][0]);
	assign temp_pgk[25][1]=(pgk[25][0])|(pgk[25][1]&pgk[21][1]);

	assign temp_pgk[26][0]=(pgk[26][0])|(pgk[26][1]&pgk[22][0]);
	assign temp_pgk[26][1]=(pgk[26][0])|(pgk[26][1]&pgk[22][1]);

	assign temp_pgk[27][0]=(pgk[27][0])|(pgk[27][1]&pgk[23][0]);
	assign temp_pgk[27][1]=(pgk[27][0])|(pgk[27][1]&pgk[23][1]);

	assign temp_pgk[28][0]=(pgk[28][0])|(pgk[28][1]&pgk[24][0]);
	assign temp_pgk[28][1]=(pgk[28][0])|(pgk[28][1]&pgk[24][1]);

	assign temp_pgk[29][0]=(pgk[29][0])|(pgk[29][1]&pgk[25][0]);
	assign temp_pgk[29][1]=(pgk[29][0])|(pgk[29][1]&pgk[25][1]);

	assign temp_pgk[30][0]=(pgk[30][0])|(pgk[30][1]&pgk[26][0]);
	assign temp_pgk[30][1]=(pgk[30][0])|(pgk[30][1]&pgk[26][1]);

	assign temp_pgk[31][0]=(pgk[31][0])|(pgk[31][1]&pgk[27][0]);
	assign temp_pgk[31][1]=(pgk[31][0])|(pgk[31][1]&pgk[27][1]);

	assign temp_pgk[32][0]=(pgk[32][0])|(pgk[32][1]&pgk[28][0]);
	assign temp_pgk[32][1]=(pgk[32][0])|(pgk[32][1]&pgk[28][1]);

    D_flip_flop #(64) dff(clock,temp_pgk,buffer);
    
endmodule

module pgk_8_jump(
    input clock,
    input [32:1][1:0] pgk,
    output [32:1][1:0] buffer
    );

    wire [32:1][1:0] temp_pgk;

    assign temp_pgk[1][0]=pgk[1][0];
	assign temp_pgk[1][1]=pgk[1][1];

	assign temp_pgk[2][0]=pgk[2][0];
	assign temp_pgk[2][1]=pgk[2][1];

	assign temp_pgk[3][0]=pgk[3][0];
	assign temp_pgk[3][1]=pgk[3][1];

	assign temp_pgk[4][0]=pgk[4][0];
	assign temp_pgk[4][1]=pgk[4][1];

	assign temp_pgk[5][0]=pgk[5][0];
	assign temp_pgk[5][1]=pgk[5][1];

	assign temp_pgk[6][0]=pgk[6][0];
	assign temp_pgk[6][1]=pgk[6][1];

	assign temp_pgk[7][0]=pgk[7][0];
	assign temp_pgk[7][1]=pgk[7][1];

	assign temp_pgk[8][0]=pgk[8][0];
	assign temp_pgk[8][1]=pgk[8][1];

	assign temp_pgk[9][0]=(pgk[9][0])|(pgk[9][1]&pgk[1][0]);
	assign temp_pgk[9][1]=(pgk[9][0])|(pgk[9][1]&pgk[1][1]);

	assign temp_pgk[10][0]=(pgk[10][0])|(pgk[10][1]&pgk[2][0]);
	assign temp_pgk[10][1]=(pgk[10][0])|(pgk[10][1]&pgk[2][1]);

	assign temp_pgk[11][0]=(pgk[11][0])|(pgk[11][1]&pgk[3][0]);
	assign temp_pgk[11][1]=(pgk[11][0])|(pgk[11][1]&pgk[3][1]);

	assign temp_pgk[12][0]=(pgk[12][0])|(pgk[12][1]&pgk[4][0]);
	assign temp_pgk[12][1]=(pgk[12][0])|(pgk[12][1]&pgk[4][1]);

	assign temp_pgk[13][0]=(pgk[13][0])|(pgk[13][1]&pgk[5][0]);
	assign temp_pgk[13][1]=(pgk[13][0])|(pgk[13][1]&pgk[5][1]);

	assign temp_pgk[14][0]=(pgk[14][0])|(pgk[14][1]&pgk[6][0]);
	assign temp_pgk[14][1]=(pgk[14][0])|(pgk[14][1]&pgk[6][1]);

	assign temp_pgk[15][0]=(pgk[15][0])|(pgk[15][1]&pgk[7][0]);
	assign temp_pgk[15][1]=(pgk[15][0])|(pgk[15][1]&pgk[7][1]);

	assign temp_pgk[16][0]=(pgk[16][0])|(pgk[16][1]&pgk[8][0]);
	assign temp_pgk[16][1]=(pgk[16][0])|(pgk[16][1]&pgk[8][1]);

	assign temp_pgk[17][0]=(pgk[17][0])|(pgk[17][1]&pgk[9][0]);
	assign temp_pgk[17][1]=(pgk[17][0])|(pgk[17][1]&pgk[9][1]);

	assign temp_pgk[18][0]=(pgk[18][0])|(pgk[18][1]&pgk[10][0]);
	assign temp_pgk[18][1]=(pgk[18][0])|(pgk[18][1]&pgk[10][1]);

	assign temp_pgk[19][0]=(pgk[19][0])|(pgk[19][1]&pgk[11][0]);
	assign temp_pgk[19][1]=(pgk[19][0])|(pgk[19][1]&pgk[11][1]);

	assign temp_pgk[20][0]=(pgk[20][0])|(pgk[20][1]&pgk[12][0]);
	assign temp_pgk[20][1]=(pgk[20][0])|(pgk[20][1]&pgk[12][1]);

	assign temp_pgk[21][0]=(pgk[21][0])|(pgk[21][1]&pgk[13][0]);
	assign temp_pgk[21][1]=(pgk[21][0])|(pgk[21][1]&pgk[13][1]);

	assign temp_pgk[22][0]=(pgk[22][0])|(pgk[22][1]&pgk[14][0]);
	assign temp_pgk[22][1]=(pgk[22][0])|(pgk[22][1]&pgk[14][1]);

	assign temp_pgk[23][0]=(pgk[23][0])|(pgk[23][1]&pgk[15][0]);
	assign temp_pgk[23][1]=(pgk[23][0])|(pgk[23][1]&pgk[15][1]);

	assign temp_pgk[24][0]=(pgk[24][0])|(pgk[24][1]&pgk[16][0]);
	assign temp_pgk[24][1]=(pgk[24][0])|(pgk[24][1]&pgk[16][1]);

	assign temp_pgk[25][0]=(pgk[25][0])|(pgk[25][1]&pgk[17][0]);
	assign temp_pgk[25][1]=(pgk[25][0])|(pgk[25][1]&pgk[17][1]);

	assign temp_pgk[26][0]=(pgk[26][0])|(pgk[26][1]&pgk[18][0]);
	assign temp_pgk[26][1]=(pgk[26][0])|(pgk[26][1]&pgk[18][1]);

	assign temp_pgk[27][0]=(pgk[27][0])|(pgk[27][1]&pgk[19][0]);
	assign temp_pgk[27][1]=(pgk[27][0])|(pgk[27][1]&pgk[19][1]);

	assign temp_pgk[28][0]=(pgk[28][0])|(pgk[28][1]&pgk[20][0]);
	assign temp_pgk[28][1]=(pgk[28][0])|(pgk[28][1]&pgk[20][1]);

	assign temp_pgk[29][0]=(pgk[29][0])|(pgk[29][1]&pgk[21][0]);
	assign temp_pgk[29][1]=(pgk[29][0])|(pgk[29][1]&pgk[21][1]);

	assign temp_pgk[30][0]=(pgk[30][0])|(pgk[30][1]&pgk[22][0]);
	assign temp_pgk[30][1]=(pgk[30][0])|(pgk[30][1]&pgk[22][1]);

	assign temp_pgk[31][0]=(pgk[31][0])|(pgk[31][1]&pgk[23][0]);
	assign temp_pgk[31][1]=(pgk[31][0])|(pgk[31][1]&pgk[23][1]);

	assign temp_pgk[32][0]=(pgk[32][0])|(pgk[32][1]&pgk[24][0]);
	assign temp_pgk[32][1]=(pgk[32][0])|(pgk[32][1]&pgk[24][1]);

    D_flip_flop #(64) dff(clock,temp_pgk,buffer);
    
endmodule

module pgk_16_jump(
    input clock,
    input [32:1][1:0] pgk,
    output [32:1][1:0] buffer
    );

    wire [32:1][1:0] temp_pgk;

    assign temp_pgk[1][0]=pgk[1][0];
	assign temp_pgk[1][1]=pgk[1][1];

	assign temp_pgk[2][0]=pgk[2][0];
	assign temp_pgk[2][1]=pgk[2][1];

	assign temp_pgk[3][0]=pgk[3][0];
	assign temp_pgk[3][1]=pgk[3][1];

	assign temp_pgk[4][0]=pgk[4][0];
	assign temp_pgk[4][1]=pgk[4][1];

	assign temp_pgk[5][0]=pgk[5][0];
	assign temp_pgk[5][1]=pgk[5][1];

	assign temp_pgk[6][0]=pgk[6][0];
	assign temp_pgk[6][1]=pgk[6][1];

	assign temp_pgk[7][0]=pgk[7][0];
	assign temp_pgk[7][1]=pgk[7][1];

	assign temp_pgk[8][0]=pgk[8][0];
	assign temp_pgk[8][1]=pgk[8][1];

	assign temp_pgk[9][0]=pgk[9][0];
	assign temp_pgk[9][1]=pgk[9][1];

	assign temp_pgk[10][0]=pgk[10][0];
	assign temp_pgk[10][1]=pgk[10][1];

	assign temp_pgk[11][0]=pgk[11][0];
	assign temp_pgk[11][1]=pgk[11][1];

	assign temp_pgk[12][0]=pgk[12][0];
	assign temp_pgk[12][1]=pgk[12][1];

	assign temp_pgk[13][0]=pgk[13][0];
	assign temp_pgk[13][1]=pgk[13][1];

	assign temp_pgk[14][0]=pgk[14][0];
	assign temp_pgk[14][1]=pgk[14][1];

	assign temp_pgk[15][0]=pgk[15][0];
	assign temp_pgk[15][1]=pgk[15][1];

	assign temp_pgk[16][0]=pgk[16][0];
	assign temp_pgk[16][1]=pgk[16][1];

	assign temp_pgk[17][0]=(pgk[17][0])|(pgk[17][1]&pgk[1][0]);
	assign temp_pgk[17][1]=(pgk[17][0])|(pgk[17][1]&pgk[1][1]);

	assign temp_pgk[18][0]=(pgk[18][0])|(pgk[18][1]&pgk[2][0]);
	assign temp_pgk[18][1]=(pgk[18][0])|(pgk[18][1]&pgk[2][1]);

	assign temp_pgk[19][0]=(pgk[19][0])|(pgk[19][1]&pgk[3][0]);
	assign temp_pgk[19][1]=(pgk[19][0])|(pgk[19][1]&pgk[3][1]);

	assign temp_pgk[20][0]=(pgk[20][0])|(pgk[20][1]&pgk[4][0]);
	assign temp_pgk[20][1]=(pgk[20][0])|(pgk[20][1]&pgk[4][1]);

	assign temp_pgk[21][0]=(pgk[21][0])|(pgk[21][1]&pgk[5][0]);
	assign temp_pgk[21][1]=(pgk[21][0])|(pgk[21][1]&pgk[5][1]);

	assign temp_pgk[22][0]=(pgk[22][0])|(pgk[22][1]&pgk[6][0]);
	assign temp_pgk[22][1]=(pgk[22][0])|(pgk[22][1]&pgk[6][1]);

	assign temp_pgk[23][0]=(pgk[23][0])|(pgk[23][1]&pgk[7][0]);
	assign temp_pgk[23][1]=(pgk[23][0])|(pgk[23][1]&pgk[7][1]);

	assign temp_pgk[24][0]=(pgk[24][0])|(pgk[24][1]&pgk[8][0]);
	assign temp_pgk[24][1]=(pgk[24][0])|(pgk[24][1]&pgk[8][1]);

	assign temp_pgk[25][0]=(pgk[25][0])|(pgk[25][1]&pgk[9][0]);
	assign temp_pgk[25][1]=(pgk[25][0])|(pgk[25][1]&pgk[9][1]);

	assign temp_pgk[26][0]=(pgk[26][0])|(pgk[26][1]&pgk[10][0]);
	assign temp_pgk[26][1]=(pgk[26][0])|(pgk[26][1]&pgk[10][1]);

	assign temp_pgk[27][0]=(pgk[27][0])|(pgk[27][1]&pgk[11][0]);
	assign temp_pgk[27][1]=(pgk[27][0])|(pgk[27][1]&pgk[11][1]);

	assign temp_pgk[28][0]=(pgk[28][0])|(pgk[28][1]&pgk[12][0]);
	assign temp_pgk[28][1]=(pgk[28][0])|(pgk[28][1]&pgk[12][1]);

	assign temp_pgk[29][0]=(pgk[29][0])|(pgk[29][1]&pgk[13][0]);
	assign temp_pgk[29][1]=(pgk[29][0])|(pgk[29][1]&pgk[13][1]);

	assign temp_pgk[30][0]=(pgk[30][0])|(pgk[30][1]&pgk[14][0]);
	assign temp_pgk[30][1]=(pgk[30][0])|(pgk[30][1]&pgk[14][1]);

	assign temp_pgk[31][0]=(pgk[31][0])|(pgk[31][1]&pgk[15][0]);
	assign temp_pgk[31][1]=(pgk[31][0])|(pgk[31][1]&pgk[15][1]);

	assign temp_pgk[32][0]=(pgk[32][0])|(pgk[32][1]&pgk[16][0]);
	assign temp_pgk[32][1]=(pgk[32][0])|(pgk[32][1]&pgk[16][1]);

    D_flip_flop #(64) dff(clock,temp_pgk,buffer);
    
endmodule

module calculate_GK(
    input clock,
    input [32:1][1:0] pgk,
    output [32:1] out
    );

    wire [32:1] gk;

    assign gk[1]=pgk[1][1];
	assign gk[2]=pgk[2][1];
	assign gk[3]=pgk[3][1];
	assign gk[4]=pgk[4][1];
	assign gk[5]=pgk[5][1];
	assign gk[6]=pgk[6][1];
	assign gk[7]=pgk[7][1];
	assign gk[8]=pgk[8][1];
	assign gk[9]=pgk[9][1];
	assign gk[10]=pgk[10][1];
	assign gk[11]=pgk[11][1];
	assign gk[12]=pgk[12][1];
	assign gk[13]=pgk[13][1];
	assign gk[14]=pgk[14][1];
	assign gk[15]=pgk[15][1];
	assign gk[16]=pgk[16][1];
	assign gk[17]=pgk[17][1];
	assign gk[18]=pgk[18][1];
	assign gk[19]=pgk[19][1];
	assign gk[20]=pgk[20][1];
	assign gk[21]=pgk[21][1];
	assign gk[22]=pgk[22][1];
	assign gk[23]=pgk[23][1];
	assign gk[24]=pgk[24][1];
	assign gk[25]=pgk[25][1];
	assign gk[26]=pgk[26][1];
	assign gk[27]=pgk[27][1];
	assign gk[28]=pgk[28][1];
	assign gk[29]=pgk[29][1];
	assign gk[30]=pgk[30][1];
	assign gk[31]=pgk[31][1];
	assign gk[32]=pgk[32][1];

    D_flip_flop #(32) dff(clock,gk,out);

endmodule

module CLA_32bit(
    input clock,
    input [32:1] a,
    input [32:1] b,
    output [32:1] sum,
    output cout
    );

    wire [32:1][1:0] pgk;
    wire [32:1][1:0] temp_pgk;

    wire [32:1][1:0] pgk_stage_1;
    wire [32:1][1:0] pgk_stage_2;
    wire [32:1][1:0] pgk_stage_3;
    wire [32:1][1:0] pgk_stage_4;
    wire [32:1][1:0] pgk_stage_5;

    wire [32:1] gk;
    wire [32:1] buffer_a;
    wire [32:1] buffer_b;

    assign pgk[1][0]=(a[1]&b[1]);
    assign pgk[1][1]=(a[1]&b[1]);

    assign pgk[2][0]=(a[2]&b[2]);
	assign pgk[2][1]=(a[2]|b[2]);

	assign pgk[3][0]=(a[3]&b[3]);
	assign pgk[3][1]=(a[3]|b[3]);

	assign pgk[4][0]=(a[4]&b[4]);
	assign pgk[4][1]=(a[4]|b[4]);

	assign pgk[5][0]=(a[5]&b[5]);
	assign pgk[5][1]=(a[5]|b[5]);

	assign pgk[6][0]=(a[6]&b[6]);
	assign pgk[6][1]=(a[6]|b[6]);

	assign pgk[7][0]=(a[7]&b[7]);
	assign pgk[7][1]=(a[7]|b[7]);

	assign pgk[8][0]=(a[8]&b[8]);
	assign pgk[8][1]=(a[8]|b[8]);

	assign pgk[9][0]=(a[9]&b[9]);
	assign pgk[9][1]=(a[9]|b[9]);

	assign pgk[10][0]=(a[10]&b[10]);
	assign pgk[10][1]=(a[10]|b[10]);

	assign pgk[11][0]=(a[11]&b[11]);
	assign pgk[11][1]=(a[11]|b[11]);

	assign pgk[12][0]=(a[12]&b[12]);
	assign pgk[12][1]=(a[12]|b[12]);

	assign pgk[13][0]=(a[13]&b[13]);
	assign pgk[13][1]=(a[13]|b[13]);

	assign pgk[14][0]=(a[14]&b[14]);
	assign pgk[14][1]=(a[14]|b[14]);

	assign pgk[15][0]=(a[15]&b[15]);
	assign pgk[15][1]=(a[15]|b[15]);

	assign pgk[16][0]=(a[16]&b[16]);
	assign pgk[16][1]=(a[16]|b[16]);

	assign pgk[17][0]=(a[17]&b[17]);
	assign pgk[17][1]=(a[17]|b[17]);

	assign pgk[18][0]=(a[18]&b[18]);
	assign pgk[18][1]=(a[18]|b[18]);

	assign pgk[19][0]=(a[19]&b[19]);
	assign pgk[19][1]=(a[19]|b[19]);

	assign pgk[20][0]=(a[20]&b[20]);
	assign pgk[20][1]=(a[20]|b[20]);

	assign pgk[21][0]=(a[21]&b[21]);
	assign pgk[21][1]=(a[21]|b[21]);

	assign pgk[22][0]=(a[22]&b[22]);
	assign pgk[22][1]=(a[22]|b[22]);

	assign pgk[23][0]=(a[23]&b[23]);
	assign pgk[23][1]=(a[23]|b[23]);

	assign pgk[24][0]=(a[24]&b[24]);
	assign pgk[24][1]=(a[24]|b[24]);

	assign pgk[25][0]=(a[25]&b[25]);
	assign pgk[25][1]=(a[25]|b[25]);

	assign pgk[26][0]=(a[26]&b[26]);
	assign pgk[26][1]=(a[26]|b[26]);

	assign pgk[27][0]=(a[27]&b[27]);
	assign pgk[27][1]=(a[27]|b[27]);

	assign pgk[28][0]=(a[28]&b[28]);
	assign pgk[28][1]=(a[28]|b[28]);

	assign pgk[29][0]=(a[29]&b[29]);
	assign pgk[29][1]=(a[29]|b[29]);

	assign pgk[30][0]=(a[30]&b[30]);
	assign pgk[30][1]=(a[30]|b[30]);

	assign pgk[31][0]=(a[31]&b[31]);
	assign pgk[31][1]=(a[31]|b[31]);

	assign pgk[32][0]=(a[32]&b[32]);
	assign pgk[32][1]=(a[32]|b[32]);

    D_flip_flop #64 dff_1(clock,pgk,temp_pgk);

    pgk_1_jump jump_1(clock,pgk,pgk_stage_1);
    pgk_2_jump jump_2(clock,pgk_stage_1,pgk_stage_2);
    pgk_4_jump jump_4(clock,pgk_stage_2,pgk_stage_3);
    pgk_8_jump jump_8(clock,pgk_stage_3,pgk_stage_4);
    pgk_16_jump jump_16(clock,pgk_stage_4,pgk_stage_5);

    calculate_GK GK_final(clock,pgk_stage_5,gk);

    clock_delay #(4) delay_1(clock,a,buffer_a);
    clock_delay #(4) delay_2(clock,b,buffer_b);

    assign sum[1]=buffer_a[1]^buffer_b[1];
	assign sum[2]=buffer_a[2]^buffer_b[2]^gk[1];
	assign sum[3]=buffer_a[3]^buffer_b[3]^gk[2];
	assign sum[4]=buffer_a[4]^buffer_b[4]^gk[3];
	assign sum[5]=buffer_a[5]^buffer_b[5]^gk[4];
	assign sum[6]=buffer_a[6]^buffer_b[6]^gk[5];
	assign sum[7]=buffer_a[7]^buffer_b[7]^gk[6];
	assign sum[8]=buffer_a[8]^buffer_b[8]^gk[7];
	assign sum[9]=buffer_a[9]^buffer_b[9]^gk[8];
	assign sum[10]=buffer_a[10]^buffer_b[10]^gk[9];
	assign sum[11]=buffer_a[11]^buffer_b[11]^gk[10];
	assign sum[12]=buffer_a[12]^buffer_b[12]^gk[11];
	assign sum[13]=buffer_a[13]^buffer_b[13]^gk[12];
	assign sum[14]=buffer_a[14]^buffer_b[14]^gk[13];
	assign sum[15]=buffer_a[15]^buffer_b[15]^gk[14];
	assign sum[16]=buffer_a[16]^buffer_b[16]^gk[15];
	assign sum[17]=buffer_a[17]^buffer_b[17]^gk[16];
	assign sum[18]=buffer_a[18]^buffer_b[18]^gk[17];
	assign sum[19]=buffer_a[19]^buffer_b[19]^gk[18];
	assign sum[20]=buffer_a[20]^buffer_b[20]^gk[19];
	assign sum[21]=buffer_a[21]^buffer_b[21]^gk[20];
	assign sum[22]=buffer_a[22]^buffer_b[22]^gk[21];
	assign sum[23]=buffer_a[23]^buffer_b[23]^gk[22];
	assign sum[24]=buffer_a[24]^buffer_b[24]^gk[23];
	assign sum[25]=buffer_a[25]^buffer_b[25]^gk[24];
	assign sum[26]=buffer_a[26]^buffer_b[26]^gk[25];
	assign sum[27]=buffer_a[27]^buffer_b[27]^gk[26];
	assign sum[28]=buffer_a[28]^buffer_b[28]^gk[27];
	assign sum[29]=buffer_a[29]^buffer_b[29]^gk[28];
	assign sum[30]=buffer_a[30]^buffer_b[30]^gk[29];
	assign sum[31]=buffer_a[31]^buffer_b[31]^gk[30];
	assign sum[32]=buffer_a[32]^buffer_b[32]^gk[31];

	assign cout=gk[32];

endmodule
