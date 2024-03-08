#include<bits/stdc++.h>
using namespace std;
 bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int start=0;
        int end=n-1;
        int mid;
        while(start<=end){
            mid=(start+end)/2;
            if(nums[mid]==target){
                return true;
            }
            else if(nums[mid]>nums[start]){
                if(target>=nums[start]&&target<nums[mid]){
                    end=mid-1;
                }
                
                
                else{
                    start=mid+1;
                }
            }
            else if(nums[mid]==nums[start]){
                start++;
            }
            else if(nums[mid]==nums[end]){
                end--;
            }
            else{
                if(target>nums[mid]&&target<=nums[end]){
                    start=mid+1;
                }
                
                else{
                    end=mid-1;
                }
            }
        }
        return false;
        
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
    cout<<search(ans,target)<<endl;
    return 0;
    }