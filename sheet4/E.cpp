#include <bits/stdc++.h>
using namespace std;

void dfs(int u, vector<vector<int>> &adj, vector<bool> &vis, int &count){
    vis[u] = true;
    for(int v: adj[u]){
        if(!vis[v]){
            count++;
            dfs(v, adj, vis, count);
        }
    }
}


int main() {
    int n, m;
    while(cin>>n>>m, n || m){
        unordered_map<string, int> animals;
        vector<vector<int>> adj(n);
        vector<bool> vis(n, false);
        for (int i = 0; i < n; i++) {
            string animal;
            cin >> animal;
            animals[animal] = i;
        }
        for(int i = 0; i<m; i++){
            string animalA, animalB;
            cin>>animalA>>animalB;
            int a = animals[animalA];
            int b = animals[animalB];    
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        // print adj list

        // for(int i = 0; i<n; i++){
        //     cout << i << ": ";
        //     for(int j: adj[i]){
        //         cout << j << " ";
        //     }
        //     cout << endl;
        // }
        int max_c = 0;
        for(int i = 0; i<n; i++){
            int c = 1;
            dfs(i, adj, vis, c);    
            max_c = max(max_c, c);
        }

        cout << max_c << endl;

    }
    
    return 0;
}