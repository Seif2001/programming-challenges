#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int values[N];
int prefix[N];

int main(){
    int n, k, q;
    cin >> n >> k >> q;
    int mx = 0;
    int mn = N;
    int sum = 0;

    int l, r, a, b;
    for (int i = 0; i < n; i++){
        cin >> l >> r;
        mx = max(mx, r+1);
        values[l]++;
        values[r + 1]--;  
    }

    for(int i = 1; i <= N; i++){
        values[i] += values[i - 1];
        sum += values[i] >= k;
        prefix[i] = sum;
    }


    for(int i = 0; i < q; i++){
        cin >> a >> b;
        cout << prefix[b] - prefix[a - 1] << endl;
    }
}
