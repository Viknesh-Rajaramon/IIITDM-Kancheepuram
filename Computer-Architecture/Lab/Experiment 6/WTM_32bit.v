`include "Adder.v"
`include "CLA_64bit.v"

module WTM_32bit(
    input clock,
    input [31:0] a,
    input [31:0] b,
    output [31:0] product
    );

    genvar i;

    wire [31:0][63:0] partial_product,temp;
    wire [63:0] product_64bit,buffer;
    wire [1:0][63:0] out;
    wire cout;

    generate
        for(i=0;i<32;i=i+1)
        begin
            assign temp[i]=(a&{64{b[i]}})<<i;
        end
    endgenerate

    D_flip_flop #(32*64) dff_1(clock,temp,partial_product);

    Adder_Tree add_tree(clock,partial_product,out);
    
    CLA_64bit CLA(clock,out[1],out[0],buffer,cout);

    D_flip_flop #(64) dff_2(clock,buffer,product_64bit);

    assign product[0]=product_64bit[0];
	assign product[1]=product_64bit[1];
	assign product[2]=product_64bit[2];
	assign product[3]=product_64bit[3];
	assign product[4]=product_64bit[4];
	assign product[5]=product_64bit[5];
	assign product[6]=product_64bit[6];
	assign product[7]=product_64bit[7];
	assign product[8]=product_64bit[8];
	assign product[9]=product_64bit[9];
	assign product[10]=product_64bit[10];
	assign product[11]=product_64bit[11];
	assign product[12]=product_64bit[12];
	assign product[13]=product_64bit[13];
	assign product[14]=product_64bit[14];
	assign product[15]=product_64bit[15];
	assign product[16]=product_64bit[16];
	assign product[17]=product_64bit[17];
	assign product[18]=product_64bit[18];
	assign product[19]=product_64bit[19];
	assign product[20]=product_64bit[20];
	assign product[21]=product_64bit[21];
	assign product[22]=product_64bit[22];
	assign product[23]=product_64bit[23];
	assign product[24]=product_64bit[24];
	assign product[25]=product_64bit[25];
	assign product[26]=product_64bit[26];
	assign product[27]=product_64bit[27];
	assign product[28]=product_64bit[28];
	assign product[29]=product_64bit[29];
	assign product[30]=product_64bit[30];
	assign product[31]=product_64bit[31];

endmodule