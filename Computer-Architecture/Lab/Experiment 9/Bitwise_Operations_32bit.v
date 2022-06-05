`include "Adder_32bit.v"

module and_gate_32_bit(
    input [31:0] in1,
    input [31:0] in2,
    output [31:0] out
);

    assign out[0] = in1[0] & in2[0];
	assign out[1] = in1[1] & in2[1];
	assign out[2] = in1[2] & in2[2];
	assign out[3] = in1[3] & in2[3];
	assign out[4] = in1[4] & in2[4];
	assign out[5] = in1[5] & in2[5];
	assign out[6] = in1[6] & in2[6];
	assign out[7] = in1[7] & in2[7];
	assign out[8] = in1[8] & in2[8];
	assign out[9] = in1[9] & in2[9];
	assign out[10] = in1[10] & in2[10];
	assign out[11] = in1[11] & in2[11];
	assign out[12] = in1[12] & in2[12];
	assign out[13] = in1[13] & in2[13];
	assign out[14] = in1[14] & in2[14];
	assign out[15] = in1[15] & in2[15];
	assign out[16] = in1[16] & in2[16];
	assign out[17] = in1[17] & in2[17];
	assign out[18] = in1[18] & in2[18];
	assign out[19] = in1[19] & in2[19];
	assign out[20] = in1[20] & in2[20];
	assign out[21] = in1[21] & in2[21];
	assign out[22] = in1[22] & in2[22];
	assign out[23] = in1[23] & in2[23];
	assign out[24] = in1[24] & in2[24];
	assign out[25] = in1[25] & in2[25];
	assign out[26] = in1[26] & in2[26];
	assign out[27] = in1[27] & in2[27];
	assign out[28] = in1[28] & in2[28];
	assign out[29] = in1[29] & in2[29];
	assign out[30] = in1[30] & in2[30];
	assign out[31] = in1[31] & in2[31];

endmodule

module xor_gate_32_bit(
    input [31:0] in1,
    input [31:0] in2,
    output [31:0] out
);

    assign out[0] = in1[0] ^ in2[0];
	assign out[1] = in1[1] ^ in2[1];
	assign out[2] = in1[2] ^ in2[2];
	assign out[3] = in1[3] ^ in2[3];
	assign out[4] = in1[4] ^ in2[4];
	assign out[5] = in1[5] ^ in2[5];
	assign out[6] = in1[6] ^ in2[6];
	assign out[7] = in1[7] ^ in2[7];
	assign out[8] = in1[8] ^ in2[8];
	assign out[9] = in1[9] ^ in2[9];
	assign out[10] = in1[10] ^ in2[10];
	assign out[11] = in1[11] ^ in2[11];
	assign out[12] = in1[12] ^ in2[12];
	assign out[13] = in1[13] ^ in2[13];
	assign out[14] = in1[14] ^ in2[14];
	assign out[15] = in1[15] ^ in2[15];
	assign out[16] = in1[16] ^ in2[16];
	assign out[17] = in1[17] ^ in2[17];
	assign out[18] = in1[18] ^ in2[18];
	assign out[19] = in1[19] ^ in2[19];
	assign out[20] = in1[20] ^ in2[20];
	assign out[21] = in1[21] ^ in2[21];
	assign out[22] = in1[22] ^ in2[22];
	assign out[23] = in1[23] ^ in2[23];
	assign out[24] = in1[24] ^ in2[24];
	assign out[25] = in1[25] ^ in2[25];
	assign out[26] = in1[26] ^ in2[26];
	assign out[27] = in1[27] ^ in2[27];
	assign out[28] = in1[28] ^ in2[28];
	assign out[29] = in1[29] ^ in2[29];
	assign out[30] = in1[30] ^ in2[30];
	assign out[31] = in1[31] ^ in2[31];
    
endmodule

module nand_gate_32_bit(
    input [31:0] in1,
    input [31:0] in2,
    output [31:0] out
);

    assign out[0] = ~(in1[0] & in2[0]);
	assign out[1] = ~(in1[1] & in2[1]);
	assign out[2] = ~(in1[2] & in2[2]);
	assign out[3] = ~(in1[3] & in2[3]);
	assign out[4] = ~(in1[4] & in2[4]);
	assign out[5] = ~(in1[5] & in2[5]);
	assign out[6] = ~(in1[6] & in2[6]);
	assign out[7] = ~(in1[7] & in2[7]);
	assign out[8] = ~(in1[8] & in2[8]);
	assign out[9] = ~(in1[9] & in2[9]);
	assign out[10] = ~(in1[10] & in2[10]);
	assign out[11] = ~(in1[11] & in2[11]);
	assign out[12] = ~(in1[12] & in2[12]);
	assign out[13] = ~(in1[13] & in2[13]);
	assign out[14] = ~(in1[14] & in2[14]);
	assign out[15] = ~(in1[15] & in2[15]);
	assign out[16] = ~(in1[16] & in2[16]);
	assign out[17] = ~(in1[17] & in2[17]);
	assign out[18] = ~(in1[18] & in2[18]);
	assign out[19] = ~(in1[19] & in2[19]);
	assign out[20] = ~(in1[20] & in2[20]);
	assign out[21] = ~(in1[21] & in2[21]);
	assign out[22] = ~(in1[22] & in2[22]);
	assign out[23] = ~(in1[23] & in2[23]);
	assign out[24] = ~(in1[24] & in2[24]);
	assign out[25] = ~(in1[25] & in2[25]);
	assign out[26] = ~(in1[26] & in2[26]);
	assign out[27] = ~(in1[27] & in2[27]);
	assign out[28] = ~(in1[28] & in2[28]);
	assign out[29] = ~(in1[29] & in2[29]);
	assign out[30] = ~(in1[30] & in2[30]);
	assign out[31] = ~(in1[31] & in2[31]);
    
endmodule

module or_gate_32_bit(
    input [31:0] in1,
    input [31:0] in2,
    output [31:0] out
);

    assign out[0] = in1[0] | in2[0];
	assign out[1] = in1[1] | in2[1];
	assign out[2] = in1[2] | in2[2];
	assign out[3] = in1[3] | in2[3];
	assign out[4] = in1[4] | in2[4];
	assign out[5] = in1[5] | in2[5];
	assign out[6] = in1[6] | in2[6];
	assign out[7] = in1[7] | in2[7];
	assign out[8] = in1[8] | in2[8];
	assign out[9] = in1[9] | in2[9];
	assign out[10] = in1[10] | in2[10];
	assign out[11] = in1[11] | in2[11];
	assign out[12] = in1[12] | in2[12];
	assign out[13] = in1[13] | in2[13];
	assign out[14] = in1[14] | in2[14];
	assign out[15] = in1[15] | in2[15];
	assign out[16] = in1[16] | in2[16];
	assign out[17] = in1[17] | in2[17];
	assign out[18] = in1[18] | in2[18];
	assign out[19] = in1[19] | in2[19];
	assign out[20] = in1[20] | in2[20];
	assign out[21] = in1[21] | in2[21];
	assign out[22] = in1[22] | in2[22];
	assign out[23] = in1[23] | in2[23];
	assign out[24] = in1[24] | in2[24];
	assign out[25] = in1[25] | in2[25];
	assign out[26] = in1[26] | in2[26];
	assign out[27] = in1[27] | in2[27];
	assign out[28] = in1[28] | in2[28];
	assign out[29] = in1[29] | in2[29];
	assign out[30] = in1[30] | in2[30];
	assign out[31] = in1[31] | in2[31];
    
endmodule

module not_gate_32_bit(
    input [31:0] in,
    output [31:0] out
);

    assign out[0] = ~in[0];
	assign out[1] = ~in[1];
	assign out[2] = ~in[2];
	assign out[3] = ~in[3];
	assign out[4] = ~in[4];
	assign out[5] = ~in[5];
	assign out[6] = ~in[6];
	assign out[7] = ~in[7];
	assign out[8] = ~in[8];
	assign out[9] = ~in[9];
	assign out[10] = ~in[10];
	assign out[11] = ~in[11];
	assign out[12] = ~in[12];
	assign out[13] = ~in[13];
	assign out[14] = ~in[14];
	assign out[15] = ~in[15];
	assign out[16] = ~in[16];
	assign out[17] = ~in[17];
	assign out[18] = ~in[18];
	assign out[19] = ~in[19];
	assign out[20] = ~in[20];
	assign out[21] = ~in[21];
	assign out[22] = ~in[22];
	assign out[23] = ~in[23];
	assign out[24] = ~in[24];
	assign out[25] = ~in[25];
	assign out[26] = ~in[26];
	assign out[27] = ~in[27];
	assign out[28] = ~in[28];
	assign out[29] = ~in[29];
	assign out[30] = ~in[30];
	assign out[31] = ~in[31];
    
endmodule

module nor_gate_32_bit(
    input [31:0] in1,
    input [31:0] in2,
    output [31:0] out
);

    assign out[0] = ~(in1[0] | in2[0]);
	assign out[1] = ~(in1[1] | in2[1]);
	assign out[2] = ~(in1[2] | in2[2]);
	assign out[3] = ~(in1[3] | in2[3]);
	assign out[4] = ~(in1[4] | in2[4]);
	assign out[5] = ~(in1[5] | in2[5]);
	assign out[6] = ~(in1[6] | in2[6]);
	assign out[7] = ~(in1[7] | in2[7]);
	assign out[8] = ~(in1[8] | in2[8]);
	assign out[9] = ~(in1[9] | in2[9]);
	assign out[10] = ~(in1[10] | in2[10]);
	assign out[11] = ~(in1[11] | in2[11]);
	assign out[12] = ~(in1[12] | in2[12]);
	assign out[13] = ~(in1[13] | in2[13]);
	assign out[14] = ~(in1[14] | in2[14]);
	assign out[15] = ~(in1[15] | in2[15]);
	assign out[16] = ~(in1[16] | in2[16]);
	assign out[17] = ~(in1[17] | in2[17]);
	assign out[18] = ~(in1[18] | in2[18]);
	assign out[19] = ~(in1[19] | in2[19]);
	assign out[20] = ~(in1[20] | in2[20]);
	assign out[21] = ~(in1[21] | in2[21]);
	assign out[22] = ~(in1[22] | in2[22]);
	assign out[23] = ~(in1[23] | in2[23]);
	assign out[24] = ~(in1[24] | in2[24]);
	assign out[25] = ~(in1[25] | in2[25]);
	assign out[26] = ~(in1[26] | in2[26]);
	assign out[27] = ~(in1[27] | in2[27]);
	assign out[28] = ~(in1[28] | in2[28]);
	assign out[29] = ~(in1[29] | in2[29]);
	assign out[30] = ~(in1[30] | in2[30]);
	assign out[31] = ~(in1[31] | in2[31]);
    
endmodule

module complement_2s_32_bit(
    input [31:0] in,
    output [31:0] out
);

    wire [31:0] temp;

    assign temp[0] = ~in[0];
	assign temp[1] = ~in[1];
	assign temp[2] = ~in[2];
	assign temp[3] = ~in[3];
	assign temp[4] = ~in[4];
	assign temp[5] = ~in[5];
	assign temp[6] = ~in[6];
	assign temp[7] = ~in[7];
	assign temp[8] = ~in[8];
	assign temp[9] = ~in[9];
	assign temp[10] = ~in[10];
	assign temp[11] = ~in[11];
	assign temp[12] = ~in[12];
	assign temp[13] = ~in[13];
	assign temp[14] = ~in[14];
	assign temp[15] = ~in[15];
	assign temp[16] = ~in[16];
	assign temp[17] = ~in[17];
	assign temp[18] = ~in[18];
	assign temp[19] = ~in[19];
	assign temp[20] = ~in[20];
	assign temp[21] = ~in[21];
	assign temp[22] = ~in[22];
	assign temp[23] = ~in[23];
	assign temp[24] = ~in[24];
	assign temp[25] = ~in[25];
	assign temp[26] = ~in[26];
	assign temp[27] = ~in[27];
	assign temp[28] = ~in[28];
	assign temp[29] = ~in[29];
	assign temp[30] = ~in[30];
	assign temp[31] = ~in[31];
    
    Adder_32bit RDA(temp,32'b1,out);
    
endmodule

module xnor_gate_32_bit(
    input [31:0] in1,
    input [31:0] in2,
    output [31:0] out
);

    assign out[0] = ~(in1[0] ^ in2[0]);
	assign out[1] = ~(in1[1] ^ in2[1]);
	assign out[2] = ~(in1[2] ^ in2[2]);
	assign out[3] = ~(in1[3] ^ in2[3]);
	assign out[4] = ~(in1[4] ^ in2[4]);
	assign out[5] = ~(in1[5] ^ in2[5]);
	assign out[6] = ~(in1[6] ^ in2[6]);
	assign out[7] = ~(in1[7] ^ in2[7]);
	assign out[8] = ~(in1[8] ^ in2[8]);
	assign out[9] = ~(in1[9] ^ in2[9]);
	assign out[10] = ~(in1[10] ^ in2[10]);
	assign out[11] = ~(in1[11] ^ in2[11]);
	assign out[12] = ~(in1[12] ^ in2[12]);
	assign out[13] = ~(in1[13] ^ in2[13]);
	assign out[14] = ~(in1[14] ^ in2[14]);
	assign out[15] = ~(in1[15] ^ in2[15]);
	assign out[16] = ~(in1[16] ^ in2[16]);
	assign out[17] = ~(in1[17] ^ in2[17]);
	assign out[18] = ~(in1[18] ^ in2[18]);
	assign out[19] = ~(in1[19] ^ in2[19]);
	assign out[20] = ~(in1[20] ^ in2[20]);
	assign out[21] = ~(in1[21] ^ in2[21]);
	assign out[22] = ~(in1[22] ^ in2[22]);
	assign out[23] = ~(in1[23] ^ in2[23]);
	assign out[24] = ~(in1[24] ^ in2[24]);
	assign out[25] = ~(in1[25] ^ in2[25]);
	assign out[26] = ~(in1[26] ^ in2[26]);
	assign out[27] = ~(in1[27] ^ in2[27]);
	assign out[28] = ~(in1[28] ^ in2[28]);
	assign out[29] = ~(in1[29] ^ in2[29]);
	assign out[30] = ~(in1[30] ^ in2[30]);
	assign out[31] = ~(in1[31] ^ in2[31]);
    
endmodule