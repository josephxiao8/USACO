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

ofstream cout ("cowtip.out");
ifstream cin ("cowtip.in");

int n;
cin>>n;
vector<vl> grid(n,vl(n));
for(int j=0; j<n; j++){
	ll temp;
	cin>>temp;
	ll div=pow(10,n-1);
	for(int i=0; i<n; i++){
		grid[j][i]=temp/div;
		temp-=grid[j][i]*div;
		div/=10;
	}
}

int counter=0;
for(int j=n-1; j>=0; j--){
	for(int i=n-1; i>=0; i--){
		if(grid[j][i]==1){
			counter++;
			for(int tempj=0; tempj<=j; tempj++){
				for(int tempi=0; tempi<=i; tempi++){
					if(grid[tempj][tempi]==1) grid[tempj][tempi]=0;
					else grid[tempj][tempi]=1;
				}
			}
		}
	}
}

cout<<counter<<endl;
return 0;
}
