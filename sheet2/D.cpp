#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;  // Adjusted constant, as 10e5 is not accurate for the given constraints
long long a[N];

bool solve(long long x, int n, int k) {
    //cout << "x: " << x << " n: " << n << " k: " << k << endl;
    long long last = -1; long long cnt = 0;
    for(long long i =0; i<n; i++){
        if(last<a[i]){
            last = a[i] + x -1;
            cnt++;
        }
    }
    //cout << "cnt: " << cnt << endl;
    return cnt <= k;
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;

        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }

        // Set the binary search bounds
        long long s = 0;
        long long e = 1e9 + 10;
        // Binary search for the minimum maximum strip length
        while (e - s > 1) {
            long long mid = (s + e) / 2;
            if (solve(mid, n, k)) {
                e = mid;
            } else {
                s = mid;
            }
        }

        // e is now the minimum length of the longest strip that allows covering all holes
        cout << e <<endl;
    }

    return 0;
}
