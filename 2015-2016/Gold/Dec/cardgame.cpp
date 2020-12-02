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
typedef priority_queue<pl,vector<pl>,greater<pl>> pqg;
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

	ofstream cout ("cardgame.out");
	ifstream cin ("cardgame.in");
	
	int n;
	cin>>n;
	vi elsie1;
	vi elsie2;
	vector<bool> used(2*n+1, false);
	for(int i=1; i<=n; i++) {
		int temp;
		cin>>temp;
		if(i<=n/2) elsie1.pb(temp);
		else elsie2.pb(temp);
		used[temp]=true;
	}
	
	vi bessie;
	set<int> sett1;
	set<int> sett2;
	for(int i=1; i<=2*n; i++) if(!used[i]) bessie.pb(i);
	sort(bessie.begin(), bessie.end());
	
	for(int i=0; i<n; i++){
		if(i<n/2) sett2.insert(bessie[i]);
		else sett1.insert(bessie[i]);
	}
	sort(elsie1.begin(), elsie1.end());
	sort(elsie2.begin(), elsie2.end());
	
	int ans1=0;
	for(int i=0; i<n/2; i++){
		auto it=sett1.ub(elsie1[i]);
		if(it!=sett1.end()){
			ans1++;
			sett1.erase(*it);
		}
	}
	
	int ans2=0;
	for(int i=n/2-1; i>=0; i--){
		auto it=sett2.ub(elsie2[i]);
		if(it!=sett2.begin()){
			it--;
			ans2++;
			sett2.erase(it);
		}
	}
	
	cout<<ans1+ans2<<"\n";
	return 0;	
}

