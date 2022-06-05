`include "Barrel_Shifter.v"
`include "Wallace_Tree_Multiplier.v"

module NORMALIZE(
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
	assign M1=MX[22:0];
	assign M2=MY[22:0];
	
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
	assign X3={S3,E4,MAN[22:0]};
	
endmodule

module FPM_32BIT(
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
	
	assign S1=X1[31];
	assign S2=X2[31];
	assign E1=X1[30:23];
	assign E2=X2[30:23];
	assign M1[31:24]=8'b00000000;
	assign M2[31:24]=8'b00000000;
	assign M1[23]=1'b1;
	assign M2[23]=1'b1;
	assign M1[22:0]=X1[22:0];
	assign M2[22:0]=X2[22:0];
	
	WTM Mul(M1,M2,MAN);
	
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
	
	NORMALIZE norm(S1,S2,E1,E2,E3,M1[23:0],M2[23:0],M3,X3);
	
endmodule
