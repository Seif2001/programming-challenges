#include<bits/stdc++.h>

using namespace std;

int main(){
    long long n;
    cin>>n;
    long long sum = n/2;
    if(n%2==1){
        sum-=n;
    }
    cout<<sum<<endl;
}