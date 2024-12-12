#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int color[N];

bool dfs(int u, vector<vector<int>> adj){
    bool is_bipartite = true;
    for(int v: adj[u]){
        if(!color[v]){
            color[v] = color[u] == 1 ? 2 : 1;
            is_bipartite &= dfs(v, adj);
        }
        else if(color[v] == color[u]){
            is_bipartite = false;
        }
    }
    return is_bipartite;
}

int main(){
    int t;
    cin>>t;
    int s = 1;
    while(t--){
        fill(color, color+N, 0);
        int n, m;
        cin>>n>>m;
        vector<vector<int>> adj(n);
        for(int i = 0; i < m; i++){
            int u, v;
            cin>>u>>v;
            u--, v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        bool is_bipartite = true;
        for(int i = 0; i <n; i++){
           is_bipartite &= dfs(i, adj);
        }
        if(is_bipartite){
            cout<<"Scenario #"<<s<<":"<<endl;
            cout<<"No suspicious bugs found!"<<endl;
        }
        else{
            cout<<"Scenario #"<<s<<":"<<endl;
            cout<<"Suspicious bugs found!"<<endl;
        }
        s++;
    }
}