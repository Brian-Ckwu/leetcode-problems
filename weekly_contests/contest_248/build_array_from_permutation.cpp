#include <vector>

using namespace std;

class Solution {
 public:
  // Naive solution
  vector<int> buildArray(vector<int>& nums) {
    vector<int> ans(nums.size());
    
    for (int i = 0; i < nums.size(); ++i) {
      ans[i] = nums[nums[i]];
    }
    
    return ans;
  }

  // Follow-up: O(1) memory (no extra spcae solution)
};