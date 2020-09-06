#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace __gnu_pbds;
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
typedef unsigned long ul;
 
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
 
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
 
typedef priority_queue<int> pq;
typedef priority_queue<int,vector<int>,greater<int>> pqg;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound


bool comp(pl a, pl b){
	if(a.s==b.s) return a.f>b.f;
	else return a.s>b.s;
}

int main() {
ios::sync_with_stdio(0);
cin.tie(0);

ofstream cout ("reststops.out");
ifstream cin ("reststops.in");

ll l,n,f,b;
cin>>l>>n>>f>>b;

vpl v;
for(ll i=0; i<n; i++){
	ll x,c;
	cin>>x>>c;
	v.pb(mp(x,c));
}
sort(v.begin(), v.end(),comp);

ll pos=0;
ll dif=f-b;
ll ans=0;
for(ll i=0; i<n; i++){
	if(v[i].f<=pos) continue;
	ll x,c;
	tie(x,c)=v[i];
	ans+=dif*(x-pos)*c;
	pos=x;
}

cout<<ans<<"\n";
return 0;	
}
