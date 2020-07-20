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

ofstream cout ("hoofball.out");
ifstream cin ("hoofball.in");

int n;
cin>>n;
if(n==1){
	cout<<1<<endl;
	return 0;
}

vi v(n);
for(int i=0; i<n; i++)cin>>v[i];
sort(v.begin(), v.end());

vi dir(n); // 1 is right, 0 is left
vi split;
split.pb(0);
for(int i=0; i<n; i++){
	if(i==0) dir[i]=1;
	else if(i==n-1) dir[i]=0;
	else{
		if(v[i]-v[i-1]<=v[i+1]-v[i]) dir[i]=0;
		else dir[i]=1;
	}
	if(i>0 && dir[i]==1 && dir[i-1]==0){
		split.pb(i);
	}
}
split.pb(n);

int counter=0;
for(int i=0; i<split.size()-1; i++) {
	int l=0, r=0;
	for(int j=split[i]; j<split[i+1]; j++){
		if(dir[j]==1) r++;
		else l++;
	}
	if(l>=2 && r>=2) counter+=2;
	else counter++;
}

cout<<counter<<endl;
return 0;
}
