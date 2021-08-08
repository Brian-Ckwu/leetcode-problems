#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  // BST solution: key is obstacle height, and value is the longest valid obstacle course
  vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
    map<int, int, greater<int>> lens;
    vector<int> res;
    for (int obs : obstacles) {
      int len = 1;
      auto it = lens.lower_bound(obs);
      if (it != lens.end()) {
        len = it->second + 1;
      }
      res.push_back(len);
      // update map
      if (it == lens.end() || it->first != obs) {
        it = lens.insert(make_pair(obs, len)).first;
      } else {
        it->second += 1;
      }
      // remove larger keys with smaller values
      while (it != lens.begin()) {
        --it;
        if (it->second <= len) {
          it = lens.erase(it);
        } else {
          break;
        }
      }
    }
    return res;
  }
};