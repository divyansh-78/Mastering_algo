#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;
const int MAXN = 100005;
const long long INF = numeric_limits<long long>::max();
vector<pair<int, int>> adj[MAXN]; 
vector<long long> dist(MAXN, INF); 
void dijkstra(int start) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    dist[start] = 0;
    pq.push({0, start});
    while (!pq.empty()) {
        long long d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (d>dist[u]) continue;
        for (auto edge : adj[u]) {
            int v = edge.first;
            int len = edge.second;
            if (dist[u] + len < dist[v]) {
                dist[v] = dist[u] + len;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    int n;
    int m;
    cin>>n>>m;
    int i= 0;
    for (i=0;i<m;i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    dijkstra(1);
    for (i=1;i<=n;i++) {
        cout << (dist[i] == INF ? -1 : dist[i]) << " ";
    }
    cout << endl;
    return 0;
}
