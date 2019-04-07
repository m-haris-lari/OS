#include<stdio.h>
int mem[10],pro[10];
int memoryall(int,int);

int main()
{	
	int m,n,i;
	printf("Enter no. of memory blocks:");
	scanf("%d",&m);

	for(i=0;i<m;i++)
	{
		printf("Enter size of block %d:",i+1);
		scanf("%d",&mem[i]);
	}
	printf("\nEnter no. of process:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter size of process %d:",i+1);
		scanf("%d",&pro[i]);
	}
	memoryall(m,n);
	return 0;
}

int memoryall(int m, int n)
{
	int i,j,temp1,temp2,temp3,proc[n],memo[m],p[m],me[m],sum=0,sum2=0;
	for(i=0;i<n;i++)
	{
		proc[i]=0;
	}
	for(i=0;i<m;i++)
	{
		memo[i]=0;
	}
	for(i=0;i<m;i++)
	{
		p[i]=0;
	}
	for(i=0;i<n;i++)
	{	temp3=-1;
		temp2=0;
		for(j=0;j<m;j++)
		{
			if(pro[i]<=mem[j] && memo[j]==0)
			{
				temp1=mem[j]-pro[i];
				proc[i]=-1;
			}
			else
				continue;
			if(temp1>temp2)
			{
				temp2=temp1;
				temp3=j;
			}
		}
			memo[temp3]=-1;
			p[temp3]=i+1;
			me[temp3]=temp2;
	}
	for(i=0;i<m;i++)
	{
		if(memo[i]==0)
			me[i]=mem[i];
	}
	printf("\nWorst Fit Method\n");
	for(i=0;i<m;i++)
	{
		printf("|%d\t|",mem[i]);
	}
	printf("\n");
	for(i=0;i<m;i++)
	{
		if(p[i]==0)
			printf("|-\t|");
		else
		printf("|P%d\t|",p[i]);
	}
	printf("\n");
	for(i=0;i<m;i++)
	{
		printf("|%d\t|",me[i]);
	}
	for(i=0;i<m;i++)
	{	if(p[i]==0)
		sum+=mem[i];
		else
			sum2+=me[i];
	}
	printf("\nTotal unallocated memory=%d",sum);
	printf("\nTotal internal infregmentation=%d",sum2);
	return 0;
}
