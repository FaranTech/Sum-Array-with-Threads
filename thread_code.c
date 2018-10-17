#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int data_set[1000];
int chunk_size=100;

void *Add(void *args1,void *args2)
{
	int start=(int)args1;
	int end=(int)args2;
	int sum=0;
	for(int i=start;i<end;i++)
	{	data_set[i]=1;
		sum=sum+data_set[i];
	}
	return((void*)sum);
}
int main()
{
	pthread_t t1,t2,t3,t4,t5,t6,t7,t8,t9,t10;
	int sum_t1,sum_t2,sum_t3,sum_t4,sum_t5,sum_t6,sum_t7,sum_t8,sum_t9,sum_t10;
	
	pthread_create(&t1,NULL,Add,(void*)(0*chunk_size),(void*)(1*chunk_size));
	pthread_join(&t1,(void**)&sum_t1);
	
	pthread_create(&t2,NULL,Add,(void*)(1*chunk_size),(void*)(2*chunk_size));
	pthread_join(&t2,(void**)&sum_t2);
	
	pthread_create(&t3,NULL,Add,(void*)(2*chunk_size),(void*)(3*chunk_size));
	pthread_join(&t3,(void**)&sum_t3);	
	
	pthread_create(&t4,NULL,Add,(void*)(3*chunk_size),(void*)(4*chunk_size));
	pthread_join(&t4,(void**)&sum_t4);
	
	pthread_create(&t5,NULL,Add,(void*)(4*chunk_size),(void*)(5*chunk_size));
	pthread_join(&t5,(void**)&sum_t5);
	
	pthread_create(&t6,NULL,Add,(void*)(5*chunk_size),(void*)(6*chunk_size));
	pthread_join(&t6,(void**)&sum_t6);
	
	pthread_create(&t7,NULL,Add,(void*)(6*chunk_size),(void*)(7*chunk_size));
	pthread_join(&t7,(void**)&sum_t7);
	
	pthread_create(&t8,NULL,Add,(void*)(7*chunk_size),(void*)(8*chunk_size));
	pthread_join(&t8,(void**)&sum_t8);
	
	pthread_create(&t9,NULL,Add,(void*)(8*chunk_size),(void*)(9*chunk_size));
	pthread_join(&t9,(void**)&sum_t9);
	
	pthread_create(&t10,NULL,Add,(void*)(9*chunk_size),(void*)(10*chunk_size));
	pthread_join(&t10,(void**)&sum_t10);

int Final_sum=0;
Final_sum=sum_t1+sum_t2+sum_t3+sum_t4+sum_t5+sum_t6+sum_t7+sum_t8+sum_t9+sum_t10;
printf("Final SUM %d\n",Final_sum);
return 0;
}
