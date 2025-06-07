#include<bits/stdc++.h>
using namespace std;
 
vector<vector<int>> adj;
vector<bool> visited;

void dfs(int s){
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while(q.size()){
        int x = q.front();
        q.pop();
        for(auto i: adj[x]){
            if(!visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }

    }
}

int main(){
    int n;
    cin>>n;
    adj.resize(n);
    visited.resize(n);
    for(int i = 0; i<n; i++){
        int x;
        cin>>x;
        adj[i].push_back(x-1);
        adj[x-1].push_back(i);
    }
    int ans = 0;
    for(int i = 0; i<n; i++){
        if(!visited[i]){
            dfs(i);
            ans++;
        }
    }
    cout<<ans<<endl;
}