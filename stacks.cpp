//https://www.codechef.com/problems/STACKS
#include<bits/stdc++.h>
using namespace std;

void show(int arr[],int n){
    for(int i =0; i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
/*
    **This code is has linear search which gave TLE**


int main(){
    int T;
    cin>>T;
    while(T--){
        int N,n;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N; i++){
            cin>>n;
            arr[i] = n;
        }
        int arr1[N],top=1,j;
        arr1[0] = arr[0];
        for(int i=1;i<N;i++){
            j = 0;
            while(j<top){
                if(arr[i]<arr1[j]){
                    arr1[j] = arr[i];
                    break;
                }else{
                    j++;
                }
            }
            if(j>=top){
                arr1[top] = arr[i];
                top++;
            }
        }
        cout<<top<<" ";
        show(arr1,top);
    }
    return 0;
}
*/

// replaced linear search with binary search

int main(){
    int T;
    cin>>T;
    while(T--){
        int N,n;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N; i++){
            cin>>n;
            arr[i] = n;
        }
        int arr1[N],top=1,j,index;
        arr1[0] = arr[0];
        for(int i=1;i<N;i++){
                if(upper_bound(arr1,arr1+top,arr[i])-arr1 == top){
                    //cout<<upper_bound(arr1,arr1+top,arr[i])-arr1<<endl;
                    arr1[top] = arr[i];
                    top++;
                }else{
                    index = upper_bound(arr1,arr1+top,arr[i])-arr1;
                    arr1[index] = arr[i];
                }
        }
        cout<<top<<" ";
        show(arr1,top);
    }
    return 0;
}
