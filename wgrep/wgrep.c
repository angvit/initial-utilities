#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void search_in_file(FILE *fp, char *search_term){
    char buffer[1000];

    while(fgets(buffer, sizeof(buffer), fp) != NULL){
        if(strstr(buffer, search_term)){
            printf("%s", buffer);
        }
    }
}

int main(int argc, char *argv[]){

    if (argc == 1){
        printf("wgrep: searchterm [file ...]\n");
        exit(1);
    } else if (argc == 2){
        search_in_file(stdin, argv[1]);
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
        search_in_file(fp, argv[1]);
        fclose(fp);
        }

    exit(0);
    }
    return 0;
}