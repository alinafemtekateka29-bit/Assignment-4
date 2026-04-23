#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to print the dictionary
void printDictionary(char **list, int size) {
    for (int i = 0; i < size; i++) {
        printf("[%d] %s\n", i, list[i]);
    }
}

// Function to search for a word
int searchWord(char **list, int size, const char *word) {
    for (int i = 0; i < size; i++) {
        if (strcmp(list[i], word) == 0) {
            return i;
        }
    }
    return -1;
}

// Function to modify a word at a specific index
void modifyWord(char **list, int index, const char *newWord) {
    // Free the old memory
    free(list[index]);
    // Allocate new memory for the new word
    list[index] = (char*)malloc(strlen(newWord) + 1);
    strcpy(list[index], newWord);
}

// Function to delete a word by value
void deleteWord(char **list, int *size, const char *word) {
    int index = searchWord(*&list, *size, word);
    if (index != -1) {
        // Free the memory of the word to delete
        free(list[index]);
        
        // Shift all following elements one position to the left
        for (int i = index; i < (*size) - 1; i++) {
            list[i] = list[i + 1];
        }
        
        (*size)--;
    }
}

int main() {
    // Initial words to store
    const char *initialWords[] = {"alpha", "bravo", "charlie", "delta", "echo"};
    int capacity = 5;
    int size = 5;
    
    // Allocate memory for the list of pointers
    char **dictionary = (char**)malloc(capacity * sizeof(char*));
    
    // Allocate memory for each word and copy the string
    for (int i = 0; i < size; i++) {
        dictionary[i] = (char*)malloc(strlen(initialWords[i]) + 1);
        strcpy(dictionary[i], initialWords[i]);
    }
    
    // 1. Print initial dictionary
    printf("[Initial Dictionary]\n");
    printDictionary(dictionary, size);
    printf("\n");
    
    // 2. Search for "delta"
    const char *searchWordStr = "delta";
    int foundIndex = searchWord(dictionary, size, searchWordStr);
    printf("[Search Result]\n");
    if (foundIndex != -1) {
        printf("%s found at index %d\n", searchWordStr, foundIndex);
    } else {
        printf("%s not found\n", searchWordStr);
    }
    printf("\n");
    
    // 3. Modify word at index 1 from "bravo" to "blueberry"
    modifyWord(dictionary, 1, "blueberry");
    printf("[After Update]\n");
    printDictionary(dictionary, size);
    printf("\n");
    
    // 4. Delete the word "charlie"
    deleteWord(dictionary, &size, "charlie");
    printf("[After Delete]\n");
    printDictionary(dictionary, size);
    
    // Free all remaining allocated memory
    for (int i = 0; i < size; i++) {
        free(dictionary[i]);
    }
    free(dictionary);
    
    return 0;
}