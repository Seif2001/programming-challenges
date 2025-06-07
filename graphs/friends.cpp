#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;


int bfs(int start, int n){
    queue<int> q;
    visited[start] = true;
    q.push(start);
    int ans = 1;
    while(q.size()){
        int node = q.front();
        q.pop();

        for(int i = 0; i<adj[node].size(); i++){
            int neigh = adj[node][i];
            if(!visited[neigh]){
                visited[neigh] = true;
                ans++;
                q.push(neigh);
            }
        }
    }

    return ans;
}


int main(){
    int t;
    cin>>t;

    while(t--){
        int n, m;
        cin>>n>>m;

        adj.resize(n);
        visited.assign(n, false);
        adj.assign(n, vector<int>());
        for(int i = 0; i<m; i++){
            int u, v;
            cin>>u>>v;

            adj[u-1].push_back(v-1);
            adj[v-1].push_back(u-1);
        }

        int maxg = 0;
        for(int i = 0; i<n; i++){
            if(!visited[i]){
                int ans = bfs(i, n);
                maxg = max(ans, maxg);
            }
        }
        cout<<maxg<<endl;
    }
    
}