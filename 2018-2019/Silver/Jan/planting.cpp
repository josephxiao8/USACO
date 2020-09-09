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

ofstream cout ("planting.out");
ifstream cin ("planting.in");

int ans=1;
int n;
cin>>n;
vi deg(n,0);
for(int i=0; i<n-1; i++){
	int a,b;
	cin>>a>>b;
	a--;
	b--;
	deg[a]++;
	deg[b]++;
	ans=max(ans,deg[a]);
	ans=max(ans,deg[b]);
}

cout<<ans+1<<"\n";
return 0;	
}

