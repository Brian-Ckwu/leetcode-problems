#include <iostream>
#include <vector>
#include <stack>

using namespace std;


struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 

class Solution {
 public:
  // my first solution
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> values;
    
    if (root == nullptr) {
      return vector<int>(0);
    }
    
    vector<int> lvalues = inorderTraversal(root->left);
    values.insert(values.end(), lvalues.begin(), lvalues.end());
    values.push_back(root->val);
    vector<int> rvalues = inorderTraversal(root->right);
    values.insert(values.end(), rvalues.begin(), rvalues.end());
    
    return values;
  }

  // From the most voted C++ solution
  // 1. Recursive method (time: O(n) / space: O(n))
  vector<int> inorderTraversalRecur(TreeNode* root) {
    vector<int> values;
    inorderRecur(root, values);
    return values;
  }
  
  void inorderRecur(TreeNode* root, vector<int>& values) {
    if (root == nullptr) {
      return;
    }
    
    inorderRecur(root->left, values);
    values.push_back(root->val);
    inorderRecur(root->right, values);
  }

  // 2. Iterative method (using stack to keep track of the current node) (time: O(n) / space: O(n))
  vector<int> inorderTraversalIter(TreeNode* root) {
    vector<int> values;
    stack<TreeNode*> todos;
    
    while (root || !todos.empty()) { // right root from the last loop or the parent node
      while (root) {
        todos.push(root);
        root = root->left;
      }
      
      TreeNode* node = todos.top();
      todos.pop();
      values.push_back(node->val);
      root = node->right;
    }
    
    return values;    
  }

  // 3. Morris traversal (time: O(n) / space: O(1))

};