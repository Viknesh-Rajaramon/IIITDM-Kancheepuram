module Full_Adder(
    input a,
    input b,
    input cin,
    output sum,
    output cout
    );

    assign sum=a^b^cin;
    assign cout=((a&b) | (a&cin) | (b&cin));

endmodule

module Adder_Array #(parameter SIZE=64) (
    input [SIZE-1:0] a,
    input [SIZE-1:0] b,
    input [SIZE-1:0] cin,
    output [SIZE-1:0] sum,
    output [SIZE-1:0] cout
    );

    genvar i;

    generate
        assign sum[SIZE-1]=a[SIZE-1]^b[SIZE-1]^cin[SIZE-1];
        assign cout[0]=1'b0;

        for(i=0;i<SIZE-1;i=i+1)
        begin
            Full_Adder FA(a[i],b[i],cin[i],sum[i],cout[i+1]);
        end
    endgenerate

endmodule

module Carry_Save_Adder #(parameter N=32, M=22) (
    input clock,
    input [N-1:0][63:0] in,
    output [M-1:0][63:0] out
    );

    genvar i;

    wire [M-1:0][63:0] temp;

    generate
        for(i=0;i<N/3;i=i+1)
        begin
            Adder_Array addarr(in[3*i],in[3*i+1],in[3*i+2],temp[2*i],temp[2*i+1]);
        end

        for(i=1;i<=N%3;i=i+1)
        begin
            assign temp[M-i]=in[N-i];
        end
    endgenerate

    D_flip_flop #(M*64) dff(clock,temp,out);

endmodule

module Adder_Tree(
    input clock,
    input [31:0][63:0] in,
    output [1:0][63:0] out
    );

    wire [21:0][63:0] temp_1;
    wire [14:0][63:0] temp_2;
    wire [9:0][63:0] temp_3;
    wire [6:0][63:0] temp_4;
    wire [4:0][63:0] temp_5;
    wire [3:0][63:0] temp_6;
    wire [2:0][63:0] temp_7;
    wire [1:0][63:0] temp_8;

    Carry_Save_Adder #(32,22) CSA_1(clock,in,temp_1);
    Carry_Save_Adder #(22,15) CSA_2(clock,temp_1,temp_2);
    Carry_Save_Adder #(15,10) CSA_3(clock,temp_2,temp_3);
    Carry_Save_Adder #(10,7) CSA_4(clock,temp_3,temp_4);
    Carry_Save_Adder #(7,5) CSA_5(clock,temp_4,temp_5);
    Carry_Save_Adder #(5,4) CSA_6(clock,temp_5,temp_6);
    Carry_Save_Adder #(4,3) CSA_7(clock,temp_6,temp_7);
    Carry_Save_Adder #(3,2) CSA_8(clock,temp_7,temp_8);

    D_flip_flop #(2*64) dff(clock,temp_8,out);

endmodule