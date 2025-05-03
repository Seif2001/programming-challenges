#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

bool bfs(vector<vector<int>> adj, vector<bool> visited, int n){
    queue<int> q;
    q.push(0);
    int size = 1;

    while(q.size()){
        int node = q.front();
        q.pop();
        visited[node] = true;
        for(int i = 0; i<adj[node].size(); i++){
            // cout<<"PARENT = "<<node<<"Child = "<<adj[node][i]<<endl;
            if(visited[adj[node][i]]){
                return false;
            }
            size++;
            visited[adj[node][i]] = true;
            q.push(adj[node][i]);
        }
    }
    // cout<<"SIZE = "<<size<<endl;
    return n == size;
}

int main(){
    int m, n;
    cin>>n>>m;
    adj.resize(n);
    visited.resize(n, false);
    for(int i = 0; i<m; i++){
        int u, v;
        cin>>u>>v;
        adj[u-1].push_back(v-1);
    }
    if(m != n - 1){
        cout<<"NO";
        return 0;
    }
    if(bfs(adj, visited, n)){
        cout<<"YES";
        return 0;
    }
    // cout<<"HERE";
    cout<<"NO";
}
