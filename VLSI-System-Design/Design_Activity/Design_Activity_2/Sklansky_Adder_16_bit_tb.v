`include "Sklansky_Adder_16_bit.v"

module top;
	
	reg [15:0] a,b;
	wire [15:0] sum;
	wire cin,cout;
	
	assign cin=1'b0;
	
	initial
	begin
		$dumpfile("Sklansky_Adder_16_bit.vcd");
		$dumpvars(0,top);
	end
	
	sklansky SA(a,b,cin,sum,cout);
	
	initial
		begin
			
			#10;
			#10
			a=16'b0000000000001111;//15 - decimal value
			b=16'b0000000000001000;//8 - decimal value
			
			#10;
			#10
			a=16'b0000000100001101;//269 - decimal value
			b=16'b0001000001001010;//4170 - decimal value
		end
		
	initial
		begin
			$monitor($time, "\ta=%d; b=%d; sum=%d; cout=%b",a,b,sum,cout);
		end
	
endmodule
