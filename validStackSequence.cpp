#include<bits/stdc++.h>
using namespace std;
// Better
bool valideStackSequence(vector<int>&pushded,vector<int>&popped){
    stack<int>st;
    int j=0;
    for(auto x:pushded){
        st.push(x);
        while(st.size()>0 && st.top()==popped[j]){
            st.pop();
            j++;
        }
    }
    return st.size()==0;
}
// optimal Approach
bool validSequence(vector<int>&pushed,vector<int>&popped){
    int i=0;
    int j=0;
    for(auto x:pushed){
        pushed[i++]=x;
        while(i>0 && pushed[i-1]==popped[j]){
            i--;
            j++;
        }
    }
    return i==0;
}
int main(){

}