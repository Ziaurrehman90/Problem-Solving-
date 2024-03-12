
class Solution {
public:
    int mySqrt(int x) {
        if (x==0) return 0;
        int low=1, high=x, mid;
        while(high-low>1){
            mid=low+(high-low)/2;
            if ((long long)mid*mid<=(long long)x)
                low=mid;
            else
                high=mid;
        }
        return low;       
    }
};
