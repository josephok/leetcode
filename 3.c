// 3. Longest Substring Without Repeating Characters
//
// Given a string, find the length of the longest substring without repeating
// characters.
//
// Examples:
//
// Given "abcabcbb", the answer is "abc", which the length is 3.
//
// Given "bbbbb", the answer is "b", with the length of 1.
//
// Given "pwwkew", the answer is "wke", with the length of 3. Note that the
// answer must be a substring, "pwke" is a subsequence and not a substring.
//

#include <string.h>
#include <stdlib.h>
#include <assert.h>
#define MAX_LENGTH 256

int lengthOfLongestSubstring(char* s) {
    int length = strlen(s);
    if (length == 0) {
        return 0;
    }
    int cur_len = 1;  // lenght of current substring
    int max_len = 1;  // result
    int prev_index;  //  previous index
    int i;
    int *visited = malloc(sizeof(int) * MAX_LENGTH);

    /* Initialize the visited array as -1, -1 is used to
       indicate that character has not been visited yet. */
    for (i = 0; i < MAX_LENGTH;  i++)
        visited[i] = -1;

    /* Mark first character as visited by storing the index
       of first   character in visited array. */
    visited[s[0]] = 0;

    /* Start from the second character. First character is
       already processed (cur_len and max_len are initialized
       as 1, and visited[s[0]] is set */
    for (i = 1; i < length; i++)
    {
        prev_index =  visited[s[i]];

        /* If the currentt character is not present in the
           already processed substring or it is not part of
           the current Non-Repeating Character Substring, then do cur_len++ */
        if (prev_index == -1 || i - cur_len > prev_index)
            cur_len++;

        /* If the current character is present in currently
           considered Non-Repeating Character Substring, then update
           Non-Repeating Character Substring to start from
           the next character of previous instance. */
        else
        {
            /* Also, when we are changing the Non-Repeating Character Substring
            , we
               should also check whether length of the
               previous Non-Repeating Character Substring was greater than
               max_len or  not.*/

            if (cur_len > max_len)
                max_len = cur_len;

            cur_len = i - prev_index;
        }

        // update the index of current character
        visited[s[i]] = i;
    }

    // Compare the length of last Non-Repeating Character Substring with
    // max_len and update max_len if needed
    if (cur_len > max_len)
        max_len = cur_len;

    free(visited); // free memory allocated for visited
    return max_len;
}

int main(int argc, char const *argv[]) {
    char s1[] = "abcabcbb";
    char s2[] = "bbbbb";
    char s3[] = "pwwkew";

    assert(lengthOfLongestSubstring(s1) == 3);
    assert(lengthOfLongestSubstring(s2) == 1);
    assert(lengthOfLongestSubstring(s3) == 3);
    return 0;
}
