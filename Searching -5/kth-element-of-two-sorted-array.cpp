#include<bits/stdc++.h>
int kthElement(vector<int> &arr1, vector<int>& arr2, int n, int m, int k){

   
int low=n-1;
int high=0;
while(low>=0 && high<=m-1){
    if(arr1[low]>=arr2[high]){
        swap(arr1[low],arr2[high]);
        low--;
        high++;
    }
    else{
        break;
    }
}
sort(arr1.begin(),arr1.end());
sort(arr2.begin(),arr2.end());
if(k<=n){
    return arr1[k-1];
}
else{
    return arr2[k-(n+1)];
}
return 0;
}
