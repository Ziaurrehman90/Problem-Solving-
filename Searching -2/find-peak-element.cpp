#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int low = 0;
        int high = nums.size()-1;
        while(low<=high){
            int mid = low+(high-low)/2 ;
            if( mid-1>=low && nums[mid-1]>nums[mid] )
                high = mid-1;
            else if( mid+1<=high && nums[mid]<nums[mid+1] )
                low = mid+1;
            else
                return mid;
        } 
        return -1;
    }
};