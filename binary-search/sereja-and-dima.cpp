#include <bits/stdc++.h>
using namespace std;
const int N = 1003;
int a[N];

int main(){
    int n;
    cin>>n;
    int sereja = 0, dima = 0;
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }

    int s = 0, e = n-1, i = 0;

    while(s<=e){
        if(a[s] > a[e]){
            if(i%2==0){
                sereja+=a[s];
            }else{
                dima+=a[s];
            }
            s++;
        }else{
            if(i%2==0){
                sereja+=a[e];
            }else{
                dima+=a[e];
            }
            e--; 
        }
        i++;
    }
    cout<<sereja<<" "<<dima;
}