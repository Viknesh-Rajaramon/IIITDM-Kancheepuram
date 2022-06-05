`include "FPM.v"

module top;
	
	reg [31:0] a,b;
	wire [31:0] product;
	reg clock;

	initial
	begin
		$dumpfile("FPM_32bit.vcd");
		$dumpvars(0,top);
	end
	
	initial
	begin
		clock = 1'b0;

		$display($time,"\n\t\tX1 = %b\n\t\tX2 = %b\n\n\t\tX3 = %b\n" ,a,b,product);
		//A = 125.125, B = 12.0625
		a = 32'b01000010111110100100000000000000;
		b = 32'b01000001010000010000000000000000;
			
		//A = 0, B = 0.5625
		#25
		$display($time,"\n\t\tX1 = %b\n\t\tX2 = %b\n\n\t\tX3 = %b\n" ,a,b,product);
		a = 32'b00000000000000000000000000000000;
		b = 32'b00111111000100000000000000000000;
	
		//A = 9.75, B = Infinity
		#25
		$display($time,"\n\t\tX1 = %b\n\t\tX2 = %b\n\n\t\tX3 = %b\n" ,a,b,product);
		a = 32'b01000001000111000000000000000000;
		b = 32'b01111111100000000000000000000000;
			
		//A = 9.75, B = NaN
		#25
		$display($time,"\n\t\tX1 = %b\n\t\tX2 = %b\n\n\t\tX3 = %b\n" ,a,b,product);
		a = 32'b01000001000111000000000000000000;
		b = 32'b01111111111111111111111111111111;

		#25
		$display($time,"\n\t\tX1 = %b\n\t\tX2 = %b\n\n\t\tX3 = %b\n" ,a,b,product);
		$finish;
			
	end
	
	FPM_32BIT fp_multiplier(clock,a,b,product);
	
	always
	begin
		#1
		clock = ~clock;
	end
	
endmodule
