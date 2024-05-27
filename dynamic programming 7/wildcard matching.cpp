// class Solution {
// public:
// bool f(string &s,string &p,int i,int j){
// //base casae
// // true kab return hoga jab dono 1 sath string khatam ho zaye
// if(i<0 && j<0){
//     return true;
// }
// // agr meri string s tou khatam ho gi but p bachi iska kya mtlv  h yahi k string equal nhi ho sakti
// if(j<0 && i>=0){
//     return false;
// }
// // last case k string phli bchi h but last puri khatam hogi h tou true tabhi return krunga agr mere saare characters * bche honge
// if(i<0 && j>=0){
// for(int k=0;k<=i;k++){
//     if(s[k]!='*'){
//         return false;
//     }
// }
// return true;
// }

//     //match condtion

//     if(s[i]==p[j] || s[i]=='?'){
//         return f(s,p,i-1,j-1);
//     }
//     //not matching condition
//     //case 1 ki m kya kru * ko neglect hi kr deta hm
//     if(s[i]=='*'){
//         // f(s,p,i-1,j);
//         //dusri situation yeh h k character hi deltt kr du
//         // f(s,p,i,j-1);
//         return  f(s,p,i-1,j) |  f(s,p,i,j-1);
//     }
//     return false;

// }
//     bool isMatch(string s, string p) {
//         //match comdition

//         int n=s.size();
//         int m=p.size();
//         return f(s,p,n-1,m-1);

//     }
// };
class Solution
{
public:
    bool solve(string &s, string &p, int i, int j, vector<vector<int>> &dp)
    {

        if (i < 0 && j < 0)
        {
            return 1;
        }

        if (i >= 0 && j < 0)
            return 0;

        if (i < 0 && j >= 0)
        {
            while (j >= 0)
            {
                if (p[j] != '*')
                    return 0;
                j--;
            }
            return 1;
        };
        if (dp[i][j] != -1)
            return dp[i][j];
        if (p[j] == s[i] || p[j] == '?')
        {
            return dp[i][j] = solve(s, p, i - 1, j - 1, dp);
        }

        if (p[j] == '*')
        {
            int t = solve(s, p, i - 1, j, dp);

            int neglect = solve(s, p, i, j - 1, dp);
            return dp[i][j] = t || neglect;
        }
        return dp[i][j] = 0;
    }
    bool isMatch(string &s, string &p)
    {

        int n = s.size();
        int m = p.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return solve(s, p, n - 1, m - 1, dp);
    }
};