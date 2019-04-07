#include<stdio.h>
int frame[10],page[20],pagehit=0,pagefault,lv=0;

int main()
{
	int m,n,i,j,k,temp;
	printf("\nEnter no. of frames:");
	scanf("%d",&m);
	printf("\nEnter no. of inputs:");
	scanf("%d",&n);
	printf("\nEnter inputs:");
	for(i=0;i<n;i++)
		scanf("%d",&page[i]);
	printf("\nFrames\t");
	for(i=0;i<m;i++)
	{
		printf("%d\t",i);
	}

	for(i=0;i<n;i++)
	{
		temp=0;
		if(i<m)
			frame[i]=page[i];
		else
		{
			for(j=0;j<m;j++)
			{
				if(frame[j]==page[i])
				{
					temp=1;
					pagehit++;
					break;
				}
			}
			if(temp==0)
			{
				frame[lv]=page[i];
				lv++;
				if(lv==m)
					lv=0;
			}
		}
		printf("\n%d\t",page[i]);
		for(k=0;k<m;k++)
		{
			if(k>i&&i<m)
				printf("-\t");
			else
				printf("%d\t",frame[k]);
		}
	}
	
	printf("\nPage Hit=%d\tPage Fault=%d",pagehit,n-pagehit);

	return 0;
}