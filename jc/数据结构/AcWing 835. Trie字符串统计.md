```c++
#include <iostream>
using namespace std;
const int N = 1e5+10;
int son[N][26],idx,cnt[N];
char s[N];
char op[2];

void insert(char str[]){
	int p = 0;
	for(int i = 0;str[i];i++){
		int u = str[i] - 'a';
		if(!son[p][u]) son[p][u] = ++idx;
		p = son[p][u];
	}
	cnt[p]++;
}

int query(char str[]){
	int p = 0;
	for(int i = 0;str[i];i++){
		int u = str[i] - 'a';
		if(!son[p][u]) return 0;
		p = son[p][u];
	}
	return cnt[p];
}

int main(){
	int n; scanf("%d",&n);
	while(n--){
		scanf("%s",op);
		scanf("%s",s);
		if(*op=='I') insert(s);
		else printf("%d\n",query(s));
	}
	return 0;
}
```
