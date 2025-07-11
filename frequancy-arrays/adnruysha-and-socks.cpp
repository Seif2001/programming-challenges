#include <bits/stdc++.h>
using namespace std;

const int N = 10e5+3;
int a[N];
int b[N];

int main(){
    int n;
    cin>>n;

    for(int i = 0; i<2*n; i++){
        cin>>a[i];
    }
    
    int cnt = 0;
    int maxCount = 0;

    for(int i = 0; i<2*n; i++){
        if(b[a[i]] == 0){
            cnt++;
            b[a[i]] = 1;
        }else if(b[a[i]]){
            cnt--;
            b[a[i]] = 2;
        }
        maxCount = max(maxCount, cnt);
    }
    cout<<maxCount;
}