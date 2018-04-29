#define N 10001
vector <int> graph[N];
bool visit[N];
int dist [N];

void bfs(int start)
{
    queue <int> q;
    visit[start] = true;
    dist[start] = 0;
    q.push(start); //insert in queue
    while(!q.empty())
    {
        int u = q.front(); q.pop();
        for(int i = 0;i<graph[u].size();i++) // check all adjacent node
        {
            int v = graph[u][i];
            if(visit[v])
                continue;
            visit[v] = true;
            dist[v] = dist[u]+1;
            q.push(v);
        }
    }
}
void Clear()
{
    for(int i=0;i<N;i++)
        graph[i].clear();
    mem(visit);
}
