#include <vector>
#include <cmath>

using namespace std;

class Solution {
 public:
  int addRungs(vector<int>& rungs, int dist) {
    int added = 0;
    int loc = 0;
    
    for (int& rung : rungs) {
      if ((rung - loc) > dist) {
        added += ceil((double)(rung - loc) / dist) - 1;
      }
      loc = rung;
    }
    
    return added;
  }
};