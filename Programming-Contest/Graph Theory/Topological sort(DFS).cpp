vector <int> graph[N];
int arr[N],temp;
bool visit[N];
void topo(int u)
{
    visit[u] = true;
    for(int i:graph[u])
    {
        if(!visit[i])
            topo(i);
    }
    arr[--temp] = u;
}

void Clear()
{
    mem(arr,0);
    for(int i=0;i<N;i++)
        graph[i].clear();
    mem(visit,false);
}
