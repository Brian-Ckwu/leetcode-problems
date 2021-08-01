#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool compare(vector<int>& a, vector<int>& b) {
  return a[0] < b[0];
}

class Compare {
 public:
  bool operator()(pair<int, int>& a, pair<int, int>& b) {
    if (a.second == b.second) {
      return b.first < a.first;
    }
    return b.second < a.second;
  }
};

class Solution {
 public:
  int smallestChair(vector<vector<int>>& times, int targetFriend) {
    int target_arrival_time = times[targetFriend][0];
    // sort the arrival time
    sort(times.begin(), times.end(), compare);
    // find the index of the targetfriend
    int target_index = 0;
    for (int i = 0; i < times.size(); ++i) {
      if (times[i][0] == target_arrival_time) {
        target_index = i;
      }
    }

    cout << target_index;
    // chairs[]
    vector<int> chairs_indexes;
    // priority queue for chairs (chair_index, available time), initial {0, 0}
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> chairs;
    chairs.push({0, 0});
    
    for (vector<int>& time : times) {
      pair<int, int> chair = chairs.top();
      if (time[0] >= chair.second) {
        chairs.pop();
        chairs.push({chair.first, time[1]});
      } else {
        chair = {chairs.size(), time[1]};
        chairs.push(chair);
      }
      chairs_indexes.push_back(chair.first);
    }
    
    return chairs_indexes[target_index];
  }
};

int main() {
  Solution s;
  vector<vector<int>> times = {{3,10}, {1, 5}, {2, 6}};
  s.smallestChair(times, 1);

  return 0;
}