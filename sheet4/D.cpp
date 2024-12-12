#include <bits/stdc++.h>

using namespace std;

int dfs(int u, vector<vector<int>> &adj, vector<bool> &vis){
    if(vis[u]) return 0;
    vis[u] = true;
    int count = 1;
    for(int v: adj[u]){
        if(!vis[v]){
            count += dfs(v, adj, vis);
        }
    }
    return count;
}

int main(){
    int t;

    cin >> t;

    while(t--){
        int m, n;
        cin >> n >> m;
        vector<vector<int>> adj(n);
        vector<bool> vis(n, false);
        for(int i = 0; i < m; i++){
            int u, v;
            cin >> u >> v;
            u--, v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int max_c = 0;
        for(int i = 0; i<n; i++){
            int c = dfs(i, adj, vis);    
            max_c = max(max_c, c);
        }
        cout << max_c << endl;

    }
}