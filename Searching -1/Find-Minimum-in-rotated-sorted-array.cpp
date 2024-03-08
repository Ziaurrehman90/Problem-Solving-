#include<bits/stdc++.h>
using namespace std;
int helper(vector<int>&nums){
     int low=0;
        int high=nums.size()-1;
        while(low<high){
            int mid=low+(high-low)/2;
            if(nums[mid]>nums[high]){
                low=mid+1;
            }
            else{
                high=mid;
            }
        }
        return low;
    }

    int findMin(vector<int>& nums) {
        // we should only find the pivot index 
        int index=helper(nums);
        return nums[index];
    }
    int main(){
        int n;
    cin>>n;
    vector<int>ans(n);
    for(int i=0;i<n;i++){
        cin>>ans[i];
    }
    
    cout<<findMin(ans)<<endl;
    return 0;
    }
       
