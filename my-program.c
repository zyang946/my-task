#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int f[6] = {2,4,0,6,6,0};
int g[6] = {1,3,5,0,5,0};
int getf(char op){
	switch(op){
		case '+':
			return f[0];
		case '*' :
			return f[1];
		case '(':
			return f[2];
		case ')':
			return f[3];
		case 'i':
			return f[4];
		case '\r':
			return f[5];
	}
}
int getg(char op){
	switch(op){
		case '+':
			return g[0];
		case '*' :
			return g[1];
		case '(':
			return g[2];
		case ')':
			return g[3];
		case 'i':
			return g[4];
		case '\r':
			return g[5];
	}
}
int top=0;
char stack[1010];
void push(char op){
	stack[top++] = op;
}
char pop(){
	return stack[--top];
}
int getstackpriority(){
	int now = top-1;
	while(stack[now] == 'F')
		now--;
	return getf(stack[now]);
}
int main(int argc ,char** argv){
	FILE *fp = NULL;
	fp = fopen(argv[1],"r");
	char str[1010];
	str = fgets(str,1000,fp);
	push('\r');
	int i=0;
	bool flag = true;
	while(str[i]!='\n'){
		while(getfstackpriority()>getg(str[i])){
			char op = pop();
			if(op1 == '+'|| op1 == '*' || op1 == '('){
				break;
				flag = false;
			}
			else if(op == '#'){
				push('#');
				break;
			}
			else if(op == 'F'){
				
			}
			else if(op == 'i'){
				
			}
			else if(op == ')'){
				
			}
			
		}
		if(flag == false)
			break;
		push(str[i]);
		printf("I%c\n",str[i]);
		i++;
	}
} 
