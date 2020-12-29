#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(void){
    char message[1000];
    printf("Enter the full message to be encrypted: ");
    gets(message);
    
    FILE *pFile;

    pFile = fopen("encrypted.bin", "rb+");

    if(pFile == NULL){
        perror("Error Occured");
        printf("Error Code: %d\n", errno);

        printf("File is being created...");
        printf("\n");
        pFile = fopen("encrypted.bin", "wb+");

        if(pFile == NULL){
            perror("Error Occured");
            printf("Error Code: %d", errno);
            exit(1);
        }
        fwrite(message, sizeof(message[0]), sizeof(message)/sizeof(message[0]), pFile);

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
        size_t dataInFile;
        dataInFile = fread(buffer, 1, fileSize, pFile);

        if(dataInFile != fileSize){
            perror("Error Occured\n");
            printf("Error Code: %d\n", errno);
            exit(3);
        }

        FILE *anotherFile;
        anotherFile = fopen("anotherEncFile.txt", "w");
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

        printf("\nEncrypted file has been created with your entered message.\n");
    }
}