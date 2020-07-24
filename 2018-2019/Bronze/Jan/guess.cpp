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
 
typedef priority_queue<pair<int,string>> pq;
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

ofstream cout ("guess.out");
ifstream cin ("guess.in");

int n;
cin>>n;

vector<set<string> > sett(n);
for(int i=0; i<n; i++){
	string animal;
	int k;
	cin>>animal>>k;
	for(int j=0; j<k; j++){
		string trait;
		cin>>trait;
		sett[i].insert(trait);
	}
}

int ans=0;
for(int j=0; j<n; j++){
	int maxx=0;
	for(int i=0; i<n; i++){
		int counter=0;
		if(i==j) continue;
		for(auto x:sett[j]){
			if(sett[i].count(x)) counter++;
		}
		maxx=max(maxx,counter);
	}
	ans=max(ans,maxx);
}

cout<<ans+1;
return 0;
}
