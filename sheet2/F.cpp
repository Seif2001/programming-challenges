#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int book[N];

long long n, t;

bool ok(long long x){
    for(int i = 0; i<=n-x;i++){
        // cout<<i<<" "<<x<<endl;
        if(book[i + x] - book[i] <= t){
            return true;
        }
    }
    return false;
}

int main(){
    cin>>n;
    cin>>t;

    for (int i = 1; i < n+1; i++) {
        int x;
        cin>>x;
        book[i] = x + book[i-1];        
    }

    // for(int i = 1; i<n+1; i++){
    //     cout<<book[i]<<" ";
    // }
    // cout<<endl;
    long long s = 0;
    long long e = N;

    while(e - s > 1){
        long long m = (s + e) / 2;
        if(ok(m)){
            s = m;
        }else{
            e = m;
        }
    }
    cout<<s<<endl;

}