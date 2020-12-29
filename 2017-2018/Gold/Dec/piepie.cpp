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
typedef priority_queue<tuple<int,pi,int>,vector<tuple<int,pi,int>>,greater<tuple<int,pi,int>>> pqg;
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
	
	ofstream cout ("piepie.out");
	ifstream cin ("piepie.in");
	
	int n,d;
	cin>>n>>d;
	multiset<pi> bes;
	multiset<pi> els;
	queue<pi> q; // {,0} for bes, {,1} for els
	vi dis(2*n, -1);
	vpi pies(2*n);
	for(int i=0; i<n; i++){
		cin>>pies[i].f>>pies[i].s;
		if(pies[i].s==0) {
			q.push(mp(i,0));
			dis[i]=1;
		}
		else bes.insert(mp(pies[i].s,i));
	}
	for(int i=n; i<2*n; i++){
		cin>>pies[i].f>>pies[i].s;
		if(pies[i].f==0) {
			q.push(mp(i,1));
			dis[i]=1;
		}
		else els.insert(mp(pies[i].f,i));
	}
	
	while(!q.empty()){
		int a,b;
		tie(a,b)=q.front(); q.pop();
		
		if(b==0){ //we need to transiton to an elsie pie
			for(auto it=els.lb(mp(pies[a].f-d,0)); it!=els.end() && it!=els.lb(mp(pies[a].f+1,0)); it++){
				int c=(*it).s;
				dis[c]=dis[a]+1;
				q.push(mp(c,1));
			}
			els.erase(els.lb(mp(pies[a].f-d,0)),els.lb(mp(pies[a].f+1,0)));
		}
		else{ //we need to transition to a bessie pie
			for(auto it=bes.lb(mp(pies[a].s-d,0)); it!=bes.end() && it!=bes.lb(mp(pies[a].s+1,0)); it++){
				int c=(*it).s;
				dis[c]=dis[a]+1;
				q.push(mp(c,0));
			}
			bes.erase(bes.lb(mp(pies[a].s-d,0)),bes.lb(mp(pies[a].s+1,0)));
		}
	}

	for(int i=0; i<n; i++) cout<<dis[i]<<"\n";
	return 0;
}
