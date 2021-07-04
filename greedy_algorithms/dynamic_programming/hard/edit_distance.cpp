#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

class Solution {
 public:
  int minDistance(string word1, string word2) {
    int m = word1.size();
    int n = word2.size();
    int ed[m + 1][n + 1];
    
    // Initialize the 2D array
    for (int row = 0; row <= m; ++row) {
      ed[row][0] = row;
    }
    
    for (int col = 0; col <= n; ++col) {
      ed[0][col] = col;
    }
    
    // Bottom-up solution
    int in, del, match, repl;
    for (int col = 1; col <= n; ++col) {
      for (int row = 1; row <= m; ++row) {
        in = ed[row][col - 1] + 1;
        del = ed[row - 1][col] + 1;
        match = ed[row - 1][col - 1];
        repl = ed[row - 1][col - 1] + 1;
        
        if (word1[row - 1] == word2[col - 1]) {
          ed[row][col] = min(min(in, del), match);
        } else {
          ed[row][col] = min(min(in, del), repl);
        }
      }
    }
    
    return ed[m][n];
  }
};