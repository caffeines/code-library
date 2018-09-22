#define N 10000201
vector <int> IsPrime(N);
vector <int> Prime;

/// Sieve Starts here
void sieve()
{
    IsPrime[0] = IsPrime[1] = 1;
    for( int i=4;i<=N;i+=2 )
        IsPrime[i] = 1;

    int SQT = sqrt(N);
    for( int i=3;i<=SQT;i+=2 ) {
        if( IsPrime[i]==0 ) {
            for(int j=i*i;j<=N;j+=2*i)
                IsPrime[j] = 1;
        }
    }

    /// sieve ends here
    Prime.push_back(2);
    for(int i=3;i<N;i+=2) {
        if(IsPrime[i]==0)
            Prime.push_back(i);
    }
}

/// Number of Divisors Starts here
int NOD( int  n ) {
    int res = 1, sqrtn = sqrt( n );
    for( int i = 0; i < Prime.size() && Prime[i] <= sqrtn; i++) {
        if( n % Prime[i] == 0 ) {
            int p = 0; /// Counter for power of prime
            while ( n % Prime[i] == 0 ) {
                n /= Prime[i];
                p++;
            }
            sqrtn = sqrt( n );
            p++; /// Increase it by one at end
            res *= p; /// Multiply with answer
        }
    }
    if( n != 1) {
        res *= 2; /// Remaining prime has power p^1. So multiply with 2
    }
    return res;
}


