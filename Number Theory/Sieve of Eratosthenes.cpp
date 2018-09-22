#define N 1000020
vector <int> IsPrime(N);
vector <int> Prime;
void sieve()
{
    IsPrime[0] = IsPrime[1] = 1;
    for(int i = 4;i < N; i += 2)
        IsPrime[i] = 1;

    int SQT = sqrt( N );
    for(int i = 3; i <= SQT; i += 2) {
        if(IsPrime[i] == 0) {
            for(int j = i*i; j <= N;j += 2*i)
                IsPrime[j] = 1;
        }
    }
    // sieve ends here

    Prime.push_back(2);
    for(int i = 3;i < N;i += 2) {
        if(IsPrime[i]==0)
            Prime.push_back(i);
    }
}

