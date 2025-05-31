/*
https://leetcode.com/problems/path-with-maximum-probability/description/?envType=daily-question&envId=2024-08-27
You are given an undirected weighted graph of n nodes (0-indexed), represented by an edge list where edges[i] = [a, b] is an undirected edge connecting the nodes a and b with a probability of success of traversing that edge succProb[i].

Given two nodes start and end, find the path with the maximum probability of success to go from start to end and return its success probability.

If there is no path from start to end, return 0. Your answer will be accepted if it differs from the correct answer by at most 1e-5.

 

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


class Solution {
public:

    struct Edge {
        int node;
        double probability;
    };
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        // Create the graph as an adjacency list
    vector<vector<Edge>> graph(n);
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0], v = edges[i][1];
        double prob = succProb[i];
        graph[u].push_back({v, prob});
        graph[v].push_back({u, prob});
    }

    // Max heap priority queue to store (current probability, current node)
    priority_queue<pair<double, int>> pq;
    pq.push({1.0, start}); // Start with the start node with probability 1

    // Vector to track the maximum probability to reach each node
    vector<double> maxProb(n, 0.0);
    maxProb[start] = 1.0;

    while (!pq.empty()) {
        auto [curProb, curNode] = pq.top();
        pq.pop();

        // If we have reached the end node, return the probability
        if (curNode == end) return curProb;

        // If the current probability is less than the stored max probability, skip this node
        if (curProb < maxProb[curNode]) continue;

        // Traverse the neighbors
        for (Edge& edge : graph[curNode]) {
            double newProb = curProb * edge.probability;

            // If a higher probability is found, update and push to the queue
            if (newProb > maxProb[edge.node]) {
                maxProb[edge.node] = newProb;
                pq.push({newProb, edge.node});
            }
        }
    }

    // If we never reached the end node, return 0
    return 0.0;
    }
};