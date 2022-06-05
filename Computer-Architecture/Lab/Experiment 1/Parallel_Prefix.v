module parallelprefix(
	input x0_j_1,
	input x1_j_1,
	input x0_j,
	input x1_j,
	output reg y0,
	output reg y1
	);
	
	always @(x0_j_1,x1_j_1,x0_j,x1_j)
		begin
			if((x0_j_1^x1_j_1)==1'b0)
				begin
					assign y0=x0_j_1;
					assign y1=x1_j_1;
				end
			else
				begin
					assign y0=x0_j;
					assign y1=x1_j;
				end
		end

endmodule
