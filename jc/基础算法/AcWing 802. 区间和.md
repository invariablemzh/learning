```c++
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int N = 3e5+10;

vector<PII> add,query;
vector<int> alls;

int s[N];

int find(int x){
	int l = 0, r = alls.size()-1;
	while(l<r){
		int mid = l+r>>1;
		if(alls[mid]>=x) r = mid;
		else l = mid+1;
	}
	return l + 1;
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i = 1;i<=n;i++){
		int x,c;
		scanf("%d%d",&x,&c);
		add.push_back({x,c});
		alls.push_back(x);
	}
	for(int i = 1;i<=m;i++){
		int l,r;
		scanf("%d%d",&l,&r);
		alls.push_back(l);
		alls.push_back(r);
		query.push_back({l,r});
	}
	sort(alls.begin(),alls.end());
	alls.erase(unique(alls.begin(),alls.end()),alls.end());
	for(int i = 0;i<add.size();i++){
		int t = find(add[i].first);
		s[t] += add[i].second;
	}
	for(int i = 1;i<=alls.size();i++){
		s[i] += s[i-1];
	}
	for(int i = 0;i<m;i++){
		int l = find(query[i].first);
		int r = find(query[i].second);
		printf("%d\n",s[r]-s[l-1]);
	}
	return 0;
}	
```
