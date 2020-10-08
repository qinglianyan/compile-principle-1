#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

char token[1000];//һ���ַ��� 
char ch;//��ǰ������ַ� 

int is_letter(char a){//����ĸ 
	if((a>='a')&&(a<='z')){
		return 1;
	}
	else if((a>='A')&&(a<='Z')){
		return 1;
	}
	return 0;
}
int is_digit(char a){//������ 
	if((a>='0')&&a<='9'){
		return 1;
	}
	else{
		return 0;
	}
	
}
int reserve(char *a){//�ж�token�е��ַ����Ǳ����ֻ��Ǳ�ʶ�� 
	if(strcmp(a, "BEGIN")==0||strcmp(a, "END")==0||strcmp(a, "FOR")==0||strcmp(a, "IF")==0||strcmp(a, "THEN")==0||strcmp(a, "ELSE")==0){
		return 1;
	}
	return 0;
}
void show(char *a){
	if(strcmp(a, "BEGIN")==0){
		printf("Begin\n");
	}
	if(strcmp(a, "END")==0){
		printf("End\n");
	}
	if(strcmp(a, "FOR")==0){
		printf("For\n");
	}
	if(strcmp(a, "IF")==0){
		printf("If\n");
	}
	if(strcmp(a, "THEN")==0){
		printf("Then\n");
	}
	if(strcmp(a, "ELSE")==0){
		printf("Else\n");
	}
}
int a_to_i(char *a){//�ַ���ת��Ϊ���� 
	return atoi(a);
}

int main(int argc, char* argv[]){
	FILE *file=fopen(argv[1],"r");
	if(file==NULL){
		printf("open error!\n");
		return 0;
	}
//	else{
//		printf("open success!\n");
//	}
	
//	ch=fgetc(file);
//	printf("%c\n",ch);
//	fseek(file, -1, SEEK_CUR); 
	
	while((ch=fgetc(file))!=EOF){
//		printf("%c",ch);

		token[0]='\0';//��tokenΪ�մ� 
//		printf("%d", sizeof(token));
		while(ch==' '||ch=='\n'||ch=='\t'||ch=='\r'){
			ch=fgetc(file);
		}//getnbc,getchar
		if(is_letter(ch)){
			strcat(token, &ch);
			ch=fgetc(file);
			while(is_letter(ch)||is_digit(ch)){
				strcat(token, &ch);
				ch=fgetc(file);
			}
			if(ch!=EOF){
				fseek(file, -1, SEEK_CUR);
			}

			if(reserve(token)==0){
				printf("Ident(%s)\n", token);
			}
			else{
				show(token);
			}
		}
		else if(is_digit(ch)){
			strcat(token, &ch);
			ch=fgetc(file);
			while(is_digit(ch)){
				strcat(token, &ch);
				ch=fgetc(file);
			}
			if(ch!=EOF){
				fseek(file, -1, SEEK_CUR);
			}
			
			printf("Int(%d)\n", a_to_i(token));
		}
		else if(ch=='+'){
			printf("Plus\n");
		}
		else if(ch=='*'){
			printf("Star\n");
		}
		else if(ch==','){
			printf("Comma\n");
		}
		else if(ch=='('){
			printf("LParenthesis\n");
		}
		else if(ch==')'){
			printf("RParenthesis\n");
		}
		else if(ch==':'){
			ch=fgetc(file);
			if(ch=='='){
				printf("Assign\n");
			}
			else{
				if(ch!=EOF){
					fseek(file, -1, SEEK_CUR);
				}
				
				printf("Assign\n");
			}
		}
//		else if(ch=='/'){
//			ch=fgetc(file);
//			if(ch=='/'){
//				while((ch=fgetc(file))!='\n'){
//				}
//			}
//			else if(ch=='*'){
//				
//			}
//			else{
//				printf("Unknown\n");
//				fclose(file);
//				return 0;
//			}
//		}
		else{
			printf("Unknown\n");
			fclose(file);
			return 0;
		}
	}
	fclose(file);
	
	
	return 0;	
}
