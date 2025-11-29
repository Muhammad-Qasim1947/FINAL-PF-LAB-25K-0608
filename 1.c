// Q1: Create a recursive function that a concatenated string using a pointer (the two strings are
// passed by reference) and then returns the concatenated strings' starting address. You are not
// allowed to use concat() function.
// Suggested function declaration: char* recursiveConcat(char *dest, char sre)


#include <stdio.h>

char* recursiveconcat(char *dest , char *src){
    if (*dest != '\0'){
        return recursiveconcat(dest + 1 , src);
    }
    
    if (*src == '\0'){
        *dest = '\0';
        return dest ;
    }

    *dest = *src;

    recursiveConcat(dest + 1, src + 1);

    return dest;
    
}

int main(){
    char dest[50] = "HELLO";
    char src[50] = "WORLD";

    char result = recursiveconcat(dest , src);
    printf("%s", result);

    return ;
}