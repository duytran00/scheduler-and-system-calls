#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/pstat.h"


const char *state_names[] = {
  [UNUSED]    = "UNUSED",
  [SLEEPING]  = "SLEEPING",
  [RUNNABLE]  = "RUNNABLE",
  [RUNNING]   = "RUNNING",
  [ZOMBIE]    = "ZOMBIE"
};


int main(int argc, char *argv[])
{

  setPriority(getpid(), 20);

  struct pstat p;
  if (getpinfo(&p) < 0) {
    printf("Error: getpinfo failed\n");
    exit(1);
  }

  printf("NAME\tPID\tSTATUS\tPRIORITY\n");
  for (int i = 0; i < NPROC; i++) {
    if (p.inuse[i] != UNUSED) {
      printf("%s\t%d\t%s\t%d\n", p.name[i], p.pid[i], 
              state_names[p.state[i]], p.effective_priority[i]);
    }
  }
  
  exit(0);
}