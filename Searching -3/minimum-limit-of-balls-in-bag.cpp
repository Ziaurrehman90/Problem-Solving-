#include<bits/stdc++.h>
using namespace std;
bool isvalid(vector<int> v,int n,int mid,int maxOperation ){
    int sum=0;
    for(auto x:v){
        sum+=x/mid - 1;
        if(x%mid) sum++;
        if(sum>maxOperation) return false;
    }
    return true;
}
class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int start=1;
        int end=*max_element(nums.begin(),nums.end());
        int ans=0,n=nums.size();
        while(start<=end){
            int mid=start+(end-start)/2;
            if(isvalid(nums,n,mid,maxOperations)){
                ans=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return ans;
    }
};