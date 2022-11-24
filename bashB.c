#include<stdio.h>
#include<unistd.h>
#include <sys/wait.h>
#include<stdlib.h>
#include <strings.h>
#include <limits.h>
#include<pthread.h>

int main(int argc , char* argv[]){
	int niceB;
	FILE *fptr;
   	fptr = fopen("niceValueB.txt","r"); 
   	fscanf(fptr,"%d", &niceB);
   	fclose(fptr); 
	struct timespec start, end;
	clock_gettime(CLOCK_REALTIME,&start);
	struct sched_param param;
   	int pid_num = 0;
   	pid_t x = fork();
   	if(x==0){
   		int priority =niceB; 
   		param.sched_priority = priority;
   		sched_setscheduler(pid_num, SCHED_RR, &param); 
   		printf("priority value for SCHED_RR: %d\n",priority);
		for(long int i = 0 ; i<4294967296 ; i++){
			continue;
		}
	}
	else{
		wait(NULL); 
		
		clock_gettime(CLOCK_REALTIME,&end);
    	double timeA = (end.tv_sec - start.tv_sec)+(end.tv_nsec - start.tv_nsec)*0.000000001;
		printf("time RR: %f\n",timeA);
		for(int i = 0 ; i<(int)timeA*10 ; i++){
			printf("|"); 
		}
		printf("\n");

	}
	return 0;
}