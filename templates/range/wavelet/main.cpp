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

const int N=P2(18),M=1e9+7;
struct wavelet{
    vector<int> tol[N];
    void build(vector<int> a,int ind=1,int l=0,int r=N-1){
        if(l==r||!sz(a)) return;
        vector<int> A[2]; int mid=(l+r)/2; tol[ind].pb(0);
        for(auto i:a){
            A[i>mid].pb(i);
            tol[ind].pb(sz(A[0]));
        }
        build(A[0],2*ind,l,mid); build(A[1],2*ind+1,mid+1,r);
    }
    int query(int lo,int hi,int k,int ind=1,int l=0,int r=N-1){ //kth min number in lo to hi-1 0 indexed
        if(l==r) return l;
        int mid=(l+r)/2,temp=tol[ind][hi]-tol[ind][lo];
        if(temp>=k) return query(tol[ind][lo],tol[ind][hi],k,2*ind,l,mid);
        return query(lo-tol[ind][lo],hi-tol[ind][hi],k-temp,2*ind+1,mid+1,r);
    }
} st;
int n,q,a,b,c;
vector<int> num,poi;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin); //freopen("", "w", stdout);
    cin>>n>>q;
    fori(0,n){
        cin>>a; num.pb(a); poi.pb(a);
    }
    sort(all(poi)); a=0;
    for(auto& i:num) i=lower_bound(all(poi),i)-begin(poi);
    st.build(num);
    fori(0,q){
        cin>>a>>b>>c;
        cout<<poi[st.query(a,b,c+1)]<<"\n";
    }
    return 0;
}
/**

*/
