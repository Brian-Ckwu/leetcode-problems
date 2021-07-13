#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

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
  // 1. Recursive method (time: O(n) / space: O(n))
  vector<int> postorderTraversal(TreeNode* root) {
    vector<int> values;
    postorder(root, values);
    return values;
  }
  
  void postorder(TreeNode* root, vector<int>& values) {
    if (root == nullptr) {
      return;
    }
    
    postorder(root->left, values);
    postorder(root->right, values);
    values.push_back(root->val);
  }

  // 2. Iterative method (using stack to keep track of the current node) (time: O(n) / space: O(n))
  // this implementation is harder than the preorder one (stuck so long...)
  vector<int> postorderTraversalIter(TreeNode* root) {
    if (!root) {
      return {};
    }
    
    vector<int> values;
    stack<TreeNode*> todos;
    
    todos.push(root);
    
    // (root right left preorder)
    while (!todos.empty()) {
      root = todos.top(); todos.pop();
      values.push_back(root->val);
      
      if (root->left) {
        todos.push(root->left);
      }
      if (root->right) {
        todos.push(root->right);
      }
    }
    
    // reverse the order
    reverse(values.begin(), values.end());
    
    return values;   
  }

  // 3. Morris traversal (time: O(n) / space: O(1))

};