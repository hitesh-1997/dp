#include <cmath>
#include <cstdio>
#include <vector>
#include <climits>
#include <iostream>
using namespace std;

int arr[50];
int n;

int find(int jump[],int n){
    if(n==0)
        return 0;
    if(jump[n]!=999)
        return jump[n];
    for(int i=n-1;i>=0;i--){
        if(i+arr[i]>=n){
            int min=find(jump,i)+1;
            if(min<jump[n])
                jump[n]=min;
        }
            
    }
    return jump[n];
    
}

int main() {
    cin>>n;
    int jump[50];
    for(int i=0;i<n;i++){
        cin >> arr[i];
        jump[i]=999;
    }
    cout<<find(jump,n-1);
    
    /*cout<<"jump array "<<endl;
    for(int i=0;i<n;i++)
        cout<<jump[i]<<" ";*/
    //cout<<count;
    
}
