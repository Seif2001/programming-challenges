#include<bits/stdc++.h> 
using namespace std;

const int N = 1e7;
bool is_prime[N + 1];
void sieve() {
    fill(is_prime, is_prime + N, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= N; ++i) {
        if (is_prime[i]) {
        // if i is prime mark all its multiples as composite
        for (int j = i + i; j <= N; j += i)
            is_prime[j] = false;
        }
    }
}

int main() {
    sieve();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << (is_prime[n] ? "YES" : "NO") << endl;
    }
    return 0;
}
