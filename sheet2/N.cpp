#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        vector<pair<long long, int>> factors;
        for (long long i =2; i*i <=n; i++){
            int x = 0;
            while(n%i == 0){
                x++;
                n = n/i;
            }
            if (x > 0) {
                factors.emplace_back(i, x);
            }
        }
        if(n!=1){
            factors.emplace_back(n, 1);
        }
        int maxi = -1;
        long long max_factor = -1;
        for(auto x: factors){
            if(x.second > maxi){
                maxi = x.second;
                max_factor = x.first;
            }
        }
        cout<<maxi<<endl;
        for (int i = 0; i < maxi-1; i++){
            cout<<max_factor<<" ";
        }
        long long last = 1;
        for(auto x: factors){
            for (int i = 0; i < x.second; i++){
                if (x.first != max_factor){
                    last *= x.first;

                }
            }
        }
        last = last*max_factor;

        cout<<last<<endl;

        
    }
    
}