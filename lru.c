#include<stdio.h>
int frame[10],page[20],pagehit=0,pagefault,lv[10],level=0;

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
			{
				lv[i]=level;
				frame[i]=page[i];
				level++;
			}	
		else
		{
			for(j=0;j<m;j++)
			{
				if(frame[j]==page[i])
				{
					temp=1;
					pagehit++;
					lv[j]=level-1;
					for(k=0;k<m;k++)
					{
						if(k!=j)
							lv[k]--;
					}
					break;
				}

			}
			if(temp==0)
			{
				for(j=0;j<m;j++)
				{
					if(lv[j]==0)
					{
						frame[j]=page[i];
						lv[j]=level-1;
					}
					else
						lv[j]--;
				}
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