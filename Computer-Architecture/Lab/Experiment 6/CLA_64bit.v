`include "Clock_Delay.v"

module pgk_1_jump(
    input clock,
    input [64:1][1:0] pgk,
    output [64:1][1:0] buffer
    );

    wire [64:1][1:0] temp_pgk;

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

	assign temp_pgk[33][0]=(pgk[33][0])|(pgk[33][1]&pgk[32][0]);
	assign temp_pgk[33][1]=(pgk[33][0])|(pgk[33][1]&pgk[32][1]);

	assign temp_pgk[34][0]=(pgk[34][0])|(pgk[34][1]&pgk[33][0]);
	assign temp_pgk[34][1]=(pgk[34][0])|(pgk[34][1]&pgk[33][1]);

	assign temp_pgk[35][0]=(pgk[35][0])|(pgk[35][1]&pgk[34][0]);
	assign temp_pgk[35][1]=(pgk[35][0])|(pgk[35][1]&pgk[34][1]);

	assign temp_pgk[36][0]=(pgk[36][0])|(pgk[36][1]&pgk[35][0]);
	assign temp_pgk[36][1]=(pgk[36][0])|(pgk[36][1]&pgk[35][1]);

	assign temp_pgk[37][0]=(pgk[37][0])|(pgk[37][1]&pgk[36][0]);
	assign temp_pgk[37][1]=(pgk[37][0])|(pgk[37][1]&pgk[36][1]);

	assign temp_pgk[38][0]=(pgk[38][0])|(pgk[38][1]&pgk[37][0]);
	assign temp_pgk[38][1]=(pgk[38][0])|(pgk[38][1]&pgk[37][1]);

	assign temp_pgk[39][0]=(pgk[39][0])|(pgk[39][1]&pgk[38][0]);
	assign temp_pgk[39][1]=(pgk[39][0])|(pgk[39][1]&pgk[38][1]);

	assign temp_pgk[40][0]=(pgk[40][0])|(pgk[40][1]&pgk[39][0]);
	assign temp_pgk[40][1]=(pgk[40][0])|(pgk[40][1]&pgk[39][1]);

	assign temp_pgk[41][0]=(pgk[41][0])|(pgk[41][1]&pgk[40][0]);
	assign temp_pgk[41][1]=(pgk[41][0])|(pgk[41][1]&pgk[40][1]);

	assign temp_pgk[42][0]=(pgk[42][0])|(pgk[42][1]&pgk[41][0]);
	assign temp_pgk[42][1]=(pgk[42][0])|(pgk[42][1]&pgk[41][1]);

	assign temp_pgk[43][0]=(pgk[43][0])|(pgk[43][1]&pgk[42][0]);
	assign temp_pgk[43][1]=(pgk[43][0])|(pgk[43][1]&pgk[42][1]);

	assign temp_pgk[44][0]=(pgk[44][0])|(pgk[44][1]&pgk[43][0]);
	assign temp_pgk[44][1]=(pgk[44][0])|(pgk[44][1]&pgk[43][1]);

	assign temp_pgk[45][0]=(pgk[45][0])|(pgk[45][1]&pgk[44][0]);
	assign temp_pgk[45][1]=(pgk[45][0])|(pgk[45][1]&pgk[44][1]);

	assign temp_pgk[46][0]=(pgk[46][0])|(pgk[46][1]&pgk[45][0]);
	assign temp_pgk[46][1]=(pgk[46][0])|(pgk[46][1]&pgk[45][1]);

	assign temp_pgk[47][0]=(pgk[47][0])|(pgk[47][1]&pgk[46][0]);
	assign temp_pgk[47][1]=(pgk[47][0])|(pgk[47][1]&pgk[46][1]);

	assign temp_pgk[48][0]=(pgk[48][0])|(pgk[48][1]&pgk[47][0]);
	assign temp_pgk[48][1]=(pgk[48][0])|(pgk[48][1]&pgk[47][1]);

	assign temp_pgk[49][0]=(pgk[49][0])|(pgk[49][1]&pgk[48][0]);
	assign temp_pgk[49][1]=(pgk[49][0])|(pgk[49][1]&pgk[48][1]);

	assign temp_pgk[50][0]=(pgk[50][0])|(pgk[50][1]&pgk[49][0]);
	assign temp_pgk[50][1]=(pgk[50][0])|(pgk[50][1]&pgk[49][1]);

	assign temp_pgk[51][0]=(pgk[51][0])|(pgk[51][1]&pgk[50][0]);
	assign temp_pgk[51][1]=(pgk[51][0])|(pgk[51][1]&pgk[50][1]);

	assign temp_pgk[52][0]=(pgk[52][0])|(pgk[52][1]&pgk[51][0]);
	assign temp_pgk[52][1]=(pgk[52][0])|(pgk[52][1]&pgk[51][1]);

	assign temp_pgk[53][0]=(pgk[53][0])|(pgk[53][1]&pgk[52][0]);
	assign temp_pgk[53][1]=(pgk[53][0])|(pgk[53][1]&pgk[52][1]);

	assign temp_pgk[54][0]=(pgk[54][0])|(pgk[54][1]&pgk[53][0]);
	assign temp_pgk[54][1]=(pgk[54][0])|(pgk[54][1]&pgk[53][1]);

	assign temp_pgk[55][0]=(pgk[55][0])|(pgk[55][1]&pgk[54][0]);
	assign temp_pgk[55][1]=(pgk[55][0])|(pgk[55][1]&pgk[54][1]);

	assign temp_pgk[56][0]=(pgk[56][0])|(pgk[56][1]&pgk[55][0]);
	assign temp_pgk[56][1]=(pgk[56][0])|(pgk[56][1]&pgk[55][1]);

	assign temp_pgk[57][0]=(pgk[57][0])|(pgk[57][1]&pgk[56][0]);
	assign temp_pgk[57][1]=(pgk[57][0])|(pgk[57][1]&pgk[56][1]);

	assign temp_pgk[58][0]=(pgk[58][0])|(pgk[58][1]&pgk[57][0]);
	assign temp_pgk[58][1]=(pgk[58][0])|(pgk[58][1]&pgk[57][1]);

	assign temp_pgk[59][0]=(pgk[59][0])|(pgk[59][1]&pgk[58][0]);
	assign temp_pgk[59][1]=(pgk[59][0])|(pgk[59][1]&pgk[58][1]);

	assign temp_pgk[60][0]=(pgk[60][0])|(pgk[60][1]&pgk[59][0]);
	assign temp_pgk[60][1]=(pgk[60][0])|(pgk[60][1]&pgk[59][1]);

	assign temp_pgk[61][0]=(pgk[61][0])|(pgk[61][1]&pgk[60][0]);
	assign temp_pgk[61][1]=(pgk[61][0])|(pgk[61][1]&pgk[60][1]);

	assign temp_pgk[62][0]=(pgk[62][0])|(pgk[62][1]&pgk[61][0]);
	assign temp_pgk[62][1]=(pgk[62][0])|(pgk[62][1]&pgk[61][1]);

	assign temp_pgk[63][0]=(pgk[63][0])|(pgk[63][1]&pgk[62][0]);
	assign temp_pgk[63][1]=(pgk[63][0])|(pgk[63][1]&pgk[62][1]);

	assign temp_pgk[64][0]=(pgk[64][0])|(pgk[64][1]&pgk[63][0]);
	assign temp_pgk[64][1]=(pgk[64][0])|(pgk[64][1]&pgk[63][1]);

	D_flip_flop #(128) dff(clock,temp_pgk,buffer);
    
endmodule

module pgk_2_jump(
    input clock,
    input [64:1][1:0] pgk,
    output [64:1][1:0] buffer
    );

    wire [64:1][1:0] temp_pgk;

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

	assign temp_pgk[33][0]=(pgk[33][0])|(pgk[33][1]&pgk[31][0]);
	assign temp_pgk[33][1]=(pgk[33][0])|(pgk[33][1]&pgk[31][1]);

	assign temp_pgk[34][0]=(pgk[34][0])|(pgk[34][1]&pgk[32][0]);
	assign temp_pgk[34][1]=(pgk[34][0])|(pgk[34][1]&pgk[32][1]);

	assign temp_pgk[35][0]=(pgk[35][0])|(pgk[35][1]&pgk[33][0]);
	assign temp_pgk[35][1]=(pgk[35][0])|(pgk[35][1]&pgk[33][1]);

	assign temp_pgk[36][0]=(pgk[36][0])|(pgk[36][1]&pgk[34][0]);
	assign temp_pgk[36][1]=(pgk[36][0])|(pgk[36][1]&pgk[34][1]);

	assign temp_pgk[37][0]=(pgk[37][0])|(pgk[37][1]&pgk[35][0]);
	assign temp_pgk[37][1]=(pgk[37][0])|(pgk[37][1]&pgk[35][1]);

	assign temp_pgk[38][0]=(pgk[38][0])|(pgk[38][1]&pgk[36][0]);
	assign temp_pgk[38][1]=(pgk[38][0])|(pgk[38][1]&pgk[36][1]);

	assign temp_pgk[39][0]=(pgk[39][0])|(pgk[39][1]&pgk[37][0]);
	assign temp_pgk[39][1]=(pgk[39][0])|(pgk[39][1]&pgk[37][1]);

	assign temp_pgk[40][0]=(pgk[40][0])|(pgk[40][1]&pgk[38][0]);
	assign temp_pgk[40][1]=(pgk[40][0])|(pgk[40][1]&pgk[38][1]);

	assign temp_pgk[41][0]=(pgk[41][0])|(pgk[41][1]&pgk[39][0]);
	assign temp_pgk[41][1]=(pgk[41][0])|(pgk[41][1]&pgk[39][1]);

	assign temp_pgk[42][0]=(pgk[42][0])|(pgk[42][1]&pgk[40][0]);
	assign temp_pgk[42][1]=(pgk[42][0])|(pgk[42][1]&pgk[40][1]);

	assign temp_pgk[43][0]=(pgk[43][0])|(pgk[43][1]&pgk[41][0]);
	assign temp_pgk[43][1]=(pgk[43][0])|(pgk[43][1]&pgk[41][1]);

	assign temp_pgk[44][0]=(pgk[44][0])|(pgk[44][1]&pgk[42][0]);
	assign temp_pgk[44][1]=(pgk[44][0])|(pgk[44][1]&pgk[42][1]);

	assign temp_pgk[45][0]=(pgk[45][0])|(pgk[45][1]&pgk[43][0]);
	assign temp_pgk[45][1]=(pgk[45][0])|(pgk[45][1]&pgk[43][1]);

	assign temp_pgk[46][0]=(pgk[46][0])|(pgk[46][1]&pgk[44][0]);
	assign temp_pgk[46][1]=(pgk[46][0])|(pgk[46][1]&pgk[44][1]);

	assign temp_pgk[47][0]=(pgk[47][0])|(pgk[47][1]&pgk[45][0]);
	assign temp_pgk[47][1]=(pgk[47][0])|(pgk[47][1]&pgk[45][1]);

	assign temp_pgk[48][0]=(pgk[48][0])|(pgk[48][1]&pgk[46][0]);
	assign temp_pgk[48][1]=(pgk[48][0])|(pgk[48][1]&pgk[46][1]);

	assign temp_pgk[49][0]=(pgk[49][0])|(pgk[49][1]&pgk[47][0]);
	assign temp_pgk[49][1]=(pgk[49][0])|(pgk[49][1]&pgk[47][1]);

	assign temp_pgk[50][0]=(pgk[50][0])|(pgk[50][1]&pgk[48][0]);
	assign temp_pgk[50][1]=(pgk[50][0])|(pgk[50][1]&pgk[48][1]);

	assign temp_pgk[51][0]=(pgk[51][0])|(pgk[51][1]&pgk[49][0]);
	assign temp_pgk[51][1]=(pgk[51][0])|(pgk[51][1]&pgk[49][1]);

	assign temp_pgk[52][0]=(pgk[52][0])|(pgk[52][1]&pgk[50][0]);
	assign temp_pgk[52][1]=(pgk[52][0])|(pgk[52][1]&pgk[50][1]);

	assign temp_pgk[53][0]=(pgk[53][0])|(pgk[53][1]&pgk[51][0]);
	assign temp_pgk[53][1]=(pgk[53][0])|(pgk[53][1]&pgk[51][1]);

	assign temp_pgk[54][0]=(pgk[54][0])|(pgk[54][1]&pgk[52][0]);
	assign temp_pgk[54][1]=(pgk[54][0])|(pgk[54][1]&pgk[52][1]);

	assign temp_pgk[55][0]=(pgk[55][0])|(pgk[55][1]&pgk[53][0]);
	assign temp_pgk[55][1]=(pgk[55][0])|(pgk[55][1]&pgk[53][1]);

	assign temp_pgk[56][0]=(pgk[56][0])|(pgk[56][1]&pgk[54][0]);
	assign temp_pgk[56][1]=(pgk[56][0])|(pgk[56][1]&pgk[54][1]);

	assign temp_pgk[57][0]=(pgk[57][0])|(pgk[57][1]&pgk[55][0]);
	assign temp_pgk[57][1]=(pgk[57][0])|(pgk[57][1]&pgk[55][1]);

	assign temp_pgk[58][0]=(pgk[58][0])|(pgk[58][1]&pgk[56][0]);
	assign temp_pgk[58][1]=(pgk[58][0])|(pgk[58][1]&pgk[56][1]);

	assign temp_pgk[59][0]=(pgk[59][0])|(pgk[59][1]&pgk[57][0]);
	assign temp_pgk[59][1]=(pgk[59][0])|(pgk[59][1]&pgk[57][1]);

	assign temp_pgk[60][0]=(pgk[60][0])|(pgk[60][1]&pgk[58][0]);
	assign temp_pgk[60][1]=(pgk[60][0])|(pgk[60][1]&pgk[58][1]);

	assign temp_pgk[61][0]=(pgk[61][0])|(pgk[61][1]&pgk[59][0]);
	assign temp_pgk[61][1]=(pgk[61][0])|(pgk[61][1]&pgk[59][1]);

	assign temp_pgk[62][0]=(pgk[62][0])|(pgk[62][1]&pgk[60][0]);
	assign temp_pgk[62][1]=(pgk[62][0])|(pgk[62][1]&pgk[60][1]);

	assign temp_pgk[63][0]=(pgk[63][0])|(pgk[63][1]&pgk[61][0]);
	assign temp_pgk[63][1]=(pgk[63][0])|(pgk[63][1]&pgk[61][1]);

	assign temp_pgk[64][0]=(pgk[64][0])|(pgk[64][1]&pgk[62][0]);
	assign temp_pgk[64][1]=(pgk[64][0])|(pgk[64][1]&pgk[62][1]);

	D_flip_flop #(128) dff(clock,temp_pgk,buffer);
    
endmodule

module pgk_4_jump(
    input clock,
    input [64:1][1:0] pgk,
    output [64:1][1:0] buffer
    );

    wire [64:1][1:0] temp_pgk;

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

	assign temp_pgk[33][0]=(pgk[33][0])|(pgk[33][1]&pgk[29][0]);
	assign temp_pgk[33][1]=(pgk[33][0])|(pgk[33][1]&pgk[29][1]);

	assign temp_pgk[34][0]=(pgk[34][0])|(pgk[34][1]&pgk[30][0]);
	assign temp_pgk[34][1]=(pgk[34][0])|(pgk[34][1]&pgk[30][1]);

	assign temp_pgk[35][0]=(pgk[35][0])|(pgk[35][1]&pgk[31][0]);
	assign temp_pgk[35][1]=(pgk[35][0])|(pgk[35][1]&pgk[31][1]);

	assign temp_pgk[36][0]=(pgk[36][0])|(pgk[36][1]&pgk[32][0]);
	assign temp_pgk[36][1]=(pgk[36][0])|(pgk[36][1]&pgk[32][1]);

	assign temp_pgk[37][0]=(pgk[37][0])|(pgk[37][1]&pgk[33][0]);
	assign temp_pgk[37][1]=(pgk[37][0])|(pgk[37][1]&pgk[33][1]);

	assign temp_pgk[38][0]=(pgk[38][0])|(pgk[38][1]&pgk[34][0]);
	assign temp_pgk[38][1]=(pgk[38][0])|(pgk[38][1]&pgk[34][1]);

	assign temp_pgk[39][0]=(pgk[39][0])|(pgk[39][1]&pgk[35][0]);
	assign temp_pgk[39][1]=(pgk[39][0])|(pgk[39][1]&pgk[35][1]);

	assign temp_pgk[40][0]=(pgk[40][0])|(pgk[40][1]&pgk[36][0]);
	assign temp_pgk[40][1]=(pgk[40][0])|(pgk[40][1]&pgk[36][1]);

	assign temp_pgk[41][0]=(pgk[41][0])|(pgk[41][1]&pgk[37][0]);
	assign temp_pgk[41][1]=(pgk[41][0])|(pgk[41][1]&pgk[37][1]);

	assign temp_pgk[42][0]=(pgk[42][0])|(pgk[42][1]&pgk[38][0]);
	assign temp_pgk[42][1]=(pgk[42][0])|(pgk[42][1]&pgk[38][1]);

	assign temp_pgk[43][0]=(pgk[43][0])|(pgk[43][1]&pgk[39][0]);
	assign temp_pgk[43][1]=(pgk[43][0])|(pgk[43][1]&pgk[39][1]);

	assign temp_pgk[44][0]=(pgk[44][0])|(pgk[44][1]&pgk[40][0]);
	assign temp_pgk[44][1]=(pgk[44][0])|(pgk[44][1]&pgk[40][1]);

	assign temp_pgk[45][0]=(pgk[45][0])|(pgk[45][1]&pgk[41][0]);
	assign temp_pgk[45][1]=(pgk[45][0])|(pgk[45][1]&pgk[41][1]);

	assign temp_pgk[46][0]=(pgk[46][0])|(pgk[46][1]&pgk[42][0]);
	assign temp_pgk[46][1]=(pgk[46][0])|(pgk[46][1]&pgk[42][1]);

	assign temp_pgk[47][0]=(pgk[47][0])|(pgk[47][1]&pgk[43][0]);
	assign temp_pgk[47][1]=(pgk[47][0])|(pgk[47][1]&pgk[43][1]);

	assign temp_pgk[48][0]=(pgk[48][0])|(pgk[48][1]&pgk[44][0]);
	assign temp_pgk[48][1]=(pgk[48][0])|(pgk[48][1]&pgk[44][1]);

	assign temp_pgk[49][0]=(pgk[49][0])|(pgk[49][1]&pgk[45][0]);
	assign temp_pgk[49][1]=(pgk[49][0])|(pgk[49][1]&pgk[45][1]);

	assign temp_pgk[50][0]=(pgk[50][0])|(pgk[50][1]&pgk[46][0]);
	assign temp_pgk[50][1]=(pgk[50][0])|(pgk[50][1]&pgk[46][1]);

	assign temp_pgk[51][0]=(pgk[51][0])|(pgk[51][1]&pgk[47][0]);
	assign temp_pgk[51][1]=(pgk[51][0])|(pgk[51][1]&pgk[47][1]);

	assign temp_pgk[52][0]=(pgk[52][0])|(pgk[52][1]&pgk[48][0]);
	assign temp_pgk[52][1]=(pgk[52][0])|(pgk[52][1]&pgk[48][1]);

	assign temp_pgk[53][0]=(pgk[53][0])|(pgk[53][1]&pgk[49][0]);
	assign temp_pgk[53][1]=(pgk[53][0])|(pgk[53][1]&pgk[49][1]);

	assign temp_pgk[54][0]=(pgk[54][0])|(pgk[54][1]&pgk[50][0]);
	assign temp_pgk[54][1]=(pgk[54][0])|(pgk[54][1]&pgk[50][1]);

	assign temp_pgk[55][0]=(pgk[55][0])|(pgk[55][1]&pgk[51][0]);
	assign temp_pgk[55][1]=(pgk[55][0])|(pgk[55][1]&pgk[51][1]);

	assign temp_pgk[56][0]=(pgk[56][0])|(pgk[56][1]&pgk[52][0]);
	assign temp_pgk[56][1]=(pgk[56][0])|(pgk[56][1]&pgk[52][1]);

	assign temp_pgk[57][0]=(pgk[57][0])|(pgk[57][1]&pgk[53][0]);
	assign temp_pgk[57][1]=(pgk[57][0])|(pgk[57][1]&pgk[53][1]);

	assign temp_pgk[58][0]=(pgk[58][0])|(pgk[58][1]&pgk[54][0]);
	assign temp_pgk[58][1]=(pgk[58][0])|(pgk[58][1]&pgk[54][1]);

	assign temp_pgk[59][0]=(pgk[59][0])|(pgk[59][1]&pgk[55][0]);
	assign temp_pgk[59][1]=(pgk[59][0])|(pgk[59][1]&pgk[55][1]);

	assign temp_pgk[60][0]=(pgk[60][0])|(pgk[60][1]&pgk[56][0]);
	assign temp_pgk[60][1]=(pgk[60][0])|(pgk[60][1]&pgk[56][1]);

	assign temp_pgk[61][0]=(pgk[61][0])|(pgk[61][1]&pgk[57][0]);
	assign temp_pgk[61][1]=(pgk[61][0])|(pgk[61][1]&pgk[57][1]);

	assign temp_pgk[62][0]=(pgk[62][0])|(pgk[62][1]&pgk[58][0]);
	assign temp_pgk[62][1]=(pgk[62][0])|(pgk[62][1]&pgk[58][1]);

	assign temp_pgk[63][0]=(pgk[63][0])|(pgk[63][1]&pgk[59][0]);
	assign temp_pgk[63][1]=(pgk[63][0])|(pgk[63][1]&pgk[59][1]);

	assign temp_pgk[64][0]=(pgk[64][0])|(pgk[64][1]&pgk[60][0]);
	assign temp_pgk[64][1]=(pgk[64][0])|(pgk[64][1]&pgk[60][1]);

	D_flip_flop #(128) dff(clock,temp_pgk,buffer);
    
endmodule

module pgk_8_jump(
    input clock,
    input [64:1][1:0] pgk,
    output [64:1][1:0] buffer
    );

    wire [64:1][1:0] temp_pgk;

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

	assign temp_pgk[33][0]=(pgk[33][0])|(pgk[33][1]&pgk[25][0]);
	assign temp_pgk[33][1]=(pgk[33][0])|(pgk[33][1]&pgk[25][1]);

	assign temp_pgk[34][0]=(pgk[34][0])|(pgk[34][1]&pgk[26][0]);
	assign temp_pgk[34][1]=(pgk[34][0])|(pgk[34][1]&pgk[26][1]);

	assign temp_pgk[35][0]=(pgk[35][0])|(pgk[35][1]&pgk[27][0]);
	assign temp_pgk[35][1]=(pgk[35][0])|(pgk[35][1]&pgk[27][1]);

	assign temp_pgk[36][0]=(pgk[36][0])|(pgk[36][1]&pgk[28][0]);
	assign temp_pgk[36][1]=(pgk[36][0])|(pgk[36][1]&pgk[28][1]);

	assign temp_pgk[37][0]=(pgk[37][0])|(pgk[37][1]&pgk[29][0]);
	assign temp_pgk[37][1]=(pgk[37][0])|(pgk[37][1]&pgk[29][1]);

	assign temp_pgk[38][0]=(pgk[38][0])|(pgk[38][1]&pgk[30][0]);
	assign temp_pgk[38][1]=(pgk[38][0])|(pgk[38][1]&pgk[30][1]);

	assign temp_pgk[39][0]=(pgk[39][0])|(pgk[39][1]&pgk[31][0]);
	assign temp_pgk[39][1]=(pgk[39][0])|(pgk[39][1]&pgk[31][1]);

	assign temp_pgk[40][0]=(pgk[40][0])|(pgk[40][1]&pgk[32][0]);
	assign temp_pgk[40][1]=(pgk[40][0])|(pgk[40][1]&pgk[32][1]);

	assign temp_pgk[41][0]=(pgk[41][0])|(pgk[41][1]&pgk[33][0]);
	assign temp_pgk[41][1]=(pgk[41][0])|(pgk[41][1]&pgk[33][1]);

	assign temp_pgk[42][0]=(pgk[42][0])|(pgk[42][1]&pgk[34][0]);
	assign temp_pgk[42][1]=(pgk[42][0])|(pgk[42][1]&pgk[34][1]);

	assign temp_pgk[43][0]=(pgk[43][0])|(pgk[43][1]&pgk[35][0]);
	assign temp_pgk[43][1]=(pgk[43][0])|(pgk[43][1]&pgk[35][1]);

	assign temp_pgk[44][0]=(pgk[44][0])|(pgk[44][1]&pgk[36][0]);
	assign temp_pgk[44][1]=(pgk[44][0])|(pgk[44][1]&pgk[36][1]);

	assign temp_pgk[45][0]=(pgk[45][0])|(pgk[45][1]&pgk[37][0]);
	assign temp_pgk[45][1]=(pgk[45][0])|(pgk[45][1]&pgk[37][1]);

	assign temp_pgk[46][0]=(pgk[46][0])|(pgk[46][1]&pgk[38][0]);
	assign temp_pgk[46][1]=(pgk[46][0])|(pgk[46][1]&pgk[38][1]);

	assign temp_pgk[47][0]=(pgk[47][0])|(pgk[47][1]&pgk[39][0]);
	assign temp_pgk[47][1]=(pgk[47][0])|(pgk[47][1]&pgk[39][1]);

	assign temp_pgk[48][0]=(pgk[48][0])|(pgk[48][1]&pgk[40][0]);
	assign temp_pgk[48][1]=(pgk[48][0])|(pgk[48][1]&pgk[40][1]);

	assign temp_pgk[49][0]=(pgk[49][0])|(pgk[49][1]&pgk[41][0]);
	assign temp_pgk[49][1]=(pgk[49][0])|(pgk[49][1]&pgk[41][1]);

	assign temp_pgk[50][0]=(pgk[50][0])|(pgk[50][1]&pgk[42][0]);
	assign temp_pgk[50][1]=(pgk[50][0])|(pgk[50][1]&pgk[42][1]);

	assign temp_pgk[51][0]=(pgk[51][0])|(pgk[51][1]&pgk[43][0]);
	assign temp_pgk[51][1]=(pgk[51][0])|(pgk[51][1]&pgk[43][1]);

	assign temp_pgk[52][0]=(pgk[52][0])|(pgk[52][1]&pgk[44][0]);
	assign temp_pgk[52][1]=(pgk[52][0])|(pgk[52][1]&pgk[44][1]);

	assign temp_pgk[53][0]=(pgk[53][0])|(pgk[53][1]&pgk[45][0]);
	assign temp_pgk[53][1]=(pgk[53][0])|(pgk[53][1]&pgk[45][1]);

	assign temp_pgk[54][0]=(pgk[54][0])|(pgk[54][1]&pgk[46][0]);
	assign temp_pgk[54][1]=(pgk[54][0])|(pgk[54][1]&pgk[46][1]);

	assign temp_pgk[55][0]=(pgk[55][0])|(pgk[55][1]&pgk[47][0]);
	assign temp_pgk[55][1]=(pgk[55][0])|(pgk[55][1]&pgk[47][1]);

	assign temp_pgk[56][0]=(pgk[56][0])|(pgk[56][1]&pgk[48][0]);
	assign temp_pgk[56][1]=(pgk[56][0])|(pgk[56][1]&pgk[48][1]);

	assign temp_pgk[57][0]=(pgk[57][0])|(pgk[57][1]&pgk[49][0]);
	assign temp_pgk[57][1]=(pgk[57][0])|(pgk[57][1]&pgk[49][1]);

	assign temp_pgk[58][0]=(pgk[58][0])|(pgk[58][1]&pgk[50][0]);
	assign temp_pgk[58][1]=(pgk[58][0])|(pgk[58][1]&pgk[50][1]);

	assign temp_pgk[59][0]=(pgk[59][0])|(pgk[59][1]&pgk[51][0]);
	assign temp_pgk[59][1]=(pgk[59][0])|(pgk[59][1]&pgk[51][1]);

	assign temp_pgk[60][0]=(pgk[60][0])|(pgk[60][1]&pgk[52][0]);
	assign temp_pgk[60][1]=(pgk[60][0])|(pgk[60][1]&pgk[52][1]);

	assign temp_pgk[61][0]=(pgk[61][0])|(pgk[61][1]&pgk[53][0]);
	assign temp_pgk[61][1]=(pgk[61][0])|(pgk[61][1]&pgk[53][1]);

	assign temp_pgk[62][0]=(pgk[62][0])|(pgk[62][1]&pgk[54][0]);
	assign temp_pgk[62][1]=(pgk[62][0])|(pgk[62][1]&pgk[54][1]);

	assign temp_pgk[63][0]=(pgk[63][0])|(pgk[63][1]&pgk[55][0]);
	assign temp_pgk[63][1]=(pgk[63][0])|(pgk[63][1]&pgk[55][1]);

	assign temp_pgk[64][0]=(pgk[64][0])|(pgk[64][1]&pgk[56][0]);
	assign temp_pgk[64][1]=(pgk[64][0])|(pgk[64][1]&pgk[56][1]);

	D_flip_flop #(128) dff(clock,temp_pgk,buffer);
    
endmodule

module pgk_16_jump(
    input clock,
    input [64:1][1:0] pgk,
    output [64:1][1:0] buffer
    );

    wire [64:1][1:0] temp_pgk;

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

	assign temp_pgk[33][0]=(pgk[33][0])|(pgk[33][1]&pgk[17][0]);
	assign temp_pgk[33][1]=(pgk[33][0])|(pgk[33][1]&pgk[17][1]);

	assign temp_pgk[34][0]=(pgk[34][0])|(pgk[34][1]&pgk[18][0]);
	assign temp_pgk[34][1]=(pgk[34][0])|(pgk[34][1]&pgk[18][1]);

	assign temp_pgk[35][0]=(pgk[35][0])|(pgk[35][1]&pgk[19][0]);
	assign temp_pgk[35][1]=(pgk[35][0])|(pgk[35][1]&pgk[19][1]);

	assign temp_pgk[36][0]=(pgk[36][0])|(pgk[36][1]&pgk[20][0]);
	assign temp_pgk[36][1]=(pgk[36][0])|(pgk[36][1]&pgk[20][1]);

	assign temp_pgk[37][0]=(pgk[37][0])|(pgk[37][1]&pgk[21][0]);
	assign temp_pgk[37][1]=(pgk[37][0])|(pgk[37][1]&pgk[21][1]);

	assign temp_pgk[38][0]=(pgk[38][0])|(pgk[38][1]&pgk[22][0]);
	assign temp_pgk[38][1]=(pgk[38][0])|(pgk[38][1]&pgk[22][1]);

	assign temp_pgk[39][0]=(pgk[39][0])|(pgk[39][1]&pgk[23][0]);
	assign temp_pgk[39][1]=(pgk[39][0])|(pgk[39][1]&pgk[23][1]);

	assign temp_pgk[40][0]=(pgk[40][0])|(pgk[40][1]&pgk[24][0]);
	assign temp_pgk[40][1]=(pgk[40][0])|(pgk[40][1]&pgk[24][1]);

	assign temp_pgk[41][0]=(pgk[41][0])|(pgk[41][1]&pgk[25][0]);
	assign temp_pgk[41][1]=(pgk[41][0])|(pgk[41][1]&pgk[25][1]);

	assign temp_pgk[42][0]=(pgk[42][0])|(pgk[42][1]&pgk[26][0]);
	assign temp_pgk[42][1]=(pgk[42][0])|(pgk[42][1]&pgk[26][1]);

	assign temp_pgk[43][0]=(pgk[43][0])|(pgk[43][1]&pgk[27][0]);
	assign temp_pgk[43][1]=(pgk[43][0])|(pgk[43][1]&pgk[27][1]);

	assign temp_pgk[44][0]=(pgk[44][0])|(pgk[44][1]&pgk[28][0]);
	assign temp_pgk[44][1]=(pgk[44][0])|(pgk[44][1]&pgk[28][1]);

	assign temp_pgk[45][0]=(pgk[45][0])|(pgk[45][1]&pgk[29][0]);
	assign temp_pgk[45][1]=(pgk[45][0])|(pgk[45][1]&pgk[29][1]);

	assign temp_pgk[46][0]=(pgk[46][0])|(pgk[46][1]&pgk[30][0]);
	assign temp_pgk[46][1]=(pgk[46][0])|(pgk[46][1]&pgk[30][1]);

	assign temp_pgk[47][0]=(pgk[47][0])|(pgk[47][1]&pgk[31][0]);
	assign temp_pgk[47][1]=(pgk[47][0])|(pgk[47][1]&pgk[31][1]);

	assign temp_pgk[48][0]=(pgk[48][0])|(pgk[48][1]&pgk[32][0]);
	assign temp_pgk[48][1]=(pgk[48][0])|(pgk[48][1]&pgk[32][1]);

	assign temp_pgk[49][0]=(pgk[49][0])|(pgk[49][1]&pgk[33][0]);
	assign temp_pgk[49][1]=(pgk[49][0])|(pgk[49][1]&pgk[33][1]);

	assign temp_pgk[50][0]=(pgk[50][0])|(pgk[50][1]&pgk[34][0]);
	assign temp_pgk[50][1]=(pgk[50][0])|(pgk[50][1]&pgk[34][1]);

	assign temp_pgk[51][0]=(pgk[51][0])|(pgk[51][1]&pgk[35][0]);
	assign temp_pgk[51][1]=(pgk[51][0])|(pgk[51][1]&pgk[35][1]);

	assign temp_pgk[52][0]=(pgk[52][0])|(pgk[52][1]&pgk[36][0]);
	assign temp_pgk[52][1]=(pgk[52][0])|(pgk[52][1]&pgk[36][1]);

	assign temp_pgk[53][0]=(pgk[53][0])|(pgk[53][1]&pgk[37][0]);
	assign temp_pgk[53][1]=(pgk[53][0])|(pgk[53][1]&pgk[37][1]);

	assign temp_pgk[54][0]=(pgk[54][0])|(pgk[54][1]&pgk[38][0]);
	assign temp_pgk[54][1]=(pgk[54][0])|(pgk[54][1]&pgk[38][1]);

	assign temp_pgk[55][0]=(pgk[55][0])|(pgk[55][1]&pgk[39][0]);
	assign temp_pgk[55][1]=(pgk[55][0])|(pgk[55][1]&pgk[39][1]);

	assign temp_pgk[56][0]=(pgk[56][0])|(pgk[56][1]&pgk[40][0]);
	assign temp_pgk[56][1]=(pgk[56][0])|(pgk[56][1]&pgk[40][1]);

	assign temp_pgk[57][0]=(pgk[57][0])|(pgk[57][1]&pgk[41][0]);
	assign temp_pgk[57][1]=(pgk[57][0])|(pgk[57][1]&pgk[41][1]);

	assign temp_pgk[58][0]=(pgk[58][0])|(pgk[58][1]&pgk[42][0]);
	assign temp_pgk[58][1]=(pgk[58][0])|(pgk[58][1]&pgk[42][1]);

	assign temp_pgk[59][0]=(pgk[59][0])|(pgk[59][1]&pgk[43][0]);
	assign temp_pgk[59][1]=(pgk[59][0])|(pgk[59][1]&pgk[43][1]);

	assign temp_pgk[60][0]=(pgk[60][0])|(pgk[60][1]&pgk[44][0]);
	assign temp_pgk[60][1]=(pgk[60][0])|(pgk[60][1]&pgk[44][1]);

	assign temp_pgk[61][0]=(pgk[61][0])|(pgk[61][1]&pgk[45][0]);
	assign temp_pgk[61][1]=(pgk[61][0])|(pgk[61][1]&pgk[45][1]);

	assign temp_pgk[62][0]=(pgk[62][0])|(pgk[62][1]&pgk[46][0]);
	assign temp_pgk[62][1]=(pgk[62][0])|(pgk[62][1]&pgk[46][1]);

	assign temp_pgk[63][0]=(pgk[63][0])|(pgk[63][1]&pgk[47][0]);
	assign temp_pgk[63][1]=(pgk[63][0])|(pgk[63][1]&pgk[47][1]);

	assign temp_pgk[64][0]=(pgk[64][0])|(pgk[64][1]&pgk[48][0]);
	assign temp_pgk[64][1]=(pgk[64][0])|(pgk[64][1]&pgk[48][1]);

	D_flip_flop #(128) dff(clock,temp_pgk,buffer);
    
endmodule

module pgk_32_jump(
    input clock,
    input [64:1][1:0] pgk,
    output [64:1][1:0] buffer
    );

    wire [64:1][1:0] temp_pgk;

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

	assign temp_pgk[17][0]=pgk[17][0];
	assign temp_pgk[17][1]=pgk[17][1];

	assign temp_pgk[18][0]=pgk[18][0];
	assign temp_pgk[18][1]=pgk[18][1];

	assign temp_pgk[19][0]=pgk[19][0];
	assign temp_pgk[19][1]=pgk[19][1];

	assign temp_pgk[20][0]=pgk[20][0];
	assign temp_pgk[20][1]=pgk[20][1];

	assign temp_pgk[21][0]=pgk[21][0];
	assign temp_pgk[21][1]=pgk[21][1];

	assign temp_pgk[22][0]=pgk[22][0];
	assign temp_pgk[22][1]=pgk[22][1];

	assign temp_pgk[23][0]=pgk[23][0];
	assign temp_pgk[23][1]=pgk[23][1];

	assign temp_pgk[24][0]=pgk[24][0];
	assign temp_pgk[24][1]=pgk[24][1];

	assign temp_pgk[25][0]=pgk[25][0];
	assign temp_pgk[25][1]=pgk[25][1];

	assign temp_pgk[26][0]=pgk[26][0];
	assign temp_pgk[26][1]=pgk[26][1];

	assign temp_pgk[27][0]=pgk[27][0];
	assign temp_pgk[27][1]=pgk[27][1];

	assign temp_pgk[28][0]=pgk[28][0];
	assign temp_pgk[28][1]=pgk[28][1];

	assign temp_pgk[29][0]=pgk[29][0];
	assign temp_pgk[29][1]=pgk[29][1];

	assign temp_pgk[30][0]=pgk[30][0];
	assign temp_pgk[30][1]=pgk[30][1];

	assign temp_pgk[31][0]=pgk[31][0];
	assign temp_pgk[31][1]=pgk[31][1];

	assign temp_pgk[32][0]=pgk[32][0];
	assign temp_pgk[32][1]=pgk[32][1];

	assign temp_pgk[33][0]=(pgk[33][0])|(pgk[33][1]&pgk[1][0]);
	assign temp_pgk[33][1]=(pgk[33][0])|(pgk[33][1]&pgk[1][1]);

	assign temp_pgk[34][0]=(pgk[34][0])|(pgk[34][1]&pgk[2][0]);
	assign temp_pgk[34][1]=(pgk[34][0])|(pgk[34][1]&pgk[2][1]);

	assign temp_pgk[35][0]=(pgk[35][0])|(pgk[35][1]&pgk[3][0]);
	assign temp_pgk[35][1]=(pgk[35][0])|(pgk[35][1]&pgk[3][1]);

	assign temp_pgk[36][0]=(pgk[36][0])|(pgk[36][1]&pgk[4][0]);
	assign temp_pgk[36][1]=(pgk[36][0])|(pgk[36][1]&pgk[4][1]);

	assign temp_pgk[37][0]=(pgk[37][0])|(pgk[37][1]&pgk[5][0]);
	assign temp_pgk[37][1]=(pgk[37][0])|(pgk[37][1]&pgk[5][1]);

	assign temp_pgk[38][0]=(pgk[38][0])|(pgk[38][1]&pgk[6][0]);
	assign temp_pgk[38][1]=(pgk[38][0])|(pgk[38][1]&pgk[6][1]);

	assign temp_pgk[39][0]=(pgk[39][0])|(pgk[39][1]&pgk[7][0]);
	assign temp_pgk[39][1]=(pgk[39][0])|(pgk[39][1]&pgk[7][1]);

	assign temp_pgk[40][0]=(pgk[40][0])|(pgk[40][1]&pgk[8][0]);
	assign temp_pgk[40][1]=(pgk[40][0])|(pgk[40][1]&pgk[8][1]);

	assign temp_pgk[41][0]=(pgk[41][0])|(pgk[41][1]&pgk[9][0]);
	assign temp_pgk[41][1]=(pgk[41][0])|(pgk[41][1]&pgk[9][1]);

	assign temp_pgk[42][0]=(pgk[42][0])|(pgk[42][1]&pgk[10][0]);
	assign temp_pgk[42][1]=(pgk[42][0])|(pgk[42][1]&pgk[10][1]);

	assign temp_pgk[43][0]=(pgk[43][0])|(pgk[43][1]&pgk[11][0]);
	assign temp_pgk[43][1]=(pgk[43][0])|(pgk[43][1]&pgk[11][1]);

	assign temp_pgk[44][0]=(pgk[44][0])|(pgk[44][1]&pgk[12][0]);
	assign temp_pgk[44][1]=(pgk[44][0])|(pgk[44][1]&pgk[12][1]);

	assign temp_pgk[45][0]=(pgk[45][0])|(pgk[45][1]&pgk[13][0]);
	assign temp_pgk[45][1]=(pgk[45][0])|(pgk[45][1]&pgk[13][1]);

	assign temp_pgk[46][0]=(pgk[46][0])|(pgk[46][1]&pgk[14][0]);
	assign temp_pgk[46][1]=(pgk[46][0])|(pgk[46][1]&pgk[14][1]);

	assign temp_pgk[47][0]=(pgk[47][0])|(pgk[47][1]&pgk[15][0]);
	assign temp_pgk[47][1]=(pgk[47][0])|(pgk[47][1]&pgk[15][1]);

	assign temp_pgk[48][0]=(pgk[48][0])|(pgk[48][1]&pgk[16][0]);
	assign temp_pgk[48][1]=(pgk[48][0])|(pgk[48][1]&pgk[16][1]);

	assign temp_pgk[49][0]=(pgk[49][0])|(pgk[49][1]&pgk[17][0]);
	assign temp_pgk[49][1]=(pgk[49][0])|(pgk[49][1]&pgk[17][1]);

	assign temp_pgk[50][0]=(pgk[50][0])|(pgk[50][1]&pgk[18][0]);
	assign temp_pgk[50][1]=(pgk[50][0])|(pgk[50][1]&pgk[18][1]);

	assign temp_pgk[51][0]=(pgk[51][0])|(pgk[51][1]&pgk[19][0]);
	assign temp_pgk[51][1]=(pgk[51][0])|(pgk[51][1]&pgk[19][1]);

	assign temp_pgk[52][0]=(pgk[52][0])|(pgk[52][1]&pgk[20][0]);
	assign temp_pgk[52][1]=(pgk[52][0])|(pgk[52][1]&pgk[20][1]);

	assign temp_pgk[53][0]=(pgk[53][0])|(pgk[53][1]&pgk[21][0]);
	assign temp_pgk[53][1]=(pgk[53][0])|(pgk[53][1]&pgk[21][1]);

	assign temp_pgk[54][0]=(pgk[54][0])|(pgk[54][1]&pgk[22][0]);
	assign temp_pgk[54][1]=(pgk[54][0])|(pgk[54][1]&pgk[22][1]);

	assign temp_pgk[55][0]=(pgk[55][0])|(pgk[55][1]&pgk[23][0]);
	assign temp_pgk[55][1]=(pgk[55][0])|(pgk[55][1]&pgk[23][1]);

	assign temp_pgk[56][0]=(pgk[56][0])|(pgk[56][1]&pgk[24][0]);
	assign temp_pgk[56][1]=(pgk[56][0])|(pgk[56][1]&pgk[24][1]);

	assign temp_pgk[57][0]=(pgk[57][0])|(pgk[57][1]&pgk[25][0]);
	assign temp_pgk[57][1]=(pgk[57][0])|(pgk[57][1]&pgk[25][1]);

	assign temp_pgk[58][0]=(pgk[58][0])|(pgk[58][1]&pgk[26][0]);
	assign temp_pgk[58][1]=(pgk[58][0])|(pgk[58][1]&pgk[26][1]);

	assign temp_pgk[59][0]=(pgk[59][0])|(pgk[59][1]&pgk[27][0]);
	assign temp_pgk[59][1]=(pgk[59][0])|(pgk[59][1]&pgk[27][1]);

	assign temp_pgk[60][0]=(pgk[60][0])|(pgk[60][1]&pgk[28][0]);
	assign temp_pgk[60][1]=(pgk[60][0])|(pgk[60][1]&pgk[28][1]);

	assign temp_pgk[61][0]=(pgk[61][0])|(pgk[61][1]&pgk[29][0]);
	assign temp_pgk[61][1]=(pgk[61][0])|(pgk[61][1]&pgk[29][1]);

	assign temp_pgk[62][0]=(pgk[62][0])|(pgk[62][1]&pgk[30][0]);
	assign temp_pgk[62][1]=(pgk[62][0])|(pgk[62][1]&pgk[30][1]);

	assign temp_pgk[63][0]=(pgk[63][0])|(pgk[63][1]&pgk[31][0]);
	assign temp_pgk[63][1]=(pgk[63][0])|(pgk[63][1]&pgk[31][1]);

	assign temp_pgk[64][0]=(pgk[64][0])|(pgk[64][1]&pgk[32][0]);
	assign temp_pgk[64][1]=(pgk[64][0])|(pgk[64][1]&pgk[32][1]);

	D_flip_flop #128 dff(clock,temp_pgk,buffer);
    
endmodule

module calculate_GK(
    input clock,
    input [64:1][1:0] pgk,
    output [64:1] out
    );

    wire [64:1] gk;

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
	assign gk[33]=pgk[33][1];
	assign gk[34]=pgk[34][1];
	assign gk[35]=pgk[35][1];
	assign gk[36]=pgk[36][1];
	assign gk[37]=pgk[37][1];
	assign gk[38]=pgk[38][1];
	assign gk[39]=pgk[39][1];
	assign gk[40]=pgk[40][1];
	assign gk[41]=pgk[41][1];
	assign gk[42]=pgk[42][1];
	assign gk[43]=pgk[43][1];
	assign gk[44]=pgk[44][1];
	assign gk[45]=pgk[45][1];
	assign gk[46]=pgk[46][1];
	assign gk[47]=pgk[47][1];
	assign gk[48]=pgk[48][1];
	assign gk[49]=pgk[49][1];
	assign gk[50]=pgk[50][1];
	assign gk[51]=pgk[51][1];
	assign gk[52]=pgk[52][1];
	assign gk[53]=pgk[53][1];
	assign gk[54]=pgk[54][1];
	assign gk[55]=pgk[55][1];
	assign gk[56]=pgk[56][1];
	assign gk[57]=pgk[57][1];
	assign gk[58]=pgk[58][1];
	assign gk[59]=pgk[59][1];
	assign gk[60]=pgk[60][1];
	assign gk[61]=pgk[61][1];
	assign gk[62]=pgk[62][1];
	assign gk[63]=pgk[63][1];
	assign gk[64]=pgk[64][1];

    D_flip_flop #(64) dff(clock,gk,out);

endmodule

module CLA_64bit(
    input clock,
    input [64:1] a,
    input [64:1] b,
    output [64:1] sum,
    output cout
    );

    wire [64:1][1:0] pgk;
    wire [64:1][1:0] temp_pgk;

    wire [64:1][1:0] pgk_stage_1;
    wire [64:1][1:0] pgk_stage_2;
    wire [64:1][1:0] pgk_stage_3;
    wire [64:1][1:0] pgk_stage_4;
    wire [64:1][1:0] pgk_stage_5;
	wire [64:1][1:0] pgk_stage_6;

    wire [64:1] gk;
    wire [64:1] buffer_a;
    wire [64:1] buffer_b;

    assign pgk[1][0]=(a[1]&b[1]);
	assign pgk[1][1]=(a[1]|b[1]);

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

	assign pgk[33][0]=(a[33]&b[33]);
	assign pgk[33][1]=(a[33]|b[33]);

	assign pgk[34][0]=(a[34]&b[34]);
	assign pgk[34][1]=(a[34]|b[34]);

	assign pgk[35][0]=(a[35]&b[35]);
	assign pgk[35][1]=(a[35]|b[35]);

	assign pgk[36][0]=(a[36]&b[36]);
	assign pgk[36][1]=(a[36]|b[36]);

	assign pgk[37][0]=(a[37]&b[37]);
	assign pgk[37][1]=(a[37]|b[37]);

	assign pgk[38][0]=(a[38]&b[38]);
	assign pgk[38][1]=(a[38]|b[38]);

	assign pgk[39][0]=(a[39]&b[39]);
	assign pgk[39][1]=(a[39]|b[39]);

	assign pgk[40][0]=(a[40]&b[40]);
	assign pgk[40][1]=(a[40]|b[40]);

	assign pgk[41][0]=(a[41]&b[41]);
	assign pgk[41][1]=(a[41]|b[41]);

	assign pgk[42][0]=(a[42]&b[42]);
	assign pgk[42][1]=(a[42]|b[42]);

	assign pgk[43][0]=(a[43]&b[43]);
	assign pgk[43][1]=(a[43]|b[43]);

	assign pgk[44][0]=(a[44]&b[44]);
	assign pgk[44][1]=(a[44]|b[44]);

	assign pgk[45][0]=(a[45]&b[45]);
	assign pgk[45][1]=(a[45]|b[45]);

	assign pgk[46][0]=(a[46]&b[46]);
	assign pgk[46][1]=(a[46]|b[46]);

	assign pgk[47][0]=(a[47]&b[47]);
	assign pgk[47][1]=(a[47]|b[47]);

	assign pgk[48][0]=(a[48]&b[48]);
	assign pgk[48][1]=(a[48]|b[48]);

	assign pgk[49][0]=(a[49]&b[49]);
	assign pgk[49][1]=(a[49]|b[49]);

	assign pgk[50][0]=(a[50]&b[50]);
	assign pgk[50][1]=(a[50]|b[50]);

	assign pgk[51][0]=(a[51]&b[51]);
	assign pgk[51][1]=(a[51]|b[51]);

	assign pgk[52][0]=(a[52]&b[52]);
	assign pgk[52][1]=(a[52]|b[52]);

	assign pgk[53][0]=(a[53]&b[53]);
	assign pgk[53][1]=(a[53]|b[53]);

	assign pgk[54][0]=(a[54]&b[54]);
	assign pgk[54][1]=(a[54]|b[54]);

	assign pgk[55][0]=(a[55]&b[55]);
	assign pgk[55][1]=(a[55]|b[55]);

	assign pgk[56][0]=(a[56]&b[56]);
	assign pgk[56][1]=(a[56]|b[56]);

	assign pgk[57][0]=(a[57]&b[57]);
	assign pgk[57][1]=(a[57]|b[57]);

	assign pgk[58][0]=(a[58]&b[58]);
	assign pgk[58][1]=(a[58]|b[58]);

	assign pgk[59][0]=(a[59]&b[59]);
	assign pgk[59][1]=(a[59]|b[59]);

	assign pgk[60][0]=(a[60]&b[60]);
	assign pgk[60][1]=(a[60]|b[60]);

	assign pgk[61][0]=(a[61]&b[61]);
	assign pgk[61][1]=(a[61]|b[61]);

	assign pgk[62][0]=(a[62]&b[62]);
	assign pgk[62][1]=(a[62]|b[62]);

	assign pgk[63][0]=(a[63]&b[63]);
	assign pgk[63][1]=(a[63]|b[63]);

	assign pgk[64][0]=(a[64]&b[64]);
	assign pgk[64][1]=(a[64]|b[64]);

    D_flip_flop #128 dff_1(clock,pgk,temp_pgk);

    pgk_1_jump jump_1(clock,pgk,pgk_stage_1);
    pgk_2_jump jump_2(clock,pgk_stage_1,pgk_stage_2);
    pgk_4_jump jump_4(clock,pgk_stage_2,pgk_stage_3);
    pgk_8_jump jump_8(clock,pgk_stage_3,pgk_stage_4);
    pgk_16_jump jump_16(clock,pgk_stage_4,pgk_stage_5);
	pgk_32_jump jump_32(clock,pgk_stage_5,pgk_stage_6);

    calculate_GK GK_final(clock,pgk_stage_6,gk);

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
	assign sum[33]=buffer_a[33]^buffer_b[33]^gk[32];
	assign sum[34]=buffer_a[34]^buffer_b[34]^gk[33];
	assign sum[35]=buffer_a[35]^buffer_b[35]^gk[34];
	assign sum[36]=buffer_a[36]^buffer_b[36]^gk[35];
	assign sum[37]=buffer_a[37]^buffer_b[37]^gk[36];
	assign sum[38]=buffer_a[38]^buffer_b[38]^gk[37];
	assign sum[39]=buffer_a[39]^buffer_b[39]^gk[38];
	assign sum[40]=buffer_a[40]^buffer_b[40]^gk[39];
	assign sum[41]=buffer_a[41]^buffer_b[41]^gk[40];
	assign sum[42]=buffer_a[42]^buffer_b[42]^gk[41];
	assign sum[43]=buffer_a[43]^buffer_b[43]^gk[42];
	assign sum[44]=buffer_a[44]^buffer_b[44]^gk[43];
	assign sum[45]=buffer_a[45]^buffer_b[45]^gk[44];
	assign sum[46]=buffer_a[46]^buffer_b[46]^gk[45];
	assign sum[47]=buffer_a[47]^buffer_b[47]^gk[46];
	assign sum[48]=buffer_a[48]^buffer_b[48]^gk[47];
	assign sum[49]=buffer_a[49]^buffer_b[49]^gk[48];
	assign sum[50]=buffer_a[50]^buffer_b[50]^gk[49];
	assign sum[51]=buffer_a[51]^buffer_b[51]^gk[50];
	assign sum[52]=buffer_a[52]^buffer_b[52]^gk[51];
	assign sum[53]=buffer_a[53]^buffer_b[53]^gk[52];
	assign sum[54]=buffer_a[54]^buffer_b[54]^gk[53];
	assign sum[55]=buffer_a[55]^buffer_b[55]^gk[54];
	assign sum[56]=buffer_a[56]^buffer_b[56]^gk[55];
	assign sum[57]=buffer_a[57]^buffer_b[57]^gk[56];
	assign sum[58]=buffer_a[58]^buffer_b[58]^gk[57];
	assign sum[59]=buffer_a[59]^buffer_b[59]^gk[58];
	assign sum[60]=buffer_a[60]^buffer_b[60]^gk[59];
	assign sum[61]=buffer_a[61]^buffer_b[61]^gk[60];
	assign sum[62]=buffer_a[62]^buffer_b[62]^gk[61];
	assign sum[63]=buffer_a[63]^buffer_b[63]^gk[62];
	assign sum[64]=buffer_a[64]^buffer_b[64]^gk[63];

	assign cout=gk[64];

endmodule