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
Given two 0-indexed integer arrays nums1 and nums2, return a list answer of size 2 where:

answer[0] is a list of all distinct integers in nums1 which are not present in nums2.
answer[1] is a list of all distinct integers in nums2 which are not present in nums1.
Note that the integers in the lists may be returned in any order.
*/


vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<vector<int>> answer(2,vector<int>());
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            while(i+1 < nums1.size() && nums1[i] == nums1[i+1] ){
                i++;
            }
            while(j+1 < nums2.size() && nums2[j] == nums2[j+1] ){
                j++;
            }
            if (nums1[i] == nums2[j]) {
                i++;
                j++;
            } else if (nums1[i] < nums2[j]) {
                answer[0].push_back(nums1[i]);
                i++;
                
            } else if (nums1[i] > nums2[j]) {
                answer[1].push_back(nums2[j]);
                j++;
            }
        }
        while (i < nums1.size()) {
            if (!answer[0].empty() && answer[0].back() != nums1[i]) {
                answer[0].push_back(nums1[i]);
            } else if (answer[0].empty()) {
                answer[0].push_back(nums1[i]);
            }
            i++;
        }

        while (j < nums2.size()) {
            if (!answer[1].empty() && answer[1].back() != nums2[j]) {
                answer[1].push_back(nums2[j]);
            } else if (answer[1].empty()) {
                answer[1].push_back(nums2[j]);
            }
            j++;
        }
        return answer;
    }