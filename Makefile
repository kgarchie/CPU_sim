all: scheduling

scheduling: main.o scheduler.o processor.o pcb.o
	g++ main.o scheduler.o processor.o pcb.o -o scheduling

main.o: main.cpp
	g++ -c main.cpp

scheduler.o: scheduler.cpp scheduler.h
	g++ -c scheduler.cpp

processor.o: processor.cpp processor.h
	g++ -c processor.cpp

pcb.o: pcb.cpp pcb.h
	g++ -c pcb.cpp

clean:
	rm -rf *o scheduling