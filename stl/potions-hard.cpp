#include<bits/stdc++.h>
using namespace std;

const int N = 200003;
int a[N];

int main(){
    int n;
    cin>>n;
    priority_queue<int, vector<int>, greater<>> pq;
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    long long sum = 0;
    int x = 0;
    for(int i = 0; i<n; i++){
        sum+=a[i];
        pq.push(a[i]);
        x++;
        while(sum<0){
            sum-=pq.top();
            pq.pop();
            x--;
        }
    }
    cout<<x;
}