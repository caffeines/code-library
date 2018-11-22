vector<int> graph[sz + 10];
int dist[sz + 10];
bool visited[sz + 10];

int bfs(int src, int dest) {
    visited[src] = true;
    dist[src] = 0;
    queue<int> q;
    q.push(src); //insert in queue

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int i = 0; i < graph[u].size(); i++) { // check all adjacent node
            int v = graph[u][i];
            if (visited[v]) continue;
            dist[v] = dist[u] + 1;
            if (dist[dest])
                return dist[dest];
            visited[v] = true;
            q.push(v);
        }
    }
}

void clear() {
    for (int i = 0; i < sz + 10; i++) {
        graph[i].clear();
    }
    memset(dist, 0, sizeof(dist));
    memset(visited, 0, sizeof(visited));
}
