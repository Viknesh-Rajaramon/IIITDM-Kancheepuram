`include "DFF.v"

module clock_delay #(parameter SIZE_1 = 9, parameter SIZE_2 = 64) (
	input clock,
	input [SIZE_2-1:0] in,
	output [SIZE_2-1:0] out
	);

	genvar i;

	for(i = 0; i < SIZE_1; i = i + 1)
	begin :LV
		wire [SIZE_2-1:0] temp;

		if(i == 0)
			D_flip_flop #(SIZE_2) dff(clock, in, LV[0].temp);
		else if(i == SIZE_1-1)
			D_flip_flop #(SIZE_2) dff(clock, LV[i-1].temp, out);
		else
			D_flip_flop #(SIZE_2) dff(clock, LV[i-1].temp, LV[i].temp);
	end

endmodule