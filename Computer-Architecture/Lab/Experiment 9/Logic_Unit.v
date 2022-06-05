`include "Bitwise_Operations_32bit.v"
`include "Mux_8_1.v"

module logic_unit(
    input [31:0] in1,
    input [31:0] in2,
    input [2:0] select,
    output [31:0] out
);

    // 000 - AND
    // 001 - XOR
    // 010 - NAND
    // 011 - OR
    // 100 - NOT
    // 101 - NOR
    // 110 - 2's COMPLEMENT
    // 111 - XNOR
    
    wire [31:0] out0,out1,out2,out3,out4,out5,out6,out7;

    and_gate_32_bit and_000(in1,in2,out0);

    xor_gate_32_bit xor_001(in1,in2,out1);

    nand_gate_32_bit nand_010(in1,in2,out2);
    
    or_gate_32_bit or_011(in1,in2,out3);

    not_gate_32_bit not_100(in1,out4);

    nor_gate_32_bit nor_101(in1,in2,out5);

    complement_2s_32_bit complement_2s_110(in1,out6);

    xnor_gate_32_bit xnor_111(in1,in2,out7);

    mux_8_1 mux(out0,out1,out2,out3,out4,out5,out6,out7,select,out);

endmodule