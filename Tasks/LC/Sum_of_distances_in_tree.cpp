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


/*
There is an undirected connected tree with n nodes labeled from 0 to n - 1 and n - 1 edges.

You are given the integer n and the array edges where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.

Return an array answer of length n where answer[i] is the sum of the distances between the ith node in the tree and all other nodes.

Input: n = 6, edges = [[0,1],[0,2],[2,3],[2,4],[2,5]]
Output: [8,12,6,10,10,10]
Explanation: The tree is shown above.
We can see that dist(0,1) + dist(0,2) + dist(0,3) + dist(0,4) + dist(0,5)
equals 1 + 1 + 2 + 2 + 2 = 8.
Hence, answer[0] = 8, and so on.


Input: n = 1, edges = []
Output: [0]

Input: n = 2, edges = [[1,0]]
Output: [1,1]
*/

using namespace std;



class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        count.resize(n, 1);
        ans.resize(n, 0);

        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        dfs1(0, -1);
        dfs2(0, -1);

        return ans;
    }

private:
    vector<vector<int>> adj;
    vector<int> count;
    vector<int> ans;

    void dfs1(int node, int parent) {
        for (int neighbor : adj[node]) {
            if (neighbor != parent) {
                dfs1(neighbor, node);
                count[node] += count[neighbor];
                ans[node] += ans[neighbor] + count[neighbor];
            }
        }
    }

    void dfs2(int node, int parent) {
        for (int neighbor : adj[node]) {
            if (neighbor != parent) {
                ans[neighbor] = ans[node] - count[neighbor] + (adj.size() - count[neighbor]);
                dfs2(neighbor, node);
            }
        }
    }
};