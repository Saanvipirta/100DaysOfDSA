/*Write a C program to reverse each word in a sentence while keeping the order of the words unchanged.
Example:
"Hello World" → "olleH dlroW"
*/
#include <stdio.h>
#include <string.h>

void reverseWord(char str[], int start, int end) {
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int main() {
    char str[200];

    printf("Enter a sentence:\n");
    fgets(str, sizeof(str), stdin);

    int start = 0;
    int len = strlen(str);

    for (int i = 0; i <= len; i++) {
        if (str[i] == ' ' || str[i] == '\n' || str[i] == '\0') {
            reverseWord(str, start, i - 1);
            start = i + 1;
        }
    }

    printf("Reversed words:\n%s", str);

    return 0;
}
