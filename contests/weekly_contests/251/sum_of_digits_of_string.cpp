#include <bits/stdc++.h>

using namespace std;

/*
  Conversion of int, char, string:
    1. char to int: to ASCII value
    2. int to char: use '0' + int / e.g. '7' = '0' + 7
    3. int to string: to_string(int)
*/

int getLucky(string s, int k) {
  // convert the string to int string
  string int_s;
  for (char& ch : s) {
    int_s += to_string(ch - 'a' + 1);
  }
  
  for (int i = 0; i < k; ++i) {
    int sum = 0;
    for (char& ch : int_s) {
      sum += (ch - '0');
    }
    int_s = to_string(sum);
  }
  
  return stoi(int_s);
}

int main() {
  cout << getLucky("zbax", 2);

  return 0;
}