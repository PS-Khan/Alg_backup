/*

You are given an undirected weighted connected graph containing n nodes labeled from 0 to n - 1, and an integer array edges where edges[i] = [ai, bi, wi] indicates that there is an edge between nodes ai and bi with weight wi.

Some edges have a weight of -1 (wi = -1), while others have a positive weight (wi > 0).

Your task is to modify all edges with a weight of -1 by assigning them positive integer values in the range [1, 2 * 109] so that the shortest distance between the nodes source and destination becomes equal to an integer target. If there are multiple modifications that make the shortest distance between source and destination equal to target, any of them will be considered correct.

Return an array containing all edges (even unmodified ones) in any order if it is possible to make the shortest distance from source to destination equal to target, or an empty array if it's impossible.

Note: You are not allowed to modify the weights of edges with initial positive weights.

 https://leetcode.com/problems/modify-graph-edge-weights/?envType=daily-question&envId=2024-08-30

*/



#include <iostream>
#include <type_traits>
#include <typeinfo>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#include <list>
using namespace std;


class Solution {
public:
    const int INF = 2e9;

    vector<vector<int>> modifiedGraphEdges(int nodeCount,
                                           vector<vector<int>>& edges,
                                           int source, int destination,
                                           int target) {
        // Step 1: Compute the initial shortest distance from source to
        // destination
        long long currentShortestDistance =
            runDijkstra(edges, nodeCount, source, destination);

        // If the current shortest distance is less than the target, return an
        // empty result
        if (currentShortestDistance < target) return {};

        bool matchesTarget = (currentShortestDistance == target);

        // Step 2: Iterate through each edge to adjust its weight if necessary
        for (vector<int>& edge : edges) {
            // Skip edges that already have a positive weight
            if (edge[2] > 0) continue;

            // Set edge weight to a large value if current distance matches
            // target else set to 1
            edge[2] = matchesTarget ? INF : 1;

            // Step 3: If current shortest distance does not match target
            if (!matchesTarget) {
                // Compute the new shortest distance with the updated edge
                // weight
                long long newDistance =
                    runDijkstra(edges, nodeCount, source, destination);
                // If the new distance is within the target range, update edge
                // weight to match target
                if (newDistance <= target) {
                    matchesTarget = true;
                    edge[2] += target - newDistance;
                }
            }
        }

        // Return modified edges if the target distance is achieved, otherwise
        // return an empty result
        return matchesTarget ? edges : vector<vector<int>>{};
    }

    // Dijkstra's algorithm to find the shortest path distance
    long long runDijkstra(const vector<vector<int>>& edges, int nodeCount,
                          int sourceNode, int destinationNode) {
        // Step 1: Initialize adjacency matrix and distance arrays
        vector<vector<long long>> adjMatrix(nodeCount,
                                            vector<long long>(nodeCount, INF));
        vector<long long> minDistance(nodeCount, INF);
        vector<bool> visited(nodeCount, false);

        // Set the distance to the source node as 0
        minDistance[sourceNode] = 0;

        // Step 2: Fill the adjacency matrix with edge weights
        for (const vector<int>& edge : edges) {
            if (edge[2] != -1) {
                adjMatrix[edge[0]][edge[1]] = edge[2];
                adjMatrix[edge[1]][edge[0]] = edge[2];
            }
        }

        // Step 3: Perform Dijkstra's algorithm
        for (int i = 0; i < nodeCount; ++i) {
            // Find the nearest unvisited node
            int nearestUnvisitedNode = -1;
            for (int j = 0; j < nodeCount; ++j) {
                if (!visited[j] &&
                    (nearestUnvisitedNode == -1 ||
                     minDistance[j] < minDistance[nearestUnvisitedNode])) {
                    nearestUnvisitedNode = j;
                }
            }
            // Mark the nearest node as visited
            visited[nearestUnvisitedNode] = true;

            // Update the minimum distance for each adjacent node
            for (int v = 0; v < nodeCount; ++v) {
                minDistance[v] =
                    min(minDistance[v], minDistance[nearestUnvisitedNode] +
                                            adjMatrix[nearestUnvisitedNode][v]);
            }
        }

        // Return the shortest distance to the destination node
        return minDistance[destinationNode];
    }
};