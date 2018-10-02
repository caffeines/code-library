/*Add caffeines's template*/
map <char, int> _map;
int mat[Size][Size];
ll dist[Size][Size];
int sx , sy, k, h, w;

struct Node{
    int u,v;
    ll cost;
    Node(){};
    Node(int u,int v, ll cost)
    {
        this->u = u;
        this->v = v;
        this->cost = cost;
    }

    bool operator < (const Node &node) const
    {
        return cost > node.cost;
    }

}curr,nxt;

priority_queue <Node> pq;
ll dijkstra(int sx, int sy)
{
    for( int i = 0; i < Size; i++ ) {
        for( int j = 0; j < Size; j++ ) {
            dist[i][j] = INF;
        }
    }

    curr.u = sx;
    curr.v = sy;
    curr.cost = 0;
    dist[sx][sy] = 0;

    pq.push(curr);
    while(!pq.empty())
    {
        curr = pq.top();
        pq.pop();

        for(int i = 0; i < 4; i++ )
        {
            int u = curr.u + dx[i];
            int v = curr.v + dy[i];
            if( check(u,v)){
                if(dist[u][v] > curr.cost + mat[u][v])
                {
                    dist[u][v] = curr.cost + mat[u][v];
                    pq.push({u, v, dist[u][v]});
                }
            }
        }
    }

    // value in boundary cell
    ll res = INF;
    for( int i=0; i < h; i++ ) {
        res = min(res, dist[i][0]);
        res = min(res, dist[i][w-1]);
    }
    for( int i=0; i < w; i++ ) {
        res = min(res, dist[0][i]);
        res = min(res, dist[h-1][i]);
    }
    return res;
}


int main()
{
    FasterIO;
    #ifdef caffeines
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    #endif // caffeines

    int t;
    cin>>t;
    for( int kase = 1; kase <= t; kase++ ) {
        int n;
        char ch;
        cin>>k>>w>>h;
        for( int i=0; i < k; i++ ) {
            cin>>ch>>n;
            _map[ch] = n;
        }
        string str;
        for(int i = 0; i < h; i++ ) {
            cin>>str;
            for( int j = 0; j < w; j++ ) {
                ch = str[j];
                mat[i][j] = _map[ch];
                if( ch == 'E'){
                    mat[i][j] = 0;
                    sx = i; sy = j;
                }
            }

        }
        ll res = dijkstra(sx, sy);
        cout<<res<<endl;
    }
    return 0;
}

    /*
    Sample input
    1
    6 3 3
    A 1
    B 2
    C 3
    D 4
    F 5
    G 6
    ABC
    FEC
    DBG
    */
