#include<bits/stdc++.h>
using namespace std;

const int N = 59;

int a[N];

int main(){
    string s1;
    string s2;

    getline(cin, s1);
    getline(cin, s2);


    for(int i = 0; i<s1.length(); i++){
        if(s1[i] != ' '){
            a[s1[i] - 'A']++;
        }
    }

    // for(int i = 0; i<58; i++){
    //     cout<<char(i + 'A')<<" "<<a[i]<<endl;
    // }

    for(int i = 0; i<s2.length(); i++){
        if(s2[i] == ' '){
            continue;
        }
        if(--a[s2[i] - 'A'] < 0){
            // cout<<s2[i]<<" missing "<<endl;
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
}