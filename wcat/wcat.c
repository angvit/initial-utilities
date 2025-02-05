#include <stdio.h> 
#include <stdlib.h>

int main(int argc, char *argv[]){
    if (argc == 1){
        printf("");
        exit(0);
    }

    for (int i=1; i<argc; i++){
        FILE *fp = fopen(argv[i], "r");

        if (fp == NULL){
            printf("wcat: cannot open file\n");
            exit(1);
        }
        
        char buff[10000];
        
        while (fgets(buff, sizeof(buff), fp) != NULL){
            printf("%s", buff);
        }
        fclose(fp);
    }
    return 0;
}