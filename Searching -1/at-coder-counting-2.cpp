#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,q;
    cin>>n>>q;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<int>query(q);
    for(int i=0;i<q;i++){
        cin>>query[i];
    }
    sort(v.begin(),v.end());
    int p=v.size();
    // vector<int>ans(q);
    for(int i=0;i<q;i++){
       
        int low=0;
        int high=n-1;
        int index=p;
        while(low<=high){
            int mid=low+(high-low)/2;
            
           if(v[mid]>=query[i]){
            index=mid;
                high=mid-1;
                
            }
            else{
                low=mid+1;
            }
        }
        cout<<p-index<<endl;

    }
    // for(int i=0;i<ans.size();i++){
    //     cout<<ans[i]<<" ";
    // }
    return 0;

}