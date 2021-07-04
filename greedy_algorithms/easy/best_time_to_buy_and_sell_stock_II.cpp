#include <vector>

using namespace std;

class Solution {
 public:
  // Somewhat ugly code
  int maxProfit(vector<int>& prices) {
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
};