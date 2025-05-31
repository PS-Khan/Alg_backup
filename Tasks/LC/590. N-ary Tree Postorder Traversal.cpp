/*
Given the root of an n-ary tree, return the postorder traversal of its nodes' values.

Nary-Tree input serialization is represented in their level order traversal. Each group of children is separated by the null value (See examples)

https://leetcode.com/problems/n-ary-tree-postorder-traversal/description/?envType=daily-question&envId=2024-08-26
*/


#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <cmath>
#include <queue>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <memory.h>
#include <sstream>
#include <regex>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:

    void helper(Node* root, vector<int> &res ){
        if(root == nullptr){
            return;
        }
        for(Node* root: root->children){
            helper(root, res );
        }
        res.push_back(root->val);
    }
  
    vector<int> postorder(Node* root) {
       vector<int> res;
       helper(root,res);
     
       return res;
    }
};

//

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> result;
        if (root == nullptr) {
            return result;
        }
        traversePostorder(root, result);
        return result;
    }

private:
    void traversePostorder(Node* currentNode, vector<int>& postorderList) {
        if (currentNode == nullptr) {
            return;
        }

        // First, visit all children
        for (Node* childNode : currentNode->children) {
            traversePostorder(childNode, postorderList);
        }

        // Then, add the current node's value
        postorderList.push_back(currentNode->val);
    }
};


//

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> result;

        // If the root is null, return the empty list
        if (root == nullptr) return result;

        stack<Node*> nodeStack;
        nodeStack.push(root);

        // Traverse the tree using the stack
        while (!nodeStack.empty()) {
            Node* currentNode = nodeStack.top();
            nodeStack.pop();

            result.push_back(currentNode->val);
            // Push all the children of the current node to the stack
            for (Node* child : currentNode->children) nodeStack.push(child);
        }

        // Reverse the result list to get the correct postorder traversal
        reverse(result.begin(), result.end());
        return result;
    }
};