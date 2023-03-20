#include<bits/stdc++.h>
using namespace std;
class Postfix{
    public:
    Postfix(){

    }
    int evaluatePostfix(string S)
    {
       stack<int>s;
       char ch;
       for(int i=0;i<S.length();i++){
           if(S[i]=='*' ||  S[i]=='/' || S[i]=='+' || S[i]=='-'){
               int a=s.top();
               s.pop();
               int b=s.top();
               s.pop();
               int res=0;
               if(S[i]=='*'){
                   res=a*b;
               }
               else if(S[i]=='/'){
                   res=b/a;
               }
               else if(S[i]=='+'){
                   res=b+a;
               }
               else if(S[i]=='-'){
                   res=b-a;
               }
               s.push(res);
           }else{
               s.push(int(S[i]-48));
           }
       }
       return s.top();
    }

};
int main(){
    int t;
    cin>>t;
    while(t--){
   Postfix p1;
    string s;
    cout<<"Enter The Postfix Experession"<<endl;
    cin>>s;
    cout<<p1.evaluatePostfix(s)<<endl;
    }
  return 0;
}