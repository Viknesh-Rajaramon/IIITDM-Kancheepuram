`include "DFF.v"

module clock_delay #(parameter SIZE = 5) (
	input clock,
	input [31:0] in,
	output [31:0] out
	);

	genvar i;

	for(i=0; i<SIZE; i=i+1)
	begin :LV
		wire [31:0] temp;

		if(i==0)
			D_flip_flop #(32) dff(clock, in, LV[0].temp);
		else if(i==SIZE-1)
			D_flip_flop #(32) dff(clock, LV[i-1].temp, out);
		else
			D_flip_flop #(32) dff(clock, LV[i-1].temp, LV[i].temp);
	end

endmodule