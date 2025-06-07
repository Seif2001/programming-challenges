#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;

int dfs(int s, int count) {
    int max_count = count;
    for (auto i : adj[s]) {
        int current = dfs(i, count + 1);
        max_count = max(max_count, current);
    }
    return max_count;
}

int main() {
    int n;
    cin >> n;

    adj.resize(n);
    vector<bool> has_parent(n, false);

    for (int i = 0; i < n; i++) {
        int u;
        cin >> u;
        if (u != -1) {
            adj[u - 1].push_back(i);  // parent to child
            has_parent[i] = true;     // mark that i has a parent
        }
    }

    int max_count = 1;
    for (int i = 0; i < n; i++) {
        if (!has_parent[i]) {  // node i is a root
            int count = dfs(i, 1);
            max_count = max(max_count, count);
        }
    }

    cout << max_count << endl;
}
