/*
  Didn't solve the problem during the contest
*/

#include <iostream>
#include <climits>
#include <cmath>
#include <cassert>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  // Naive solution during the contest
  // Time Complexity?
  int countGoodNumbersNaive(long long n) {
    long long evens = (n + 1) / 2;
    long long odds = n / 2;
    long long ans = 1;
    
    long long mod = pow(10, 9) + 7;
    evens = evens % (mod - 1);
    odds = odds % (mod - 1);
    
    for (int i = 0; i < evens; ++i) {
      ans = (ans * 5) % mod;
    }
    
    for (int j = 0; j < odds; ++j) {
      ans = (ans * 4) % mod;
    }
    
    return int(ans);
  }

  // Using recursion (faster) / Time complexity:
  int pow_after_mod(int x, long long y) {
    long long for_mod = pow(10, 9) + 7;

    if (y <= 1) {
      return (int) pow(x, y);
    }

    int p = pow_after_mod(x, y/2);
    if (y % 2 == 0) {
      return ((long long) p * p) % for_mod;
    } else {
      return ((long long) p * p * x) % for_mod;
    }
  }

  int countGoodNumbers(long long n) {
    long long evens = (n + 1) / 2;
    long long odds = n / 2;
    long long ans = 1;

    int for_mod = pow(10, 9) + 7; // below INT_MAX
    int fives = pow_after_mod(5, evens);
    int fours = pow_after_mod(4, odds);

    ans = ((long long) fives * fours) % for_mod;

    return ans;
  }
};

void printLimits() {
  cout << "INT_MAX: " << INT_MAX << endl; // 2 * 10**9
  cout << "LLONG_MAX: " << LLONG_MAX << endl; // 9 * 10**18
}

void stressTest() {
  Solution s;

  // Manual tests
  assert(s.countGoodNumbers(1) == 5);
  assert(s.countGoodNumbers(4) == 400);
  assert(s.countGoodNumbers(50) == 564908303);

  for (int i = 0; i <= 15; ++i) {
    long long n = pow(10, i);
    cout << s.countGoodNumbers(n) << endl;
  }
  
}

int main() {
  stressTest();

  return 0;
}