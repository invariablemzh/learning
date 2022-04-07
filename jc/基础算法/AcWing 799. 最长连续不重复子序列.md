```c++
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 1e5+10;
int q[N];
int s[N];

int main(){
	int n; scanf("%d",&n);
	for(int i = 1;i<=n;i++) scanf("%d",&q[i]);
	int res = 0;
	for(int i = 1, j = 1;i<=n;i++){
		s[q[i]]++;
		while(s[q[i]]>1){
			s[q[j++]]--;
		}
		res = max(res,i-j+1);
	}
	printf("%d\n",res);
	return 0;
}
```
