#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
      set<int>s;
     int n=nums.size();
     for(int i=0;i<n;i++){
         s.insert(nums[i]);
     }   
     int i=1;
     while(i<=n){
         if(s.find(i)!=s.end()){
             i++;
         }else{
             return i;
         }
     }
     return n+1;
    }
};
int main(){
    int n;
    Solution s1;
    cout<<"Enter The size of Array"<<endl;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int missingNO=s1.firstMissingPositive(*arr);
    cout<<missingNO<<endl;
}