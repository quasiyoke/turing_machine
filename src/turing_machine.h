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


int Act(Machine*);

Machine* CreateMachine();

void FillTape(TapeSign*, int, char**);

void FreeMachine(Machine*);

void Iterate(Machine*, int);

void ReadTable(const char*, Action**);

void ShowState(const Machine*);


const State kNoState;

const int kStatesCountMax;

const int kSignsRange;

const int kTapeLength;


#endif /* TURING_MACHINE_H_ */
