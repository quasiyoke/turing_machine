#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "turing_machine.h"

const int kArgcMin = 5;


void ShowHelp(){
  puts("Usage: turing_machine -f ACTION_TABLE_FILE -n ITERATIONS_COUNT [OPTIONS]\n\n  -f\tPath to action table file.\n  -n\tHow much cycles will machine do.\n  -o\tStart tape offset.\n  -s\tInitial state.\n  -t\tInitial tape content. Use . (dot) for spaces.");
}


int main(int argc, char** argv) {
  char* file_path = NULL;
  int iterations_count = 0;
  Machine* pMachine = CreateMachine();

  int c;
  opterr = 0;
  int show_help = 0;
  while((c = getopt(argc, argv, "f:hn:o::s::t::")) != -1){
    switch(c){
    case 'f':
      file_path = optarg;
      break;
    case 'n':
      iterations_count = atoi(optarg);
      break;
    case 'o':
      pMachine->offset = atoi(optarg);
      break;
    case 's':
      pMachine->state = atoi(optarg);
      break;
    case 't':
      FillTape(pMachine->tape, optarg);
      break;
    case 'h':
      show_help = 1;
      break;
    default:
      errno = 1;
      break;
    }
  }
  if(show_help || errno || optopt || file_path == NULL || iterations_count <= 0){
    ShowHelp();
  }else{
    if(ReadTable(file_path, pMachine->table)){
      if (errno) {
        perror(file_path);
      } else {
        Iterate(pMachine, iterations_count);
      }
    }else{
      printf("File \"%s\" not found.\n", file_path);
    }
  }
  FreeMachine(pMachine);
  return errno;
}
