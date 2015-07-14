#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "depend.h"

// the virtulization of memory

int main(int argc, char *argv[]){
    int *p =(int *)malloc(sizeof(int));
    assert( p!=NULL);
    printf("(pid:%d) addr of p (main):  %llx\n", (int) getpid(), (unsigned long long)p);
    printf("addr of p (main): %llx\n", (unsigned long long) main);
    *p =0;
    while(1){
        Spin(1);
        *p=*p+1;
        printf("(%d) p: %d\n",getpid(),*p);

    }
    return 0;
}