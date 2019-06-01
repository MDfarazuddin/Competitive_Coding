#include<bits/stdc++.h>
using namespace std;

int main(){
  while(1){
    int n;
    cin>>n;
    if(n==0){
      break;
    }
    vector <int> v;
    int ni;
    for(int i = 0;i<n;i++){
      cin>>ni;
      v.push_back(ni);
    }
    stack <int> s;
    int i1=1 , i2 = 1;
    while(i1 < n+1){
      if(s.empty()){
        if(v[i2-1] == i1 ){
          i2++;
          i1++;
          // cout<<"1"<<i2<<i1<<endl;
        }else{
          s.push(v[i2-1]);
          i2++;
          // cout<<"2"<<i2<<i1<<endl;
        }
      }else if(s.top() == i1){
        i1++;
        s.pop();
        // cout<<"3"<<i2<<i1<<endl;
      }else if(v[i2-1] ==i1 ){
        i1++;
        i2++;
        // cout<<"4"<<i2<<i1<<endl;
      }else if(s.top() > v[i2-1] && v[i2-1] !=i1){
        s.push(v[i2-1]);
        i2++;
        // cout<<"5"<<i2<<i1<<endl;
      }else{
        cout<<"no"<<endl;
        while(!s.empty()){
          s.pop();
        }
        break;
      }
    }
    if(i1>=n){
      cout<<"yes"<<endl;
  }

  }
  return 0;
}
