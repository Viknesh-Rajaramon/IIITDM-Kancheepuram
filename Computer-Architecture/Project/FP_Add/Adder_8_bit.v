module fullAdder (a, bin, cin, sum, ca);
input a, bin, cin;
output sum, ca;

wire w1, w2, w3, w4, w5;
not(b,bin);
xor xor_0 (w1, a, b);
xor xor_1 (sum, w1, cin);

and and_0 (w2, a, b);
and and_1 (w3, a, cin);
and and_2 (w4, b, cin);
or  or_0 (w5, w2, w3);
or  or_1 (ca, w4, w5);

endmodule

module fourBitAdder (a, b, cin, sum, ca);
input [3:0] a, b;
input cin;

output [3:0] sum;
output ca;

wire c1, c2, c3;

fullAdder FA_0 (a[0], b[0], cin, sum[0], c1);
fullAdder FA_1 (a[1], b[1], c1, sum[1], c2);
fullAdder FA_2 (a[2], b[2], c2, sum[2], c3);
fullAdder FA_3 (a[3], b[3], c3, sum[3], ca);

endmodule


module eightBitAdder (a, b, cin, sum, ca);
input [7:0] a, b;
input cin;

output [7:0] sum;
output ca;

wire c1;

fourBitAdder p1(a[3:0], b[3:0], cin, sum[3:0], c1);
fourBitAdder p2(a[7:4], b[7:4], c1, sum[7:4], ca);

endmodule

