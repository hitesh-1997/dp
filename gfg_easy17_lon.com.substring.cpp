
// code might have a bug in find function

#include <cmath>
#include <cstdio>
#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

int table[100][100];
string s,t;
int m,n;

int find(int i,int j){
    //cout<<"for i,j= "<<i<<" "<<j<<" tabe= "<<table[i][j]<<endl;
    if(i==m-1||j==n-1)
        table[i][j]=0;
    if(table[i][j]!=-1)
        return table[i][j];
    if(s[i]==t[j])
        table[i][j]= find(i+1,j+1)+1;
    else
        table[i][j]=max(find(i,j+1),find(i+1,j));
    return table[i][j];
    
}

int main() {
    cin >> s  >> t;
    m=s.size();
    n=t.size();
    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= n; j++)
            table[i][j] = -1;
    cout << find(0,0);
   /* for (int i = 0; i <= m; i++){
        cout<<endl;
        for (int j = 0; j <= n; j++)
            cout<<table[i][j]<<" ";
    }*/

}
