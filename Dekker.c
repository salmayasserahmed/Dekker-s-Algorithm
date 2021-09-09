#include <stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include <unistd.h>
#define SIZE 20

int flag[2] = {0,0};
int turn;
int array[SIZE - 1];

void swapf(int i, int k)
{
    int temp;
    temp = array[i];
    array[i] = array[k];
    array[k] = temp;

}
void *Sort_A(void *args)
{
    int i, j;
      flag[0]=1;
    while(flag[1])
    {
        if(turn!=0)
        {
            flag[0]=0;
            while(turn!=0)
            {
  
            }
            flag[0]=1;
        }
    }

    for(i = 1; i < SIZE; i++)
    {
        for( j = 0; j < SIZE - 1; j++)
        {
            if(array[j] > array[j+1])
                swapf(j, j+1);
        }
    }
    
    printf("Ascending Order\n");
    for(i=0;i<SIZE;i++)
    {
        printf("%d \n",array[i]);
    }
    turn=1;
    flag[0]=0;
}
void *Sort_D(void *args)
{
    int i, j;
  flag[1]=1;
    while(flag[0])
    {
        if (turn!=1)
        {
            flag[1]=0;
            while(turn!=1)
            {

            }
            flag[1]=1;
        }
    }
    for(i = 1; i < SIZE; i++)
    {
        for( j = 0; j < SIZE - 1; j++)
        {
            if(array[j] < array[j+1])
                swapf(j, j+1);
        }
    }
    
    printf("\nDescending Order\n");
    for(i=0;i<SIZE;i++)
    {
        printf("%d \n",array[i]);
    }
   turn=0;
    flag[1]=0;
}


void init()
{
    int i;
    for( i = 0; i < SIZE; i++)
    {
        array[i] = rand()%20;
    }
}

int main()
{

    init();
    pthread_t t1, t2;
    pthread_create(&t1, NULL, Sort_A, NULL);
    sleep(3);
    pthread_create(&t2, NULL, Sort_D, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}
