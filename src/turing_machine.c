/*
 * turing_machine.c
 *
 *  Created on: Oct 8, 2012
 *      Author: quasiyoke
 */

#include <stdlib.h>
#include <stdio.h>

#include "turing_machine.h"

int Act(Machine* pMachine) {
  pMachine->step++;

  Action* pAction =
    &pMachine->table[pMachine->state][(int) pMachine->tape[pMachine->offset]];

  if ((pMachine->state = pAction->state) == kNoState) {
    puts("Not defined situation reached.");
    return 0;
  }

  switch (pAction->sign) {
  case 'r':
  case 'R':
  case '>':
    if (kTapeLength <= ++pMachine->offset) {
      puts("End of tape reached.");
      return 0;
    }
    break;
  case 'l':
  case 'L':
  case '<':
    if (--pMachine->offset < 0) {
      puts("Beginning of tape reached.");
      return 0;
    }
    break;
  default:
    pMachine->tape[pMachine->offset] = pAction->sign;
    break;
  }

  return 1;
}

Machine* CreateMachine() {
  Machine* pMachine = (Machine*) malloc(sizeof(Machine));
  if ((pMachine->table = (Action**) malloc(kStatesCountMax * sizeof(Action*)))
      == NULL ) {
    exit(EXIT_FAILURE);
  }
  for (int i = 0; i < kStatesCountMax; i++) {
    if ((pMachine->table[i] = (Action*) malloc(kSignsRange * sizeof(Action)))
        == NULL ) {
      exit(EXIT_FAILURE);
    }
    for (int j = 0; j < kSignsRange; j++) {
      pMachine->table[i][j].state = kNoState;
    }
  }

  if ((pMachine->tape = (TapeSign*) malloc(sizeof(TapeSign) * kTapeLength))
      == NULL ) {
    exit(EXIT_FAILURE);
  }
  for (int i = 0; i < kTapeLength; i++) {
    pMachine->tape[i] = ' ';
  }

  pMachine->step = 0;

  return pMachine;
}

void FillTape(TapeSign* tape, int argc, char** argv) {
  int j = 0;
  for (int i = 0; i < argc && j < kTapeLength; i++) {
    char* arg = argv[i];
    while (j < kTapeLength && *arg) {
      char c = *arg++;
      if (c == '$' || c == '#') {
        c = ' ';
      }
      tape[j++] = c;
    }
    if (i + 1 < argc && j < kTapeLength) {
      tape[j++] = ' ';
    }
  }
}

void FreeMachine(Machine* pMachine) {
  for (int i = 0; i < kStatesCountMax; i++) {
    free(pMachine->table[i]);
  }
  free(pMachine->table);

  free(pMachine->tape);

  free(pMachine);
}

void Iterate(Machine* pMachine, int iterations_count) {
  do {
    ShowState(pMachine);
  } while (pMachine->step < iterations_count && Act(pMachine));
}

void ReadTable(const char* file_path, Action** table) {
  FILE* f = fopen(file_path, "r");
  int state;
  char sign;
  Action action;
  while (fscanf(f, "%d", &state) != EOF) {
    fgetc(f);
    sign = fgetc(f);
    fgetc(f);
    action.sign = fgetc(f);
    fgetc(f);
    fscanf(f, "%d", &action.state);
    table[state][(int) sign] = action;
    //printf("%d,%c,%c,%d\n", state, sign, action.sign, action.state);
  }
  fclose(f);
}

void ShowState(const Machine* pMachine) {
  printf("%3d, %02d: ", pMachine->step, pMachine->state);
  for (int i = 0; i < kTapeLength; i++) {
    putc(pMachine->tape[i], stdout);
  }
  puts("");

  for (int i = 0; i < 9 + pMachine->offset; i++) {
    printf(" ");
  }
  puts("^");
}


const State kNoState = -1;

const int kStatesCountMax = 0xff;

const int kSignsRange = 0xff;

const int kTapeLength = 70;
