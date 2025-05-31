
/*

https://leetcode.com/problems/binary-tree-paths/description/?envType=problem-list-v2&envId=backtracking

Given the root of a binary tree, return all root-to-leaf paths in any order.

A leaf is a node with no children.
*/


#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <set>
#include <queue>
#include <set>
#include <utility>
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
    void dfs(TreeNode* root, vector<string> &res, string str){
        if(root == nullptr){
            return ;
        }

        str += to_string(root->val) + "->";

        if(root->left == nullptr && root->right == nullptr){
            if(!str.empty() && str.length()>2){
                str.pop_back();str.pop_back();
                res.push_back(str);
            }
        }

        dfs(root->left, res, str);
        dfs(root->right, res, str);

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        string str;
        dfs(root, res, str);
        return res;
    }
};

//
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void backtrack(TreeNode* root, vector<string>& res, string path) {
        if (!root) return;  
        
      
        if (!path.empty()) path += "->";
        path += to_string(root->val);

       
        if (!root->left && !root->right) {
            res.push_back(path);
            return;
        }

        
        backtrack(root->left, res, path);
        backtrack(root->right, res, path);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        string str;
        backtrack(root, res, str);
        return res;
    }
};