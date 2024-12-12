#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int arr[N];
long long prefQ[N];
int prefA[N];
int leftt[N], rightt[N], X[N], Y[N];
long long value[N];

int m, k, n;
int main(){
    cin >> n >> m >> k;
    int maxr = 0;
    for(int i = 1; i<=n; i++){
        cin >> arr[i];
    }

    for(int i = 1; i<=m; i++){
        cin >> leftt[i] >> rightt[i] >> value[i];
    }

    
    for(int i = 0; i<k; i++){
        int x, y;
        cin >> x>>y;
        prefA[x] +=1;
        prefA[y+1] -=1;
        
    }

    for(int i = 1; i<=m; i++){
        prefA[i] += prefA[i-1];
    }



    for(int i = 1; i<=m; i++){
        long long ans = prefA[i] * value[i];
        prefQ[leftt[i]] += ans;
        prefQ[rightt[i]+1] -= ans;

    }



    for(int i = 1; i<=n; i++){
        prefQ[i] += prefQ[i-1];
        cout<<arr[i] + prefQ[i]<<" ";
    }   


}