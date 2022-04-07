```c++
#include <iostream>
using namespace std;
const int N = 100010;
int n,m;
int q[N];

int main(){
	scanf("%d%d",&n,&m);
	for(int i = 1;i<=n;i++) scanf("%d",&q[i]);
	while(m--){
		int t; scanf("%d",&t);
		int l = 1,r = n;
		while(l<r){
			int mid = l+r>>1;
			if(q[mid]>=t) r = mid;
			else l = mid+1;
		}
		if(q[l]!=t) printf("-1 -1\n");
		else {
			printf("%d ",l-1);
			l = 1,r = n;
			while(l<r){
				int mid = l+r+1>>1;
				if(q[mid]>t) r = mid-1;
				else l = mid;
			}
			printf("%d\n",l-1);
		}
		
	}
	return 0;
}
```
