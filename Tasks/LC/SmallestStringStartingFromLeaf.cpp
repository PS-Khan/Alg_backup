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
#include <algorithm>

using namespace std;

/*

You are given the root of a binary tree where each node has a value in the range [0, 25] representing the letters 'a' to 'z'.

Return the lexicographically smallest string that starts at a leaf of this tree and ends at the root.

As a reminder, any shorter prefix of a string is lexicographically smaller.

For example, "ab" is lexicographically smaller than "aba".
A leaf of a node is a node that has no children.

*/

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

string dfs(TreeNode* root, string currentPath) {
        if (root == nullptr) {
            return "";
        }

        currentPath += (char)('a' + root->val); 
        if (root->left == nullptr && root->right == nullptr) { 
            reverse(currentPath.begin(), currentPath.end()); 
            return currentPath;
        }

        string leftPath = dfs(root->left, currentPath);
        string rightPath = dfs(root->right, currentPath);

        if (leftPath.empty()) { 
            return rightPath;
        } else if (rightPath.empty()) {
            return leftPath;
        } else { 
            return min(leftPath, rightPath);
        }
    }


//This doesn't work as needed according to the task, but it works, so I decided to keep it to not throw my efforts away) :

string smallestFromLeaf(TreeNode* root) {
        if(root == nullptr){
            return "";
        }
        string str;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            int max = numeric_limits<int>::max();
            for(int i = 0; i < size; i++){
                TreeNode* current = q.front();
                q.pop();

                if(current->val < max){
                    max = current->val;
                }

                if(current->left != nullptr){
                    q.push(current->left);
                }else if(current->right != nullptr){
                    q.push(current->right);
                }
            }
            str+= ('a'+ max);
            

        }
        reverse(str.begin(), str.end());
        return str ;

    }