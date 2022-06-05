`include "WTM_32bit.v"

module top;
	
	reg [31:0] a,b;
	wire [31:0] product;
	reg clock;
	
	initial
		begin
			clock=1'b0;

			$display($time,"\ta = %h, b = %h, Product = %h\n" ,a,b,product);

			a = 32'd514;
			b = 32'd981;
			
			#100
			$display($time,"\ta = %h, b = %h, Product = %h\n" ,a,b,product);
			a = 32'd69841;
			b = 32'd464;
			
			#100
			$display($time,"\ta = %h, b = %h, Product = %h\n" ,a,b,product);
			a = 32'd56148;
			b = 32'd14645;
			
			#100
			$display($time,"\ta = %h, b = %h, Product = %h\n" ,a,b,product);
			a = 32'd56321;
			b = 32'd76258;

			#100
			$display($time,"\ta = %h, b = %h, Product = %h\n" ,a,b,product);
			$finish;
		end
	
	WTM_32bit WTM(clock,a,b,product);

	always
	begin
		#2;
		clock=~clock;
	end
	
endmodule
