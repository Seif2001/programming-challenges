#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+1;
int a[N];
int b[N];

int main(){
    int t;
    cin>>t;
    while(t--){

    
    int n,k;
    cin>>n>>k;
    bool allMissing = true;
    int max = 0;
    int min = k+1;
    for(int i = 0; i<n; i++){
        cin>>a[i];
        if(a[i] > max){
            max = a[i];
        }
        if(a[i] < min){
            min = a[i];
        }
    }
    int ans = 1;
    for(int i = 0; i<n; i++){
        cin>>b[i];
        if(b[i] > -1){
            allMissing = false;
        }

        
    }
    
    int prev_sum = -1;

    for(int i = 0; i<n; i++){
        if(b[i] > -1){
            int sum = a[i] + b[i];
            if(prev_sum != -1 && prev_sum != sum){
                ans = 0;
                break;

            }
            prev_sum = sum;

        }
    }
    
    if(allMissing){
        ans = (k+min) - max +1;
    }
    else{
        if(ans){
            if(prev_sum < max){
                ans = 0;
            }
            if(prev_sum > k+ min){
                ans = 0;
            }
        }
    }
    cout<<ans<<endl;
}
    
    
}