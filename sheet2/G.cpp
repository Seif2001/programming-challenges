#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int card[N];

int main(){
    int n;
    cin>>n;

    for (int i = 0; i < n; i++) {
        cin>>card[i];
    }


    int s = 0;
    int e = n-1;

    int a = 0;
    int b = 0;
    int i = 0;  
    while(s<=e){ 
        if(card[s] > card[e]){
            if(i%2 == 0){
                a+=card[s];
            }else{
                b+=card[s];
            }
            s++;
        }else{
            if(i%2 == 0){
                a+=card[e];
            }else{
                b+=card[e];
            }
            e--;
        }
        i++;
    }

    cout<<a<<" "<<b<<endl;
}