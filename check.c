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
		case '#':
			return f[5];
		default: 
			return -1;
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
		case '#':
			return g[5];
		default:
			return -1;
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
int cmpPriority(char op){
	int now = top-1;
	while(stack[now] == 'F')
		now--;
	int instack = getf(stack[now]);
	int outstack = getg(op);
	// printf("%d %d %d\n",now,instack,outstack);
	if(instack==-1 || outstack == -1)
		return -1;
	else if(stack[now]=='i'&&(op=='('||op=='i'))
		return -1;
	else if(stack[now]=='('&&op=='#')
		return -1;
	else if(stack[now]==')'&&(op=='('||op=='i'))
		return -1;
	else if(stack[now]=='#'&&(op==')'||op=='#'))
		return -1;
	else{
		if(instack<=outstack)
			return 0;
		else
			return 1;
	}
}
int main(int argc ,char** argv){
	FILE *fp = NULL;
	fp = fopen("1.txt","r");
	char str[1010];
	fgets(str,1000,fp);
	push('#');
	int i=0;
	int flag = 1;
	while(str[i]!='\n'){
		while(cmpPriority(str[i]) == 1){
			char op = pop();
			if(op == '+'|| op == '*' || op == '('){
				break;
				flag = 0;
			}
			else if(op == 'F'){
				if(top<3){
					flag = 0;
					break;
				}
				char op1 = pop();
				char op2 = pop();
				if((op1 == '+'||op1=='*')&&op2 == 'F'){
					push('F');
					printf("R\n");				
				}
				else{
					flag = 0;
					break;
				}
				
			}
			else if(op == 'i'){
					push('F');
					printf("R\n");					
			}
			else if(op == ')'){
				if(top<3){
					flag = 0;
					break;
				}
				char op1 = pop();
				char op2 = pop();
				if(op1 == 'F'&&op2=='('){
					push('F');
					printf("R\n");
				}
				else{
					flag = 0;
					break;
				}
			}
			
		}
        if(str[i]=='#')
			break;
		if(cmpPriority(str[i])==-1){
			flag=-1;
			break;
		}
		if(flag != 1)
			break;
		push(str[i]);
		printf("I%c\n",str[i]);
		i++;
	}
	if(flag==0)
		printf("RE\n");
	else if(flag == -1)
		printf("E\n");
	else{
		if(top==2&&pop()=='F')
			return 0;
		else
		{
			printf("RE\n");
			return 0;
		}
		
	}
} 
