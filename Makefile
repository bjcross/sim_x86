x86: main.o if.o id.o ex.o mem.o wb.o
	g++ -o x86 main.o x86.o -std=c++11

main.o: main.cpp main.h
	g++ -o main.cpp -std=c++11 main.o

if.o: if.cpp main.h
	g++ -o if.cpp -std=c++11 if.o

id.o: id.cpp main.h
	g++ -o id.cpp -std=c++11

ex.o: ex.cpp main.h
	g++ -o ex.cpp -std=c++11

mem.o: mem.cpp main.h
	g++ -o mem.cpp -std=c++11

wb.o: wb.cpp main.h
	g++ -o wb.cpp -std=c++11

clean:
	rm *.o x86
