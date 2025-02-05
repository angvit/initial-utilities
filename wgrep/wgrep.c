#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    if (argc == 1){
        printf("wgrep: searchterm [file ...]\n");
        exit(1);
    }

    for (int i=0;i<argc;i++){
        FILE *fp = fopen(argv[i], "r");

        if (fp == NULL){
            printf("wgrep: cannot open file\n");
            exit(1);
        }
    }

    return 0;
}