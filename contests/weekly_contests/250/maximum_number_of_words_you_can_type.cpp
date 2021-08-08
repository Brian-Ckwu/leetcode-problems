#include <string>
#include <unordered_set>

using namespace std;

class Solution {
 public:
  bool hasBroken(const string& word, const unordered_set<char>& broken) {
    for (const char& c : word) {
      if (broken.count(c)) {
        return true;
      }
    }
    return false;
  }
  
  int canBeTypedWords(string text, string brokenLetters) {
    unordered_set<char> broken(brokenLetters.begin(), brokenLetters.end());
    int count = 0;
    string word;
    for (int i = 0; i <= text.size(); ++i) {
      if (text[i] == ' ' || i == text.size()) { // check if the word can be made
        if (!hasBroken(word, broken)) {
          ++count;
        }
        word = "";
      } else { // make word
        word += text[i];
      }
    }
    
    return count;
  }
};