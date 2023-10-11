#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std; using namespace __gnu_pbds;
//#pragma GCC optimize("Ofast") //#pragma GCC optimize "unroll-loops" //#pragma GCC optimize "prefetch-loop-arrays" //#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt,tune=native"
#define foru(i,a,b) for(int i=(a);i<(b);i++)
#define ford(i,a,b) for(int i=(a);i>=(b);i--)
#define fori(a,b) foru(i,a,b)
#define forj(a,b) foru(j,a,b)
#define fork(a,b) foru(k,a,b)
#define seto(x,i) memset(x,i,sizeof x)
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define pf first
#define ps second
#define pb push_back
#define eb emplace_back
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
    typedef long long i128; typedef unsigned long long ui128;
#endif
typedef long long ll;  typedef unsigned long long ull; typedef int8_t byte; typedef long double lld;
typedef pair<int,int> pii; typedef pair<ll,ll> pll; typedef pair<lld,lld> pdd;
template<typename T1,typename T2> using ordered_map=tree<T1,T2,less<int>,rb_tree_tag,tree_order_statistics_node_update>;
template<typename T1> using ordered_set=ordered_map<T1,null_type>;
template<typename T1,typename T2> using hashmap=gp_hash_table<T1,T2>;
inline ll gcd(ll a, ll b){return !b?a:gcd(b,a%b);}
inline ll fpow(ll a,ll b){if(!b) return 1; ll t=fpow(a,b/2); if(b&1) return t*t%1000000007*a%1000000007; return t*t%1000000007;}
const ll SEED=chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count();
mt19937 randgen(SEED); inline int randint(int a, int b){return uniform_int_distribution<int>(a,b)(randgen);} inline ll randll(ll a, ll b){return uniform_int_distribution<ll>(a,b)(randgen);}
template<class T1,class T2>constexpr const auto _min(const T1&x,const T2&y){return x<y?x:y;} template<class T,class...Ts>constexpr auto _min(const T&x,const Ts&...xs){return _min(x,_min(xs...));}
template<class T1,class T2>constexpr const auto _max(const T1&x,const T2&y){return x>y?x:y;} template<class T,class...Ts>constexpr auto _max(const T&x,const Ts&...xs){return _min(x,_min(xs...));}
#define min(...) _min(__VA_ARGS__)
#define max(...) _max(__VA_ARGS__)
struct pair_hash{template<class T1,class T2> size_t operator()(const pair<T1,T2>&pair)const{return 31*hash<T1>{}(pair.first)+hash<T2>{}(pair.second);}};
struct chash{int operator()(int x) const { return x ^ SEED; }};

const int N=1000,M=1e9+7;

struct AC{
    struct node{
        unordered_map<char,int> to;
        int link;
    };
    static const int V=26;
    vector<node> ac;
    int nxt[N][V],sz[N];
    AC(){
        reset();
    }
    void reset(){
        ac.clear(); seto(sz,0);
        ac.eb();
    }
    void add(string s){
        int cur=0;
        for(auto ch:s){
            if(!ac[cur].to[ch]){
                ac[cur].to[ch]=sz(ac);
                ac.eb();
            }
            cur=ac[cur].to[ch];
        }
        sz[cur]++;
    }
    void dfs(int v){
        if(nxt[v][0]!=-1) return;
        if(ac[v].link!=-1){
            dfs(ac[v].link);
            sz[v]+=sz[ac[v].link];
        }
        fori(0,V){
            if(ac[v].to.count('a'+i)) nxt[v][i]=ac[v].to['a'+i];
            else if(ac[v].link==-1) nxt[v][i]=0;
            else nxt[v][i]=nxt[ac[v].link][i];
        }
    }
    void init(){
        int v,u; queue<int> toV; toV.push(0); ac[0].link=-1;
        while(sz(toV)){
            v=toV.front(); toV.pop();
            for(auto i:ac[v].to){
                if(!i.ps) continue;
                u=ac[v].link;
                while(u!=-1&&!ac[u].to.count(i.pf)) u=ac[u].link;
                ac[i.ps].link=u==-1? 0: ac[u].to[i.pf];
                toV.push(i.ps);
            }
        }
        seto(nxt,-1); fori(0,sz(ac)) dfs(i);
    }
} ac;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin); //freopen("", "w", stdout);
    return 0;
}
/**

*/

