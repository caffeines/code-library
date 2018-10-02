
struct Node{
    int id;
    ll cost;
    Node(){};
    Node(int id,int cost)
    {
        this->id = id;
        this->cost = cost;
    }

    bool operator < (const Node &node) const
    {
        return cost > node.cost;
    }

}curr,nxt;

int path[Size];
priority_queue <Node> pq;
vector <pii> graph[Size];
ll dist[Size];

void dijkstra(int source)
{
    FOR(i,0,Size) dist[i] = inf;
    curr.id = source;
    curr.cost = 0;
    dist[source] = 0;

    pq.push(curr);
    while(!pq.empty())
    {
        curr = pq.top();
        pq.pop();

        for(int i=0;i < graph[curr.id].size();i++)
        {
            nxt.id = graph[curr.id][i].first;
            nxt.cost = graph[curr.id][i].second + dist[curr.id];

            if(dist[nxt.id] > nxt.cost || dist[nxt.id] == inf)
            {
                dist[nxt.id] = nxt.cost;
                path[nxt.id] = curr.id ;
                pq.push(nxt);
            }
        }
    }
}

void printPath(int en )
{
    if( en ==0) return;
    printPath(path[en]) ;
    printf("%d ",en) ;
}

void Clear(){
    memset(dist, 0, sizeof(dist));
    for( int i=0; i < Size; i++ ){
        graph[i].clear();
    }
}

