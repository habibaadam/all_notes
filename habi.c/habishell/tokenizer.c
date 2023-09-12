#include <unistd.h>
#include <string.h>

char* my_strtok(char* str, const char* delimiters) {
    static char* lastToken;  // Pointer to the last token
    
    char* tokenStart;
    char* tokenEnd;
    
    if (str != NULL) {
        lastToken = str;
    }
    
    if (lastToken == NULL) {
        return NULL;
    }
    
    tokenStart = lastToken + strspn(lastToken, delimiters);
    
    if (*tokenStart == '\0') {
        lastToken = NULL;
        return NULL;
    }
    
    tokenEnd = tokenStart + strcspn(tokenStart, delimiters);
    
    if (*tokenEnd != '\0') {
        *tokenEnd = '\0';
        lastToken = tokenEnd + 1;
    } else {
        lastToken = NULL;
    }
    
    return tokenStart;
}

int main() {
    char str[] = "Hello, world! This is a test.";
    const char delimiters[] = " ,.!";

    char* token;
    ssize_t bytesWritten;
    size_t tokenLength;
    
    token = my_strtok(str, delimiters);
    while (token != NULL) {
        tokenLength = strlen(token);
        bytesWritten = write(STDOUT_FILENO, "Token: ", sizeof("Token: ") - 1);
        if (bytesWritten < 0) {
            return 1;
        }
        bytesWritten = write(STDOUT_FILENO, token, tokenLength);
        if (bytesWritten < 0) {
            return 1;
        }
        bytesWritten = write(STDOUT_FILENO, "\n", 1);
        if (bytesWritten < 0) {
            return 1;
        }
        token = my_strtok(NULL, delimiters);
    }
    
    return 0;
}
