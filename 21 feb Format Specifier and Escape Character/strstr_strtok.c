#include <stdio.h>
#include <string.h>

int main() {
    //strstr.. The strstr function is used to find the first occurrence of a substring within a string. It returns a pointer to the beginning of the first occurrence of the substring or NULL if the substring is not found.
    const char *str = "Hello, World!";
    const char *substr = "World";

    // Find the first occurrence of "World" in "Hello, World!"
    char *result = strstr(str, substr);

    if (result) {
        printf("Substring found at position: %ld\n", result - str);  // Position in string
        printf("Substring: %s\n", result);  // Output: World!
    } else {
        printf("Substring not found\n");
    }
    
    //strtok.. The strtok function is used to tokenize (split) a string into a series of tokens (substrings) based on delimiters. It modifies the original string by replacing the delimiters with '\0' (null character).
    
    char strr[] = "apple,orange,banana,grape";
    const char *delim = ",";  // Comma is the delimiter

    // Get the first token
    char *token = strtok(strr, delim);

    // Continue getting the rest of the tokens
    int i=1;
    while (token != NULL) {
        printf("Token:%d %s\n", i,token);
        token = strtok(NULL, delim);  // Pass NULL to continue tokenizing
        i++;
    }

    return 0;
}
