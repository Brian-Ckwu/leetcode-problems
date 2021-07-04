#include <vector>

using namespace std;

class Solution {
 public:
  // Somewhat ugly code
  int maxProfitUgly(const vector<int>& prices) {
    // Buy at the local minimum and sell at the local maximum
    int profit = 0;
    int buy = 0, sell = 0;
    bool has_stock = false;
    
    if (prices.size() <= 1) {
      return 0;
    }
    
    for (int i = 0; i < prices.size(); ++i) {
      if (!has_stock && i < prices.size() - 1) { // find the local minimum to buy
        if (prices[i] < prices[i + 1]) {
          buy = prices[i];
          has_stock = true;
        }
      } else { // find the local maximum to sell
        if (i == prices.size() - 1) {
          if (has_stock) {
            sell = prices[i];
            profit += (sell - buy);
          }
        } else {
          if (prices[i] > prices[i + 1]) {
            sell = prices[i];
            profit += (sell - buy);
            has_stock = false;
          }
        }
      }
    }
    
    return profit;
  }

  // Although the question specified that we cannot buy and sell at the same day, this approach is equivalent to buy and sell at different days
  int maxProfitBeautiful(const vector<int>& prices) {
    int ret = 0;
    for (size_t p = 1; p < prices.size(); ++p) 
      ret += max(prices[p] - prices[p - 1], 0);    
    return ret;
  }
};