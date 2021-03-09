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
typedef priority_queue<pair<pl,ll>,vector<pair<pl,ll>>,greater<pair<pl,ll>>> pqg;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
 
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound


int main() {
ios::sync_with_stdio(0);
cin.tie(0);

	ofstream cout ("boards.out");
	ifstream cin ("boards.in");
	
	ll n,p;
	cin>>n>>p;
	vector<pair<pl,pl>> v;
	map<pl,ll> mapp;
	for(ll i=0; i<p; i++){
		ll a,b,c,d;
		cin>>a>>b>>c>>d;
		v.pb(mp(mp(a,b),mp(-1,-1)));
		v.pb(mp(mp(c,d),mp(a,b)));
	}
	sort(v.begin(), v.end());
	
	set<pl> sett;
	sett.insert(mp(0,0));
	for(ll i=0; i<2*p; i++){
		int a,b,c,d;
		tie(a,b)=v[i].f;
		tie(c,d)=v[i].s;
		
		if(c==-1 && d==-1){
			auto kt=sett.ub(mp(b,1e18));
			kt--;
			mapp[mp(a,b)]=a+b+(*kt).s;	
		}
		else{
			auto it=sett.ub(mp(b,1e18));
			it--;
			if((*it).s>mapp[mp(c,d)]-a-b){
				if((*it).f<b) it++;
				if(it==sett.end() || (*it).s<mapp[mp(c,d)]-a-b) sett.insert(mp(b,mapp[mp(c,d)]-a-b));
				else{
					auto jt=it;
					jt++;
					for(; jt!=sett.end() && (*jt).s>=mapp[mp(c,d)]-a-b; jt++);
					sett.erase(it,jt);
					sett.insert(mp(b,mapp[mp(c,d)]-a-b));
				}
			}
		}
	}
	
	auto mt=sett.ub(mp(n,1e18));
	mt--;
	cout<<2*n+(*mt).s<<"\n";
	return 0;
}
