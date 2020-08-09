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

ofstream cout ("div7.out");
ifstream cin ("div7.in");

ll n;
cin>>n;
ll sum=0;
vector<vector<ll> > v(7);
for(ll i=0; i<n; i++){
	ll temp;
	cin>>temp;
	sum+=temp;
	v[sum%7].pb(i);
}

ll ans=0;
for(int i=0; i<7; i++){
	if(v[i].size()==0) continue;
	if(v[i].size()==1) {
		if(i==0) ans=max(ans,v[i][0]+1);
	}
	else {
		if(i==0) ans=max(ans,v[i][v[i].size()-1]+1);
		else ans=max(ans,v[i][v[i].size()-1]-v[i][0]);
	}
}

cout<<ans<<"\n";
return 0;	
}
