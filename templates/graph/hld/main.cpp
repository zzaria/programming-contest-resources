#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/priority_queue.hpp>
//#pragma GCC optimize("Ofast") //#pragma GCC optimize "unroll-loops" //#pragma GCC target "avx,avx2,fma,abm,popcnt,tune=native" //#pragma GCC optimize "prefetch-loop-arrays"
using namespace std; using namespace __gnu_pbds;
#define foru(i,a,b) for(int i=(a);i<(b);i++)
#define ford(i,a,b) for(int i=(a)-1;i>=(b);i--)
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
#define lwb lower_bound
#define upb upper_bound
#if __SIZEOF_INT128__
    typedef __int128_t i128; typedef __uint128_t ui128;
#endif
typedef int64_t ll;  typedef uint64_t ull; typedef long double lld; typedef pair<int,int> pii; typedef pair<ll,ll> pll; typedef pair<lld,lld> pdd;
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
template<class T,class U> void erase(T& t,const U& u){auto it=t.find(u);if(it!=end(t)) t.erase(it);}
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

const int N=P2(17),M=1e9+7;
struct node{
    int v,lz;
};
class segTree{ //0 indexed
public:
    node seg[2*N];
    void pull(int num){
        seg[num].v=max(seg[num*2].v,seg[num*2+1].v);
    }
    void push(int num,int l,int r){
        if(!seg[num].lz) return;
        if(l!=r) fori(0,2) seg[2*num+i].lz+=seg[num].lz;
        seg[num].v+=seg[num].lz;
        seg[num].lz=0;
    }
    void upd(int lo,int hi,int val,int num=1,int l=0,int r=N-1){
        push(num,l,r);
        if(hi<l||r<lo) return;
        if(lo<=l&&r<=hi){
            seg[num].lz=val; push(num,l,r);
            return;
        }
        int mid=(l+r)/2;
        upd(lo,hi,val,num*2,l,mid); upd(lo,hi,val,num*2+1,mid+1,r);
        pull(num);
    }
    int query(int lo,int hi,int num=1,int l=0,int r=N-1){
        push(num,l,r);
        if(hi<l||r<lo) return -inf;
        if(lo<=l&&r<=hi) return seg[num].v;
        int mid=(l+r)/2;
        return max(query(lo,hi,num*2,l,mid),query(lo,hi,2*num+1,mid+1,r));
    }
};
segTree st;
int q,n,a,b,c,sz[N],in[N],rt[N],par[N];
vector<int> gr[N];

int szDfs(int v,int p=0){
    par[v]=p; sz[v]=1;
    for(auto& i:gr[v]) if(i!=p){
        sz[v]+=szDfs(i,v);
        if(gr[v][0]==p||sz[i]>sz[gr[v][0]]) swap(i,gr[v][0]);
    }
    return sz[v];
}
void hldDfs(int v,int p=0){
    in[v]=a++;
    for(auto i:gr[v]) if(i!=p){
        rt[i]=(i==gr[v][0]? rt[v]: i);
        hldDfs(i,v);
    }
}
void updPath(int u,int v,int val){
    while(rt[u]!=rt[v]){
        if(in[rt[u]]>in[rt[v]]) swap(u,v);
        st.upd(in[rt[v]],in[v],val);
        v=par[rt[v]];
    }
    if(in[u]>in[v]) swap(u,v);
    st.upd(in[u],in[v],val); //u for nodes, gr[u][0] for edges and return if u==v
}
int queryPath(int u,int v){
    int ret=-inf;
    while(rt[u]!=rt[v]){
        if(in[rt[u]]>in[rt[v]]) swap(u,v);
        ckmax(ret,st.query(in[rt[v]],in[v]));
        v=par[rt[v]];
    }
    if(in[u]>in[v]) swap(u,v);
    ckmax(ret,st.query(in[u],in[v])); //u for nodes, gr[u][0] for edges and return if u==v
    return ret;
}

string s;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>n;
    fori(1,n){
        cin>>a>>b;
        gr[a].eb(b); gr[b].eb(a);
    }
    a=0; szDfs(1,0); hldDfs(1,0);
    cin>>q;
    while(q--){
        cin>>s>>a>>b;
        if(s=="add") st.upd(in[a],in[a]+sz[a]-1,b);
        else cout<<queryPath(a,b)<<"\n";
    }
    return 0;
}
/**
verification: https://www.hackerrank.com/challenges/subtrees-and-paths/problem
*/
