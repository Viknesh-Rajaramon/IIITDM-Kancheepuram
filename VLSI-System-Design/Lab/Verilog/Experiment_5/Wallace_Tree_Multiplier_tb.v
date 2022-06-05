`include "Wallace_Tree_Multiplier.v"

module top;
	
	reg [31:0] a,b;
	wire [63:0] out;
	
	WTM wtm_1(a,b,out);
	
	initial
		begin
			
			#10;
			#10 a=32'b00000000000000000000000000001111; b=32'b00000000000000000000000000001000;
		end
		
	initial
		begin
			$monitor($time, "\ta=%d; b=%d; out=%d",a,b,out);
		end
	
endmodule
