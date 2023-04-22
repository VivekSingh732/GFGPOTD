#include<bits/stdc++.h>
using namespace std;
/*Input:
n = 3
arr = {1, 2, 3}
Output:
0 1 3
Explanation:
For 1, there are no elements lesser than itself.
For 2, only 1 is lesser than 2.
And for 3, 1 and 2 are lesser than 3, so the sum is 3.*/
int  bianrySearch(vector<int>&arr,int k){
     int n=arr.size();
     int low=0;
     int high=n-1;
     while(low<high){
         int mid=(low+high)/2;
         if(arr[mid]<k){
             low=mid+1;
         }else{
             high=mid;
         }
     }
     return low;
 }
    vector<long long> smallerSum(int n,vector<int> &arr){
       vector<long long>res(n,0);
       vector<int>dup=arr;
       sort(dup.begin(),dup.end());
       int sum=0;
       vector<long long>pref(n,0);
       pref[0]=dup[0];
       for(int i=1;i<n;i++){
           pref[i]=pref[i-1]+dup[i];
       }
       for(int i=0;i<n;i++){
           int ind=bianrySearch(dup,arr[i]);
           
           if(ind!=0){
               res[i]=pref[ind-1];
           }else{
               res[i]=0;
           }
       }
       return res;
    }