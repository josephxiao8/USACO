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

ofstream cout ("photo.out");
ifstream cin ("photo.in");

int n;
cin>>n;

vi b(n-1);
for(int i=0; i<n-1; i++) cin>>b[i];

for(int i=1; i<b[0]; i++){
	set<int> sett;
	vi ans;
	int temp=i;
	sett.insert(i);
	ans.pb(i);
	bool good=true;
	
	for(int j=0; j<n-1; j++){
		if(temp<=0 || sett.count(b[j]-temp)) {
			good=false;
			break;
		}
		else{
			sett.insert(b[j]-temp);
			ans.pb(b[j]-temp);
			temp=b[j]-temp;
		}
	}
	
	if(good){
		for(int i=0; i<ans.size()-1; i++) cout<<ans[i]<<" ";
		cout<<ans[ans.size()-1]<<endl;
		return 0;
	}
}

}
