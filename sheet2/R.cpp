#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
int d[N];   

int main(){
    int a, b, c;
    cin>>a>>b>>c;
    int n = a*b*c;
    for(int i = 1; i<=n; i++){
        for(int j = i; j<=n; j+=i){
            d[j]++;
        }
    }
    long long ans = 0;
    for(int i = 1; i<=a; i++){
        for(int j = 1; j<=b; j++){
            for(int k = 1; k<=c; k++){
                ans += d[i*j*k];
            }
        }
    }
    ans = ans % 1073741824;
    cout<<ans<<endl;
}