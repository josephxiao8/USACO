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

ofstream cout ("taming.out");
ifstream cin ("taming.in");

int n;
cin>>n;

vi v(n);
for(int i=0; i<n; i++){
	cin>>v[i];
}
v[0]=0;

for(int i=n-1; i>=0; i--){
	if(v[i]!=-1){
		int temp=v[i];
		int pos=i;
		while(temp>=1){
			temp--;
			pos--;
			if(pos<0 || (v[pos]!=temp && v[pos]!=-1) ){
				cout<<-1<<endl;
				return 0;
			}
			else v[pos]=temp;
		}
	}
}

int m=0, M=0;
for(int i=0; i<n; i++){
	if(v[i]==0) m++;
	if(v[i]==-1) M++;
}

cout<<m<<" "<<m+M<<endl;
return 0;
}
