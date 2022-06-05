`include "Barrel_Shifter.v"
`include "Wallace_Tree_Multiplier.v"
`include "Clock_Delay.v"

module NORMALIZE(
	input clock,
	input S1,
	input S2,
	input [7:0] E1,
	input [7:0] E2,
	input [7:0] E3,
	input [23:0] MX,
	input [23:0] MY,
	input [23:0] M3,
	output [31:0] X3
	);
	
	wire S3;
	reg [7:0] E4,shift;
	wire [23:0] MAN;
	wire [22:0] M1,M2;
	
	assign S3=S1^S2;

	clock_delay #(10,23) delay_1(clock,MX[22:0],M1);
	clock_delay #(10,23) delay_2(clock,MY[22:0],M2);
	
	integer i=0;
	
	always @(E1[7:0],E2[7:0],E3[7:0],M1[22:0],M2[22:0],M3[23:0])
	begin
		//Zero case
		if(((|E1==1'b0) && (|M1==1'b0)) || ((|E2==1'b0) && (|M2==1'b0)))
		begin
			assign E4=8'b00000000;
			assign shift=8'b00011000;
		end
		
		//Infinity case
		else if(((&E1==1'b1) && (|M1==1'b0)) || ((&E2==1'b1) && (|M2==1'b0)))
		begin
			assign E4=8'b11111111;
			assign shift=8'b00011000;
		end
		
		//NAN case
		else if((E1==8'b11111111) || (E2==8'b11111111))
		begin
			assign E4=8'b11111111;
			assign shift=8'b0000000;
		end
		
		else
		begin
			assign shift=8'b0000000;
			E4=E3;
		end
	end
	
	barrel_shifter_left BS(M3,shift,MAN);

	D_flip_flop #(1) dff_1(clock,S3,X3[31]);
	D_flip_flop #(8) dff_2(clock,E4,X3[30:23]);
	D_flip_flop #(23) dff_3(clock,MAN[22:0],X3[22:0]);
	
endmodule

module FPM_32BIT(
	input clock,
	input [31:0] X1,
	input [31:0] X2,
	output [31:0] X3
	);
	
	wire S1,S2;
	wire [7:0] E1,E2;
	reg [7:0] E3;
	wire [31:0] M1,M2;
	reg [23:0] M3;
	wire [63:0] MAN;
	
	assign M1[31:24]=8'b00000000;
	assign M2[31:24]=8'b00000000;
	
	assign M1[23]=1'b1;
	assign M2[23]=1'b1;
	
	assign M1[22:0]=X1[22:0];
	assign M2[22:0]=X2[22:0];
	
	WTM Mul(clock,M1,M2,MAN);

	clock_delay #(10,1) delay_1(clock,X1[31],S1);
	clock_delay #(10,1) delay_2(clock,X2[31],S2);

	clock_delay #(10,8) delay_3(clock,X1[30:23],E1);
	clock_delay #(10,8) delay_4(clock,X2[30:23],E2);
	
	always @(E1[7:0],E2[7:0],MAN[63:0])
	begin
		if(MAN[47]==1'b1)
		begin
			E3=E1+E2+8'b10000001+8'b00000001;
			M3=MAN[47:24];
		end
		
		else
		begin
			E3=E1+E2+8'b10000001;
			M3[23:1]=MAN[46:24];
			assign M3[0]=1'b0;
		end
	end
	
	NORMALIZE norm(clock,S1,S2,E1,E2,E3,M1[23:0],M2[23:0],M3,X3);
	
endmodule
