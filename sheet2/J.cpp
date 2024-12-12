#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

long long nums[N];

int main(){
    int n;
    cin>>n;
    long long t;
    cin>>t;

    for (int i = 1; i < n+1; i++) {
        cin>>nums[i];
        nums[i] += nums[i-1];
    }
    int s = 0;
    int e = 1;
    int mini = INT_MAX;
    while(e<=n){
        if(nums[e] - nums[s] < t){
            e++;
        }else{
            mini = min(mini, e-s);
            s++;
        }
    }
    if(mini < INT_MAX){
        cout<<mini<<endl;
    }else{
        cout<<-1<<endl;
    }

}