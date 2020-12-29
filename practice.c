#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

// void noMoreNewLine(char* theString){
//     char* isANewLine;

//     isANewLine = strrchr(theString, '\n');

//     if(isANewLine){
//         *isANewLine = '\0';
//     }
// }

// typedef struct product{
//     float price;
//     char productName[30];

//     struct product *next;
// } product;

// product *pFirstNode = NULL;
// product *pLastNode = NULL;

// void createNewList(){
//     product *pNewStruct = (product *)malloc(sizeof(product));

//     printf("Enter product name: ");
//     scanf("%s", &(pNewStruct)->productName);

//     printf("Enter product price: ");
//     scanf("%f", &(pNewStruct)->price);

//     pFirstNode = pLastNode = pNewStruct;
//     pNewStruct->next = NULL;
// }

// void inputData() {
//     if(pFirstNode == NULL){
//         createNewList();
//     } else {
//     product *pNewStruct = (product *) malloc(sizeof(product));

//     printf("Enter product name: ");
//     scanf("%s", &(pNewStruct)->productName);

//     printf("Enter product price: ");
//     scanf("%f", &(pNewStruct)->price);

//     if(pFirstNode == pLastNode){
//         pFirstNode->next = pNewStruct;
//         pLastNode = pNewStruct;
//         pNewStruct->next = NULL; 
//     } else {
//         pLastNode->next = pNewStruct;
//         pNewStruct->next = NULL;
//         pLastNode = pNewStruct;
//     }
//     } 
// }

// void outputData(){
//     product *pProducts = pFirstNode;

//     printf("Products Entered\n\n");
    
//     while(pProducts != NULL){
//         printf("%s costs %.2f\n\n", pProducts->productName, pProducts->price);
//         pProducts = pProducts->next;
//     }
// }

// product* pPToDelete = NULL;
// product* fSearchProduct(char* pName) {
//     product* pProduct = pFirstNode;
//     while(pProduct != NULL){
//         int isPresent = strncmp(pProduct->productName, pName, 30);
//         if(!isPresent){
//             printf("%s found with a price value of %.2f\n", pProduct->productName, pProduct->price);
//             return pProduct;
//         }
//         pPToDelete = pProduct;
//         pProduct = pProduct->next;
//     }

//     printf("Item not found! Did you enter the correct item?");
//     return NULL;
// }

// void removeProduct(char* pName){
//     product* pFound = NULL;
//     pFound = fSearchProduct(pName);

//     if(pFound != NULL){
//         if(pFound == pFirstNode){
//             pFirstNode = pFound->next;
//         } else {
//             pPToDelete->next = pFound->next;     
//         }
//         free(pFound);    
//     } else {
//         printf("%s not found!\n\n", pName);
//     }
    
// }

int fileWrite(){
    int randomNumber;

    FILE *pFile;

    pFile = fopen("randomNumbers.txt", "w"); // if the file wasn't open, it returns 1 otherwise 0

    if(!pFile){
        printf("Error: Couldn't write to File\n");
        return 1; // because an error occured and so end it
    }

    for(int i=0; i<10; i++){
        randomNumber = rand()%100;
        fprintf(pFile, "%d\n", randomNumber);
    }

    printf("Success Writing to File\n");

    if(fclose(pFile) != 0){ // must be closed to not run out of file handlers.
        printf("Error: File not closed!");
    }

    return 0;
}

int fileRead(){
    char readFileBuffer[1000];

    FILE *pFile;

    pFile = fopen("randomnumbers.txt", "r");

    if(!pFile){
        printf("Error: Couldn't read from file\n");
        return 1;
    }

    while(fgets(readFileBuffer, 1000, pFile) != NULL){
        printf("%s", readFileBuffer);
    }

    printf("Success read from File\n");

    if(fclose(pFile) != 0){
        printf("Error: Couldn't close the file\n");
    }

    return 0;
}

int main(int argc, char const *argv[])
{   
    // char* sizeofString = "Saurabh Srivastava";
    // printf("Size of integer is %d \n", sizeof(int));
    // printf("Size of double integer is %d \n", sizeof(double));
    // printf("Size of long integer is %d \n", sizeof(long int));
    // printf("Size of float is %d \n", sizeof(float));
    // printf("Size of char is %d \n", sizeof(char));
    // printf("Size of input string is %d \n", sizeof(sizeofString));
    // printf("Length of input string is %d \n", strlen(sizeofString));
    // printf("%s", sizeofString);
    
    // int numOfBits = 0;
    // printf("How many bits?\t");
    // scanf("%d", &numOfBits);
    // int bits = pow(2,numOfBits)-1;
    // printf("The largest number from %d number of bits can be %d", numOfBits, bits);
    
    // char* randomString = "This is just a random string with no worthwhile information.";

    // while(*randomString){
    //     putchar(*randomString++);
    // }
    
    // char randomString[100];
    // printf("Enter a string: ");
    // gets(randomString);
    // puts(randomString);
    // printf("Size of randomString : %d", sizeof(randomString));
    
    // char doYouWantToQuit[10];

    // printf("Enter quit to quit: ");

    // fgets(doYouWantToQuit, 10, stdin);

    // noMoreNewLine(doYouWantToQuit);

    // printf(doYouWantToQuit);
    
    // int numProduct;
    // printf("Enter number of Products: ");
    // scanf(" %d", &numProduct);
    // for(int i=0; i < numProduct; i++){
    //     inputData();
    // }
    
    // char deleteProduct[100];
    // printf("\n\nEnter product to be searched: ");
    // scanf(" %s", deleteProduct);
    // removeProduct(deleteProduct);
    // outputData();
    char buffer[1000];
    FILE *pFile;

    pFile = fopen("randomword.txt", "w+");

    if(!pFile){
        printf("Error");
        return 1;
    }

    fputs("This is just a random string", pFile);

    fseek(pFile, 0, SEEK_SET);

    fputs("r+ is not working for some reason", pFile);

    fseek(pFile, 0, SEEK_SET);

    while(fgets(buffer, 1000, pFile) != NULL){
        printf("%s", buffer);
        
    }

    if(fclose(pFile) != 0){
        return 1;
    }
    return 0;
}

