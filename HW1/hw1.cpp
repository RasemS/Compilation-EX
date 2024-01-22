#include "tokens.hpp"
#include <iostream>
void Stringcase(char* str){
	for(int i=0;i<yyleng;i++){
		if(str[i]=='\\'){
			if(i+1<yyleng){
			switch (str[i+1]){
				case 'n': std::cout<<std::endl;
				case 'r': std::cout<<" ";
				case 't': std::cout<<"\t";
				case '\\': std::cout<<"\\";
				case '\"': std::cout<<"\"";
				default: break;
			};
			}
			if(i+3<yyleng){//check for ASCII + hexadecimal value
				if(str[i+1]=='x'){
					//turn char to number nad get the ascii
				}else {
					break; //error
				}
			}
		}else{
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