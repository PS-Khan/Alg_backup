/*
https://leetcode.com/problems/minimum-cost-walk-in-weighted-graph/description/?envType=daily-question&envId=2025-03-20

There is an undirected weighted graph with n vertices labeled from 0 to n - 1.

You are given the integer n and an array edges, where edges[i] = [ui, vi, wi] indicates that there is an edge between vertices ui and vi with a weight of wi.

A walk on a graph is a sequence of vertices and edges. The walk starts and ends with a vertex, and each edge connects the vertex that comes before it and the vertex that comes after it. It's important to note that a walk may visit the same edge or vertex more than once.

The cost of a walk starting at node u and ending at node v is defined as the bitwise AND of the weights of the edges traversed during the walk. In other words, if the sequence of edge weights encountered during the walk is w0, w1, w2, ..., wk, then the cost is calculated as w0 & w1 & w2 & ... & wk, where & denotes the bitwise AND operator.

You are also given a 2D array query, where query[i] = [si, ti]. For each query, you need to find the minimum cost of the walk starting at vertex si and ending at vertex ti. If there exists no such walk, the answer is -1.

Return the array answer, where answer[i] denotes the minimum cost of a walk for query i.

 

*/


// i got so far , and code so far , but in the end it doesnt even matter (incorrect)

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
#include <numeric>

using namespace std;

class Solution {
public:

    int min_cost(vector<int> edge, unordered_map<string, int> &map, vector<vector<pair<int,int>>> &matrix, int n, int cost, vector<int> &visited){
        string s = to_string(edge[0]) + to_string(edge[1]);
        string s2 = to_string(edge[1]) + to_string(edge[0]);
        if(map.find(s) != map.end()){
            return map[s];
        }
        if(map.find(s2) != map.end()){
            return map[s2];
        }

        //mark edge as visited if it has lees than 2 edges
        int count_edges = 0;
        for(int  i = 0; i < n; i++){
            int   f = matrix[edge[0]][i].first;
            if(f == 1 && !visited[i]){
                count_edges++;
            }
        }
        if(count_edges < 2){
            visited[edge[0]] = 1;
        }

        for(int  i = 0; i < n; i++){
            int   f = matrix[edge[0]][i].first;
            int sec = matrix[edge[0]][i].second;
            if(f == 1 && !visited[i]){
                int res = sec & min_cost({i,edge[1]}, map, matrix, n, cost, visited);
                cost    = min(cost, res);
            }
            
        }
        if(cost ==  INT_MAX){
            map[s] = -1;
            return -1;
        }
        map[s] = cost;
        map[s2] = cost;
        return cost;

    }

    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<vector<pair<int,int>>> matrix(n, vector<pair<int,int>>(n,{0,0}));
        unordered_map<string, int> map;
        for(vector<int> &edge : edges){
            matrix[edge[0]][edge[1]] = {1, edge[2]};
            matrix[edge[1]][edge[0]] = {1, edge[2]};
            string s = to_string(edge[0]) + to_string(edge[1]);
            string s2 = to_string(edge[1]) + to_string(edge[2]);
            map[s] = edge[2];
            map[s2] = edge[2];
        }
       
        vector<int> answer;
        vector<int> visited(n,0);
        for(vector<int> &edge : query){
            int res = min_cost(edge, map, matrix, n, INT_MAX, visited);
            answer.push_back(res);
        }

        return answer;

    }
};

//BFS

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges,
                            vector<vector<int>>& queries) {
        // Create the adjacency list of the graph
        vector<vector<pair<int, int>>> adjList(n);
        for (auto& edge : edges) {
            adjList[edge[0]].push_back({edge[1], edge[2]});
            adjList[edge[1]].push_back({edge[0], edge[2]});
        }

        vector<bool> visited(n, false);

        // Array to store the component ID of each node
        vector<int> components(n);
        vector<int> componentCost;

        int componentId = 0;

        // Perform BFS for each unvisited node to identify components and
        // calculate their costs
        for (int node = 0; node < n; node++) {
            // If the node hasn't been visited, it's a new component
            if (!visited[node]) {
                // Get the component cost and mark all nodes in the component
                componentCost.push_back(getComponentCost(
                    node, adjList, visited, components, componentId));
                // Increment the component ID for the next component
                componentId++;
            }
        }

        vector<int> answer;

        for (auto& query : queries) {
            int start = query[0];
            int end = query[1];

            if (components[start] == components[end]) {
                // If they are in the same component, return the precomputed
                // cost for the component
                answer.push_back(componentCost[components[start]]);
            } else {
                // If they are in different components, return -1
                answer.push_back(-1);
            }
        }

        return answer;
    }

private:
    // Helper function to calculate the cost of a component using BFS
    int getComponentCost(int source, vector<vector<pair<int, int>>>& adjList,
                         vector<bool>& visited, vector<int>& components,
                         int componentId) {
        queue<int> nodesQueue;

        // Initialize the component cost to the number that has only 1s in its
        // binary representation
        int componentCost = INT_MAX;

        nodesQueue.push(source);
        visited[source] = true;

        // Perform BFS to explore the component and calculate the cost
        while (!nodesQueue.empty()) {
            int node = nodesQueue.front();
            nodesQueue.pop();

            // Mark the node as part of the current component
            components[node] = componentId;

            // Explore all neighbors of the current node
            for (auto& [neighbor, weight] : adjList[node]) {
                // Update the component cost by performing a bitwise AND of the
                // edge weights
                componentCost &= weight;

                // If the neighbor hasn't been visited, mark it as visited and
                // add it to the queue
                if (visited[neighbor]) continue;
                visited[neighbor] = true;
                nodesQueue.push(neighbor);
            }
        }

        return componentCost;
    }
};