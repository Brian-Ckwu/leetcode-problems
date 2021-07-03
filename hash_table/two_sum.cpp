#include <vector>

using namespace std;

class Solution {
 public:
  // O(n^2) naive solution
  vector<int> twoSum1(vector<int>& nums, int target) {
    vector<int> answer(2);
    
    for (int i = 0; i < nums.size() - 1; ++i) {
      for (int j = i + 1; j < nums.size(); ++j) {
        if (nums[i] + nums[j] == target) {
          answer[0] = i;
          answer[1] = j;
          break;
        }
      }
    }
    
    return answer;
  }

  // O(n) solution
};