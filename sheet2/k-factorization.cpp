#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, k;
    cin>>n>>k;
    vector<int> factors;
    for (int i =2; i*i <=n; i++){
        int cnt = 0;
        while(n%i == 0){
            factors.push_back(i);
            n/=i;
        }
    }
    if(n!=1){
        factors.push_back(n);
    }
    if(factors.size() < k){
        cout<<-1<<endl;

    }else{
        for (int i = 0; i < k-1; i++) {
            cout<<factors[i]<<" ";
        }
        int last = 1;
        for (int i = k-1; i < factors.size(); i++) {
            last*=factors[i];
        }
        cout<<last<<endl;
    }
}