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

ofstream cout ("paintbarn.out");
ifstream cin ("paintbarn.in");

int n,k;
cin>>n>>k;
vector<vi> pick_and_drop(1001,vi(1001,0));
for(int i=0; i<n; i++){
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	for(int j=a; j<c; j++){
		pick_and_drop[j][b]++;
		pick_and_drop[j][d]--;
	}
}

int ans=0;
for(int i=0; i<=1000; i++){
	int counter=0;
	for(int j=0; j<=1000; j++){
		counter+=pick_and_drop[i][j];
		if(counter==k) ans++;
	}	
}

cout<<ans<<"\n";
return 0;	
}

