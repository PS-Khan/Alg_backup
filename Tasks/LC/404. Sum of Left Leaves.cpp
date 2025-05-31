/**
https://leetcode.com/problems/sum-of-left-leaves/description/
 * 
 * 
 * Given the root of a binary tree, return the sum of all left leaves.

A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.

 
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
#include <type_traits>
#include <typeinfo>
#include <stack>
#include <vector>
#include <queue>
#include <list>
#include <thread>
#include <mutex>
#include <string>
#include <numeric>

using namespace std;

class Solution {
public:
    
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == nullptr){
            return 0 ;
        }
        int sum = 0;
        if(root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr){
            sum+=root->left->val;
        }
        sum +=sumOfLeftLeaves(root->left);
        
        sum +=sumOfLeftLeaves(root->right);
        
        return sum;
        
    }
};