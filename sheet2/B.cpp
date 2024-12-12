#include<bits/stdc++.h>

using namespace std;
const int N = 1e6+1;
int a[N];
int b[N];

bool solve(long long x, long long n, long long k){
    long long sum = 0;

    for(long long i = 0; i < n; i++){
        if (a[i] * x > b[i]){
           
            sum += a[i] * x - b[i];
        }
        if(sum > k){
            return false;
        }
    }

    return sum <= k;
}

int main(){
    long long n, k;
    cin >> n >> k;

    for(long long i = 0; i < n; i++){
        cin >> a[i];
    }
    for(long long i = 0; i < n; i++){
        cin >> b[i];
    }

    long long s = 1;
    long long e = 1e10+10;
    long long ans = 0;

    while(s<=e){
        long long mid = (s + e) / 2;
        if(solve(mid, n, k)){
            s = mid+1;
            ans = mid;
        }else{
            e = mid-1;
        }
    }

    cout << ans<< endl;



}