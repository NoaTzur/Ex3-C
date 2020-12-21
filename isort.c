#include <stdio.h>
#define numOfElements 50
#define buffLen 120

void shift_element(int *arr, int i){

    while(i>0){  
        *(arr + i) = *(arr+i-1); // (arr+i-1) is the last element in the arr (if i=3 in the begining- we want to begin with the element in index 2 and shift it to index 3)
        i--;    
    }
}



void insertion_sort(int *arr, int len){
    int j;
    int tempKey;
    for(int i=1; i<len; i++){
        tempKey = *(arr+i);
        j = i-1;
        while(j>=0 && *(arr+j) > tempKey){
            shift_element((arr+j), 1);
            *(arr+j) = tempKey;
            j--;
        }
    }
        
}
/*
void fromUser(int *arr, int len){
    for(int i=0; i<len; i++){
        printf("please enter number");
        scanf("%d", arr+i);
        
    }
}
*/

void printArray(int *arr, int len){

    for(int i=0; i<len-1; i++){
        printf("%d,", *(arr+i));
    }
    printf("%d", *(arr+len-1));
}

int main(int argc, char const *argv[]) {

    int numArray[numOfElements];
    for(int i=0; i<numOfElements; i++)
    {
    	fscanf(stdin, "%2d", numArray+i);
    }
    
    insertion_sort(numArray, numOfElements);
    printArray(numArray, numOfElements);
    
    return 0;
}
