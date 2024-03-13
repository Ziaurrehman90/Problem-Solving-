class Solution{
public:
    bool Can_Place(int dist,int n, int k, vector<int> &s){
      // It checks if it's possible to place k cows in the stalls with a minimum distance dist between them.
// It iterates through the stalls, checking if the distance between consecutive stalls is greater than or equal to dist.

      // If the condition is met for placing all k cows, it returns true, indicating it's possible to place k cows with the given minimum distance.
// Otherwise, it returns false.
        int cows = 1;
        int last = s[0];
        for(int i =0;i<n;i++){
            if(s[i]-last>=dist){
                cows++;
                last = s[i];
            }
            if(cows>=k) return true;
        }
        return false;
    }
    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(),stalls.end());
        int low = 0,high = INT_MAX;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(Can_Place(mid,n,k,stalls)){
                low= mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return high;
    }
};
