#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;


  void moveZeroes(vector<int>& nums) {
        auto it = std::remove(nums.begin(),nums.end(),0);
        std::fill(it,nums.end(),0);
    }
    
//like pivot in qs
void moveZeroes(vector<int>& nums) {
        int r=0;
        for(int i = 0; i < nums.size(); i++ ){
            if(nums[i] != 0){
                int tmp = nums[r];
                nums[r] = nums[i];
                nums[i] = tmp;
                r++;
            }
        }

    }