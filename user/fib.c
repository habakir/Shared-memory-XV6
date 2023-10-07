#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"


int main(int argc, char *argv[]) {
    
    int prev = 0, cur = 1;
    long long res = 0;
    void *addr;

    get("Integer n", &addr);
    int *n = (int*)addr;

    get("Array of n", &addr);
    int *array = (int*)addr;

    get("Index", &addr);
    int *index =(int*)addr;

    get("Indicator", &addr);
    int *indicator =(int*)addr;

    sleep(50);

    if(*n <= 1){
        *index = *n;
        array[*n] = *n;
        printf("Uspesno izracunat fib od %d\n", *n, *n);
        while(*indicator != 2){

        }
        if(*indicator == 2){
            exit();
        }
    }
    for(int i = 2; i <= *n; i++){
        array[0] = 0;
        array[1] = 1;
        res = prev + cur;
        prev = cur;
        cur = res;
        array[i] = res;
        *index = i;
        sleep(100);
        if(*indicator == 1){
            while(*indicator == 1){
                sleep(1);
            }
        }
        if(*indicator == 2){
            exit();
        }
    }
    printf("Uspesno izracunat fib do %d\n", *n);
    while(*indicator != 2){

    }
    if(*indicator == 2){
        exit();
    }
}
