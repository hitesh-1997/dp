// topcoder(tutorial) --dp -- intermediate max apple problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int arr[3][4]={{1,1,1,60},{1,2,1,5},{1,2,2,1}};
int v[3][4];
int n=3,m=4;

int find(int i,int j){
    if(i==0&&j==0)
        return arr[0][0];
    if(v[i][j]!=0)
        return v[i][j];
    if(i==0)
        v[i][j]=arr[i][j]+find(i,j-1);
    else if(j==0)
        v[i][j]=arr[i][j]+find(i-1,j);
    else
        v[i][j]=max(arr[i][j]+find(i-1,j),arr[i][j]+find(i,j-1));
    //cout<<" before return "<<v[i][j]<<endl;
    return v[i][j];
}

int main() {
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            v[i][j]=0;
    
    cout<<"max is "<< find(n-1,m-1)<<endl;
    for(int i=0;i<n;i++){
        cout<<endl;
        for(int j=0;j<m;j++)
            cout<<v[i][j]<<"  ";
    }
        

}
