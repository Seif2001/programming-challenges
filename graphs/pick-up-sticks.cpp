#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
const int N = 1e6+4;
vector<int> t;
int degrees[N];

void topo(int n){
    queue<int> q;
    for(int i = 0; i<n; i++){
        if(degrees[i] == 0){
            q.push(i);
        }
    }
    while(q.size()){
        int node = q.front();
        q.pop();
        t.push_back(node+1);
        for(int i = 0; i<adj[node].size(); i++){
            int child = adj[node][i];
            if(--degrees[child]==0){
                q.push(child);
            }
        }
    }
    if(n == t.size()){
        for(int i = 0; i<t.size(); i++){
            cout<<t[i]<<endl;
        }
    }
    else{
        cout<<"IMPOSSIBLE"<<endl;
    }
}

int main(){
    int m, n;
    while(cin>>n>>m && n && m){
        t.clear();
        adj.assign(n, vector<int>());
        memset(degrees, 0, sizeof(int) * n);
        for(int i = 0; i<m; i++){
            int u, v;
            cin>>u>>v;
            adj[u-1].push_back(v-1);
            degrees[v-1]++;
        }
        
        topo(n);
        
    }
}