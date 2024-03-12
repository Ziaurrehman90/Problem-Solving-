#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
                int a=0;
        for(int i=0;i<nums.size();i++){
          a=nums[i]^a;
        }
        return a;       
        
    }
};