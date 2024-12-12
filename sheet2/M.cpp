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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    seive();
    int n;
    cin>>n;
    int count = 0;
    while(n--){
        long long i;
        cin>>i;
        long long root = sqrt(i);

        if(root*root == i && isPrime[root]){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
       
    }
}