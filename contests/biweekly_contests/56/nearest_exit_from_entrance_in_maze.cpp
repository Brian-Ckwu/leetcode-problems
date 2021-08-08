#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
  int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
    /*
      View the entrance as the root of a tree,
      and store each node as a pair of int values for documenting positions.
      Use the positions to access child nodes
      Loop:
        If an exit is encountered, return steps.
      If no return in the loop -> return -1;
    */
    
    int m = maze.size();
    int n = maze[0].size();
    
    queue<pair<int, int>> positions;
    pair<int, int> entry = {entrance[0], entrance[1]};
    positions.push(entry);
    int steps = -1;
    
    vector<pair<int, int>> offsets = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    while (!positions.empty()) {
      ++steps;
      int n_pos = positions.size(); // the number of positions each level
      
      for (int i = 0; i < n_pos; ++i) {
        pair<int, int> pos = positions.front(); positions.pop();
        int row = pos.first;
        int col = pos.second;
        
        // if the exit is found
        if (pos != entry && (row == 0 || row == m - 1 || col == 0 || col == n - 1))
          return steps;
        
        // visit up, down, left, right of the current position
        // remember to block the road once visited "immediately", or else will result in duplicated visiting
        for (pair<int, int>& offset : offsets) {
          int rrow = row + offset.first;
          int ccol = col + offset.second;
          // if within bound and the move is valid, i.e. '.'
          if ((rrow >= 0 && rrow <= m - 1 && ccol >= 0 && ccol <= n - 1) && (maze[rrow][ccol] == '.')) {
            positions.push({rrow, ccol});
            maze[rrow][ccol] = '+';
          }
        }
      }
    }
    
    return -1;
  }
};