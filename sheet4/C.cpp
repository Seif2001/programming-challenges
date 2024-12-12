#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> in_degree;

vector<int> topo(int n) {
    queue<int> q;
    vector<int> topo_order;
    for (int i = 0; i < n; i++) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topo_order.push_back(u);
        for (int v : adj[u]) {
            if (--in_degree[v] == 0) {
                q.push(v);
            }
        }
    }
    return topo_order;
}

int main() {
    while (true) {
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0) {
            break;
        }

        // Resize and reset for new test case
        adj.assign(n, vector<int>());
        in_degree.assign(n, 0);

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--; // Convert to zero-based indexing
            adj[u].push_back(v);
            in_degree[v]++;
        }

        vector<int> order = topo(n);

        if (order.size() != n) {
            cout << "IMPOSSIBLE\n";
        } else {
            for (int i : order) {
                cout << i + 1 << '\n'; // Convert back to one-based indexing
            }
        }
    }

    return 0;
}
