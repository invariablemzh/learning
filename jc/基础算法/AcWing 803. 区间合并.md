```c++
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int,int> PII;

int n;
vector<PII> segs;


void merge(){
	vector<PII> res;
	sort(segs.begin(),segs.end());
	int st = -2e9, ed = -2e9;
	for(int i = 0;i<segs.size();i++){
		int l = segs[i].first;
		int r = segs[i].second;
		if(l<=ed) ed = max(ed,r);
		else{
			if(st!=-2e9) res.push_back({st,ed});
			st = l, ed = r;
		}
	}
	if(st!=-2e9) res.push_back({st,ed});
	segs = res;
}


int main(){
	scanf("%d",&n);
	for(int i = 1;i<=n;i++){
		int l,r;
		scanf("%d%d",&l,&r);
		segs.push_back({l,r});
	}
	merge();
	printf("%d",segs.size());
	return 0;
}
```
