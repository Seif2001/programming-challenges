#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int line[N];

int main(){
    int d, n;
    cin>>n>>d;

    for (int i = 0; i < n; i++) {
        cin>>line[i];
    }
    int j = 0;
    long long result = 0; 
    for(int i = 0; i < n; i++){

        while(j < n && line[j] - line[i] <= d){
            j++;
        }

        int temp = j - i - 1;
        if(temp>=2){
            result+=(1LL * temp * (temp - 1)) / 2;
        }
    }

    cout<<result<<endl;



    return 0;
}