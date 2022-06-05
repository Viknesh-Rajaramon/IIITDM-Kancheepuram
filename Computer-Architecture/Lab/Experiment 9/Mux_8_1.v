module mux_2_1(
    input [31:0] in1,
    input [31:0] in2,
    input select,
    output [31:0] out
);

    assign out = ((select == 1'b0) ? in1 : in2);

endmodule

module mux_8_1(
    input [31:0] in0,
    input [31:0] in1,
    input [31:0] in2,
    input [31:0] in3,
    input [31:0] in4,
    input [31:0] in5,
    input [31:0] in6,
    input [31:0] in7,
    input [2:0] select,
    output [31:0] out
);

    wire [31:0] temp1,temp2,temp3,temp4,temp5,temp6;

    mux_2_1 mux1(in0,in1,select[0],temp1);
    mux_2_1 mux2(in2,in3,select[0],temp2);
    mux_2_1 mux3(in4,in5,select[0],temp3);
    mux_2_1 mux4(in6,in7,select[0],temp4);

    mux_2_1 mux5(temp1,temp2,select[1],temp5);
    mux_2_1 mux6(temp3,temp4,select[1],temp6);

    mux_2_1 mux7(temp5,temp6,select[2],out);

endmodule