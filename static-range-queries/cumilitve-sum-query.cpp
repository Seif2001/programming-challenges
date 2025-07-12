#include<bits/stdc++.h>
using namespace std;

const int N = 100001;

long long a[N];

int main(){
    int n;
    cin>>n;
    for(int i = 0; i<n; i++){
        long long x;
        cin>>x;
        if(!i) a[i] = x;
        else a[i] = x + a[i-1];
    }

    int m;
    cin>>m;
    for(int i = 0; i<m; i++){
        int r, l;
        cin>>l>>r;
        cout<<a[r] - (l ? a[l-1] : 0 )<<endl;
    }
}