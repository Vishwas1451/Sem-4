#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(int argc, char* argv[]) {
    int fd[2],n=8;
    if (pipe(fd) == -1) {
        return 1;
    }
    
    int pid = fork();
    if (pid == -1) {
        return 2;
    }
    
    if (pid == 0) {
        // Child  process
        close(fd[0]);
        
       
        int arr[8] = {9,4,34,1,8,3,7,2};
		printf("The elements are : ");
		for(int i=0;i<8;i++)
			printf("%d ",arr[i]);
        
        printf("\n");
        
		//
        if (write(fd[1], &n, sizeof(int)) < 0) {
            return 3;
        }
        printf("Sent n = %d\n", n);
        
        if (write(fd[1], &arr, sizeof(int) * n) < 0) {
            return 4;
        }
        
        //printf("Sent array\n");
        close(fd[1]);
    } else {
        close(fd[1]);
        int arr[10];
        int n, i, sum = 0,sum1=0;
        
        if (read(fd[0], &n, sizeof(int)) < 0) {
            return 5;
        }
        printf("Received n = %d\n", n);
        if (read(fd[0], &arr, sizeof(int) * n) < 0) {
            return 6;
        }
        //printf("Received array\n");
        
        close(fd[0]);
        for (i = 0; i < n/2; i++) {
            sum += arr[i];
        }
        for (i = n/2; i < n; i++) {
            sum1 += arr[i];
        }
        printf("Result is %d,%d\n", sum,sum1);
        wait(NULL);
    }
    
    return 0;
}
