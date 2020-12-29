#include <stdio.h>
#include <stdlib.h>

typedef struct bstTree{
    struct bstTree *leftChildElement;
    int dataElement;
    struct bstTree *rightChildElement;
}bstTree;

bstTree* bstInput(int item){
    bstTree* temp = (bstTree* )malloc(sizeof(bstTree));
    temp->dataElement = item;
    temp->leftChildElement = temp->rightChildElement = NULL;
    return temp;
}

bstTree* insertion(bstTree* node, int item){
    if(node == NULL) return bstInput(item);
    if(item<node->dataElement) node->leftChildElement = insertion(node->leftChildElement, item);
    else if (item>node->dataElement) node->rightChildElement = insertion(node->rightChildElement, item);
    return node;
}

void postorder(bstTree* traverse){
    if(traverse!=NULL){
        postorder(traverse->leftChildElement);
        postorder(traverse->rightChildElement);
        printf("%d \n", traverse->dataElement);
    }
}


int main(){
    int testCases, numberOfElements;
    int bstArray[100000];
    bstTree* root = NULL;
    printf("Enter the number of test cases: ");
    scanf(" %d", &testCases);
    printf("Enter the number of elements to be inserted: ");
    scanf(" %d", &numberOfElements);
    if((testCases<1)||(testCases>100)||(numberOfElements<1)||(numberOfElements>100)){
        exit(1);
    }else{
        printf("Enter the elements: \n");
        for(int i=0; i<testCases; i++){
            for(int j=0; j<numberOfElements; j++){
                scanf(" %d", bstArray[j]);
                if(j==0){
                    root = insertion(root, bstArray[j]);
                }else{
                    insertion(root, bstArray[j]);
                }
            }
        }
    }

    postorder(root);
    
    return 0;
}