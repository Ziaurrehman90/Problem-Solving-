#include<bits/stdc++.h>
using namespace std;
int search(vector<int>& arr, int target) {
        int n=arr.size();
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            // when we  got the target just return the index 
            if(arr[mid]==target){
                return mid;
            }
            else if(arr[low]<=arr[mid]){
                if(target>=arr[low] && target<arr[mid]){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            else{
                if(target>arr[mid] && target<=arr[high]){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }


           
            
        }
        
        return -1;
        
    }
int main(){
    // here is the concept pt 
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
