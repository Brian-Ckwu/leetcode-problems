/*
  https://leetcode.com/problems/two-sum/
*/

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  // O(n^2) naive solution
  vector<int> twoSum1(const vector<int>& nums, int target) {
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

  // O(n) solution using a hash map
  vector<int> twoSum2(const vector<int>& nums, int target) {
    vector<int> answer(2);
    unordered_map<int, int> num_to_i;

    for (int i = 0; i < nums.size(); ++i) {
      int num_to_find = target - nums[i];
      // If the number is found in the hash map, set the answer
      if (num_to_i.find(num_to_find) != num_to_i.end()) {
        answer[0] = i;
        answer[1] = num_to_i[num_to_find];
        break;
      }
      // Else put the number and the index in the hash map
      num_to_i[nums[i]] = i;
    }

    return answer;
  }
};