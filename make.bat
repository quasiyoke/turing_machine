g++ -x c -std=c99 -Wall -c -o bin\main.o src\main.c
g++ -x c -std=c99 -Wall -c -o bin\turing_machine.o src\turing_machine.c
g++ -o bin\turing_machine.exe bin\turing_machine.o bin\main.o
