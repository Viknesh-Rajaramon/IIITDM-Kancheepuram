module full_adder(
	input a,
	input b,
	input cin,
	output sum,
	output cout
	);

	wire w1,w2,w3,w4,w5;
	
	xor xor_0 (w1,a,b);
	xor xor_1 (sum,w1,cin);
	
	and and_0 (w2,a,b);
	and and_1 (w3,a,cin);
	and and_2 (w4,b,cin);
	
	or or_0 (w5,w2,w3);
	or or_1 (cout,w4,w5);

endmodule

module four_bit_RCA(
	input [3:0] a,
	input [3:0] b,
	input cin,
	output [3:0] sum,
	output cout
	);
	
	wire carry[2:0];

	full_adder f1(a[0],b[0],cin,sum[0],carry[0]);
	full_adder f2(a[1],b[1],carry[0],sum[1],carry[1]);
	full_adder f3(a[2],b[2],carry[1],sum[2],carry[2]);
	full_adder f4(a[3],b[3],carry[2],sum[3],cout);

endmodule

module sixteen_bit_RCA(
	input [15:0] a,
	input [15:0] b,
	input cin,
	output [15:0] sum,
	output cout
	);
	
	wire carry[2:0];
		
	four_bit_RCA FBA1(a[3:0],b[3:0],cin,sum[3:0],carry[0]);
	four_bit_RCA FBA2(a[7:4],b[7:4],carry[0],sum[7:4],carry[1]);
	four_bit_RCA FBA3(a[11:8],b[11:8],carry[1],sum[11:8],carry[2]);
	four_bit_RCA FBA4(a[15:12],b[15:12],carry[2],sum[15:12],cout);

endmodule

module thirty_two_bit_RCA(
	input [31:0] a,
	input [31:0] b,
	input cin,
	output [31:0] sum,
	output cout
	);
	
	wire carry;

	sixteen_bit_RCA SBA1(a[15:0],b[15:0],cin,sum[15:0],carry);
	sixteen_bit_RCA SBA2(a[31:16],b[31:16],cout0,sum[31:16],cout);

endmodule

module top;

	reg [31:0] a,b;
	reg cin;
	wire [31:0] sum;
	wire cout;
	
	thirty_two_bit_RCA adder(a,b,cin,sum,cout);
	
	initial
	begin
		a=0; b=1; cin=0;
		#10 a=32'b11011010101111001001100001110101;
		#10 b=32'b11101111101111001001011000010101;
		#10 a=32'b10101100101111001001001000110100;
	end
	
	initial
	begin
		$monitor($time, "\ta = %h, b = %h, cin = %b, Sum = %h, cout = %b",a,b,cin,sum,cout);
		$dumpfile("RCA32bit.vcd");
			$dumpvars;
	end

endmodule
