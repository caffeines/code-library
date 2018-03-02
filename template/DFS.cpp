#define N 1000007
vector <int> graph[N]; //array of vector to store node
bool visited [N]; //marker for nodes
void dfs(int curr)
{
    visited[curr] = true; //marking current node as visited
    for(int i=0;i<graph[curr].size();i++) //looping through all the adjacent nodes
    {
        if(!visited[graph[curr][i]]) //checking if we found any adjacent node is not visited
        {
            dfs(graph[curr][i]); //visiting the not visited node
        }
    }
}
void Clear()
{
    for(int i=0;i<N;i++)
        graph[i].clear();
    mem(visited);
}
