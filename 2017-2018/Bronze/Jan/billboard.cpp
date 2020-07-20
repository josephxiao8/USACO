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

ofstream cout ("billboard.out");
ifstream cin ("billboard.in");

int ax1,ay1, ax2, ay2;
cin>>ax1>>ay1>>ax2>>ay2;
int bx1, by1, bx2, by2;
cin>>bx1>>by1>>bx2>>by2;

int minn=(ax2-ax1)*(ay2-ay1);
int subtract;
if((bx2<=ax1 && ax2<=bx1) && (by2<=ay1 && ay2<=by1)) subtract=0;
else if((bx1<=ax1 && ax2<=bx2) || (by1<=ay1 && ay2<=by2)){
	if (((bx1<=ax1 && ax2<=bx2) && (by1<=ay1 || ay2<=by2)) || ((bx1<=ax1 || ax2<=bx2) && (by1<=ay1 && ay2<=by2))){
		int tempx,tempy;
		tempx=min(ax2,bx2)-max(ax1,bx1);
		tempy=min(ay2,by2)-max(ay1,by1);
		subtract=tempx*tempy;
	}
	else subtract=0;
}
else subtract=0;

cout<<minn-subtract<<endl;
return 0;	
}
