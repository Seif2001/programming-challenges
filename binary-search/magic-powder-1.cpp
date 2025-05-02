#include <bits/stdc++.h>
using namespace std;
const int N= 1005;
int need[N];
int have[N];

bool wilWork(int n, int c, int k){
    for(int i = 0; i<n; i++){
        int required = need[i] *c;
        if(have[i] < required){
            if(required - have[i] <= k){
                k-=(required-have[i]);
            }
            else{
                return false;
            }
        }
    }
    return true;
}


int main(){
    int k, n;
    cin>>n>>k;

    for(int i = 0; i<n; i++){
        cin>>need[i];
    }
    for(int i = 0; i<n; i++){
        cin>>have[i];
    }

    int s = 0;
    int e = 2005;
    int m = s + ((e-s) /2);
    int ans = 0;

    while(s <= e){

        if(wilWork(n, m, k)){
            ans = m;
            s = m+1;
        }
        else{
            e = m - 1;
        }
        m = s+  (e-s) /2;
    }
    cout<<ans;


}

/*

3 1
2 1 4
11 3 16

binary search on the number of cookies

0 - 10,000

will 10,000 work?

no

try 5000

no try 2500

until it works

*/