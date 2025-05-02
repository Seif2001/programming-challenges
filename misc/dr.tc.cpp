#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int sum = 0;
        for(int i = 0; i<n; i++){
            if(s[i] == '0'){
                sum+=1;
            }
            else{
                sum+=(n-1);
            }
        }
        cout<<sum<<endl;
    }
}