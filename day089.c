//Write a C program to check whether two strings are anagrams of each other. Two strings are anagrams if they contain the same characters with the same frequency, regardless of their order.
#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100];
    int freq1[256] = {0}, freq2[256] = {0};

    printf("Enter first string: ");
    scanf("%s", str1);

    printf("Enter second string: ");
    scanf("%s", str2);

    if(strlen(str1) != strlen(str2)) {
        printf("The strings are not anagrams.\n");
        return 0;
    }

    for(int i = 0; str1[i] != '\0'; i++) {
        freq1[(unsigned char)str1[i]]++;
        freq2[(unsigned char)str2[i]]++;
    }

    for(int i = 0; i < 256; i++) {
        if(freq1[i] != freq2[i]) {
            printf("The strings are not anagrams.\n");
            return 0;
        }
    }

    printf("The strings are anagrams.\n");

    return 0;
}
