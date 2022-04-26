```c++
#include <iostream>
using namespace std;
const int N = 1e5+10;
int p[N];

int find(int x){
	if(p[x]!=x) p[x] = find(p[x]);
	return p[x];
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i = 1;i<=n;i++) p[i] = i;
	while(m--){
		char op[2];
		scanf("%s",op);
		int x,y;
		scanf("%d%d",&x,&y);
		if(*op=='M'){
			p[find(x)] = find(y);
		}
		else{
			if(find(x)==find(y)) puts("Yes");
			else puts("No");
		}
	}
	return 0;
}
```
