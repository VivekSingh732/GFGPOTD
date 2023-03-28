#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
// count Operation 
int SoldiersCnt(vector<int>&sol){
    int low=0;
    int high=sol.size()-1;
    int mid=0;
    while(low<=high){
        mid=low+(high-low)/2;
        if(sol[mid]==0){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return low;
}
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        priority_queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            q.push({SoldiersCnt(mat[i]),i});
            if(q.size()>k){
                q.pop();
            }
        }
        vector<int>ans;
        while(q.size()){
            ans.push_back(q.top().second);
            q.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};