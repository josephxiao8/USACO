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

ofstream cout ("gymnastics.out");
ifstream cin ("gymnastics.in");

int k,n;
cin>>k>>n;

vector<vi> v(k, vi(n));
for(int j=0; j<k; j++){
	for(int i=0; i<n; i++) cin>>v[j][i];
}

int pairs=0;
for(int j=0; j<n-1; j++){
	for(int i=j+1; i<n; i++){
		
		int a=0, b=0;
		for(auto x:v){
			for(int c=0; c<n; c++){
				if(x[c]==j+1){
					a++;
					break;
				}
				if(x[c]==i+1){
					b++;
					break;
				}
			}
		}
		if(a==0 || b==0) pairs++;
	}	
}

cout<<pairs<<endl;
return 0;	
}
