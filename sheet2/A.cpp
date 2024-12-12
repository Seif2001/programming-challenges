#include <bits/stdc++.h>
const int N = 1e5+5;
const int xN = 1e9+5;
int n;
int s[N];
int c;
using namespace std;

bool ok(int m){
    int nxt = 0;
    int cnt = c;

    for(int i = 0; i<n; i++){
        if(s[i]>=nxt){
            if(!--cnt) return true;
            nxt = s[i]+m;
        }
    }
    return false;
}
int BS(int s, int e){
    while(e-s>1){
        int m = (s+e+1)/2;
        if(ok(m)) s = m;
        else e = m;
    }
    return s;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        cin>>c;
        for(int i = 0; i<n; i++){
            cin>>s[i];
        }
        sort(s,s+n);
        cout<<BS(s[0], s[n-1])<<endl;
    }
    
}