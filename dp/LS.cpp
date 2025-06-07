#include<bits/stdc++.h>
using namespace std;

const int N = 10;

int arr[N];
int dp[N];


int main(){
    int n;
    cin>>n;
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    int maxl = 0;
    for(int i = 0; i<n; i++){
        dp[i] = 1;
        for(int j = 0; j<i; j++){
            if(arr[i]>arr[j]){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        maxl = max(maxl, dp[i]);
    }

    cout<<maxl;
    
}