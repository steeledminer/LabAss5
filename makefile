#
#This is the make file for main.cpp and dictionary.cpp
#
main : main.o	dictionary.o
	g++ main.o dictionary.o -o main

main.o : main.cpp
	g++ -c main.cpp

dictionary.o : dictionary.cpp
	g++ -c dictionary.cpp

clean :
	rm *.o main
