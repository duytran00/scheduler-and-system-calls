#include "kernel/types.h"
#include "user/user.h"
#include "kernel/fcntl.h"
#include "kernel/pstat.h"
#include "kernel/stat.h"

int main() {

    int pid = fork();sleep(1);  
    if (pid == 0){
        setPriority(getpid(), -10);
        sleep(1000); 
        exit(0);  
    }

    int priorities[3] = {-20, 0, 20};
    int pid1 = fork();sleep(1);
    if (pid1 == 0) {
        printf("Child 1 priority %d. pid: %d\n", priorities[0], getpid());
        fprintf(1, "");
        //setPriority(getpid(), priorities[0]);
        //sleep(100);
        exit(0);    
    }

    int pid2 = fork();sleep(1);
    if (pid2 == 0) {
        
        printf("Child %d priority %d. pid: %d\n", 2, priorities[1], getpid());
        fprintf(1, "");
        //setPriority(getpid(), priorities[i+1]);
        //sleep(100);
        exit(0);    
    }

    int pid3 = fork();sleep(1);
    if (pid3 == 0) {
        
        printf("Child %d priority %d. pid: %d\n", 3, priorities[2], getpid());
        fprintf(1, "");
        //setPriority(getpid(), priorities[i+1]);
        //sleep(100);
        exit(0);    
    }

    sleep(1);
    exit(0);
}
