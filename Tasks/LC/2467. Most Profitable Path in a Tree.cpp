/*
https://leetcode.com/problems/most-profitable-path-in-a-tree/description/?envType=daily-question&envId=2025-02-24

There is an undirected tree with n nodes labeled from 0 to n - 1, rooted at node 0. You are given a 2D integer array edges of length n - 1 where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.

At every node i, there is a gate. You are also given an array of even integers amount, where amount[i] represents:

the price needed to open the gate at node i, if amount[i] is negative, or,
the cash reward obtained on opening the gate at node i, otherwise.
The game goes on as follows:

Initially, Alice is at node 0 and Bob is at node bob.
At every second, Alice and Bob each move to an adjacent node. Alice moves towards some leaf node, while Bob moves towards node 0.
For every node along their path, Alice and Bob either spend money to open the gate at that node, or accept the reward. Note that:
If the gate is already open, no price will be required, nor will there be any cash reward.
If Alice and Bob reach the node simultaneously, they share the price/reward for opening the gate there. In other words, if the price to open the gate is c, then both Alice and Bob pay c / 2 each. Similarly, if the reward at the gate is c, both of them receive c / 2 each.
If Alice reaches a leaf node, she stops moving. Similarly, if Bob reaches node 0, he stops moving. Note that these events are independent of each other.
Return the maximum net income Alice can have if she travels towards the optimal leaf node.

*/

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
    vector<int> parent;

    void findBobPath(int node, int par, vector<vector<int>>& tree) {
        parent[node] = par;
        for (int next : tree[node]) {
            if (next != par) {
                findBobPath(next, node, tree);
            }
        }
    }

    int dfs(int node, vector<vector<int>>& tree, vector<int>& amount, vector<bool>& visited, int depth, unordered_map<int, int>& bobPath) {
        visited[node] = true;
        
        int total = 0;
        

        if (bobPath.count(node)) {
            if (bobPath[node] == depth) {
                total += amount[node] / 2;
            } else if (bobPath[node] > depth) {
                total += amount[node];
            }
        } else {
            total += amount[node];
        }

        int maxSubtree = INT_MIN;
        bool isLeaf = true;

        for (int next : tree[node]) {
            if (!visited[next]) {
                isLeaf = false;
                maxSubtree = max(maxSubtree, dfs(next, tree, amount, visited, depth + 1, bobPath));
            }
        }

        visited[node] = false;

        return total + (isLeaf ? 0 : maxSubtree);
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        vector<vector<int>> tree(n);
        
        for (auto& e : edges) {
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }

        parent.assign(n, -1);
        findBobPath(0, -1, tree);

        unordered_map<int, int> bobPath;
        int depth = 0;
        while (bob != -1) {
            bobPath[bob] = depth++;
            bob = parent[bob];
        }

        vector<bool> visited(n, false);
        return dfs(0, tree, amount, visited, 0, bobPath);
    }
};