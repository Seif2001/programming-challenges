#include<bits/stdc++.h>

using namespace std;

int bfs(int u, vector<vector<int>> &adj, vector<bool> &vis){
    queue<int> q;
    q.push(u);
    vis[u] = true;
    int count = 0;
    while(!q.empty()){
        int level_size = q.size();
        for(int i = 0; i<level_size; i++){
            int u = q.front();
            q.pop();
            for(int v: adj[u]){
                 q.push(v);
            }
        }
        count++;
    }
    // cout<<"count: "<<count<<endl;
    return count;
}

int main(){
    int n;
    cin >>n;
    vector<vector<int>> adj(n);

    for(int i =0; i<n; i++){
        int u;
        cin >> u;
        if(u != -1){
            u--;
            adj[u].push_back(i);
        }
    }

    // // //print adj list
    // for(int i = 0; i<n; i++){
    //     cout << i << ": ";
    //     for(int j: adj[i]){
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }


    vector<bool> vis(n, false);
    int max_c = 0;  
    for(int i = 0; i<n; i++){

        max_c = max(max_c, bfs(i, adj, vis));
    }

    cout<<max_c<<endl;
    

}