#define N 10000201
vector <int> IsPrime(N);
vector <int> Prime;

/// Sieve Starts here
void sieve()
{
    IsPrime[0] = IsPrime[1] = 1;
    for(int i=4;i<=N;i+=2)
        IsPrime[i] = 1;

    int SQT = sqrt(N);
    for(int i=3;i<=SQT;i+=2) {
        if(IsPrime[i]==0) {
            for(int j=i*i;j<=N;j+=2*i)
                IsPrime[j] = 1;
        }
    }

    // sieve ends here
    Prime.push_back(2);
    for(int i=3;i<N;i+=2) {
        if(IsPrime[i]==0)
            Prime.push_back(i);
    }
}

/// Prime Factorization Starts here

vector <int> factors;
void factorize( int n ) {
    factors.clear();
    int sqrtn = sqrt( n );
    for(int i = 0; i < Prime.size() && Prime[i] <= sqrtn; i++){
        if(IsPrime[n]  == 0 ) break; /*Checks if n is prime or not*/
        if( n % Prime[i] == 0) {
            while( n % Prime[i] == 0 ) {
                n /= Prime[i];
                factors.push_back(Prime[i]); // If you want unique factors, take this line out of loop
            }
        }
        sqrtn = sqrt( n );
    }
    if( n != 1) {
        factors.push_back( n );
    }
}

