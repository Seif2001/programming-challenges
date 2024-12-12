#include <iostream>
#include <bits/stdc++.h>

using namespace std;
const int N = 2000+3;
int arr[N], large[N], small[N];
int main(){
    int t;
    cin >> t;

    while(t--){
        int n, d;
        cin >> n >> d;
        int largeInd = 0;
        int smallInd = 0;
        for (int i = 0; i < n; i++){
            cin >> arr[i];
            if (arr[i]>d){
                large[largeInd] = arr[i];
                largeInd++;
            }
            else{
                small[smallInd] = arr[i];
                smallInd++;
            }
        }
        if (largeInd ==0){
            cout<<"YES"<<endl;
            continue;
        }
        sort(small, small+smallInd);
        // print small
        // for (int i = 0; i < smallInd; i++){
        //     cout<<small[i]<<" ";
        // }
        if(smallInd>=2){
            if (small[0]+small[1] <= d){
                cout<<"YES"<<endl;
                continue;
            }
            else{
                cout<<"NO"<<endl;
                continue;
            }   

        }
        else {
            cout<<"NO"<<endl;
            continue;
        }
        


    }
}