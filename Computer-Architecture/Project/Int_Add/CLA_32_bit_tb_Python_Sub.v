`include "CLA_32_bit.v"

module top;
    reg [31:0] a, b;
    reg cin, clk;
    wire [31:0] sum;
    wire cout;

    initial
    begin
		clk = 0;
	end

	always 
		#1 clk = ~clk;

    rdcla rdcla0(sum, cout, a, b, cin, clk);
    
	initial
	begin
	    cin = 1'b1;
    
	    a = 32'h&;
        b = 32'h!;

    	#50 $finish();
    end

    initial 
    	#50
        $display("%d %d %d \n", a, b, sum);

endmodule