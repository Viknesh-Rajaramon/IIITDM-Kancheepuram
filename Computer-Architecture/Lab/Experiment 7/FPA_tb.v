`include "FPA.v"

module top;
	reg [31:0] a,b;
	wire [31:0] sum;
	reg clock;

	initial
	begin
		$dumpfile("FPA_32bit.vcd");
		$dumpvars(0,top);
	end

	initial
	begin
		clock=1'b0;

		$display($time,"\n\t\tX1 = %b\n\t\tX2 = %b\n\t\tX3 = %b\n\n" ,a,b,sum);

		//A = 9.765625, B = 0.5625
		a = 32'b01000001000111000100000000000000;
		b = 32'b00111111000100000000000000000000;
			
		//A = 0, B = 0.5625
		#15
		$display($time,"\n\t\tX1 = %b\n\t\tX2 = %b\n\t\tX3 = %b\n\n" ,a,b,sum);
		a = 32'b00000000000000000000000000000000;
		b = 32'b00111111000100000000000000000000;
			
		//A = 9.765625, B = Infinity
		#15
		$display($time,"\n\t\tX1 = %b\n\t\tX2 = %b\n\t\tX3 = %b\n\n" ,a,b,sum);
		a = 32'b01000001000111000100000000000000;
		b = 32'b01111111100000000000000000000000;
			
		//A = 9.765625, B = -9.765625
		#15
		$display($time,"\n\t\tX1 = %b\n\t\tX2 = %b\n\t\tX3 = %b\n\n" ,a,b,sum);
		a = 32'b01000001000111000100000000000000;
		b = 32'b11000001000111000100000000000000;

		#15
		$display($time,"\n\t\tX1 = %b\n\t\tX2 = %b\n\t\tX3 = %b" ,a,b,sum);
		$finish;
	end
	
	FPA_32BIT fp_adder(clock,a,b,sum);

	always
	begin
		#1;
		clock = ~clock;
	end
	
endmodule
