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

ofstream cout ("cowsignal.out");
ifstream cin ("cowsignal.in");

int m,n,k;
cin>>m>>n>>k;
vector<vector<char> >grid(m,vector<char>(n));
for(int j=0; j<m; j++){
	for(int i=0; i<n; i++){
		cin>>grid[j][i];
	}
}

vector<vector<char> > ans(k*m, vector<char>(2*n));
for(int j=0; j<k*m; j++){
	for(int i=0; i<k*n; i++){
		cout<<grid[j/k][i/k];
	}
	cout<<endl;
}

return 0;
}
