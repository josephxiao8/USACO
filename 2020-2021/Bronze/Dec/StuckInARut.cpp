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
typedef priority_queue<int,vector<int>,greater<int>> pqg;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
 
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound


bool comp(pair<char,pi> a, pair<char,pi>  b){
	return a.s.f<b.s.f;
}

int main() {
ios::sync_with_stdio(0);
cin.tie(0);

	int n;
	cin>>n;
	vector<pair<char,pi> > v(n);
	map<int,int> mapp;
	for(int i=0; i<n; i++) {
		cin>>v[i].f>>v[i].s.f>>v[i].s.s;
		mapp[v[i].s.f]=i;
	}
	sort(v.begin(), v.end(), comp);

	vi ans(n, 1e9+7);
	queue<int> q;
	for(int j=0; j<n; j++){
		if(v[j].f=='E') {
			q.push(j);
			continue;
		}
		
		vi temp;
		while(!q.empty()){
			int i=q.front(); q.pop();
			temp.pb(i);
			
			if(v[j].s.s>v[i].s.s) continue;
			if(v[i].s.s-v[j].s.s>v[j].s.f-v[i].s.f) ans[j]=min(ans[j],v[i].s.s-v[j].s.s);
		}
		
		for(auto i:temp){
			if(v[j].s.s>v[i].s.s){
				q.push(i);
				continue;
			}
	
			if(v[j].s.f-v[i].s.f>v[i].s.s-v[j].s.s && v[i].s.s-v[j].s.s<ans[j]) ans[i]=v[j].s.f-v[i].s.f;
			else q.push(i);
		}
	}
	
	vi res(n);
	for(int i=0; i<n; i++) res[mapp[v[i].s.f]]=ans[i];
	for(auto x:res){
		if(x==1e9+7) cout<<"Infinity"<<"\n";
		else cout<<x<<"\n";
	}
	
	return 0;
}
