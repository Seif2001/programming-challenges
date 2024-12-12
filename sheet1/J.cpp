#include <bits/stdc++.h>
using namespace std;

const int N = 1.5e5 + 5;
int values[N];
int prefix[N];

int main(){
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++){
        cin >> values[i];
    }
    for(int i = 1; i < n+1; i++){
        prefix[i] = prefix[i-1] + values[i-1];
    }
    int mn = INT_MAX, mnIndex = 0;
    int sum = 0;
    for(int i = 0; i <= n-k; i++){
        sum = prefix[i+k] - prefix[i];
        if (sum < mn){
            mn = sum;
            mnIndex = i;
        }
    }
   
    cout << mnIndex+1<< endl;
}