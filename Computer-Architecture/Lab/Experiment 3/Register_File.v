module register_file(
    input [31:0] in,
    input [4:0] select_input,
    input [4:0] select_output_1,
    input [4:0] select_output_2,
    input read,
    input write,
    input clock,
    input enable,
    input reset,
    output reg [31:0] data_1,
    output reg [31:0] data_2
    );

    reg [31:0] register_file [31:0];

    integer i;

    initial
    begin
        for(i=0;i<=31;i=i+1)
            register_file[i]=32'b0;
    end

    always @(posedge clock)
    begin
        if(enable==1'b1)
        begin
            if(reset==1'b1)
            begin
                for(i=0;i<=31;i=i+1)
                    register_file[i]=32'h0;
            end
            
            else
            begin
                if(read==1'b1)
                begin
                    data_1=register_file[select_output_1];
                    data_2=register_file[select_output_2];
                end

                else if(write==1'b1)
                begin
                    register_file[select_input]=in;
                end
                
                else
                ;
            end
        end

        else
        ;
    end

endmodule