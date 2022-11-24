#include<stdio.h>
#include<unistd.h>
#include <sys/wait.h>
#include<stdlib.h>
#include <strings.h>
#include <limits.h>
#include<pthread.h>
#include<sys/wait.h>

double timeA ; 
double timeB ; 
double timeC ; 
pid_t x;
pid_t y;
pid_t z;
int flagA = 0; 
int flagB = 0;
int flagC = 0;
int main(){

		int in; 
		int status;
		printf("Enter priority value for SCHED_OTHER:\n");
		int niceA ; scanf("%d" , &niceA); 
		FILE *ptrA = fopen("fileopen","mode");
		ptrA = fopen("niceValueA.txt","w");
		fprintf(ptrA, "%d", niceA);
		fclose(ptrA); 
		


		printf("Enter priority value for SCHED_RR\n");
		int niceB ; scanf("%d" , &niceB); 
		FILE *ptrB = fopen("fileopen","mode");
		ptrB = fopen("niceValueB.txt","w");
		fprintf(ptrB, "%d", niceB);
		fclose(ptrB); 
		


		printf("Enter priority value for SCHED_FIFO\n");
		int niceC ; scanf("%d" , &niceC); 
		FILE *ptrC = fopen("fileopen","mode");
		ptrC = fopen("niceValueC.txt","w");
		fprintf(ptrC, "%d", niceC);
		fclose(ptrC); 
		


		double startTime = clock(); 
		x = fork();
		if(x == 0){
			char *args[] = {NULL , NULL , NULL , NULL}; 
			execv("./bashA", args);
		}
		else{
			y = fork();
			if(y == 0){
				char *args[] = {NULL , NULL , NULL , NULL}; 
				execv("./bashB", args);
			}
			else{
				z = fork();
				if(z==0){
					char *args[] = {NULL , NULL , NULL , NULL}; 
					execv("./bashC", args);
				}
				else{
					while(((x = waitpid(x, &status, WNOHANG))!=-1 || (y = waitpid(y, &status, WNOHANG))!=-1) || ((z = waitpid(z, &status, WNOHANG))!=-1)){
						wait(NULL); 
					}					
				}
			}
		}
	printf("parent reached :)\n" );
	return 0;
}










