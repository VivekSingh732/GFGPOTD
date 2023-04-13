#include<bits/stdc++.h>
using namespace std;
/*Input:
N = 5
A[] = [4,2,2,5,1]
Output: 4
Explanation: let partition the array 
P,Q,R,S = [4],[2,2],[5],[1]
W = 4, X = 4, Y = 5, Z = 1 
Differnce = max(W,X,Y,Z)-min(W,X,Y,Z)= 5-1 = 4 */
class Solution
{
public:
   typedef pair<long long,long long> p;
   p minmax(long long prSm[],int l,int r){
       int low=l;
       int high=r-1;
       long long minSm=0,maxSm=prSm[r]-prSm[l-1];
       while(low<=high){
           int mid=low+(high-low)/2;
           long long lSm=prSm[mid]-prSm[l-1];
           long long rSm=prSm[r]-prSm[mid];
           if(abs(lSm-rSm)<maxSm-minSm){
               minSm=min(lSm,rSm);
               maxSm=max(lSm,rSm);
           }
           if(lSm<rSm){
               low=mid+1;
           }else{
               high=mid-1;
           }
       }
       return {minSm,maxSm};
   }
    long long minDifference(int n, vector<int> &arr) {
      long  long preSm[n+1];
      preSm[0]=0;
      for(int i=1;i<=n;i++){
          preSm[i]=preSm[i-1]+arr[i-1];
      }
      long long ans=preSm[n];
      for(int i=1;i<n-2;i++){
          p left=minmax(preSm,1,i+1);
          p right=minmax(preSm,i+2,n);
          ans=min(ans,max(left.second,right.second)-min(left.first,right.first));
      }
      return ans;
    }
};