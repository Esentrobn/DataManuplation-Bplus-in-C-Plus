# DataManuplation-Bplustree-in-C-Plus-Plus

      Instruction to run project through Makefile with g++ command on a unix system
      
 input          > g++ Bplusmain.cpp 
 input          > make 
              
   displayed by the compiler(output)              <    g++ Bplusmain.cpp -o main
                     
input  > main 
 
      
                          Make file content
      
main :
	g++ Bplusmain.cpp -o main

Bplusmain.o: Bplusmain.cpp
	g++ -c Bplusmain.cpp

clean:
	rm -rf *o main
