#include <bits/stdc++.h>

using namespace std;
const int N = 21;
int a[N];
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        int s;
        cin >> n;
        cin >> s;
        for(int i = 0; i < s; i++){
            cin>>a[i];
        }
        bool flag = false;
        for(int mask = 0; mask < (1<<s); mask++){
            int sum = 0;
            for(int j = 0; j < s; j++){
                if((mask >> j) & 1){
                    sum += a[j];
                }
            }
            if(sum == n){
                cout << "YES" << endl;
                flag = true;
                break;
            }
        }
        if(!flag){
            cout << "NO" << endl;
        }


    }
}