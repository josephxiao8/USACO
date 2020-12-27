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


int n,m;
vector<string> v;

bool possible(int size){
	for(int i=0; i+size<m; i++){
		set<string> sett;
		for(int j=0; j<n; j++) sett.insert(v[j].substr(i,size+1));
		bool good=true;
		for(int j=n; j<2*n; j++){
			if(sett.count(v[j].substr(i,size+1))){
				good=false;
				break;
			}
		}
		if(good) return true;
	}
	return false;
}


int main() {
ios::sync_with_stdio(0);
cin.tie(0);
	
	ofstream cout ("cownomics.out");
	ifstream cin ("cownomics.in");
	
	cin>>n>>m;
	v=vector<string>(2*n);
	for(int i=0; i<2*n; i++) cin>>v[i];
	
	int size=1;
	for(int b=m/2; b>=1; b/=2){
		while(size+b<m && !possible(size+b)) size+=b;
	}
	
	cout<<size+2<<"\n";
	return 0;
}
