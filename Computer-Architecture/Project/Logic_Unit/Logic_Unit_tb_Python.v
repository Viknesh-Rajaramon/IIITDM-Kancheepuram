`include "Logic_Unit.v"
module top;

reg [2:0]sel;
reg [31:0] a, b;
wire [31:0] out;

logic_u u1(a,b,sel,out);

initial
begin
sel=3'b^;
a=32'h&;
b=32'h!;
end

initial $monitor($time,"\t %d \n",out);
endmodule
