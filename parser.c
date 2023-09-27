#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 10000

void removeChars(char *str, const char *charsToRemove) {
    int i, j;
    int len = strlen(charsToRemove);
    int strLen = strlen(str);

    for (i = 0; i < len; ++i) {
        char *src = str;
        char *dst = str;
        char currChar = charsToRemove[i];

        while (*src) {
            if (*src != currChar) {
                *dst++ = *src++;
            } else {
                ++src;
            }
        }

        *dst = '\0';
    }
}

int main() {
    FILE *file;
    char filename[] = "data.json";
    char *jsonString;
    long fileSize;

    // Open the JSON file in read mode
    file = fopen("example.json", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Get the file size
    fseek(file, 0, SEEK_END);
    fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

   // Allocate memory for the JSON string
    jsonString = (char *)malloc(fileSize * sizeof(char));
    if (jsonString == NULL) {
        printf("Memory allocation failed.\n");
        fclose(file);
        return 1;
    }

    // Read the JSON string from the file
    fread(jsonString, sizeof(char), fileSize, file);
    fclose(file); 

    // Remove unwanted characters
    const char charsToRemove[] = "{}[],\"";
    removeChars(jsonString, charsToRemove);

    // Print the cleaned JSON string
    printf("JSON Data:\n%s\n", jsonString);

    // Process the JSON data as needed
    
    // Cleanup
    free(jsonString);

    return 0;
}
