#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
    // information of 8 directions
    vector<int> r = {-1, -1, 0, 1, 1, 1, 0, -1};
    vector<int> c = {0, 1, 1, 1, 0, -1, -1, -1};
    // check 8 directions
    for (int i = 0; i < 8; ++i) {
      int x = rMove + r[i], y = cMove + c[i]; // start checking from the next cell (original no need)
      bool seen_opp = false, end_with_color = false;
      for (; 0 <= x && x < 8 && 0 <= y && y < 8; x += r[i], y += c[i]) {
        if (board[x][y] == '.') {
          break;
        } else if (board[x][y] == color) {
          end_with_color = true;
          break;
        } else {
          seen_opp = true;
        }
      }
      // check if the line is valid
      if (end_with_color && seen_opp)
        return true;
    }
    // no good lines
    return false;
  }
};