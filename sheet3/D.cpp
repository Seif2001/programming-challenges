#include <bits/stdc++.h>
using namespace std;

const int N = 16;
int a[N];

int main(){
    int l, r, n, x;
    cin >> n >> l >> r >> x;

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int count = 0;

    for(int mask = 0; mask < (1<<n); mask++){
        int sum = 0;
        int minn = INT_MAX;
        int maxx = INT_MIN;
        
        for(int j = 0; j < n; j++){
            if((mask >> j) & 1){
                sum += a[j];
                minn = min(minn, a[j]);
                maxx = max(maxx, a[j]);
            }
        }
        if(sum >= l && sum <= r && maxx - minn >= x){
            count++;
        }
    }
    cout<<count<<endl;
}