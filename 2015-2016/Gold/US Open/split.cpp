#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace __gnu_pbds;
using namespace std; 
 
typedef long long ll;
 
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef tuple<int,int,int> ti;
typedef tuple<ll,ll,ll> tl;
 
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<ti> vti;
typedef vector<tl> vtl;
 
typedef priority_queue<int> pq;
typedef priority_queue<pl,vector<pl>,greater<pl>> pqg;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
 
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound


bool comp(pl a, pl b){
	if(a.s==b.s) return (a.f<b.f);
	else return a.s<b.s;	
}

int main() {
ios::sync_with_stdio(0);
cin.tie(0);

	ofstream cout ("split.out");
	ifstream cin ("split.in");
	
	int n;
	cin>>n;
	vpl v(n);
	for(int i=0; i<n; i++) cin>>v[i].f>>v[i].s;
	
	ll ans=LONG_LONG_MAX;
	vpl pre_x(n); //min, max
	vpl suf_x(n); //min, max
	vpl pre_y(n); //min, max
	vpl suf_y(n); //min, max 
	
	sort(v.begin(), v.end());
	pre_x[0]={v[0].s, v[0].s};
	suf_x[n-1]={v[n-1].s, v[n-1].s};
	for(int i=1; i<n; i++) pre_x[i]={min(pre_x[i-1].f,v[i].s), max(pre_x[i-1].s,v[i].s)};
	for(int i=n-2; i>=0; i--) suf_x[i]={min(suf_x[i+1].f, v[i].s), max(suf_x[i+1].s,v[i].s)};
	
	for(int i=0; i<n-1; i++){
		ll temp=0;
		temp+=((pre_x[i].s-pre_x[i].f)*(v[i].f-v[0].f));
		temp+=((suf_x[i+1].s-suf_x[i+1].f)*(v[n-1].f-v[i+1].f));
		ans=min(ans, temp);
	}
	
	sort(v.begin(), v.end(), comp);
	pre_y[0]={v[0].f, v[0].f};
	suf_y[n-1]={v[n-1].f, v[n-1].f};
	for(int i=1; i<n; i++) pre_y[i]={min(pre_y[i-1].f,v[i].f), max(pre_y[i-1].s,v[i].f)};
	for(int i=n-2; i>=0; i--) suf_y[i]={min(suf_y[i+1].f, v[i].f), max(suf_y[i+1].s,v[i].f)};
	
	for(int i=0; i<n-1; i++){
		ll temp=0;
		temp+=((pre_y[i].s-pre_y[i].f)*(v[i].s-v[0].s));
		temp+=((suf_y[i+1].s-suf_y[i+1].f)*(v[n-1].s-v[i+1].s));
		ans=min(ans, temp);
	}
	
	ll temp=abs((pre_y[n-1].s-pre_y[n-1].f)*(v[n-1].s-v[0].s));
	cout<<temp-ans<<"\n";
	
	return 0;
}
