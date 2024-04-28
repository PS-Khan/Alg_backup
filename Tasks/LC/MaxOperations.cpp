/*
You are given an integer array nums and an integer k.

In one operation, you can pick two numbers from the array whose sum equals k and remove them from the array.

Return the maximum number of operations you can perform on the array.
*/

#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <unordered_map>
using namespace std;

/*too slow, sad but true.*/

int maxOperations(vector<int>& nums, int k) {
        int count = 0;
        int size = nums.size();
        for(int j = 0; j < size; j++){
            if(nums[j] == k){
                continue;
            }
            for(int i = j+1; i<size; i++ ){
                if(nums[i] + nums[j] == k){
                    count++;
                    nums[j] = k;
                    nums[i] = k;
                    break;
                }
            }
        }
       
        return count;
    }


//
int maxOperations(vector<int>& nums, int k) {
        int count = 0;
        int size = nums.size();
        std::unordered_map<int,int> numap;
        for(int &i: nums){
            numap[i]++;
        }
        for(auto &i: numap){
            int dif = k - i.first;
            if(dif == i.first){
                count+= i.second/2;
                i.second =0;
            }else if(numap.find(dif) != numap.end()){
                int res = min(i.second, numap[dif]);
                count+=res;
                numap[dif] -= res;
                i.second -= res;
            }

        }

        
        return count;
    }



int maxOperations(std::vector<int>& nums, int k) {
    std::unordered_map<int, int> freq;
    int count = 0;

    for (int num : nums) {
        int complement = k - num;
        if (freq[complement] > 0) {
            count++;
            freq[complement]--;
        } else {
            freq[num]++;
        }
    }

    return count;
}