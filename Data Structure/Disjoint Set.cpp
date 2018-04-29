int parent[N];

void makeSet()
{
    for(int i=0;i<N;i++)
        parent[i] = i;
}

int setFind(int val)
{
    if(parent[val] == val)
        return val;

    parent[val] = setFind(parent[val]);

    return parent[val];
}

void SetUnion(int a, int b)
{
    int repA = setFind(a);
    int repB = setFind(b);

    if(repA != repB)
        parent[repB] = repA;
}


