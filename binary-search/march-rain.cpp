#include <bits/stdc++.h>
using namespace std;

const int N = 100003;
long long hole[N];

// Check if we can cover all holes using at most k strips of length c
bool willWork(int n, long long c, int k) {
    int i = 0;
    while (i < n) {
        long long end = hole[i] + c;
        k--;
        // Skip all holes covered by the current strip
        if(k<0){
            return false;
        }
        while (i < n && hole[i] < end) {
            i++;
        }
        // cout<<"i = "<<i<<endl;
    }
    return k >= 0;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            cin >> hole[i];
        }

        long long s = 0, e = 1e9, ans = e;
        while (s <= e) {
            long long m = s + (e - s) / 2;
            // cout<<"m = "<<m<<endl;
            if (willWork(n, m, k)) {
                ans = m;
                e = m - 1;
            } else {
                s = m + 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
