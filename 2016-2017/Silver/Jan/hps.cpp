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

ofstream cout ("hps.out");
ifstream cin ("hps.in");

int n;
cin>>n;
vector<char> v(n);
for(int i=0; i<n; i++) cin>>v[i];

vector<vi> prefix(n+1, vi(3));
prefix[0]={0,0,0};
for(int i=1; i<=n; i++){
	int a,b,c;
	a=prefix[i-1][0];
	b=prefix[i-1][1];
	c=prefix[i-1][2];
	if(v[i-1]=='H') b++;
	else if(v[i-1]=='P') c++;
	else a++;
	prefix[i]={a,b,c};
}

int ans=0;
for(int j=0; j<3; j++){
	for(int i=0; i<3; i++){
		for(int k=0; k<=n; k++){
			ans=max(ans, prefix[k][j]-prefix[0][j] + prefix[n][i]-prefix[k][i]);
		}
	}
}

cout<<ans<<"\n";
return 0;	
}

