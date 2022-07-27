#include<stdio.h>
#include<stdlib.h>
#include<time.h>
float timedifference_msec(struct timeval t0, struct timeval t1)
{
    return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}

int main()
{
	struct timeval t0;
	struct timeval t1;
	int i, d, t, flag = 0,j,num;
	long *arr;
	float elapsed;
	printf("Enter number of elements in array :");
	scanf("%d",&num);
	arr = (long *)malloc(sizeof(long)*num);
	srand( (unsigned) time(NULL) * getpid());
	if(arr!= NULL)
	{
		for(j = 0;j<num; j++)
		    	arr[j]=rand()%100;
	}
	gettimeofday(&t0, NULL);
	for (i=1;i<=num-1; i++) 
	{
		t = arr[i];
		for (d=i-1;d>=0;d--) 
		{
		  	if (arr[d] > t) 
		  	{
		    	arr[d+1] = arr[d];
		    	flag = 1;
		  	}
		  		else
		    		break;
		}
	 if (flag)
		  arr[d+1] = t;
	  }
	  gettimeofday(&t1, NULL);
	  printf("Sorted list in ascending order:\n");
	  for(i=0; i<num; i++) 
			printf("%ld\t",arr[i]);
		printf("\n");
	   elapsed = timedifference_msec(t0, t1);
	   printf("Code executed in %f milliseconds.\n", elapsed);

	  return 0;
}
