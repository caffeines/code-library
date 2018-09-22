#define pii pair<int, int>
#define N 10001
int cell[N][N],r,c;
bool visit[N][N];
int dist [N][N];

void bfs2D(int sx, int sy)
{
    memset( visit, 0, sizeof(visit));
    visit[sx][sy] = true;
    queue <pii> q;

    dist[sx][sy] = 0;
    q.push( {sx, sy} ); //insert in queue
    while(!q.empty())
    {
        pii top = q.front(); q.pop();
        for( int i = 0; i<4; i++) {
            int u = top.first + dx[i];
            int v = top.second + dy[i];

            if(check(u, v) && cell[u][v] > 0){
                visit[u][v] = true;
                dist[u][v] = dist[top.first][top.second] + 1;
                q.push({u, v});
            }
        }
    }
}
void Clear()
{
    memset(cell, 0, sizeof(cell));
}


