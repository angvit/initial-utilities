#include <stdio.h> 
#include <stdlib.h>
#include <string.h>


void encode(FILE *input, char *previous, int *rLen, int *firstFile){
    char current;
    
    if (*firstFile == 1){
        if (fread(previous, sizeof(char), 1, input) == 0){
            return;
        }
        *rLen = 1;
        *firstFile = 0;
    }
    
    while (fread(&current, sizeof(char), 1, input) == 1){
        if (current == *previous){
            (*rLen)++;
        } else {
            fwrite(rLen, sizeof(int), 1, stdout);  
            fwrite(previous, sizeof(char), 1, stdout); 

            *previous = current;
            *rLen = 1;
        }
    } 

}


int main(int argc, char *argv[]){
    if (argc == 1){
        printf("wzip: file1 [file2 ...]\n");
        exit(1);
    }

    char previous;
    int rLen = 0;
    int firstFile = 1;


    for (int i=1; i<argc; i++){
        FILE *fp = fopen(argv[i], "r");

        encode(fp, &previous, &rLen, &firstFile);
        fclose(fp);
    }

    fwrite(&rLen, sizeof(int), 1, stdout);  
    fwrite(&previous, sizeof(char), 1, stdout); 

    return 0;
}