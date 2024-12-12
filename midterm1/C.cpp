#include <bits/stdc++.h>
using namespace std;
const int N = 1e7+5;
int t[N];
int s[N];


int main(){
    int n, T;
    cin >> n >> T;
    for(int i = 1; i < n + 1; i++){
        cin >> t[i];
        t[i] += t[i-1];
    }
    for(int i = 1; i < n + 1; i++){
        cin >> s[i];
        s[i] = s[i] + s[i-1];
    }



    int l = 1, r = 1, max_score = 0;
    int start = 0;
    int end = 0;
    for(l; l < n + 1; l++){
        while(r < n + 1 && t[r+1] - t[l-1] <= T){
            r++;
            // cout<<l<<" " <<r<<endl;
            // cout<<t[r] - t[l-1]<<endl;
            if(max_score < s[r] - s[l-1]){
                max_score = s[r] - s[l-1];
                start = l;
                end = r;
            }
        }
    }
    cout << start << " " << end << endl;
    //cout << max_score << endl;
}