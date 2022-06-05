`include "CLA_32bit.v"

module top;
	
	reg [31:0] a,b;
	wire [31:0] sum;
	wire cout;
	reg clock;

	initial
		begin
			clock=1'b0;

			$display($time,"\ta = %h, b = %h, Sum = %h, cout = %b\n" ,a,b,sum,cout);

			a = 32'd515;
			b = 32'd981;
			
			#100
			$display($time,"\ta = %h, b = %h, Sum = %h, cout = %b\n" ,a,b,sum,cout);
			a = 32'd69841;
			b = 32'd46411651;
			
			#100
			$display($time,"\ta = %h, b = %h, Sum = %h, cout = %b\n" ,a,b,sum,cout);
			a = 32'd56148851;
			b = 32'd1464149;
			
			#100
			$display($time,"\ta = %h, b = %h, Sum = %h, cout = %b\n" ,a,b,sum,cout);
			a = 32'd879856321;
			b = 32'd3284511984;

			#500
			$display($time,"\ta = %h, b = %h, Sum = %h, cout = %b\n" ,a,b,sum,cout);
			$finish;
		end
	
	CLA_32bit CLA(clock,a,b,sum,cout);

	always
	begin
		#5;
		clock=~clock;
	end
	
endmodule
