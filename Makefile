x86: main.o if.o id.o ex.o mem.o wb.o
	g++ -o x86 main.o frac.o

main.o: main.cpp main.h
	g++ -c main.cpp

if.o: if.cpp main.h
	g++ -c if.cpp

id.o: id.cpp main.h
	g++ -c id.cpp

ex.o: ex.cpp main.h
	g++ -c ex.cpp

mem.o: mem.cpp main.h
	g++ -c mem.cpp

wb.o: wb.cpp main.h
	g++ -c wb.cpp

clean:
	rm *.o x86
