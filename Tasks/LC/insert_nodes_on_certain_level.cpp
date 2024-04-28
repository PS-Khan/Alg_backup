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


/*
Given the root of a binary tree and two integers val and depth, add a row of nodes with value val at the given depth depth.

Note that the root node is at depth 1.

The adding rule is:

Given the integer depth, for each not null tree node cur at the depth depth - 1, create two tree nodes with value val as cur's left subtree root and right subtree root.
cur's original left subtree should be the left subtree of the new left subtree root.
cur's original right subtree should be the right subtree of the new right subtree root.
If depth == 1 that means there is no depth depth - 1 at all, then create a tree node with value val as the new root of the whole original tree, and the original tree is the new root's left subtree.
 

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
#include <sstream>

using namespace std;
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (root == nullptr) {
            return nullptr;
        }
        if(depth == 1){
            TreeNode* tmp = new TreeNode(val);
            tmp->left = root;
            return tmp;
        }

        std::queue<TreeNode*> q;
        q.push(root);
        int d = 1;

        while (!q.empty()) {
            int size = q.size();
            if (d == depth - 1) { 
                for (int i = 0; i < size; ++i) {
                    TreeNode* current = q.front();
                    q.pop();

                    TreeNode* newLeft = new TreeNode(val);
                    TreeNode* newRight = new TreeNode(val);

                    newLeft->left = current->left;
                    newRight->right = current->right;

                    current->left = newLeft;
                    current->right = newRight;
                }
                break; 
            } else { 
                for (int i = 0; i < size; ++i) {
                    TreeNode* current = q.front();
                    q.pop();

                    if (current->left != nullptr) {
                        q.push(current->left);
                    }
                    if (current->right != nullptr) {
                        q.push(current->right);
                    }
                }
            }
            ++d;
        }

        return root;
    }
};