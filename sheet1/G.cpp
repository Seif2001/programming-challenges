#include<bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;
int prefix[N];
string s;

int main(){
    cin >> s;
    int n;
    cin >> n;
    for (int i = 0; i<s.size()-1; i++){
        // cout<<"hi"<<endl;
        if (s[i] == s[i+1]){
            prefix[i+1] = prefix[i] + 1;
            
        }
        else{
            prefix[i+1] = prefix[i];
        }
    }
    for(int i = 0; i<n; i++){
        int l, r;
        cin >> l >> r;
        cout << prefix[r-1] - prefix[l-1] << endl;
    }


}