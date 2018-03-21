/*===============================================
    Username    : Caffeines
    Name        : Abu Sadat Md. Sayem
    about me    : caffeines.github.io
    University  : North South University (NSU)
=================================================*/

#include <bits/stdc++.h>
#define F first
#define S second
#define pf printf
#define Size 1001
#define MP make_pair
#define pb push_back
#define pl printf("\n")
#define SQ(x) ((x)*(x))
#define sf(n) scanf("%d",&n)
#define ABS(x) ((x)<0?-(x):(x))
#define slf(n) scanf("%lld",&n)
#define phl printf ( "hello\n" )
#define MOD(x,y) (((x)*(y))%mod)
#define NORM(x) if(x>=mod)x-=mod
#define RIGHTMOST __builtin_ctzll
#define SZ(x) ((vlong)(x).size())
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define pcase printf("Case %d: ",t)
#define ODD(x) (((x)&1)==0?(0):(1))
#define FABS(x) ((x)+eps<0?-(x):(x))
#define all(x) (x).begin(),(x).end()
#define sff(n,m) scanf("%d %d",&n,&m)
#define POPCOUNT __builtin_popcountll
#define read(x)  freopen(x,"r",stdin)
#define write(x) freopen(x,"w",stdout)
#define mem(x,y) memset(x,y,sizeof(x))
#define slff(n,m) scanf("%lld %lld",&n,&m)
#define LEFTMOST(x) (63-__builtin_clzll((x)))
#define REP(i,y) for(ull i = 0 ; i < (y) ; ++i)
#define kase(a,t) for(int a = 1 ; a <= (t) ; ++a)
#define FOR(i,x,y) for(ull i = (x) ; i <= (y) ; ++i)
#define ROF(i,x,y) for(ull i = (y) ; i >= (x) ; --i)
#define NUMDIGIT(x,y) (((ll)(log10((x))/log10((y))))+1)
#define valid(i,j) (i >= 0 && j>= 0 && i < 1001 && j < 1001)
#define LB(a,key) lower_bound(a.begin(),a.end(), key) -a.begin()
#define UB(a,key) upper_bound(a.begin(),a.end(), key) -a.begin()
#define Unique(V) (V).erase(unique((V).begin(),(V).end()),(V).end())

using namespace std;
typedef long long ll;
const double eps = 1e-9;
typedef unsigned long long ull;
typedef pair < ll, ll> pll;
typedef pair < int,int> pii;
typedef vector<pll> pv;
typedef vector<ll> vl;
typedef vector <int> vi;
const int inf = (int) 10e9;
const int INF = (ll) 10e18;
const double PI = 2 * acos ( 0.0 );

int dx[] = {+1,-1,0,0};
int dy[] = {0,0,+1,-1};
int hx[] = {+1,-1,-1,+1,-2,-2,+2,+2};
int hy[] = {+2,+2,-2,-2,+1,-1,+1,-1};
int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1};
int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1};

template < typename T> inline T GCD(T a, T b) {a=ABS(a), b=ABS(b); return !b ? a : GCD(b,a%b); }
template < typename T> inline T LCM(T x, T y) {T g = GCD(x,y); return x*(y/g); }
template < typename T> inline T power(T b,T p) { T res = 1, x = b; while ( p ) { if ( p & 1 ) res = ( res * x ); x = ( x * x ); p >>= 1;}return res;}
template < typename T> inline T bigmod (T b, T p, T m) { T res = 1 % m, x = b % m; while ( p ) { if ( p & 1 ) res = ( res * x ) % m; x = ( x * x ) % m; p >>= 1; }return res; }

/*=========================================================
    stop doubting yourself, work hard and make it happen.
==========================================================*/

int main()
{
    //read("input.txt");
    //write("output.txt");

    return 0;
}
