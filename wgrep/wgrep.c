#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    char buff[10000];

    if (argc == 1){
        printf("wgrep: searchterm [file ...]\n");
        exit(1);
    } else if (argc == 2){
        while(fgets(buff, sizeof(buff), stdin) != NULL){
            char *str = strstr(buff, argv[1]);
            if (str != NULL){
                printf("%s", buff);
            }
        }
    } else {
        if (argv[1] == "") {
            printf("");
            exit(0);
        }

        for (int i=2;i<argc;i++){
        FILE *fp = fopen(argv[i], "r");

        if (fp == NULL){
            printf("wgrep: cannot open file\n");
            exit(1);
        }
        
        while(fgets(buff, sizeof(buff), fp) != NULL){
            char *str = strstr(buff, argv[1]);
            if (str != NULL){
                printf("%s", buff);
            }
        }
        fclose(fp);
        }

    exit(0);
    }
    return 0;
}