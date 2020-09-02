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

ofstream cout ("cownomics.out");
ifstream cin ("cownomics.in");

int n,m;
cin>>n>>m;

map<char,int> mapp;
mapp['A']=0;
mapp['C']=1;
mapp['G']=2;
mapp['T']=3;

vector<vi> spot(n, vi(m));
for(int j=0; j<n; j++){
	string temp;
	cin>>temp;
	for(int i=0; i<m; i++){
		spot[j][i]=mapp[temp[i]];
	}
}
vector<vi> plain(n, vi(m));
for(int j=0; j<n; j++){
	string temp;
	cin>>temp;
	for(int i=0; i<m; i++){
		plain[j][i]=mapp[temp[i]];
	}
}

int ans=0;
for(int k=0; k<m-2; k++){
	for(int j=k+1; j<m-1; j++){
		for(int i=j+1; i<m; i++){
			
			bool good=true;
			vector<bool> found(65,false);
			for(auto x:spot){
				int temp=0;
				temp+=16*x[k];
				temp+=4*x[j];
				temp+=x[i];
				found[temp]=true;
			}
			
			for(auto x:plain){
				int temp=0;
				temp+=16*x[k];
				temp+=4*x[j];
				temp+=x[i];
				if(found[temp]){
					good=false;
					break;
				}
			}
			
			if(good) ans++;
		}
	}
}

cout<<ans<<"\n";
return 0;	
}

