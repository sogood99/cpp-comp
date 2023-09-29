#include <bits/stdc++.h>

using namespace std;

inline char lowercase(char c) {
  return (c >= 'A' && c <= 'Z') ? (c - 'A' + 'a') : c;
}

inline bool alphanumeric(char c) {
  return c >= 'A' && c <= 'Z' || c >= '0' && c <= '9' || c >= 'a' && c <= 'z';
}

class Solution {
public:
  bool isPalindrome(string s) {
    int i = 0, j = s.size() - 1;
    while (i < j) {
      if (!alphanumeric(s[i])) {
        i++;
      } else if (!alphanumeric(s[j])) {
        j--;
      } else {
        if (lowercase(s[i]) != lowercase(s[j])) {
          return false;
        }
        i++;
        j--;
      }
    }

    return true;
  }
};

int main() {

  cout << Solution().isPalindrome("A man, a plan, a canal: Panama");

  return 0;
}
