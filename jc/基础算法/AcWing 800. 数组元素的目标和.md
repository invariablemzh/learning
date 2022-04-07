```c++
#include <iostream>
using namespace std;
const int N = 1e5+10;
int a[N],b[N];
int main(){
	int n,m,x; 
	scanf("%d%d%d",&n,&m,&x);
	for(int i = 1;i<=n;i++) scanf("%d",&a[i]);
	for(int i = 1;i<=m;i++) scanf("%d",&b[i]);
	int i,j;
	for(i = 1,j = m;i<=n;i++){
		while(j&&a[i]+b[j]>x) j--;
		if(a[i]+b[j]==x) break;
	}
	printf("%d %d\n",i-1,j-1);
	return 0;
}
```
