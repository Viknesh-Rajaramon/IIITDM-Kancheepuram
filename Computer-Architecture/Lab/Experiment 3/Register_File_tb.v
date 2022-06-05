`include "Register_File.v"

module top;

    reg [31:0] in;
    reg [4:0] select_in,select_out1,select_out2;
    reg write,read,enable,reset,clock;

    wire [31:0] out1,out2;

    initial
		begin
			$dumpfile("Register_File.vcd");
			$dumpvars(0,top);
		end
	
	initial
		begin
			in=32'b0;
			select_in=5'b0;
			select_out1=5'b0;
			select_out2=5'b0;
			read=1'b0;
			write=1'b0;
			reset=1'b0;
			enable=1'b0;
			clock=1'b0;
			
			#100
			reset=1'b0;
			enable=1'b1;
			
			#50
			write=1'b1;
			read=1'b0;
			in=32'habcdefab;
			select_in=5'd1;
			
			#50
			in=32'h01234567;
			select_in=5'd2;
			
			#50
			write=1'b0;
			read=1'b1;
			select_out1=5'd1;
			select_out2=5'd31;
			
			#400
			$finish;
		end

    register_file mem_reg_file(in,select_in,select_out1,select_out2,read,write,clock,enable,reset,out1,out2);

    always
    begin
        #10;
        clock=~clock;
    end

    initial
		$monitor("\n\t\tReset = %b\t\tEnable = %b\t\tRead = %b\t\tWrite = %b\n\t\tSource Address 1 = %b\tSource Address 2 = %b\t\tDestination Address = %b\n\t\tInput Data = %h\n\t\tData 1 = %h\n\t\tData 2 = %h",reset,enable,read,write,select_out1,select_out2,select_in,in,out1,out2);

endmodule
