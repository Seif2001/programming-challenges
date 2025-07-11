#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;

int a[N];


int main(){
    int n;
    int maxa = 0, smaxa = 0;
    long long sum = 0;
    cin>>n;
    vector<int> res;

    for(int i =0; i<n; i++){
        cin>>a[i];
        sum+=a[i];
        if(a[i] > maxa){
            smaxa = maxa;
            maxa = a[i];
        }
        else if(a[i] > smaxa){
            smaxa = a[i];
        }
    }
    // cout<<"Max "<<maxa<<" smax "<<smaxa<<endl;
    for(int i =0; i<n; i++){
        // cout<<"rem: "<<sum - a[i] - maxa<<" at "<<i<<endl;
        if(a[i] == maxa){
            if(sum - maxa - smaxa == smaxa){
                res.push_back(i+1);
            }
        }
        else if(sum - a[i] - maxa == maxa){
            res.push_back(i+1);
        }
    }
    cout<<res.size()<<endl;
    for(auto num: res){
        cout<<num<<" ";
    }
}