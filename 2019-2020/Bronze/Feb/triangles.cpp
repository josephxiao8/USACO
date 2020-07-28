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

ofstream cout ("triangles.out");
ifstream cin ("triangles.in");

int n;
cin>>n;
vpi fence(n);
for(int i=0; i<n; i++){
	int a,b;
	cin>>a>>b;
	fence[i]=(mp(a,b));
}

int maxx=0;
for(int k=0; k<n; k++){
	for(int j=0; j<n; j++){
		for(int i=0; i<n; i++){
			int a,b,c,d,e,f;
			tie(a,b)=fence[k];
			tie(c,d)=fence[j];
			tie(e,f)=fence[i];
			if((a==c && b==d) || (a==e && b==f) || (c==e && d==f)) continue;
			
			if(a==c && b==f) maxx=max(maxx,abs((a-e)*(b-d)));
			else if(a==e && b==d) maxx=max(maxx,abs((a-c)*(b-f)));
		}
	}
}

cout<<maxx<<endl;
return 0;	
}
