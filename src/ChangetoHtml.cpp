#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<io.h>
using namespace std;
void readPath(){
	if(~_access("afterChange.txt", 4)){
		cout<<"Caution, documents in afterChange.txt will be lost. Continue?(Y/anything)"<<endl;
		if(getchar()=='Y' && getchar()=='\n')
			remove("afterChange.txt");
		else exit(0);
	}
	if(~_access("toChange.txt", 4)){
		freopen("toChange.txt", "r", stdin);
		cout<<"toChange found."<<endl;
	}
	else{
		cout<<"Cannot find toChange.txt\nYou may type here, end with EOF."<<endl;
	}
	freopen("afterChange.txt", "w", stdout);
}
int main(){
	readPath();
	while(true){
		char c=getchar();
		if(c==EOF)break;
		else if(c=='<')printf("&lt;");
		else if(c=='>')printf("&gt;");
		else if(c=='&')printf("&amp;");
		else if(c=='"')printf("&quot;");
		else putchar(c);
	}
	return 0;
}