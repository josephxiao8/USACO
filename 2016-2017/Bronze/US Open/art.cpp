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

int main() {
ios::sync_with_stdio(0);
cin.tie(0);

ofstream cout ("art.out");
ifstream cin ("art.in");

ll n;
cin>>n;
vector<vl> grid(n, vl(n));
vector<pair<pl,pl> > rect(10,mp(mp(LONG_LONG_MIN,LONG_LONG_MAX),mp(LONG_LONG_MIN,LONG_LONG_MAX))); //{right,left},{down,up}
for(ll j=0; j<n; j++){
	ll temp;
	cin>>temp;
	ll div=pow(10,n-1);
	for(ll i=0; i<n; i++){
		grid[j][i]=temp/div;
		temp-=grid[j][i]*div;
		div/=10;
		rect[grid[j][i]].f.f=max(rect[grid[j][i]].f.f,i);
		rect[grid[j][i]].f.s=min(rect[grid[j][i]].f.s,i);
		rect[grid[j][i]].s.f=max(rect[grid[j][i]].s.f,j);
		rect[grid[j][i]].s.s=min(rect[grid[j][i]].s.s,j);
	}
}

set<ll> colors;
set<ll> notfirst;
for(ll j=0; j<n; j++){
	for(ll i=0; i<n; i++){
		if(grid[j][i]==0 || colors.count(grid[j][i])) continue;
		colors.insert(grid[j][i]);
		for(ll j_temp=rect[grid[j][i]].s.s; j_temp<=rect[grid[j][i]].s.f; j_temp++){
			for(ll i_temp=rect[grid[j][i]].f.s; i_temp<=rect[grid[j][i]].f.f; i_temp++){
				if(grid[j_temp][i_temp]==0 || grid[j_temp][i_temp]==grid[j][i]) continue;
				notfirst.insert(grid[j_temp][i_temp]);
			}
		}
	}
}

cout<<colors.size()-notfirst.size()<<endl;
return 0;
}
