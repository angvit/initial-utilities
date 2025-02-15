#include <stdio.h>
#include <stdlib.h>

void decode(FILE *input){
    int rLen;
    char ch;

    while (fread(&rLen, sizeof(int), 1, input) == 1){
        fread(&ch, sizeof(char), 1, input);

        for (int i=0; i<rLen; i++){
            fwrite(&ch, sizeof(char), 1, stdout);
        }
    }
}

int main(int argc, char *argv[]){
    if (argc == 1){
        printf("wunzip: file1 [file2 ...]\n");
        exit(1);
    }

    for (int i=1; i<argc; i++){
        FILE *fp = fopen(argv[i], 'r');
        decode(fp);
        fclose(fp);
    }
    
    return 0;
}