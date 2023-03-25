#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int target) {
     int n=arr.size();
     int m=arr[0].size();
     int i=0,j=m-1;
     while(i<n && j>=0){
         if(arr[i][j]==target){
             return true;
         }
         if(arr[i][j]>target){
             j--;
         }else{
             i++;
         }
     }
     return false;
    }
};