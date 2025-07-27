#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+3;
int preSum[N], preMin[N], preMax[N];
int sufSum[N], sufMin[N], sufMax[N];
char arr[N];

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        cin>>(arr+1);
        for(int i = 1; i<n+1; i++){
            preSum[i] = preSum[i-1] + (arr[i] == '-' ? -1 : 1);
            preMax[i] = max(preSum[i], preMax[i-1]);
            preMin[i] = min(preSum[i], preMin[i-1]);
        }
        sufSum[n+1]=sufMin[n+1]=sufMax[n+1]=0;
        for(int i = n; i>=1; i--){
            sufSum[i] = sufSum[i+1] + (arr[i] == '-' ? 1 : -1);
            sufMax[i] = max(sufSum[i], sufMax[i+1]);
            sufMin[i] = min(sufSum[i], sufMin[i+1]);
        }

        while(m--){
            int s, e;
            cin>>s>>e;
            int mn = preMin[s-1];
            int mx = preMax[s-1];
            int sum = preSum[s-1];
            int suf = sufSum[e+1];
            int diff = sum - suf;
            mx = max(mx, diff + sufMax[e+1]);
            mn = min(mn, diff + sufMin[e+1]);
            cout<<mx-mn+1<<endl;
        }
    }
}