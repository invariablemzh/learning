```c++
#include <iostream>
using namespace std;
const int N = 1e6+10;
int a[N],q[N];
int main(){
	int n,k; scanf("%d%d",&n,&k);
	for(int i = 1;i<=n;i++) scanf("%d",&a[i]);
	int hh = 0, tt = -1;
	for(int i = 1;i<=n;i++){
		while(hh<=tt&&i-k+1>q[hh]) hh++;
		while(hh<=tt&&a[q[tt]]>=a[i]) tt--;
		q[++tt] = i;
		if(i>=k) printf("%d ",a[q[hh]]);
	}
	puts("");
	hh = 0, tt = -1;
	for(int i = 1;i<=n;i++){
		while(hh<=tt&&i-k+1>q[hh]) hh++;
		while(hh<=tt&&a[q[tt]]<=a[i]) tt--;
		q[++tt] = i;
		if(i>=k) printf("%d ",a[q[hh]]);
	}
	return 0;
}
```
