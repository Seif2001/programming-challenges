#include<bits/stdc++.h>

using namespace std;
long long t;

bool solve(long long n){
    long long x = 314 * n + 4;
    return x >= t;
}


int main(){
    cin>>t;
    long long s = 0;
    long long e = t;
    while(e-s>1){
        long long mid = (s+e)/2;
        if(solve(mid)){
            e = mid;
        }else{
            s = mid;
        }
    }
    cout << e << endl;
}