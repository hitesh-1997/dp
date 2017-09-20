#include <cmath>
#include <cstdio>
#include <vector>
#include <climits>
#include <iostream>
using namespace std;


// refer gfg for memoization

int arr[50];

bool issum(int n,int sum){
    if(n==0&&sum!=0)
        return false;
    else if(sum==0)
        return true;
    return issum(n-1,sum)||issum(n-1,sum-arr[n-1]);
}

int main() {
    int n,sum;
    cin >> n >> sum;
    for(int i=0;i<n;i++)
        cin >> arr[i];
    if (issum(n, sum) == true)
        printf("Found a subset with given sum");
    else
        printf("No subset with given sum");
}
