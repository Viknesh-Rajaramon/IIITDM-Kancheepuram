module logic_u (a, b, select,out);
input [31:0] a,b;
input [2:0] select;
output reg [31:0] out;
always @(*)
begin
  case(select)
  3'b000    :   out= a&b;
  3'b001    :   out[31:0] = a[31:0] | b[31:0];
  3'b010    :   out= ~a & ~b;
  3'b011    :   out= ~a | ~b;
  3'b100    :   out= a^b;
  3'b101    :   out= ~(a^b);
  3'b110    :   out= ~a;
  endcase
end
endmodule
