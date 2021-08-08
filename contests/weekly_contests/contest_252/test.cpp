#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<int> v = {3, 5, 2};
  sort(v.begin(), v.end());
  for (auto& i : v) {
    cout << i << " ";
  }

  return 0;
}