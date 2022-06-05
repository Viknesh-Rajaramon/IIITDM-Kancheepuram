`include "FP_Adder.v"

module top();

reg [31:0]r_a, r_b,r_s;
reg r_cin,clk;
wire [31:0]sum;
initial begin
		clk=0;
	end

	always 
		#1 clk=~clk;

fpadd m_gh(r_a,r_b,sum,clk);

initial
begin

	r_a=32'h000f7125;
	r_b=32'h0006985b;
	#30 $finish();
end

initial begin
	#30
	$display("%d %d %d \n",r_a,r_b,sum);
	end
endmodule
