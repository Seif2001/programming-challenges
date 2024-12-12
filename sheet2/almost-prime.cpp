#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
bool isPrime[N];

void seive(){
    fill(isPrime, isPrime+N, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i*i < N; i++) {
        if(isPrime[i]){
            for (int j = i*i; j < N; j+=i) {
                isPrime[j] = false;
            }
        }
    }
}

int main(){
    int n;
    cin>>n;
    seive();
    int count = 0;
    for(int i = 6; i<=n; i++){
        int cnt = 0;
        for (int j = 2; j <= i; j++) {
            if(isPrime[j] && i%j == 0){
                cnt++;
                
            }

            if(cnt > 2){
                break;
            }
        }
        if(cnt == 2){
            count++;
        }
    }
    cout<<count<<endl;
}