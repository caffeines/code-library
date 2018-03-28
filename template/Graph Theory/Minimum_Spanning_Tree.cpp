
struct Node
{
    int x,y,cost;
    Node(){};
    Node(int x,int y,int cost)
    {
        this->x = x;
        this->y = y;
        this->cost = cost;
    }
    bool operator <(const Node &node) const
    {
        return node.cost > cost;
    }
};

int par[Size],temp;
int setFind(int pos)
{
    if(pos == par[pos])
        return pos;
    par[pos] = setFind(par[pos]);
    return par[pos];
}

void make_set()
{
    for(int i=0;i<Size;i++)
        par[i] = i;
}

vector <Node> graph;
int MST(int n)
{
    sort(graph.begin(),graph.end());
    make_set();

    int counter=0,sum=0;
    for(int i=0;i<graph.size();i++)
    {
        int u = setFind(graph[i].x);
        int v = setFind(graph[i].y);

        if(u != v)
        {
            par[u] = v;
            counter++;
            sum += graph[i].cost;
            if(counter == n)
                break;
        }
    }
    return sum;
}
// if input is string type
map< string,int > MAP;
int mapFind(string x)
{
    if(MAP.find(x) == MAP.end())
        MAP[x] = ++temp;
    return MAP[x];
}

void Clear()
{
    graph.clear();
    MAP.clear();
    temp = 0;
}
///make sure, you have cleared all

