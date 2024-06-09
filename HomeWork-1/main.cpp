#include <stdio.h>
#include <stdlib.h>

void scanfInteger(char* string, int* num){
    int scanResult;
    do {
        printf("%s\n", string);
        scanResult = scanf("%d", num);
        if (scanResult != 1) {
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF);
        }
    } while (scanResult != 1);
}

// Function to allocate array and take size input
int* allocateAndInput(int* size) {
    char* input = "Enter array size: ";
    char enterNum[50]; // Buffer for prompt string with index
    scanfInteger(input, size);
    int byteLength = *size * sizeof(int);
    int* list = (int*)malloc(byteLength);
    if (list == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < *size; i++) {
        sprintf(enterNum, "Enter a number at index %d: ", i);
        scanfInteger(enterNum, &list[i]);
    }

    return list;
}

int main() {
    int size;
    int* list = allocateAndInput(&size);
    for (int i = 0; i < size; i++){
        printf("%d ", list[i]); // Adding space for better readability
    }
    printf("\n");
    free(list);

    return 0;
}
