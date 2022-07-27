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
   int temp,i,j,num;
   printf("Enter number of elemens :");
   scanf("%d",&num);	 
   arr = (long *)malloc(sizeof(long)*num);
   srand( (unsigned) time(NULL) * getpid());
   if(arr != NULL)
    {
        for(i= 0;i< num;i++)
            arr[i] = rand()%100;
    }
    gettimeofday(&t0, NULL);
	for(i= 0;i< num - 1; i++)
    {       
        for(j=0;j<num-i-1;j++)
        {          
            if(arr[j]>arr[j+1])
            {               
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
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
