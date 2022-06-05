module D_flip_flop #(parameter SIZE = 32*64) (
	input clock,
	input [SIZE-1:0] in,
	output reg [SIZE-1:0] out
	);

	always @(posedge clock)
	begin
		out <= in;
	end

endmodule