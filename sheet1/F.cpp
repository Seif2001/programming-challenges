#include<bits/stdc++.h>

using namespace std;

const int N = 1005;
int x;
int a[N], b[N];
int main(){
    int n;
    cin>>n;
    int x;
    cin >> x;
    bool np = 0;
    for(int i=0; i<n; i++){
        cin>>a[i];
        cin>>b[i];
        if (7 - x == a[i] || 7 - x == b[i] || x == a[i] || x == b[i]){
            np = 1;
        }
        x = 7 - x;
    }
    if (!np){
        cout<<"YES";
    }
    else{
        cout<<"NO"; 
    }
}