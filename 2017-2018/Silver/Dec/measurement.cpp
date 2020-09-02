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

ofstream cout ("measurement.out");
ifstream cin ("measurement.in");

ll n,g;
cin>>n>>g;

map<ll,ll> at_g;
map<ll,ll> mapp;
multiset<ll> sett;
vector<tuple<ll,ll,ll> > v;
for(int i=0; i<n; i++){
	int a,b,c;
	cin>>a>>b>>c;
	v.pb(make_tuple(a,b,c));
}
sort(v.begin(), v.end());

ll maxx, size, ans=0;
for(ll i=0; i<n; i++){
	ll a,b,c;
	tie(a,b,c)=v[i];
	
	if(at_g[b]==0){
		at_g[b]=1;
		mapp[b]=g+c;
		sett.insert(g+c);
	}
	else{
		if(mapp[b]+c==g){
			sett.erase(sett.find(mapp[b]));
			at_g[b]=0;
		}
		else{
			sett.erase(sett.find(mapp[b]));
			mapp[b]+=c;
			sett.insert(mapp[b]);
		}
	}
	
	if(i==0){
		ans++;
		maxx=max(g,mapp[b]);
		if(maxx==mapp[b]) size=1;
		else size=1e9;
	}
	else{
		ll prevsize=size;
		ll prevmaxx=maxx;
		if(sett.empty()) maxx=g;
		else maxx=max(g,*(--sett.end()));
		if(maxx==*(--sett.end())) size=sett.count(*(--sett.end()));
		else size=1e9;
		int temp;
		if(at_g[b]==0) temp=g;
		else temp=mapp[b];
		
		if(prevsize==1 && size==1 && prevmaxx==temp-c && maxx==temp) continue;
		if(prevmaxx!=maxx) ans++;
		else if(temp==maxx) ans++;
		else if(temp-c==maxx) ans++;
	}
}

cout<<ans<<"\n";
return 0;	
}

