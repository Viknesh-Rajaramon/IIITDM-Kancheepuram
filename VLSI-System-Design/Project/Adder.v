module half_adder(
	input a,
	input b,
	output sum,
	output carry
	);

	assign sum=(a^b);
	assign carry=(a&b);

endmodule

module full_adder(
	input a,
	input b,
	input cin,
	output sum,
	output cout
	);

    assign sum=(a^b^cin);
    assign cout=((a&b)|(b&cin)|(a&cin));

endmodule
