/*10. Regular Expression Matching

Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") == false
isMatch("aa","aa") == true
isMatch("aaa","aa") == false
isMatch("aa", "a*") == true
isMatch("aa", ".*") == true
isMatch("ab", ".*") == true
isMatch("aab", "c*a*b") == true
*/

#include <stdbool.h>
#include <assert.h>

bool isMatch(const char *s, const char *p) {
  if (*p == '\0') return *s == '\0';

  // next char is not '*': must match current character
  if (*(p+1) != '*') {
    return ((*p == *s) || (*p == '.' && *s != '\0')) && isMatch(s+1, p+1);
  }
  // next char is '*'
  while ((*p == *s) || (*p == '.' && *s != '\0')) {
    if (isMatch(s, p+2)) return true;
    s++;
  }
  return isMatch(s, p+2);
}

int main(int argc, char const *argv[]) {
    assert(isMatch("aa","a") == false);
    assert(isMatch("aa","aa") == true);
    assert(isMatch("aaa","aa") == false);
    assert(isMatch("aa", "a*") == true);
    assert(isMatch("aa", ".*") == true);
    assert(isMatch("ab", ".*") == true);
    assert(isMatch("aab", "c*a*b") == true);
    return 0;
}
