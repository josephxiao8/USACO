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


int n;
vi v;

bool possible(int k){
	vi temp;
	for(int i=0; i<k; i++) temp.pb(v[i]);
	sort(temp.rbegin(), temp.rend());
	set<int> sett;
	map<int,stack<int>> mapp;
	
	vector<bool> added(n+1,false);
	for(int i=0; i<k; i++){
		added[v[i]]=true;
		auto it=sett.ub(v[i]);
		if(it==sett.end()) {
			sett.insert(v[i]);
			mapp[v[i]].push(v[i]);
		}
		else mapp[*it].push(v[i]);
		while(!sett.empty() && temp.size()){
			if(!added[temp.back()]) break;
			auto jt=sett.lb(temp.back());
			if(mapp[*jt].top()==temp.back()){
				mapp[*jt].pop();
				if(*jt==temp.back()) sett.erase(jt);
				temp.pop_back();
			}
			else break;
		}
	}
	return sett.empty();
}

int main() {
ios::sync_with_stdio(0);
cin.tie(0);

	ofstream cout ("dishes.out");
	ifstream cin ("dishes.in");
	
	cin>>n;
	v=vi(n);
	for(int i=0; i<n; i++) cin>>v[i];
	
	int k=0;
	for(int b=n/2; b>=1; b/=2){
		while(k+b<=n && possible(k+b)) k+=b;
	}
	
	cout<<k<<"\n";
	return 0;
}
