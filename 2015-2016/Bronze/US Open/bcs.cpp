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

ofstream cout ("bcs.out");
ifstream cin ("bcs.in");

int n,k;
cin>>n>>k;
vector<vector<char> > fig(n, vector<char>(n));
int hashtags=0;
for(int j=0; j<n; j++){
	for(int i=0; i<n; i++){
		cin>>fig[j][i];
		if(fig[j][i]=='#') hashtags++;
	}	
}


vector<vector<vector<char> > > pieces(k,vector<vector<char> >(n,vector<char>(n)));
vector<pair<pi,pi> > shift(k); //(right,left),(down,up)
for(int x=0; x<k; x++){
int r=0,l=n-1,d=0,u=n-1;
	for(int j=0; j<n; j++){
		for(int i=0; i<n; i++){
			cin>>pieces[x][j][i];
			if(pieces[x][j][i]=='#'){
			r=max(r,i);
			l=min(l,i);
			d=max(d,j);
			u=min(u,j);
			}
		}
	}
	shift[x]=mp(mp(n-1-r,l-0),mp(n-1-d,u-0));
}


vector<vector<set<pi> > >comp(k); //(x,{(j,i),...})
for(int x=0; x<k; x++){	
	int r,l,d,u;
	r=shift[x].f.f;
	l=shift[x].f.s;
	d=shift[x].s.f;
	u=shift[x].s.s;
	for(int hor=-1*l; hor<=r; hor++){
		for(int ver=-1*u; ver<=d; ver++){
			bool good=true;
			set<pi> temp; //{(j,i),....}
			
			for(int j=0; j<n && good; j++){
				for(int i=0; i<n; i++){
					if(pieces[x][j][i]=='#' && fig[j+ver][i+hor]=='#') temp.insert(mp(j+ver,i+hor));
					else if(pieces[x][j][i]=='#' && fig[j+ver][i+hor]=='.') {
						good=false;
						break;
					}
				}
			}
			
			if(good) comp[x].pb(temp);
		}
	}
			
}

for(int j=0; j<k-1; j++){
	for(int i=j+1; i<k; i++){
		for(auto set_j:comp[j]){
			for(auto set_i:comp[i]){
				if(set_j.size()+set_i.size()==hashtags){
					bool good=true;
					for(auto element_j:set_j){
						if(set_i.count(element_j)==1){
							good=false;
							break;
						}
					}
					
					if(good){
						cout<<j+1<<" "<<i+1<<endl;
						return 0;	
					}
				}
			}
		}
	}
}

return 0;
}
