#include<bits/stdc++.h>
using namespace std;
class Solution 
{
    public:
    bool isPossible(int arr[],int n,int m,int mid){
        int stcnt=1;
        int pageSm=0;
        for(int i=0;i<n;i++){
            if(pageSm+arr[i]<=mid){
                pageSm+=arr[i];
            }else{
                stcnt++;
                if(stcnt>m || arr[i]>mid){
                    return false;
                }
                pageSm=arr[i];
            }
        }
        return true;
    }
    int findPages(int arr[], int n, int m) 
    {
       int low=0;
       int sum=0;
       for(int i=0;i<n;i++){
           sum+=arr[i];
       }
       int high=sum;
       int ans=-1;
       while(low<=high){
           int mid=low+(high-low)/2;
           if(isPossible(arr,n,m,mid)){
               ans=mid;
               high=mid-1;
           }else{
               low=mid+1;
           }
       }
       return ans;
    }
};
int main(){
    cout<<"Enter The number of test Cases"<<endl;
    int t;
    cin>>t;
    while(t--){
        int n;
        cout<<"Enter The Size of Array"<<endl;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int m;
        cout<<"Enter The Number of Student"<<endl;
        cin>>m;
        Solution s;
        cout<<s.findPages(arr,n,m)<<endl;
    }
}