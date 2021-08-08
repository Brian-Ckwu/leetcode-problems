#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  string makeFancyString(string s) {
    string new_s;
    int cnt = 1;
    new_s += s[0];
    for (int i = 1; i < s.size(); ++i) {
      // update cnt
      if (s[i] == s[i - 1]) {
        ++cnt;
      } else {
        cnt = 1;
      }
      // check cnt
      if (cnt < 3)
        new_s += s[i];
    }
    return new_s;
  }
};