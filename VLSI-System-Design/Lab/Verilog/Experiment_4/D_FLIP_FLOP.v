module d_flip_flop(
	input D,
	input clock,
	input clear,
	output reg Q
	);
	
	always @(posedge clock)
		if(clear==1'b1)
			Q<=1'b0;
		else
			Q<=D;
		
endmodule
