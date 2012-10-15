#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#include "turing_machine.h"


const int kArgcMin = 5;


void ShowHelp(){
	puts("Using: PATH_TO_ACTION_TABLE_FILE STATE OFFSET ITERATIONS_COUNT [INITIAL_TAPE_CONTENT]");
}


int main(int argc, char** argv) {
	if (argc < kArgcMin) {
		ShowHelp();
	} else {
		Machine* pMachine = CreateMachine();

		char* file_path = argv[1];
		pMachine->state = atoi(argv[2]);
		pMachine->offset = atoi(argv[3]);
		int iterations_count = atoi(argv[4]);
		FillTape(pMachine->tape, argc - kArgcMin, argv + kArgcMin);

		ReadTable(file_path, pMachine->table);
		if (errno) {
			perror(file_path);
		} else {
			Iterate(pMachine, iterations_count);
		}

		FreeMachine(pMachine);
	}
	return errno;
}
