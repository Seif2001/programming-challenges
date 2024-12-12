#include <bits/stdc++.h>

using namespace std;
const int N = 5e6 + 5;
int a[N];
int main(){
    //fast io
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    while(q--){
        int t;
        cin>>t;
        // if(t==1 ){
        //     cout<<n<<endl;
        // } else if(t == 2){
        //     cout<<n/2<<endl;
        // }
        // else if(t > n/2){
        //         cout<<1<<endl;
        // }else{
        //     cout<<2<<endl;
        // }
        cout<<n/t<<endl;

    }
}