#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int getFibArgument(const char* str) {
    char temp[4];
    strncpy(temp, str, 3);
    if (strcmp(temp, "fib") != 0)
        return -1;

    const char* argumentStr = str + 4;

    int argument = 0;
    while (*argumentStr >= '0' && *argumentStr <= '9') {
        argument = argument * 10 + (*argumentStr - '0');
        argumentStr++;
    }

    return argument;
}


int main(int argc, char *argv[]) {
    void *addr;

    get("Integer n", &addr);
    int *n = (int*)addr;

    get("Array of n", &addr);
    int *array = (int*)addr;

    get("Index", &addr);
    int *index = (int*)addr;
    
    get("Indicator", &addr);
    int *indicator = (int*)addr;

    
    char command[20];
    printf("1. fib <n>\n2. latest\n3. pause\n4. resume\n5. end\n");

    while(1){
        gets(command, sizeof(command));
        if(command[strlen(command) - 1] == '\n')
            command[strlen(command) - 1] = '\0';
    

        if(strcmp(command, "latest") == 0){
            printf("Last counted number: %d\n", *index);
        }
        else if(getFibArgument(command) >= 0){
            if(getFibArgument(command) > *index){
                printf("Fib sequence of index %d still not counted, last counted: %d\n", getFibArgument(command), *index);
            }
            printf("Fib sequence of index %d = %d\n", getFibArgument(command), array[getFibArgument(command)]);
        }
        else if(strcmp(command, "pause") == 0){
            printf("Pausing...\n");
            *indicator = 1;
        }
        else if(strcmp(command, "resume") == 0){
            printf("Resuming...\n");
            *indicator = 0;
        }
        else if(strcmp(command, "end") == 0){
            *indicator = 2;
            exit();
        }
        else{
            printf("Uknown command!\n1. fib <n>\n2. latest\n3. pause\n4. resume\n5. end\n");
        }
    }
}

