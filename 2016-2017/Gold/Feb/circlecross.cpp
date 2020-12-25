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


int main() {
ios::sync_with_stdio(0);
cin.tie(0);
	
	ofstream cout ("circlecross.out");
	ifstream cin ("circlecross.in");
	
	int n;
	cin>>n;
	int ans=0;
	indexed_set sett;
	vi idx(n+1,-1);
	for(int i=0; i<2*n; i++){
		int num;
		cin>>num;
		if(idx[num]!=-1){
			ans+=sett.size()-1-sett.order_of_key(idx[num]);
			sett.erase(sett.find(idx[num]));
		}
		else {
			idx[num]=i;
			sett.insert(i);
		}
	}
	
	cout<<ans<<"\n";
	return 0;
}
