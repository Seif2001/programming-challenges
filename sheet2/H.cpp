#include<bits/stdc++.h>

using namespace std;
const int N = 5e5 + 5;
int s[N];

int main(){
    int n;
    cin>>n;

    for (int i = 0; i < n; i++) {
        cin>>s[i];
    }
    sort(s, s+n);

    int st = 0;
    int e = (n+1)/2;

    int ans = n;

    while(e<n){
        if(s[st] * 2 <= s[e]){
            ans--;
            st++;
        }
        e++;
    }
    cout<<ans<<endl;    
}