#include <bits/stdc++.h>

using namespace std;

int main(){
    int x;
    cin >> x;
    int res = 0;
    while(x>0){
        if(x%2 == 1){
            res++;
        }
        x /= 2;
    }
    cout << res << endl;
}