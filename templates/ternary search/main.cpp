#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#ifndef LOCAL/*
    #pragma GCC optimize("Ofast")
    #pragma GCC optimize "unroll-loops"
    #pragma GCC target "mmx,sse,sse2,sse3,sse4,avx,avx2,fma,abm,popcnt,tune=native" //*/
    //#pragma GCC optimize "prefetch-loop-arrays"
#endif // LOCAL
using namespace std; using namespace __gnu_pbds;
#define foru(i,a,b) for(ll i=(a);i<(b);i++)
#define ford(i,a,b) for(ll i=(a)-1;i>=(b);i--)
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
#define sz(x) (ll)x.size()
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
template<class T1,class T2,class T3,class T4> constexpr const auto operator+(const pair<T1,T2>& a,const pair<T3,T4>& b){return mp(a.pf+b.pf,a.ps+b.ps);}
template<class T1,class T2,class T3,class T4> constexpr const auto operator-(const pair<T1,T2>& a,const pair<T3,T4>& b){return mp(a.pf-b.pf,a.ps-b.ps);}
template<class T1,class T2,class T3> constexpr const auto operator *(const pair<T1,T2>& a,const T3& b){return mp(a.pf*b,a.ps*b);}
template<class T1,class T2,class T3> constexpr const auto operator *(const T1& a,const pair<T2,T3>& b){return b*a;}
template<class T1,class T2,class T3> constexpr const auto operator /(const pair<T1,T2>& a,const T3& b){return mp(a.pf/b,a.ps/b);}
template<class T1,class T2,class T3,class T4> constexpr const auto& operator+=(pair<T1,T2> &a,const pair<T3,T4> &b){return a=a+b;}
template<class T1,class T2,class T3,class T4> constexpr const auto& operator-=(pair<T1,T2> &a,const pair<T3,T4> &b){return a=a-b;}
template<class T1,class T2,class T3> constexpr const auto& operator*=(pair<T1,T2> &a,const T3 &b){return a=a*b;}
template<class T1,class T2,class T3> constexpr const auto& operator/=(pair<T1,T2> &a,const T3 &b){return a=a/b;}
template<class T,class U> void erase(T& t,const U& u){auto it=t.find(u);if(it!=end(t)) t.erase(it);}
template<class T> T pop(queue<T> &a){auto b=a.front(); a.pop(); return b;} template<class T> auto pop(T &a){auto b=a.top(); a.pop(); return b;}
template<class T> T operator -(vector<T> &a,size_t x){return a[a.size()-x];} template<class T> T operator -(deque<T> &a,size_t x){return a[a.size()-x];}
struct chash{
    static ll splitmix64(ll x){x+=0x9e3779b97f4a7c15; x=(x^(x>>30))*0xbf58476d1ce4e5b9; x=(x^(x>>27))*0x94d049bb133111eb; return x^(x>>31);}
    template<class T> size_t operator()(const T &x) const{return splitmix64(hash<T>()(x)+SEED);}
    template<class T1,class T2> size_t operator()(const pair<T1,T2>&x)const{return 31*operator()(x.first)+operator()(x.second);}};
struct mint {//thanks benq
	//static constexpr mint rt() { return RT; } // primitive root for FFT
	int v; explicit operator int() const { return v; } // explicit -> don't silently convert to int
	mint():v(0) {}
	mint(ll _v) { v = int((-MOD < _v && _v < MOD) ? _v : _v % MOD);
		if (v < 0) v += MOD; }
	bool operator==(const mint& o) const {
		return v == o.v; }
	friend bool operator!=(const mint& a, const mint& b) {
		return !(a == b); }
	friend bool operator<(const mint& a, const mint& b) {
		return a.v < b.v; }
	//friend void re(mint& a) { ll x; re(x); a = mint(x); }
	//friend string ts(mint a) { return ts(a.v); }
	mint& operator+=(const mint& o) {
		if ((v += o.v) >= MOD) v -= MOD;
		return *this; }
	mint& operator-=(const mint& o) {
		if ((v -= o.v) < 0) v += MOD;
		return *this; }
	mint& operator*=(const mint& o) {
		v = int((ll)v*o.v%MOD); return *this; }
	mint& operator/=(const mint& o) { return (*this) *= inv(o); }
	friend mint pow(mint a, ll p) {
		mint ans = 1; assert(p >= 0);
		for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans; }
	friend mint inv(const mint& a) { assert(a.v != 0);
		return pow(a,MOD-2); }

	mint operator-() const { return mint(-v); }
	mint& operator++() { return *this += 1; }
	mint& operator--() { return *this -= 1; }
	friend mint operator+(mint a, const mint& b) { return a += b; }
	friend mint operator-(mint a, const mint& b) { return a -= b; }
	friend mint operator*(mint a, const mint& b) { return a *= b; }
	friend mint operator/(mint a, const mint& b) { return a /= b; }
	friend string to_string(const mint& a){ return to_string(a.v); }
	friend std::ostream & operator<<(std::ostream & Str, mint const & v) {
      Str << v.v;
      return Str;
    }
    friend istream& operator>> (istream& stream,  mint& v){
        stream>>v.v;
        return stream;
    }
};
void fin(string s){freopen(s.c_str(),"r",stdin);} void fout(string s){freopen(s.c_str(),"w",stdout);} void fio(string s){fin(s+".in"); fout(s+".out");}
string to_string(char c){return string(1,c);} string to_string(char* s){return (string)s;} string to_string(string s){return s;}
template<class T> string to_string(complex<T> c){stringstream ss; ss<<c; return ss.str();}
template<class T1,class T2> string to_string(pair<T1,T2> p){return "("+to_string(p.pf)+","+to_string(p.ps)+")";}
template<class T1,class T2,class T3> string to_string(tuple<T1,T2,T3> p){auto [a,b,c]=p; return "("+to_string(a)+","+to_string(b)+","+to_string(c)+")";}
template<class T1,class T2,class T3,class T4> string to_string(tuple<T1,T2,T3,T4> p){auto [a,b,c,d]=p; return "("+to_string(a)+","+to_string(b)+","+to_string(c)+","+to_string(d)+")";}
template<class T> string to_string(T v){string ret="{"; for(const auto& x:v) ret+=to_string(x)+","; return ret+"}";}
void DBG(){cerr<<"]"<<endl;} template<class T,class... Ts> void DBG(T x,Ts... xs){cerr<<to_string(x); if(sizeof...(xs)) cerr<<", "; DBG(xs...);}
#ifdef LOCAL
    #define dbg(...) cerr<<"Line("<< __LINE__<<") -> ["<<#__VA_ARGS__<<"]: [", DBG(__VA_ARGS__)
#else
    #define dbg(...) 0
#endif
#define nl "\n"

const int N=3e4,M=34444,L=31;
ll f[N],aa[N];
ll calc(ll x){
    if(x>=N) return INF+x*inf;
    return aa[x];
}
void test(ll M){
    dbg(M);
    fori(0,N){
        aa[i]=abs(i-M)*(abs(i-M)+1);
    }

}
void solve(){
    f[1]=1;
    fori(2,L) f[i]=f[i-1]+f[i-2];
    ll a,b,fa,fb;
    a=f[L-2]-1; b=f[L-1]-1; fa=calc(a); fb=calc(b);
    ford(i,L,3){
        if(fa<=fb){
            b=a; fb=fa;
            a-=f[i-3];
            fa=calc(a);
        }
        else{
            a=b; fa=fb;
            b+=f[i-3];
            fb=calc(b);
        }
    }
    assert(a==b);
    dbg(a);
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    #ifdef LOCAL
        //fin("a.txt");
    #endif
    int T=1; //cin>>T;
    foru(t,1,T+1){
        solve();
    }
    return 0;
}
/**

*/
