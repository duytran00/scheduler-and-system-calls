#ifndef _PSTAT_H_
#define _PSTAT_H_

#include "param.h"
#include "process.h"

struct pstat {
  char name[NPROC][16];
  enum procstate state[NPROC];
  int inuse[NPROC];
  int effective_priority[NPROC];
  int real_priority[NPROC];
  int pid[NPROC];
  int ticks[NPROC];
};

#endif // _PSTAT_H_