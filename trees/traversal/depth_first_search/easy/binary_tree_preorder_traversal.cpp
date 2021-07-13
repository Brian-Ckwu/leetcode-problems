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
  // 1. Recursive method (time: O(n) / space: O(n))
  vector<int> preorderTraversal(TreeNode* root) {
    vector<int> values;
    preorder(root, values);
    return values;
  }
  
  void preorder(TreeNode* root, vector<int>& values) {
    if (root == nullptr) {
      return;
    }
    
    values.push_back(root->val);
    preorder(root->left, values);
    preorder(root->right, values);
  }

  // 2. Iterative method (using stack to keep track of the current node) (time: O(n) / space: O(n))
  vector<int> preorderTraversalIter(TreeNode* root) {
    vector<int> values;
    stack<TreeNode*> todos;
    
    while (root || !todos.empty()) {
      while (root) {
        values.push_back(root->val);
        todos.push(root);
        root = root->left;
      }
      
      TreeNode* node = todos.top();
      todos.pop();
      root = node->right;
    }
    
    return values;    
  }

  vector<int> preOrderTraversalIter2(TreeNode* root) { // a more understandable version of iterative method
    if (!root) {
      return {};
    }
    
    vector<int> values;
    stack<TreeNode*> todos;
    
    todos.push(root);
    
    while (!todos.empty()) {
      root = todos.top(); todos.pop();
      values.push_back(root->val);
      
      if (root->right) {
        todos.push(root->right);
      }
      
      if (root->left) {
        todos.push(root->left);
      }
    }
    
    return values;
  }

  // 3. Morris traversal (time: O(n) / space: O(1))

};