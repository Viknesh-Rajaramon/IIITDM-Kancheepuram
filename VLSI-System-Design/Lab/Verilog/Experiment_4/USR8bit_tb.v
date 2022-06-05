`include "USR8bit.v"

module top;

	reg clock,reset;
	reg [7:0] in;
	reg [1:0] select;
	reg SINL,SINR;
	
	wire [7:0] out;
	
	initial
	begin
		$dumpfile("USR8bit.vcd");
		$dumpvars(0,top);
	end
	
	eight_bit_USR USR(in,clock,reset,SINL,SINR,select,out);
	
	initial
	$display("  00 - No Change, 01 - Shift Left, 10 - Shift Right, 11 - Parallel In \n");
	
	initial
	begin
		reset=1'b0;
		clock=1'b0;
		select=2'b11;
		SINL=1'b0;
		SINR=1'b1;
		
		select=2'b00;
		
		#10;
		reset=1'b1;
		
		#10;
		in=8'b01010101;
		reset=1'b0;
		
		#10;
		select=2'b11;
		
		#10;
		select=2'b01;
		
		#10
		select=2'b10;
		
		#10;
		select=2'b00;
		
		#10;
		
		#10;
		in=8'b10101010;
		reset=1'b0;
		
		#10;
		select=2'b11;
		
		#10;
		select=2'b01;
		
		#10;
		select=2'b10;
		
		#10;
		select=2'b00;
		
		#10
		reset=1'b1;
		
	end
	
	always #5 clock=~clock;
	
	initial
	$monitor($time, ": input=%b, reset=%b, select=%b, clk=%b, SINR=%b, SINL=%b, out=%b",in,reset,select,clock,SINR,SINL,out);
	
	initial
	#140 $finish;

endmodule
