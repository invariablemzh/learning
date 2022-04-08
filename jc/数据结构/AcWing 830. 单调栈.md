```c++
#include <iostream>
using namespace std;

const int N = 1e5+10;
int stk[N],tt;

int main(){
	int n; scanf("%d",&n);
	while(n--){
		int x; scanf("%d",&x);
		while(tt&&stk[tt]>=x) tt--;
		if(tt) printf("%d ",stk[tt]);
		else printf("-1 ");
		stk[++tt] = x;
	}
	return 0;
}
```
