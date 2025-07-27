#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+4;
char arr[N];
int pref[N];
int main(){
    int m;
    cin>>(arr+1);
    cin>>m;
    int i = 1;
    while(arr[i] == '.' || arr[i] == '#'){
        pref[i] = pref[i-1] + (arr[i] == arr[i-1] ? 1 : 0);
        i++;
    }
    while(m--){
        int s, e;
        cin>>s>>e;
        cout<<pref[e] - pref[s]<<endl;
    }
}