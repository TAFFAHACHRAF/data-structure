#include <stdio.h>
#include <stdlib.h>

int* createArray(int size){
    int* tab = malloc(size * sizeof(int));
    for(int i = 0; i < size; i++){
        printf("Enter element %d: ", i + 1);
        scanf("%d", &tab[i]);
    }
    return tab;
}

void deleteElement(int* array, int size, int element) {
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] == element) {
            found = 1;
            break;
        }
    }
    if(found){
        int shiftIndex = 0;
        for (int i = 0; i < size; i++) {
            if (array[i] != element) {
                array[shiftIndex] = array[i];
                shiftIndex++;
            }
        }
        size--;
        array = realloc(array, size * sizeof(int));
    }
}

int searchElement(int* array, int size, int element){
    for(int i = 0; i < size; i++) {
        if(array[i] == element)
            return 1;
    }
    return 0;
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int* array = createArray(size);

    int element;
    printf("Enter the element to delete: ");
    scanf("%d", &element);

    deleteElement(array, size, element);

    int search;
    printf("Enter the element to search: ");
    scanf("%d", &search);

    int found = searchElement(array, size, search);
    if (found)
        printf("Element found in the array.\n");
    else
        printf("Element not found in the array.\n");

    free(array);

    return 0;
}
