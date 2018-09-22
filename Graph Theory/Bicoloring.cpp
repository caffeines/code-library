#define N 10001
vector <int> graph[N];
int visit[N];
int color[N];
bool flag = true;
void bfs(int start)
{
    queue <int> q;
    q.push(start); //insert in queue
    color[start] = 0;
    while(!q.empty())
    {
        int u = q.front(); q.pop();
        for(int i = 0;i<graph[u].size();i++) // check all adjacent node
        {
            int v = graph[u][i];
            if(color[v]==0)
            {
                if(color[u] == 1)
                   color[v] = -1;
                else
                    color[v] = 1;

                q.push(v);
            }
            else
            {
                if(color[u] == color[v])
                    flag = false;
            }
        }
    }
}

void Clear()
{
    for(int i=0;i<N;i++)
    {
        graph[i].clear();
    }
    mem(color); flag = true;
}

int main()
{
    int n,l,x,y;
    while(cin>>n and n)
    {
        Clear();
        cin>>l;
        while(l--)
        {
            cin>>x>>y;
            graph[x].push_back(y);
            graph[y].push_back(x);

        }
        bfs(x);

        flag==1?
        cout<<"BICOLORABLE.\n":
        cout<<"NOT BICOLORABLE.\n";

    }

    return 0;
}

    /*
    Sample input
    3
    3
    0 1
    1 2
    2 0
    */
