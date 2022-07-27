#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float timedifference_msec(struct timeval t0, struct timeval t1)
{
    return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}

int main(void)
{
	struct timeval t0;
   	struct timeval t1;
   	float elapsed;
   	long *arr;
   	int i,j,temp,pos,num;
   	printf("Enter number of elements :");
   	scanf("%d",&num);
   	arr=(long *)malloc(sizeof(long)*num);
   	srand((unsigned)time(NULL)*getpid());
   	if(arr!=NULL)
    {
        for(j = 0;j<num; j++)
            arr[j] = rand()%100;
    }
    gettimeofday(&t0, NULL);
	for(i = 0; i < num - 1; i++)
    {
        pos=i;
        for(j=i+1;j<num;j++)
        {
            if(arr[pos]>arr[j])
                pos=j;
        }
        if(pos!=i)
        {
            temp=arr[i];
            arr[i]=arr[pos];
            arr[pos]=temp;
        }
    }
    gettimeofday(&t1, NULL);
    printf("The sorted array is :\n");
    for(i=0;i<num;i++)
    	printf("%ld\t",arr[i]);
	elapsed = timedifference_msec(t0, t1);
	printf("\nCode executed in %f milliseconds.\n", elapsed);
	return 0;
}
