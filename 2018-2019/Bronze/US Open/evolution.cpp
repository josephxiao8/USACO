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


int n;
vector<set<string> > v(n);

bool comp(string a, string b){
	
	int countera=0, counterb=0, counterab=0;
	
	for(int i=0; i<n; i++){
		bool founda=false, foundb=false;
		
		if(v[i].count(a)) founda=true;
		if(v[i].count(b)) foundb=true;
	
		if(founda && foundb) counterab++;
		else if(founda) countera++;
		else if(foundb) counterb++;
	}
	return(countera>0 && counterb>0 && counterab>0);
}


int main() {
ios::sync_with_stdio(0);
cin.tie(0);

ofstream cout ("evolution.out");
ifstream cin ("evolution.in");

cin>>n;
v=vector<set<string> >(n);
vector<string> traits;
for(int j=0; j<n; j++){
	int k;
	cin>>k;
	for(int i=0; i<k; i++){
		string s;
		cin>>s;
		v[j].insert(s);
		bool found=false;
		for(auto x:traits) {
			if(x==s) {
				found=true;
				break;
			}
		}
		if(!found) traits.pb(s);
	}
}

for(int j=0; j<traits.size()-1; j++){
	for(int i=j+1; i<traits.size(); i++){
		if(comp(traits[j],traits[i])) {
			cout<<"no"<<endl;
			return 0;
		}
	}
}

cout<<"yes"<<endl;
return 0;
}
