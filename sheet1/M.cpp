#include<bits/stdc++.h>

using namespace std;
const int N = 2e5+5;
char s[N];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin>>tc;
    while(tc--){
        int n, q;
        cin>>n>>q;
        cin>>(s+1);

        vector<int> prefMn(n+2), prefMx(n+2), prefSum(n+2);
        vector<int> suffMn(n+2), suffMx(n+2), suffSum(n+2);
        int mn = 0, mx = 0, sum = 0; 
        for(int i = 1; i<=n; ++i){
            sum +=(s[i] == '+') * 2 - 1;
            mn = min(mn, sum);
            mx = max(mx, sum);
            prefSum[i] = sum;
            prefMn[i] = mn;
            prefMx[i] = mx;
        }
        mn = 0, mx = 0, sum = 0; 
        for(int i = n; i; --i){
            sum +=(s[i] == '-') * 2 - 1;
            mn = min(mn, sum);
            mx = max(mx, sum);
            suffSum[i] = sum;
            suffMn[i] = mn;
            suffMx[i] = mx;
        }

        int l, r;
        while(q--){
            cin>>l>>r;

            mn = prefMn[l-1];
            mx = prefMx[l-1];
            sum = prefSum[l-1];
            int diff = sum - suffSum[r+1];
            mn = min(mn, suffMn[r+1] + diff);
            mx = max(mx, suffMx[r+1] + diff);

            cout<<mx-mn+1<<"\n";

        } 
    }
}