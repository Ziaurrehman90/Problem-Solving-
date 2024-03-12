#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int ans;
    int minDays(vector<int>& arr, int m, int k) {
        
          ans = INT_MAX;
          int start = 0;
          int end   = *max_element(arr.begin(),arr.end());
          while(start <= end)
          {
              int mid = (start + end)/2;
              
              if(fun(mid,arr,m,k) == true)
              {
                   ans = min(ans,mid);
                   end = mid-1;   
              }
              else 
              {
                  start = mid+1;
              }
          }
          if(ans == INT_MAX) return -1;
          return ans;
    }
    bool fun(int mid,vector<int>&arr,int m,int k)
    {
        int idx = 0;
        while((idx < arr.size()) and (m > 0))
        {
            int temp = k;
            while((idx < arr.size()) and (temp > 0))
            {
                if(mid < arr[idx]) {
                    idx++;
                    break;
                }

                temp--;
                idx = idx + 1;
            }
            if(temp == 0) m--;
        }
        if(m == 0) return true;
        return false;
    }
};