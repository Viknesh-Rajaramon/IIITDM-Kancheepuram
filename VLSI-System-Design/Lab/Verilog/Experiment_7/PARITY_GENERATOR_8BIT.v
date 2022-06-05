`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    10:18:58 10/15/2020 
// Design Name: 
// Module Name:    parity_generator_8bit 
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
module xor_gate(
	input a,
	input b,
	output out
	);
	
	xor xor_0(out,a,b);
	
endmodule

module parity_generator_8bit(
    input [7:0] a,
    output even,
    output odd
    );

	wire w[5:0];
	
	xor_gate XOR_00(a[0],a[1],w[0]);
	xor_gate XOR_01(a[2],a[3],w[1]);
	xor_gate XOR_02(a[4],a[5],w[2]);
	xor_gate XOR_03(a[6],a[7],w[3]);
	
	xor_gate XOR_10(w[0],w[1],w[4]);
	xor_gate XOR_11(w[2],w[3],w[5]);
	
	xor_gate XOR_20 (w[4],w[5],even);
	
	not not_0 (odd,even);

endmodule
