#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

void printToken(char token[]){
	if(strcmp(token,"BEGIN")==0)
		printf("Begin\n");
	else if(strcmp(token,"END")==0)
		printf("End\n");
	else if(strcmp(token,"FOR")==0)
		printf("For\n");
	else if(strcmp(token,"IF")==0)
		printf("If\n");
	else if(strcmp(token,"THEN")==0)
		printf("Then\n");
	else if(isalpha(token[0]))
		printf("Indent(%s)\n",token);
	else if(token[0]>='0'&&token[0]<='9')
		printf("Int(%d)\n",atoi(token));
	else if(token[0]==':'&&strlen(token)==1)
		printf("Colon\n");
	else if(token[0]=='+')
		printf("Plus\n");
	else if(token[0]=='*')
		printf("Star\n");
	else if(token[0]==',')
		printf("Comma\n");
	else if(token[0]=='(')
		printf("LParenthesis\n");
	else if(token[0]==')')
		printf("RParenthesis\n");
	else if(token[0]==':'&&token[1]=='=')
		printf("Assign\n");
}
int main(){
	FILE *fp = NULL;
	fp = fopen("$input","r");
	char str[10000];
	char token[1000];
	int i=0,j=0;
	int flag=1;
	while(fgets(str,10000,fp)!=NULL){
		if(flag==0)
			break;
		i=0;
		while(str[i]!='\0'||str[i]!='\n'){
			memset(token,sizeof(token),0);
			j = 0; 
			while(str[i]==' '||str[i]=='\r'||str[i]=='\t')
				i++;
			if(isalpha(str[i])){
				while(isalpha(str[i])||(str[i]<='9'&&str[i]>='0')){
					token[j++] = str[i];
					i++;
				}
				token[j]='\0';
				printToken(token);
			}
			else if(str[i]>='0'&&str[i]<='9'){
				while(str[i]<='9'&&str[i]>='0'){
					token[j++] = str[i];
					i++;
				}
				token[j]='\0';
				printToken(token);
			}
			else if(str[i]==':'){
				token[j++]=str[i];
				i++;
				if(str[i]=='='){
					token[j++]=str[i];
					i++;
				}
				token[j]='\0';
				printToken(token);
			}
			else if(str[i]=='+'||str[i]=='*'||str[i]==','||str[i]=='('||str[i]==')'){
				token[j++]=str[i];
				i++;
				token[j]='\0';
				printToken(token);
			}
			else{
				flag=0;
				printf("Unknown\n");
				break;
			}
		}

	}
} 
