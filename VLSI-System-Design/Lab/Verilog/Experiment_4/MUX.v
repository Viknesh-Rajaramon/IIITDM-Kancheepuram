module mux_4_to_1(input i0,
	input i1,
	input i2,
	input i3,
	input [1:0] select,
	output reg out
	);
	
	always @(i0,i1,i2,i3,select[1:0])
	
	begin
		if(select[0]==0 & select[1]==0)
			out=i0;
		else if(select[0]==1 & select[1]==0)
			out=i1;
		else if(select[0]==0 & select[1]==1)
			out=i2;
		else if(select[0]==1 & select[1]==1)
			out=i3;
	end

endmodule
