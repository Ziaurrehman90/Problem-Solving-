// lets create the helper function that counts all the elements less than equal to the mid 

  int helper(vector<int>&a,int midE){
      int low=0;
      int high=a.size()-1;
      while(low<=high){
          int mid=low+(high-low)/2;
          if(a[mid]<=midE){
              low=mid+1;
          }
          else{
              high=mid-1;
          }
      }
      return low;
  }

int Solution ::findMedian(vector<vector<int> > &A) {
    // let's first define the search space 
    int low=1;
    int high=INT_MAX;
    int n=A.size();
    int m=A[0].size();
    while(low<=high){
        int mid=low+(high-low)/2;
        // now i have to count those elements in a matrix which are smaller thean mid 
        int count=0;
        for(int i=0;i<A.size();i++){
            count+=helper(A[i],mid);
        }
        // now check for the median condition 
        if(count<=(n*m)/2){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
        
    }
    return low;
}
