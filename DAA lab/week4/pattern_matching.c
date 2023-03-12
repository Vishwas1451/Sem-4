#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 20

int main(){
	
char text[MAX],pat[MAX];
int i,j,n,m;
printf("\nEnter the text:");
gets(text);
printf("\nEnter the pattern:");
gets(pat);
n=strlen(text);
m=strlen(pat);
for(i=0; i<=n-m; i++){
	j=0;
	while(j<m && (pat[j]==text[i+j]))
		j++;
	if(j==m){
		printf("The pat found at pos %d",i);
			//break;
	}
	
	
}
return 0;	
	
}