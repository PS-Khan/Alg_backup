/*
https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/?envType=daily-question&envId=2025-02-23
Given two integer arrays, preorder and postorder where preorder is the preorder traversal of a binary tree of distinct values and postorder is the postorder traversal of the same tree, reconstruct and return the binary tree.

If there exist multiple answers, you can return any of them.
*/




 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 


#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <queue>
#include <set>
#include <utility>
#include <stack>

using namespace std;
class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        unordered_map<int, int> postIndex;
        for (int i = 0; i < postorder.size(); i++) {
            postIndex[postorder[i]] = i;
        }
        int preIndex = 0;
        return build(preorder, postorder, postIndex, preIndex, 0, postorder.size() - 1);
    }

private:
    TreeNode* build(vector<int>& preorder, vector<int>& postorder, unordered_map<int, int>& postIndex, 
                    int& preIndex, int left, int right) {
        if (preIndex >= preorder.size() || left > right) return nullptr;

        TreeNode* root = new TreeNode(preorder[preIndex++]);
        if (preIndex >= preorder.size() || left == right) return root;

        int leftSubtreeRootIndex = postIndex[preorder[preIndex]];
        
        root->left = build(preorder, postorder, postIndex, preIndex, left, leftSubtreeRootIndex);
        root->right = build(preorder, postorder, postIndex, preIndex, leftSubtreeRootIndex + 1, right - 1);
        
        return root;
    }
};