#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"



int main(int argc, char *argv[]) {
    int n;
    if(argc > 1)
        n = atoi(argv[1]);
    else
        n = 10000;

    share("Integer n", &n, sizeof(int));

    int array[n];
    share("Array of n", &array, sizeof(int));
    
    int index = 0;
    share("Index", &index, sizeof(int));

    int indicator = 0;
    share("Indicator", &indicator, sizeof(int));

    int comm = fork();
    if(comm < 0){
        printf("Comm failed");
        exit();
    }
    if(comm == 0){
        char *args[] = {"/bin/comm", 0};
        exec("/bin/comm", args);
    }

    int fib = fork();
    if(fib < 0){
        printf("Fork failed");
        exit();
    }
    if(fib == 0){
        char *args[] = {"/bin/fib", 0};
        exec("/bin/fib", args);
    }

    wait();
    wait();

    exit();
}
