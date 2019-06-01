//https://www.spoj.com/problems/JNEXT/
#include <bits/stdc++.h>
using namespace std;

void showstack(stack <int>s){
  // cout<<"stack is";
  while(!s.empty()){
    cout<<s.top();
    s.pop();
  }
  cout<<'\n';
}

void reversestack(stack <int>s){
  stack <int> temp;
  while(!s.empty()){
    temp.push(s.top());
    s.pop();
  }
  showstack(temp);
}

int main(){
   int T;
   cin>>T;
   while(T--){
     int n,ni;
     cin>>n;
     stack <int> s;
     vector<int> v;
     for(int i = 0;i < n;i++){
       cin>>ni;
       s.push(ni);
     }
     if(n!=1){
       v.push_back(s.top());
       s.pop();
       while(v.back() <= s.top() && !s.empty()){
         v.push_back(s.top());
         s.pop();
         if(s.empty()){
           break;
         }
       }
       if(!s.empty()){
         v.push_back(s.top());
         s.pop();
         int nmax,temp,j;
         nmax = 10000000;
         for(int i = 0; i < v.size()-1;i++){
            if(v[i]>v.back() && v[i] <nmax  ){
              nmax = v[i];
              j = i;
            }else{
              continue;
            }
         }
         temp = v.back();
         v[v.size()-1] = v[j];
         v[j] = temp;

         s.push(v.back());
         v.pop_back();
         sort(v.begin(),v.end());
         for(int i = 0;i<v.size();i++){
           s.push(v[i]);
         }
         reversestack(s);
       }else{
         cout<<-1<<endl;
       }


     }else{
       cout<<-1<<endl;
     }
     }
  return 0;
}
