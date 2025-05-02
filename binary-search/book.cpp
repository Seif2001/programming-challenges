#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+2;
int books[N];

bool willWork(int n, int m, int b){
    for(int i = 0; i<n-b; i++){
        int x = 0;
        int sum = 0;
        while(x<b){
            sum+=books[i+x];
            if(sum>m){
                return false;
            }
            cout<<"sum = "<<sum<<endl;
            x++;
        }
    }
    
    return true;
}

int main(){
    int n, m;
    cin>>n>>m;
    for(int i = 0; i<n; i++){
        cin>>books[i];
    }

    int s = 0, e = n;
    int ans = 0;
    while(e>s){
        int l = s+(e-s)/2;
        cout<<"L = "<<l<<endl;
        if(willWork(n, m, l)){
            s = l+1;
            ans = l;
        }
        else{
            e = l-1;
        }
    }
    cout<<ans;
}