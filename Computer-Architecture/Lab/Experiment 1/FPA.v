`include "Adder_24bit.v"
`include "Barrel_Shifter.v"

module SWAP(
	input [31:0] X1,
	input [31:0] X2,
	output reg [31:0] Y1,
	output reg [31:0] Y2
	);
	
	always @(X1[31:0],X2[31:0])
	begin
		if(X1[30:0]<X2[30:0])
			begin
				Y2=X1;
				Y1=X2;
			end
		
		else
			begin
				Y1=X1;
				Y2=X2;
			end
	end

endmodule

module EXPONENT_SAME(
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
	
	reg [7:0] diff;
	wire [23:0] M3;
	
	always @(S1,S2,E1[7:0],E2[7:0],M1[23:0],M2[23:0])
	begin
		diff=E1-E2;
	end
	
	barrel_shifter_right BS(M2,diff,M3);
	
	assign P1=M1;	
	assign P2=M3;
	assign S3=S1;
	assign E3=E1;

endmodule

module ADD_MANTISSA(
	input S1,
	input S2,
	input [23:0] M1,
	input [23:0] M2,
	output [23:0] M3,
	output cout
	);
	
	reg [23:0] comp_1,comp_2;
	reg [24:0] temp;
	
	always @(S1,S2,M2[23:0])
	begin
		if(S1!=S2)
			begin
				comp_1=~M2[23:0];
				temp=comp_1+23'b1;
				comp_2=temp[23:0];
			end
		else
			begin
				comp_2=M2;
			end
	end
	
	Adder_24bit add_mantissa(M1,comp_2,M3,cout);

endmodule

module NORMALIZE(
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
	
	integer i=23;
	
	always @(M3[23:0])
	begin
		while((i>=0) && (M3[i]!=1'b1))
		begin
			--i;
		end
		
		if(i==-1)
		begin
			i=0;
		end
		
		else
		begin
			i=i;
		end
	end
	
	always @(E3[7:0],M3[23:0])
	begin
		if((S1!=S2) && (M1==M2) && (E1==E2))
		begin
			assign E4=8'b0;
			assign shift=8'b00011000;
		end
		
		else if((&E3==1'b1) && (|M3==1'b0))
		begin
			assign E4=E3;
			assign shift=8'b00011000;
		end
		
		else
		begin
			diff=i[7:0];
			shift=8'd23-diff;
			E4=E3+shift;
		end
	end
	
	barrel_shifter_left BS(M3,shift,MAN);
	assign X3={S3,E4,MAN[22:0]};
	
endmodule

module FPA_32BIT(
	input [31:0] a,
	input [31:0] b,
	output [31:0] X3
	);
	
	wire [31:0] X1,X2;
	
	SWAP swap(a,b,X1,X2);
	
	wire S1,S2,S3,cout;
	wire [7:0] E1,E2,E3;
	wire [23:0] M1,M2,M3;
	wire [23:0] P1,P2;
	
	assign S1=X1[31];
	assign S2=X2[31];
	assign E1=X1[30:23];
	assign E2=X2[30:23];
	assign M1[23]=1'b1;
	assign M2[23]=1'b1;
	assign M1[22:0]=X1;
	assign M2[22:0]=X2;
	
	EXPONENT_SAME exponent(S1,S2,E1,E2,M1,M2,S3,E3,P1,P2);
	
	ADD_MANTISSA add(S1,S2,P1[23:0],P2[23:0],M3[23:0],cout);
	
	NORMALIZE norm(S1,S2,S3,E1,E2,E3,P1,P2,M3,X3);
		
endmodule
