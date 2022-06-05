`include "Adder_24bit.v"
`include "Barrel_Shifter.v"

module SWAP(
	input clock,
	input [31:0] X1,
	input [31:0] X2,
	output [31:0] Y1,
	output [31:0] Y2
	);

	wire [31:0] temp1,temp2;

	assign Y1 = (X1[30:0] < X2[30:0]) ? X2 : X1;
	assign Y2 = (X1[30:0] < X2[30:0]) ? X1 : X2;

endmodule

module EXPONENT_SAME(
	input clock,
	input S1,
	input S2,
	input [7:0] E1,
	input [7:0] E2,
	input [23:0] M1,
	input [23:0] M2,
	output S3,
	output [7:0] E3,
	output [23:0] P1,
	output [23:0] P2
	);
	
	wire [7:0] diff,temp;
	wire [23:0] buffer;

	assign diff = E1 - E2;
	
	barrel_shifter_right BS(M2,diff,buffer);

	D_flip_flop #(24) dff_1(clock,buffer,P2);
	D_flip_flop #(24) dff_2(clock,M1,P1);
	D_flip_flop #(1) dff_3(clock,S1,S3);
	D_flip_flop #(8) dff_4(clock,E1,E3);

endmodule

module ADD_MANTISSA(
	input clock,
	input S1,
	input S2,
	input [23:0] M1,
	input [23:0] M2,
	output [23:0] M3,
	output cout
	);
	
	wire [23:0] comp_1,comp_2;
	wire [23:0] temp;

	wire [23:0] buffer1;
	wire buffer2;

	assign comp_1 = ~M2[23:0];
	assign temp = comp_1 + 23'b1;

	assign comp_2 = (S1 != S2) ? temp[23:0] : M2;
	
	CLA_24bit add_mantissa(clock,M1,comp_2,M3,cout);

endmodule

module NORMALIZE(
	input clock,
	input S1,
	input S2,
	input S3,
	input [7:0] E1,
	input [7:0] E2,
	input [7:0] E3,
	input [23:0] M1,
	input [23:0] M2,
	input [23:0] M3,
	output [31:0] X3
	);
	
	reg [7:0] E4,diff,shift;
	wire [23:0] MAN;
	
	integer i = 23;
	
	always @(M3[23:0])
	begin
		while((i >= 0) && (M3[i] != 1'b1))
		begin
			--i;
		end
		
		if(i == -1)
		begin
			i = 0;
		end
		
		else
		begin
			i = i;
		end
	end
	
	always @(E3[7:0],M3[23:0])
	begin
		if((S1 != S2) && (M1 == M2) && (E1 == E2))
		begin
			assign E4 = 8'b0;
			assign shift = 8'b00011000;
		end
		
		else if((&E3 == 1'b1) && (|M3 == 1'b0))
		begin
			assign E4 = E3;
			assign shift = 8'b00011000;
		end
		
		else if((&E3 == 1'b1) && (|M3 == 1'b1))
		begin
			assign E4 = E3;
			assign shift = 8'b00011000;
		end
		
		else
		begin
			diff = i[7:0];
			shift = 8'd23 - diff;
			E4 = E3 + shift;
		end
	end
	
	barrel_shifter_left BS(M3,shift,MAN);

	clock_delay #(6,1) delay_1(clock,S3,X3[31]);
	clock_delay #(6,8) delay_2(clock,E4,X3[30:23]);
	D_flip_flop #(23) dff_1(clock,MAN[22:0],X3[22:0]);
	
endmodule

module FPA_32BIT(
	input clock,
	input [31:0] a,
	input [31:0] b,
	output [31:0] X3
	);
	
	wire [31:0] X1,X2;
	
	SWAP swap(clock,a,b,X1,X2);
	
	wire S1,S2,S3,cout;
	wire [7:0] E1,E2,E3;
	wire [23:0] M1,M2,M3;
	wire [23:0] P1,P2;

	wire temp1_S1,temp1_S2,temp1_S3,temp1_cout;
	wire temp2_S1,temp2_S2,temp2_S3,temp2_cout;

	assign S1 = X1[31];
	assign S2 = X2[31];

	assign E1 = X1[30:23];
	assign E2 = X2[30:23];

	assign M1[23] = 1'b1;
	assign M2[23] = 1'b1;

	assign M1[22:0] = X1[22:0];
	assign M2[22:0] = X2[22:0];
	
	EXPONENT_SAME exponent(clock,S1,S2,E1,E2,M1,M2,S3,E3,P1,P2);

	D_flip_flop #(1) dff_1(clock,S1,temp1_S1);
	D_flip_flop #(1) dff_2(clock,S1,temp1_S2);
	
	ADD_MANTISSA add(clock,temp1_S1,temp1_S2,P1[23:0],P2[23:0],M3[23:0],cout);
	
	NORMALIZE norm(clock,S1,S2,S3,E1,E2,E3,P1,P2,M3,X3);
		
endmodule