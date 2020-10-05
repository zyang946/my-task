#include<stdio.h>
#include<stdlib.h>
int main(){
    FILE *fp;
    fp=fopen("1.txt","r");
    char str[100000];
    while(fgets(str,100000,fp)!=  NULL)
        printf("%s\n",str);
}
