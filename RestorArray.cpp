#include<bits/stdc++.h>
using namespace std;
/*Input: s = "1317", k = 2000
Output: 8
Explanation: Possible arrays are [1317],[131,7],[13,17],[1,317],[13,1,7],[1,31,7],[1,3,17],[1,3,1,7]*/
class Solution {
public:
    int numberOfArrays(string s, int k) {
       vector<int>dp(s.size(),-1);
       return solve(s,k,0,dp);
    }
    int solve(const string& s,int k,int i,vector<int>&dp){
        int n=1e9+7;
        if(i==s.size()) return 1;
        if(s[i]=='0') return 0;
        if(dp[i]!=-1){
            return dp[i];
        }
        int ans=0;
        long temp=0;
        for(int j=i;j<s.size();j++){
            temp=temp*10+s[j]-'0';
            if(temp>k){
                break;
            }
            ans+=solve(s,k,j+1,dp);
            ans=ans%n;
        }
        return dp[i]=ans;
    }
};