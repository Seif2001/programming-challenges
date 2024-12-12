#include <bits/stdc++.h>

using namespace std;
const int N = 1e3 + 5;
int s[N];
int main(){
    int n;
    cin>>n;

    for(int i = 2; i<=n; i++){
        int temp = i;
        for(int j = 2; j<=temp; j++){
            while(temp%j == 0){
                temp /= j;
                s[j]++;
            }
        }
        // if(i!=1){
        //     s[i]++;
        // }
    }
    long long ans = 1;
    for(int i = 2; i<N; i++){
        ans = (ans * (s[i]+1 )) % 1000000007;
    }
    cout<<ans<<endl;
}