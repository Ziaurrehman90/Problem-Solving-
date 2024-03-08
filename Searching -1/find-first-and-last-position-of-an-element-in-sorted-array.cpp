#include<bits/stdc++.h>
using namespace std;
int first_position(vector<int>&nums,int target){
    int low=0;
    int high=nums.size()-1;
    int index=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(nums[mid]==target){
            index=mid;
            high=mid-1;
        }
        else if(nums[mid]>target){
            high=mid-1;
        }
        else{
            low=mid+1;
        }

    }
    return index;
}
int last_position(vector<int>&nums,int target){
    int low=0;
    int high=nums.size()-1;
    int index=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(nums[mid]==target){
            index=mid;
            // high=mid-1;
            low=mid+1;
        }
        else if(nums[mid]>target){
            high=mid-1;
        }
        else{
            low=mid+1;
        }

    }
    return index;
}
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans;
        int a=first_position(nums,target);
         int b=last_position(nums,target);
         ans.push_back(a);
         ans.push_back(b);
         return ans;
       
    }
int main(){
    int n;
    cin>>n;
    vector<int>ans(n);
    for(int i=0;i<n;i++){
        cin>>ans[i];
    }
    int target;
    cin>>target;
    vector<int>a=searchRange(ans,target);
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    return 0;

}