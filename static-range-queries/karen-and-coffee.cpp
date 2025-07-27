#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+6;
int vals[N];
int prefix[N];

int main(){
    int n, k, q;
    cin>>n>>k>>q;
    int minA = N;
    int maxB = 0;
    for(int i =0; i<n; i++){
        int a, b;
        cin>>a>>b;
        minA = min(a, minA);
        maxB = max(b, maxB);
        vals[a]++;
        vals[b + 1]--;
        
    }
    // cout<<"MIN: "<<minA<<endl;
    // cout<<"MAX: "<<maxB<<endl;
    for(int i = minA; i<=N; i++){
        // cout<<vals[i]<<" "<<endl;
        vals[i] += vals[i - 1];
        prefix[i] = prefix[i-1] + (vals[i] >= k);
        // cout<<prefix[i]<<" ";
    }
    while(q--){
        int l, r;
        cin>>l>>r;
        cout<<prefix[r] - prefix[l-1]<<endl;
    }

}