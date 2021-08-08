#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int minStoneSum(vector<int>& piles, int k) {
    priority_queue<int> q(piles.begin(), piles.end()); // make_heap: O(n)
    int old_total = accumulate(piles.begin(), piles.end(), 0); // sum: O(n)
    int total_removed = 0;
    for (int i = 0; i < k; ++i) { // O(klogn)
      int pile = q.top(); q.pop();
      int removed = pile / 2;
      pile -= removed;
      total_removed += removed;
      q.push(pile);
    }
    return old_total - total_removed;
  }
};