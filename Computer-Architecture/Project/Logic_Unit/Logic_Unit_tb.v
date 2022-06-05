`include "Logic_Unit.v"
module top;

reg [2:0]sel;
reg [31:0] a, b;
wire [31:0] out;

logic_u u1(a,b,sel,out);

initial
begin
sel=3'b100;
a=32'h00000001;
b=32'h00000062;
end

initial $monitor($time,"\t %d \n",out);
endmodule
