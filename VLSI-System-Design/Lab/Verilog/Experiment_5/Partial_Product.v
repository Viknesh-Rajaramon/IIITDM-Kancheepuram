module Partial_Product(
	input [31:0] pp1,
	input [31:0] pp2,
	output reg [31:0][63:0] pp
	);
	
	integer i=0;
	
	always @(pp1,pp2)
	begin
		for(i=0;i<32;++i)
			begin
				pp[i]=pp1&{32{pp2[i]}};
				pp[i]=pp[i]<<i;
			end
	end

endmodule
