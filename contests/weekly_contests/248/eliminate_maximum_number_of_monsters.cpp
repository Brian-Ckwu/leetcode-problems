#include <vector>
#include <algorithm>

using namespace std;

class Solution {
 public:
  int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
    vector<double> monsters(dist.size());
    for (int i = 0; i < dist.size(); ++i) {
      monsters[i] = (double) dist[i] / speed[i];
    }
    
    sort(monsters.begin(), monsters.end());
    
    for (int i = 0; i < monsters.size(); ++i) {
      if (monsters[i] <= i) {
        return i;
      }
    }
    
    return dist.size();
  }
};