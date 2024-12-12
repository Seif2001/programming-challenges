#include <bits/stdc++.h>

using namespace std;

const int N = 2003;
int a[N];
bool is_prime[N];
void seive(int n){
for (int i = 2; i <= n; i++) {
        is_prime[i] = true;
    }
    for(int i = 2; i<=n; i++){
        if (is_prime[i]){
            for(int j = i*i; j<=n; j+=i){
                is_prime[j] = false;
            }
        }
    }
}

int main(){
    int n;
    int k;
    cin>>n>>k;
    seive(2*n);
    int f = 1;
    int first = 0;
    int second = 2;
    int count = 0;  
    for(int i = 3; i<n; i+=1){
        if(is_prime[i] && is_prime[second]){
            int temp = second;
            second = i;
            first = temp;
            int sum = second + first +1 ;
            if(is_prime[sum] && sum <= n){
                count++;
            }
            //break;
            // cout<<first<<" "<<second<<endl;
        }
    }
    if(count >= k){
        cout<<"YES"<<endl;
        // cout<<count<<endl;
    }
    else{
        cout<<"NO"<<endl;
        // cout<<count<<endl;

    }
}