#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, m, k;
  int ans=0;
  cin >> n >> m >> k;
  vector<long long> a(n), b(m), arr1(n+1), arr2(m+1);
  for(int i=0; i<n; i++){
    cin >> a[i];
    arr1[i+1]=arr1[i]+a[i];
  }
  int ind=0;
  for(int i=0; i<m; i++){
    cin >> b[i];
    arr2[i+1]=arr2[i]+b[i];
    if(arr2[i+1]<=k) {
      ind=i+1; 
  }
  }
  for(int i=0; i<n+1; i++){
    if(arr1[i]>k) {
      break;
    }
  
    while(arr1[i]+arr2[ind]>k) ind--;
    ans=max(ans, i+ind);
  }
  cout << ans << endl;
  return 0;
}