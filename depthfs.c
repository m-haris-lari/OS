#include <stdio.h>
#include <stdlib.h>
int matrix[20][20];
int check[101],stk[50];
int a[101];
int front=0,rear=0;
int top=0;
void insert(int v) {
	stk[top]=v;
	++top;
}
int pop() {
	--top;
	return stk[top];
}

void DFS() {
	printf("DFS : ");
	int i,v;
	while (top != 0) {
		v = pop();
		printf("%d ", v);
		for (i = 0; i < 101; ++i) {
			if (matrix[v][i]==1 && check[i]==1) {
				check[i]=2;
				insert(i);
			}
		}
	}
	printf("\n");
}


int main()
{
	int n,i,x,y;
	printf("Enter no of edges in graph:");
	scanf("%d",&n);
	printf("Enter pair of vertices:\n");
	for (i=0;i<n;++i) {
		scanf("%d %d", &x, &y);
		matrix[x][y]=1;
		matrix[y][x]=1;
		check[x]=check[y]=1;
	}
	for (i=0;i<101;++i) {
		if (check[i]==1) {
			check[i]=2;
			insert(i);
			DFS();
		}
	}
	return 0;
}