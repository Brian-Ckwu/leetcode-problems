#include <vector>

using namespace std;

class Solution {
 public:
  // Interative
  int searchInsertIter(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;
    
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (nums[mid] == target) {
        return mid;
      } else if (target < nums[mid]) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    
    return low;
  }

  // Recursive
  int searchInsertRecur(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;
    return search(nums, low, high, target);
  }
  
  int search(vector<int>& nums, int low, int high, int target) {
    if (low > high) {
      return low;
    }
    
    int mid = low + (high - low) / 2;
    if (nums[mid] == target) {
      return mid;
    } else if (target < nums[mid]) {
      return search(nums, low, mid - 1, target);
    } else {
      return search(nums, mid + 1, high, target);
    }
  }
};