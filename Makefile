main :
	g++ Bplusmain.cpp -o main

Bplusmain.o: Bplusmain.cpp
	g++ -c Bplusmain.cpp

clean:
	rm -rf *o main
