#include <vector>
#include <climits>
#include <cmath>

using namespace std;

class Solution {
 public:
  // Naive DP: O(m * n^2) time complexity
  long long maxPointsNaive(vector<vector<int>>& points) {
    int m = points.size();
    int n = points[0].size();
    long long max_points[m][n];
    // fill the first row with initial row values
    long long final_max = LLONG_MIN;
    for (int col = 0; col < n; ++col) {
      long long point = points[0][col];
      max_points[0][col] = point;
      if (point > final_max) {
        final_max = point;
      }
    }
    // fill the DP table
    for (int row = 1; row < m; ++row) {
      for (int col = 0; col < n; ++col) {
        long long original = points[row][col];
        long long max_point = LLONG_MIN;
        for (int ccol = 0; ccol < n; ++ccol) {
          long long point = original + max_points[row - 1][ccol] - abs(ccol - col);
          if (point > max_point) {
            max_point = point;
          }
        }
        max_points[row][col] = max_point;
        if (max_point > final_max) {
          final_max = max_point;
        }
      }
    }
    return final_max;
  }

  // Optimized DP: O(mn) time complexity
  long long maxPoints(vector<vector<int>>& points) {
    // matrix for storing max points
    int m = points.size();
    int n = points[0].size();
    long long max_points[m][n];
    // fill the first row
    for (int col = 0; col < n; ++col) {
      max_points[0][col] = points[0][col];
    }
    // fill the other rows (main implementation)
    for (int row = 1; row < m; ++row) {
      // left max: value in the kth cell means the maximum values
      // of the sequence p1 - (k - 1), p2 - (k - 2), ..., pk
      long long left_max[n];
      left_max[0] = max_points[row - 1][0];
      for (int col = 1; col < n; ++col) {
        left_max[col] = max(left_max[col - 1] - 1, max_points[row - 1][col]);
      }
      // right max: the same but count from the right end
      long long right_max[n];
      right_max[n - 1] = max_points[row - 1][n - 1];
      for (int col = n - 2; col > -1; --col) {
        right_max[col] = max(right_max[col + 1] - 1, max_points[row - 1][col]);
      }
      // fill the row
      for (int col = 0; col < n; ++col) {
        max_points[row][col] = points[row][col] + max(left_max[col], right_max[col]);
      }     
    }
    
    // find the maximum value in the last row
    long long final_max = LLONG_MIN;
    for (int col = 0; col < n; ++col) {
      if (max_points[m - 1][col] > final_max) {
        final_max = max_points[m - 1][col];
      }
    }
    
    return final_max;
  }
};