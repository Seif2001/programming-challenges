#include<bits/stdc++.h>

using namespace std;
const int N = 1e5+5;
int arr[N];
int vals[N];
int prefMissed[N];  
int main(){
    int n, k;
    cin>>n>>k;
    int iSum = 0;
    for(int i = 1; i<=n; i++){
        cin>>arr[i];
    }

    for(int i = 1; i<=n; i++){
        cin>>vals[i];
        iSum+=arr[i]*(vals[i] == 1);
    }

    for(int i = 1; i<=n; i++){
        prefMissed[i] = prefMissed[i-1];
        if (vals[i] == 0){
            prefMissed[i] = prefMissed[i] + arr[i];
        }
    }

    
    int sum = 0, mx = 0;
    for(int i = 1; i<=n-k+1; i++){
        sum = prefMissed[i+k-1] - prefMissed[i-1];
        mx = max(mx, sum);
    }
    cout<<iSum+mx<<endl;
}