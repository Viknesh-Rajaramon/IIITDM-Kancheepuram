`include "Dadda_Multiplier.v"

module top;
    
    reg [15:0] a,b;
    wire [31:0] out;
    
    initial
		begin
			$dumpfile("Dadda_Multiplier_16bit.vcd");
			$dumpvars(0,top);
		end

    initial
    begin
        a= 16'd15; b= 16'd5;
        #10 a= 16'd1000; b= 16'd1000;
        #10 a= 16'd96; b= 16'd9999;
        #10 a= 16'd1024; b= 16'd250;
        #10 a= 16'd13; b= 16'd255;   
    end
    
    Dadda_Multiplier DM(a,b,out);

    initial
    begin
        $monitor("a= %d\tb= %d\tout= %d\n",a,b,out);  
    end

endmodule
