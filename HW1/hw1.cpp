#include "tokens.hpp"
#include <iostream>
void Stringcase(char* str){
	if(str[0]!='\"'){
		//should never happen
		return;
	}
	for(int i=1;i<yyleng;i++){
		if(str[i]=='\\'){ //escape characters
		int outcome=1;
			if(i+1<yyleng){//acccepted escape characters
				switch (str[i+1]){
					case 'n': std::cout<<std::endl; //\n
					case 'r': std::cout<<"\r";	// \r
					case 't': std::cout<<"\t";  // \t
					case '\\': std::cout<<"\\"; //  slash
					case '\"': std::cout<<"\""; //  "
					case 'x':					//check for ASCII with hexadecimal value
								if(i+2>=yyleng||i+3>=yyleng){//cant read 2 chars after x
									std::cout<<"Error undefined escape sequence "<<str[i+1]<<"\n";
								}
								if(( '0'<=str[i+2]<='7')&&( '0'<=str[i+3]<='9' ||  'A'<=str[i+3]<='F')){
									char num=16*(str[i+2]-'0');
									num+=('0'<=str[i+3]<='9')? (str[i+3]-'0') : (10+(str[i+3]-'A'));
									std::cout<<num;
								}else{//error invalid hexa value
									std::cout<<"Error undefined escape sequence x"<<str[i+2]<<str[i+3]<<"\n";
								}
					default: std::cout<<"Error undefined escape sequence "<<str[i+1]<<"\n";;
				};
			
			
				/*if(str[i+1]=='x'){//check for ASCII with hexadecimal value
					if(i+2>=yyleng||i+3>=yyleng){//cant read 2 chars after x
						std::cout<<"Error undefined escape sequence "<<str[i+1]<<"\n";
					}
					if(( '0'<=str[i+2]<='7')&&( '0'<=str[i+3]<='9' ||  'A'<=str[i+3]<='F')){
						char num=16*(str[i+2]-'0');
						num+=('0'<=str[i+3]<='9')? (str[i+3]-'0') : (10+(str[i+3]-'A'));
						std::cout<<num;
					}else{//error invalid hexa value
						std::cout<<"Error undefined escape sequence x"<<str[i+2]<<str[i+3]<<"\n";
					}*/
				
			}else{//string ended with \ TODO
				break;
			}
		}else{ //normal character just print
			std::cout<<str[i];
		} 
	}
}
int main()
{
	int token;
	while(token = yylex()) {
		// token should be a different number thats used to identify the token (STRING /INT ...)
	// Your code here
	//<line number> <token name> <value>\n
	//printf("%d %s %s\n",yylineno,???,yytext);
	}
	return 0;
}