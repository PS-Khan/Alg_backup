/*
https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/description/?envType=daily-question&envId=2025-02-21

Given a binary tree with the following rules:

root.val == 0
For any treeNode:
If treeNode.val has a value x and treeNode.left != null, then treeNode.left.val == 2 * x + 1
If treeNode.val has a value x and treeNode.right != null, then treeNode.right.val == 2 * x + 2
Now the binary tree is contaminated, which means all treeNode.val have been changed to -1.

Implement the FindElements class:

FindElements(TreeNode* root) Initializes the object with a contaminated binary tree and recovers it.
bool find(int target) Returns true if the target value exists in the recovered binary tree.
 

Example 1:


Input
["FindElements","find","find"]
[[[-1,null,-1]],[1],[2]]
Output
[null,false,true]
Explanation
FindElements findElements = new FindElements([-1,null,-1]); 
findElements.find(1); // return False 
findElements.find(2); // return True 
Example 2:


Input
["FindElements","find","find","find"]
[[[-1,-1,-1,-1,-1]],[1],[3],[5]]
Output
[null,true,true,false]
Explanation
FindElements findElements = new FindElements([-1,-1,-1,-1,-1]);
findElements.find(1); // return True
findElements.find(3); // return True
findElements.find(5); // return False

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

class FindElements {
public:
    std::unordered_set<int> uniq;
    void dfs(TreeNode* root){
        if(root == nullptr){
            return;
        }
        uniq.emplace(root->val);
        if(root->left !=  nullptr){
            root->left->val = (2 * root->val) + 1;
            dfs(root->left);
        }
        if(root->right !=  nullptr){
            root->right->val = (2 * root->val) + 2;
            dfs(root->right);
        }


    }
    FindElements(TreeNode* root) {
        root->val = 0;
        dfs(root);
    }
    
    bool find(int target) {
        return uniq.find(target) != uniq.end();
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */



class FindElements {
public:
    std::unordered_set<int> uniq;

    void dfs(TreeNode* root) {
        if (root == nullptr) return;

        std::stack<TreeNode*> nodeStack;
        root->val = 0;
        nodeStack.push(root);

        while (!nodeStack.empty()) {
            TreeNode* node = nodeStack.top();
            nodeStack.pop();
            uniq.insert(node->val);

            if (node->right != nullptr) {
                node->right->val = 2 * node->val + 2;
                nodeStack.push(node->right);
            }
            if (node->left != nullptr) {
                node->left->val = 2 * node->val + 1;
                nodeStack.push(node->left);
            }
        }
    }

    FindElements(TreeNode* root) {
        dfs(root);
    }

    bool find(int target) {
        return uniq.find(target) != uniq.end();
    }
};