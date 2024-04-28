/*

You are given the root of a binary tree containing digits from 0 to 9 only.

Each root-to-leaf path in the tree represents a number.

For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit integer.

A leaf node is a node with no children.

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


//maybe not the best, but its my first solution to this problem and it work.

class Solution {
public:
    string str, rest;
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        
        if(root == nullptr){
            return 0;
        }
        
        if(str.size()>0 && str.back() == '+'){
            str+=rest;
        }
        str+= to_string(root->val);
        
        if(root->left == nullptr && root->right == nullptr){
            str+="+";
        }else{
            rest+= to_string(root->val);
        }
        sumNumbers(root->left);
        sumNumbers(root->right);
        if(root->left != nullptr || root->right != nullptr){
            rest.pop_back();
        }
        
        std::istringstream iss(str);
        std::string token;
        while (std::getline(iss, token, '+')) {
            sum += std::stoi(token);
        }
        //std::cout<<str<<endl;
        return sum;
    }
};

//yeah this better

int sumNumbers(TreeNode* root) {
        return sumRootToLeaf(root, 0);
    }

    int sumRootToLeaf(TreeNode* root, int currentSum) {
        if (root == nullptr) {
            return 0;
        }
        
        currentSum = currentSum * 10 + root->val;
        
        if (root->left == nullptr && root->right == nullptr) {
            return currentSum; 
        }
        
        int leftSum = sumRootToLeaf(root->left, currentSum);
        int rightSum = sumRootToLeaf(root->right, currentSum);
        
        return leftSum + rightSum;
    }