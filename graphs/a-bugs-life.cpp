#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
const int N = 2001;
int color[N];

bool bfs(int u, vector<vector<int>> adj){
    queue<int> q;
    if(!color[u]){
        q.push(u);
    }
    
    while(q.size()){
        int node = q.front();
        q.pop();
        for(int i = 0; i<adj[node].size(); i++){
            if(!color[adj[node][i]]){
                q.push(adj[node][i]);
                color[adj[node][i]] = color[node] == 1 ? 2 : 1;
            }
            else if(color[adj[node][i]] == color[node]){
                return false;
            }
        }
    }
    return true;
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
           is_bipartite &= bfs(i, adj);
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