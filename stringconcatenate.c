#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100  // Maximum size for the individual strings

void concatenateStringArrays(char result[][MAX], char arr1[][MAX], char arr2[][MAX], int size) {
    for (int i = 0; i < size; i++) {
        strcpy(result[i], arr1[i]);    
        strcat(result[i], arr2[i]);   
    }
}

int main() {
    int size;
    printf("Enter the size of the arrays: ");
    scanf("%d", &size);

    
    char arr1[size][MAX];
    char arr2[size][MAX];
    char result[size][MAX];

  
    printf("Enter the strings for the first array:\n");
    for (int i = 0; i < size; i++) {
        printf("String %d: ", i + 1);
        scanf("%s", arr1[i]);
    }

  
    printf("Enter the strings for the second array:\n");
    for (int i = 0; i < size; i++) {
        printf("String %d: ", i + 1);
        scanf("%s", arr2[i]);
    }

   
    concatenateStringArrays(result, arr1, arr2, size);

    
    printf("Resulting concatenated array:\n");
    for (int i = 0; i < size; i++) {
        printf("%s\n", result[i]);
    }

    return 0;
}
