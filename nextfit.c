#include<stdio.h>

int mem[15],pro[15],m,n;
void nextfit();

int main()
{
	int i,j;
	printf("\nEnter no. of blocks of memory=");
	scanf("%d",&m);
	printf("Enter no. of process=");
	scanf("%d",&n);
	printf("\nEnter size of memory blocks-\n");
	for(i=0;i<m;i++)
	{
		printf("Size of block %d=",i+1);
		scanf("%d",&mem[i]);
	}
	printf("\nEnter size of process-\n");
	for(i=0;i<n;i++)
	{
		printf("Size of block %d=",i+1);
		scanf("%d",&pro[i]);
	}
	nextfit();
	return 0;
}
void nextfit()
{
	int i,j,rem[15],pn[15],flag[15],ext=0,inter=0;
	for(i=0;i<m;i++)
	{
		flag[i]=1;
	}
	for(i=0;i<m;i++)
	{
		pn[i]=0;
	}
	i=0;

	for(j=0;j<n;j++)
	{
		for(;i<m;i++)
		{
			if(pro[j]<=mem[i]&&flag[i]==1)
			{
				rem[i]=mem[i]-pro[j];
				flag[i]=0;
				pn[i]=j+1;
				break;
			}
		}
		if(i==m-1)
		{
			i=0;
		}
	}
	for(i=0;i<m;i++)
	{
		if(flag[i]==1)
		{
			rem[i]=mem[i];
			ext+=rem[i];
		}
		else
		{
			inter+=rem[i];
		}
	}
	printf("\nNext Fit\n");
	for(i=0;i<m;i++)
	{
		printf("|%d\t|",mem[i]);
	}
	printf("\n");
	for(i=0;i<m;i++)
	{
		if(flag[i]==1)
		{
			printf("|-\t|");
		}
		else
		printf("|P%d\t|",pn[i]);
	}
	printf("\n");
	for(i=0;i<m;i++)
	{
		printf("|%d\t|",rem[i]);
	}
	printf("\nInternal Fragmentation=%d",inter);
	printf("\nExternal fragmentation=%d",ext);
}