/* Immutable */
#define N 1000
int memo[N][N],a[N][N],r,c;
void precal()
{

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            memo[i+1][j+1] = memo[i+1][j] + memo[i][j+1] + a[i][j] - memo[i][j];//memo[i][j] is deducting cause
                                                                                //it was added two times.
        }
    }
}

int sumRegion(int r1, int c1, int r2, int c2)
{
    r1++; c1++; r2++; c2++; //memo array is 1 indexed, thats why I am increasing
    int ans = memo[r2][c2] - memo[r1-1][c2] - memo[r2][c1-1];
    ans += memo[r1-1][c1-1]; //memo[i][j] is adding cause it was deducted two times.

    return ans;
}
