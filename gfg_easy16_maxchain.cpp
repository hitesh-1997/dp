#include <cmath>
#include <cstdio>
#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

vector< pair<int,int> > v;
int table[100]={0};

int find(int n){
    
    if(n==1)
        return 1;
    if(table[n-1]!=0)
        return table[n-1];
    int max=1;
    for(int i=0;i<n-1;i++){
        if(v[i].second<v[n-1].first){
            int value=find(i+1);
            if(value+1>max)
                max=value+1;
            cout<<v[n-1].first<<" "<<v[i].second<<" "<<value<<" "<<max<<endl;
        }
    }
    table[n-1]=max;
    return table[n-1];
}

int main() {
    int n,x,y;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x>>y;
        v.push_back(make_pair(x,y));
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
        cout<<v[i].first<<" "<<v[i].second<<endl;
    }
    
    cout << find(n);
}
