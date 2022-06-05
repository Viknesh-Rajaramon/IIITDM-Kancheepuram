// Verilog
// c
// Ninputs 4
// Noutputs 2
// NtotalGates 5
// NAND2 5

module c (N1,N2,N3,N6,N22,N23);

input N1,N2,N3,N6;

output N22,N23;

wire N10,N11,N16,N19;

nand NAND2_1 (N10, N1, N3);
nand NAND2_2 (N11, N3, N6);
nand NAND2_3 (N16, N2, N11);
nand NAND2_4 (N22, N10, N16);
nand NAND2_5 (N23, N16, N19);

endmodule