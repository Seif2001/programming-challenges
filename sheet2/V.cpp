#include <bits/stdc++.h>

using namespace std;

int main(){
    int a, b, n;
    cin>>a>>b>>n;

    int g = __gcd(a, b);
    vector<int> factors;    
    factors.push_back(1);
    for(int i = 2; i*i <= g; i++){
        if(g%i == 0){
            factors.push_back(i);
        }
        if (g % i == 0 && i != g / i) {
            factors.push_back(g / i);
        }
    }
    factors.push_back(g);

    sort(factors.begin(), factors.end());

    while(n--){
        int low, high;
        cin>>low>>high;
        int ans = -1;
        for(int i = factors.size()-1; i >= 0; i--){
            if(factors[i] >= low && factors[i] <= high){
                ans = factors[i];
                break;
            }
        }
        cout<<ans<<endl;
    }
}