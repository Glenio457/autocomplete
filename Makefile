all: bin/autocompletar

bin/autocompletar: bin/main.o bin/autocompletar.o bin/termo.o bin/lista.o
	mkdir -p bin
	g++ -o bin/autocompletar bin/main.o bin/autocompletar.o bin/termo.o bin/lista.o -Wall

bin/main.o: src/main.cpp include/autocompletar.h include/termo.h include/lista.h
	mkdir -p bin
	g++ -c src/main.cpp -o bin/main.o

bin/autocompletar.o: src/autocompletar.cpp include/autocompletar.h
	mkdir -p bin
	g++ -c src/autocompletar.cpp -o bin/autocompletar.o

bin/termo.o: src/termo.cpp include/termo.h
	mkdir -p bin
	g++ -c src/termo.cpp -o bin/termo.o

bin/lista.o: src/lista.cpp include/lista.h include/termo.h
	mkdir -p bin
	g++ -c src/lista.cpp -o bin/lista.o

clean:
	rm -rf bin