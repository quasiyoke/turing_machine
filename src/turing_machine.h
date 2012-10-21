#ifndef TURING_MACHINE_H_
#define TURING_MACHINE_H_


typedef char TapeSign;

typedef int State;

typedef struct {
  TapeSign sign;
  State state;
} Action;

typedef struct {
  Action** table;
  TapeSign* tape;
  State state;
  int offset;
  int step;
} Machine;


int Act(Machine*, int);

Machine* CreateMachine();

void FillTape(TapeSign*, char*);

void FreeMachine(Machine*);

void Iterate(Machine*, int, int);

int ReadTable(const char*, Action**);

void ReadTape(TapeSign*, FILE*);

void ShowState(const Machine*, int);


const State kNoState;

const int kStatesCountMax;

const int kSignsRange;

const int kTapeLength;


#endif /* TURING_MACHINE_H_ */
