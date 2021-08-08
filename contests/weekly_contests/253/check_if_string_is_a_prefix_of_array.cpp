#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  bool isPrefixString(string s, vector<string>& words) {
    string concat;
    int sz = s.size();
    bool equal_len = false;
    for (string& word : words) {
      concat += word;
      if (concat.size() == sz) {
        equal_len = true;
        break;
      } else if (concat.size() > sz) {
        break;
      }
    }
    if (equal_len && s == concat)
      return true;
    return false;
  }
};