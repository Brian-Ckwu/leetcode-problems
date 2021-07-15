#include <iostream>
#include <queue>

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
  // first BFS solution
  // time complexity: best: O(1) average? worst: O(n)
  int minDepthBFSFirst(TreeNode* root) {
    int tree_height = 0;
    queue<TreeNode*> q;
    if (root) {
      q.push(root);
    }
    TreeNode* level_last = root;
    
    while (!q.empty()) {
      TreeNode* node = q.front(); q.pop();
      if (!node->left && !node->right) {
        ++tree_height;
        break;
      }
      if (node->left) {
        q.push(node->left);
      }
      if (node->right) {
        q.push(node->right);
      }
      if (node == level_last) {
        ++tree_height;
        if (!q.empty()) {
          level_last = q.back();
        }
      }
    }
    
    return tree_height;
  }

  // logically clearer BFS solution (doesn't have to keep track of the last element of the level)
  int minDepthClearer(TreeNode* root) {
    if (!root)
      return 0;
    
    queue<TreeNode*> q;
    q.push(root);
    int height = 0;
    
    while (!q.empty()) {
      ++height;
      
      int k = q.size();
      for (int i = 0; i < k; ++i) { // becareful: q.size() will be modified in the loop, should assign it outside
        TreeNode* node = q.front(); q.pop();
        if (!node->left && !node->right)
          return height;
        if (node->left)
          q.push(node->left);
        if (node->right)
          q.push(node->right);
      }
    }
  
    throw "This line should not be executed.";
  }
  
  // first DFS solution
  // time complexity: O(n) for every possible tree (must search every node)
  int minDepthDFSFirst(TreeNode* root) {
    if (!root) {
      return 0;
    }
    
    if (!root->left && !root->right) {
      return 1;
    }
    
    int lefth = (root->left) ? 1 + minDepthBFSFirst(root->left) : INT_MAX;
    int righth = (root->right) ? 1 + minDepthBFSFirst(root->right): INT_MAX;
    
    return min(lefth, righth);
  }

  // concise DFS solution
  int minDepthConcise(TreeNode* root) {
    if (!root)
      return 0;
    // if (!root->left && !root->right) // this conditional is not necessary because the below one include two situations: only the right child exists or both not exists
    //   return 1;
    if (!root->left)
      return 1 + minDepthConcise(root->right);
    if (!root->right)
      return 1 + minDepthConcise(root->left);
    return 1 + min(minDepthConcise(root->left), minDepthConcise(root->right));
  }

};