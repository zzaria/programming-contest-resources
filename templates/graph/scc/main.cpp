#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/priority_queue.hpp>
//#pragma GCC optimize("Ofast") //#pragma GCC optimize "unroll-loops" //#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,avx2,fma,mmx,popcnt,tune=native" //#pragma GCC optimize "prefetch-loop-arrays"
using namespace std; using namespace __gnu_pbds;
#define foru(i,a,b) for(int i=(a);i<(b);i++)
#define ford(i,a,b) for(int i=(a);i>=(b);i--)
#define fori(a,b) foru(i,a,b)
#define forj(a,b) foru(j,a,b)
#define fork(a,b) foru(k,a,b)
#define seto(x,i) memset(x,i,sizeof x)
#define pf first
#define ps second
#define pb push_back
#define eb emplace_back
#define em emplace
#define mp make_pair
#define mt make_tuple
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll
#define clz __builtin_clz
#define clzll __builtin_clzll
#define ctz __builtin_ctz
#define ctzll __builtin_ctzll
#define P2(x) (1LL<<(x))
#define sz(x) (int)x.size()
#define all(x) begin(x),end(x)
#if __SIZEOF_INT128__
    typedef __int128_t i128; typedef __uint128_t ui128;
#else
    typedef int64_t i128; typedef uint64_t ui128;
#endif
typedef int64_t ll;  typedef uint64_t ull; typedef long double lld;
typedef pair<int,int> pii; typedef pair<ll,ll> pll; typedef pair<lld,lld> pdd;
template<class T1,class T2> using ordered_map=tree<T1,T2,less<T1>,rb_tree_tag,tree_order_statistics_node_update>; template<class T1> using ordered_set=ordered_map<T1,null_type>;
template<class T> using minpq=std::priority_queue<T,vector<T>,greater<T>>; template<class T> using maxpq=std::priority_queue<T,vector<T>,less<T>>;
template<class T> using minpairingheap=__gnu_pbds::priority_queue<T,greater<T>,pairing_heap_tag>; template<class T>using maxpairingheap=__gnu_pbds::priority_queue<T,less<T>,pairing_heap_tag>;
const int inf=0x3f3f3f3f,MOD=1e9+7; const ll INF=0x3f3f3f3f3f3f3f3f; const lld PI=acos((lld)-1);
const ll SEED=443214^chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count();
mt19937 randgen(SEED); ll rand(ll a, ll b){return uniform_int_distribution<ll>(a,b)(randgen);}
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll fpow(ll a,ll b){ll ret=1;for(;b;b>>=1){if(b&1) ret=ret*a%MOD;a=a*a%MOD;}return ret;} ll fpow(ll a,ll b,ll M){ll ret=1;for(;b;b>>=1){if(b&1) ret=ret*a%M;a=a*a%M;}return ret;}
template<class T1,class T2>constexpr const auto _min(const T1&x,const T2&y){return x<y?x:y;} template<class T,class...Ts>constexpr auto _min(const T&x,const Ts&...xs){return _min(x,_min(xs...));}
template<class T1,class T2>constexpr const auto _max(const T1&x,const T2&y){return x>y?x:y;} template<class T,class...Ts>constexpr auto _max(const T&x,const Ts&...xs){return _max(x,_max(xs...));}
#define min(...) _min(__VA_ARGS__)
#define max(...) _max(__VA_ARGS__)
template<class T1,class T2>constexpr bool ckmin(T1&x,const T2&y){return x>y?x=y,1:0;} template<class T,class...Ts>constexpr bool ckmin(T&x,const Ts&...xs){return ckmin(x,min(xs...));}
template<class T1,class T2>constexpr bool ckmax(T1&x,const T2&y){return x<y?x=y,1:0;} template<class T,class...Ts>constexpr bool ckmax(T&x,const Ts&...xs){return ckmax(x,max(xs...));}
struct chash{
    static ll splitmix64(ll x){x+=0x9e3779b97f4a7c15; x=(x^(x>>30))*0xbf58476d1ce4e5b9; x=(x^(x>>27))*0x94d049bb133111eb; return x^(x>>31);}
    template<class T> size_t operator()(const T &x) const{return splitmix64(hash<T>()(x)+SEED);}
    template<class T1,class T2> size_t operator()(const pair<T1,T2>&x)const{return 31*operator()(x.first)+operator()(x.second);}};
void fIn(string s){freopen(s.c_str(),"r",stdin);} void fOut(string s){freopen(s.c_str(),"w",stdout);} void fIO(string s){fIn(s+".in"); fOut(s+".out");}
string to_string(char c){return string(1,c);} string to_string(char* s){return (string)s;} string to_string(string s){return s;}
template<class T> string to_string(complex<T> c){stringstream ss; ss<<c; return ss.str();}
template<class T1,class T2> string to_string(pair<T1,T2> p){return "("+to_string(p.pf)+","+to_string(p.ps)+")";}
template<class T> string to_string(T v){string ret="{"; for(const auto& x:v) ret+=to_string(x)+","; return ret+"}";}
void DBG(){cerr<<"]"<<endl;} template<class T,class... Ts> void DBG(T x,Ts... xs){cerr<<to_string(x); if(sizeof...(xs)) cerr<<", "; DBG(xs...);}
#ifdef LOCAL
    #define dbg(...) cerr<<"Line("<< __LINE__<<") -> ["<<#__VA_ARGS__<<"]: [", DBG(__VA_ARGS__)
#else
    #define dbg(...) 0
#endif
#define nl "\n"

const int N=1000,M=MOD;

int n,m,a,b,c;
vector<int> gr[N],gr2[N];


struct BCC{
    stack<int> scc;
    int n2,dfn[N],low[N],inx;
    void init(){
        n2=n; inx=0; seto(dfn,0);
    }
    void genBCC(int v,int p=0){ //articulation point
        dfn[v]=low[v]=++inx; scc.push(v);
        for(auto i:gr[v]) if(i!=p){
            if(dfn[i]) ckmin(low[v],dfn[i]); //must not be min(low[v],low[i])
            else{
                genBCC(i,v);
                ckmin(low[v],low[i]);
                if(low[i]>=dfn[v]){
                    n2++;
                    gr2[v].pb(n2);
                    for(;!sz(gr2[n2])||gr2[n2].back()!=i;scc.pop()) gr2[n2].pb(scc.top());
                }
            }
        }
    }
}bcc;

struct BCC{
    stack<int> scc;
    int n2=0,dfn[N]={0},low[N],inx=0,id[N];
    void genBCC(){
        fori(1,n+1) if(!dfn[i]) dfs(i);
    }
    void dfs(int v,int p=0){ // bridge bcc
        low[v]=dfn[v]=++inx; scc.push(v);
        for(auto i:gr[v]) if(i!=p){
            if(dfn[i]) ckmin(low[v],dfn[i]); //works with min(low[v],low[i])
            else{
                dfs(i,v);
                ckmin(low[v],low[i]);
            }
        }
        if(low[v]==dfn[v]){
            for(;scc.top()!=v;scc.pop()) id[scc.top()]=n2;
            id[v]=n2++; scc.pop();
        }
    }
}bcc;

struct SCC{
    stack<int> scc;
    int n2=0,dfn[N]={0},low[N],inx=0,id[N];
    bitset<N> ins;
    void genSCC(){
        fori(1,n+1) if(!dfn[i]) dfs(i);
    }
    void dfs(int v){ // directed scc
        low[v]=dfn[v]=++inx; ins[v]=1; scc.push(v);
        for(auto i:gr[v]){
            if(!dfn[i]){
                dfs(i);
                ckmin(low[v],low[i]);
            }
            else if(ins[i]) ckmin(low[v],dfn[i]); //works with min(low[v],low[i]) too
        }
        if(low[v]==dfn[v]){
            for(int i=scc.top();;i=scc.top()){
                id[i]=n2; ins[i]=0; scc.pop();
                if(i==v) break;
            }
            n2++;
        }
    }
}scc;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin); //freopen("", "w", stdout);
    cin>>n>>m;
    fori(0,m){
        cin>>a>>b;
        gr[a].pb(b);
    }
    fori(0,n) if(!bcc.dfn[i]) bcc.genBCC(i);
    return 0;
}
/**

*/
