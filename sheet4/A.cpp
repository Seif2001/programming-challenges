#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+5;

bool vis[N];

void dfs(vector<vector<int>> &adj, int u, int &count){
    
    vis[u] = true;
    for(int v : adj[u]){
        if(!vis[v]){
            count++;
            dfs(adj, v, count);
        }
    }
}


int main(){

    vector<vector<int>> adj;

    int n, m;
    cin >> n >> m;

    if(m != n-1){
        cout << "NO" << endl;
        return 0;
    }

    if(n == 1){
        cout << "YES" << endl;
        return 0;
    }

    adj.resize(n+1);
    for(int i = 0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    int count = 0;
    dfs(adj, 1, count);
    if(count == n-1){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }



}