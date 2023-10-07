#include "kernel/types.h"
#include "user.h"


int main(int argc, char *argv[]) {
   /* void* addr1 = (void*)0x20000000;
    void* addr2 = (void*)0x30000000;
    void* addr3 = (void*)0x35000000;
    char* name1 = "struktura1dasdasdasdsa";
    char* name2 = "struktura2";
    char* name3 = "struktura3";
    char* name4 = "dsadsadasda";
    int size = sizeof(4096);
    int size2 = sizeof(8192);
    int size3 = sizeof(2048);*/
    int n = 5;


    share("proba", &n, 4);
    void* dsa;

    get("proba", &dsa);

    printf("%d\n",*((int*)dsa));
    /*if(share(&name1, &addr1, size) < 0){
        printf("Nije uspesno kreirana struktura 1\n");
    }
    else{
        printf("Uspesno kreirana struktura 1\n");
    }

    if(share(&name2, &addr2, size2) < 0){
        printf("Nije uspesno kreirana struktura 2\n");
    }
    else{
        printf("Uspesno kreirana struktura 2\n");
    }

    if(share(&name3, &addr3, size3) < 0){
        printf("Nije uspesno kreirana struktura 3\n");
    }
    else{
        printf("Uspesno kreirana struktura 3\n");
    }


    if(get(&name1, &addr1) < 0){
        printf("Nije uspesno izvucena struktura 1\n");
    }
    else
        printf("Uspesno izvucena struktura 1\n");
        
    if(get(&name2, &addr2) < 0){
        printf("Nije uspesno izvucena struktura 2\n");
    }
    else
        printf("Uspesno izvucena struktura 2\n");

    if(get(&name3, &addr3) < 0){
        printf("Nije uspesno izvucena struktura 3\n");
    }
    else
        printf("Uspesno izvucena struktura 3\n");*/
    
    exit();
}

