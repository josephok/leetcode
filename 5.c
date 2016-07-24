/* 5. Longest Palindromic Substring

Given a string S, find the longest palindromic substring in S. You may assume
that the maximum length of S is 1000, and there exists one unique longest
palindromic substring.
*/

#include <string.h>
#include <stdio.h>

char buf[1001] = {0};

char* longestPalindrome(char* s) {
    int len = strlen(s);
    if(s == NULL || len <= 0){
        return s;
    }
    int i;
    int max_length = 1;
    int start = 0;

    for(i = 1; i < len; i++) {
        // even number count
        int low = i - 1;
        int high = i;
        while (low >= 0 && high < len && s[low] == s[high]) {
            if (high - low + 1 > max_length){
                start = low;
                max_length = high - low + 1;
            }
            low--;
            high++;
        }

        // odd number count
        low = i - 1;
        high = i + 1;
        while (low >= 0 && high < len && s[low] == s[high]) {
            if (high - low + 1 > max_length) {
                start = low;
                max_length = high - low + 1;
            }
            low--;
            high++;
        }
    }
    strncpy(buf, s + start, max_length);
    return buf;
}

int main(int argc, char const *argv[]) {
    char s[] = "abb";
    char *substring = longestPalindrome(s);
    printf("%s\n", substring);
    return 0;
}
