`include "Wallace_32_bit.v"
module wallace_tb;
    reg [31:0] a, b;
    reg cin,clk;
    wire [63:0] out;
    initial begin
		clk=0;
	end

	always 
		#1 clk=~clk;

    wallace wallace0( a, b, clk, out);
    initial begin

        a = 32'h&;
        b = 32'h!;

    #25 $finish();
    end
		initial
    #25
        $display("%d %d %d \n", a, b, out[31:0]);

endmodule
