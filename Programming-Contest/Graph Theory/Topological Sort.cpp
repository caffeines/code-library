int inDegree[Size],temp;
map< string,int > MAP;
set<int> myset;

//if input is string
int mapFind(string x)
{
    if(MAP.find(x) == MAP.end())
        MAP[x] = ++temp;
    return MAP[x];
}

vi graph[Size],sequence;
int tophSort(int n)
{
    queue <int> Q; // here will contain independent nodes I mean the nodes with indegree 0
    FOR(i,1,n)  // first, I am here inserting independent nodes in queue
    {
        if(inDegree[i] == 0)
            Q.push(i);
    }

    while(!Q.empty())
    {
        int curr = Q.front(); Q.pop();
        sequence.pb(curr);
        REP(i,graph[curr].size())
        {
            int nxt = graph[curr][i];
            inDegree[nxt]--;
            if(inDegree[nxt] == 0) //if independent
            {
                Q.push(nxt);
            }
        }
    }
}

void Clear()
{
    MAP.clear();
    myset.clear();
    REP(i,Size)
        graph[i].clear();
    sequence.clear();
    mem(inDegree,0);
    temp=0;
}
