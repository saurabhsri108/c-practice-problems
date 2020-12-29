#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(void){

    FILE *pFile;
    size_t dataInFile;

    pFile = fopen("randomFile.bin", "rb+");

    if(pFile == NULL){
        perror("Error Occured");
        printf("Error Code: %d\n", errno);

        printf("FILE is being created...");

        pFile = fopen("randomFile.bin", "wb+");

        if(pFile == NULL){
            perror("Error Occured\n");
            printf("Error Code: %d\n", errno);
            exit(1);
        }
    }

    char name[] = "Saurabh Srivastava";
    //To write binary data to file - fwrite()
    fwrite(name, sizeof(name[0]), sizeof(name)/sizeof(name[0]),pFile);

    fseek(pFile, 0, SEEK_END);
    long fileSize = ftell(pFile);

    rewind(pFile);
    char* buffer;
    buffer = (char*)malloc(sizeof(char)*fileSize);

    if(buffer == NULL){
        perror("Error Occured\n");
        printf("Error Code: %d\n", errno);
        exit(2);
    }

    dataInFile = fread(buffer, 1, fileSize, pFile);

    if(dataInFile != fileSize){
        perror("Error Occured\n");
        printf("Error Code: %d\n", errno);
        exit(3);
    }

    FILE *anotherFile;
    anotherFile = fopen("anotherFile.txt", "w");
    if(!anotherFile){
        printf("Error");
        return 1;
    }

    fputs(buffer, anotherFile);

    fseek(pFile, 0, SEEK_SET);

    if(fclose(pFile) != 0){
        return 1;
    }
    printf("%s\n\n", buffer);

    fclose(pFile);
    free(buffer);
}