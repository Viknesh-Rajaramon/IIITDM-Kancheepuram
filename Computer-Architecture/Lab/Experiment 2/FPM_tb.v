`include "FPM.v"

module top;
	
	reg [31:0] a,b;
	wire [31:0] product;
	
	initial
		begin
			$dumpfile("FPM_32bit.vcd");
			$dumpvars(0,top);
		end
	
	initial
		begin
			//A = 125.125, B = 12.0625
			a = 32'b01000010111110100100000000000000;
			b = 32'b01000001010000010000000000000000;
			
			//A = 0, B = 0.5625
			#100
			a = 32'b00000000000000000000000000000000;
			b = 32'b00111111000100000000000000000000;
			
			//A = 9.75, B = Infinity
			#100
			a = 32'b01000001000111000000000000000000;
			b = 32'b01111111100000000000000000000000;
			
			//A = 9.75, B = NaN
			#100
			a = 32'b01000001000111000000000000000000;
			b = 32'b01111111111111111111111111111111;
			
		end
	
	FPM_32BIT fp_multiplier(a,b,product);
	
	initial
		$monitor("\n\t\tX1 = %b\n\t\tX2 = %b\n\n\t\tX3 = %b\n" ,a,b,product);
	
endmodule
