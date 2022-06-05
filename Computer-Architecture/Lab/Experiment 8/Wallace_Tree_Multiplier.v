module mul(
	input clock,
	input [31:0] a,
	input [31:0] b,
	output [31:0][63:0] out
	);
	
	genvar i;

	wire [31:0][63:0] buffer;
	
	generate
		for(i=0;i<32;i=i+1)
		begin
			assign buffer[i]=(a & {64{b[i]}})<<i;
		end
	endgenerate

	D_flip_flop #(32*64) dff(clock,buffer,out);
	
endmodule

module addArr(
	input [63:0] a,
	input [63:0] b,
	input [63:0] cin,
	output [63:0] sum,
	output [63:0] c
	);
	
	genvar i;
	
	generate
		for(i=0;i<63;i=i+1)
		begin
			full_adder FA1(a[i],b[i],cin[i],sum[i],c[i+1]);
		end
		
		assign sum[63]=a[63]^b[63]^cin[63];
		assign c[0]=1'b0;
	endgenerate
	
endmodule

module full_adder(
	input a,
	input b,
	input cin,
	output sum,
	output cout
	);
	
	assign sum=a^b^cin;
	assign cout=(a&b)|(a&cin)|(b&cin);
	
endmodule

module carrySave #(parameter N=32, parameter M=22)(
	input [(N-1):0][63:0] a,
	output [(M-1):0][63:0] out
	);
	
	genvar i,j;
	integer ct=0;
	
	generate
		for(i=0;i<N/3;i=i+1)
		begin
			addArr A1(a[3*i],a[3*i+1],a[3*i+2],out[2*i],out[2*i+1]);
		end
		
		for(j=1;j<=N%3;j=j+1)
		begin
			assign out[M-j]=a[N-j];
		end
	endgenerate
	
endmodule

module adderTree(
	input clock,
	input [31:0][63:0] a,
	output [1:0][63:0] out
	);

	wire [21:0][63:0] temp1,buffer1;
	wire [14:0][63:0] temp2,buffer2;
	wire [9:0][63:0] temp3,buffer3;
	wire [6:0][63:0] temp4,buffer4;
	wire [4:0][63:0] temp5,buffer5;
	wire [3:0][63:0] temp6,buffer6;
	wire [2:0][63:0] temp7,buffer7;

	carrySave #(32,22) CS1 (a,buffer1);
	D_flip_flop #(22*64) dff_1(clock,buffer1,temp1);
	
	carrySave #(22,15) CS2 (temp1,buffer2);
	D_flip_flop #(15*64) dff_2(clock,buffer2,temp2);
	
	carrySave #(15,10) CS3 (temp2,buffer3);
	D_flip_flop #(10*64) dff_3(clock,buffer3,temp3);
	
	carrySave #(10,7) CS4 (temp3,buffer4);
	D_flip_flop #(7*64) dff_4(clock,buffer4,temp4);
	
	carrySave #(7,5) CS5 (temp4,buffer5);
	D_flip_flop #(5*64) dff_5(clock,buffer5,temp5);
	
	carrySave #(5,4) CS6 (temp5,buffer6);
	D_flip_flop #(4*64) dff_6(clock,buffer6,temp6);
	
	carrySave #(4,3) CS7 (temp6,buffer7);
	D_flip_flop #(3*64) dff_7(clock,buffer7,temp7);
	
	carrySave #(3,2) CS8 (temp7,out);
	
endmodule

module WTM(
	input clock,
	input [31:0] A,
	input [31:0] B,
	output [63:0] C
	);
	
	wire [31:0][63:0]partial,temp;
	wire [1:0][63:0]out,buffer;
	
	mul M1(clock,A,B,temp);
	D_flip_flop #(32*64) dff_1(clock,temp,partial);

	adderTree At1(clock,partial,buffer);
	D_flip_flop #(2*64) dff_2(clock,buffer,out);
	
	assign C = out[1] + out[0];
	
endmodule
