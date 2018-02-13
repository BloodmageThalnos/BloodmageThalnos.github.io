#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<string>
#include<vector>
#include<io.h>
using namespace std;
string path, html, comp, arti;
vector<string> afiles;
void readPath(){
	if(~_access("config.ini", 4)){
		freopen("config.ini", "r", stdin);
		cout<<"Config found."<<endl;
	}
	else{
		cout<<"Cannot find config.ini"<<endl;
	}
}
void getFiles(string p, vector<string>& files){
	struct _finddata_t fileinfo;
	intptr_t hFile = _findfirst((p+="*").c_str(), &fileinfo);
	if(~hFile){
		do if(!(fileinfo.attrib &  _A_SUBDIR))
			files.push_back(fileinfo.name);
		while(!_findnext(hFile, &fileinfo));
		_findclose(hFile);
	}
}
int main(){
	readPath();
	cin>>path>>html>>comp>>arti;
	getFiles(path+arti, afiles);
	for(auto file:afiles){
		cout<<"Creating "<<file<<" from components."<<endl;
		string code="copy /b "+path+comp+"head.txt+"+path+arti+file+"+"+path+comp+"sidebar.txt+"+path+comp+"tail.txt "+path+html+file;
		cout<<code<<endl;
		system(code.c_str());
		cout<<"Successful composing these files.";
	}
	return 0;
}