#include<bits/stdc++.h>

using namespace std;
const int N = 1e6+5;
bool is_prime[N];
const int C = 502;
const int R = 502;
int a[R][C];
vector<long long> primes; 
void seive(){
    for (long long i = 2; i < N; i++) {
        is_prime[i] = true;
    }
    for(long long i = 2; i < N; i++){
        if (is_prime[i]){
            primes.push_back(i);
            for(long long j = i*i; j<N; j+=i){
                is_prime[j] = false;
            }
        }
    }
}

int main(){
    int r, c;

    cin>>r>>c;

    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cin>>a[i][j];
        }
    }

    seive();
    int mini = INT_MAX;
    for(int i = 0; i < r; i++){
        int count = 0;
        for (int j = 0; j < c; j++){
            if (!is_prime[a[i][j]]){
                int it = lower_bound(primes.begin(), primes.end(), a[i][j]) - primes.begin();
                count += primes[it] - a[i][j];
            }
        }
        mini = min(mini, count);
    }

    for(int i = 0; i < c; i++){
        int count = 0;
        for (int j = 0; j < r; j++){
            if (!is_prime[a[j][i]]){
                int it = lower_bound(primes.begin(), primes.end(), a[j][i]) - primes.begin();
                count += primes[it] - a[j][i];
            }
        }
        mini = min(mini, count);
    }
    cout<<mini<<endl;

}