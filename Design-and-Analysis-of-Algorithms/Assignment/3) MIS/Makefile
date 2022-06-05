all : main

obj/Greedy.o : src/Greedy.cpp
	g++ -c src/Greedy.cpp -o obj/Greedy.o

obj/DP.o : src/DP.cpp
	g++ -c src/DP.cpp -o obj/DP.o

obj/main.o : src/main.cpp
	g++ -c src/main.cpp -o obj/main.o

Greedy : obj/Greedy.o
	g++ obj/Greedy.o obj/main.o -o Greedy

DP : obj/DP.o
	g++ obj/DP.o obj/main.o -o DP

main : obj/main.o obj/DP.o obj/Greedy.o
	g++ obj/main.o obj/DP.o obj/Greedy.o -o main

