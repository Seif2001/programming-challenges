#include <bits/stdc++.h>

using namespace std;    

const int N = 1e6+5;

bool is_prime[N];
int primes[N];
int prefix[N];
int cnt[11][N];


void seive(){
    primes[1] = 0;
    for (long long i = 2; i < N; i++) {
        is_prime[i] = true;
    }
    for(long long i = 2; i < N; i++){
        if (is_prime[i]){
            primes[i] = 1;
            for(long long j = i + i; j<N; j+=i){
                is_prime[j] = false;
                primes[j]++;
            }
        }
    }

 for (int n = 0; n <= 10; n++) {
        for (int i = 1; i < N; i++) {
            cnt[n][i] = cnt[n][i - 1];
            if (primes[i] == n) {
                cnt[n][i]++;
            }
        }
    }

}

int main(){
    int t;
    cin>>t;
    seive();
    while(t--){
        int a,b,n;

        cin>>a>>b>>n;
        cout<<cnt[n][b] - cnt[n][a-1]<<endl;
        // cout<<endl;

        

    }
}
