`include "MUX.v"
`include "D_FLIP_FLOP.v"

module eight_bit_USR(
	input [7:0] in,
	input clock,
	input reset,
	input SINL,
	input SINR,
	input [1:0] select,
	output [7:0] out
	);
	
	wire [7:0] w;
	
	mux_4_to_1 MUX1(out[0],out[1],SINL,in[0],select[1:0],w[0]);
	mux_4_to_1 MUX2(out[1],out[2],out[0],in[1],select[1:0],w[1]);
	mux_4_to_1 MUX3(out[2],out[3],out[1],in[2],select[1:0],w[2]);
	mux_4_to_1 MUX4(out[3],out[4],out[2],in[3],select[1:0],w[3]);
	mux_4_to_1 MUX5(out[4],out[5],out[3],in[4],select[1:0],w[4]);
	mux_4_to_1 MUX6(out[5],out[6],out[4],in[5],select[1:0],w[5]);
	mux_4_to_1 MUX7(out[6],out[7],out[5],in[6],select[1:0],w[6]);
	mux_4_to_1 MUX8(out[7],SINR,out[6],in[7],select[1:0],w[7]);
	
	d_flip_flop D1(w[0],clock,reset,out[0]);
	d_flip_flop D2(w[1],clock,reset,out[1]);
	d_flip_flop D3(w[2],clock,reset,out[2]);
	d_flip_flop D4(w[3],clock,reset,out[3]);
	d_flip_flop D5(w[4],clock,reset,out[4]);
	d_flip_flop D6(w[5],clock,reset,out[5]);
	d_flip_flop D7(w[6],clock,reset,out[6]);
	d_flip_flop D8(w[7],clock,reset,out[7]);
	
endmodule
