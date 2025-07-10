#include<bits/stdc++.h>
using namespace std;
const int N = 200;
int w[N], v[N];
int dp[N];


int main(){
    int n;
    cin>>n;
    while(n--){
        int k, m;
        cin>>k>>m;
        int wei = k;
        for(int i = 0; i<m; i++){
            cin>>w[i]>>v[i];
        }
        int maxV = 0;
        for(int i = k; i>=0; i--){
            for(int j =0; j<m; j++){
                if(i>w[j]){
                    dp[i] = max(dp[i], dp[i - w[j]] + v[j]);
                }
            }
            maxV = max(dp[i], maxV);
        }
    }


}