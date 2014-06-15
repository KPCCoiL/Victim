#include <iostream>
#include <fstream>
#include <string>
#include <regex>
using namespace std;
int main(int argc,char* argv[]){
	if(argc == 1) {
		cerr<<"Error: no input file"<<endl;
		cerr<<"Usage: ./runvtm program.vtm"<<endl;
		return 1;
	}
	ifstream ifs(argv[1]);
	if(!ifs) cerr<<"Error: no such file"<<endl;
	string prog((istreambuf_iterator<char>(ifs)),
			istreambuf_iterator<char>());
	int arr[30000] = {};
	int* p = arr;
	prog = regex_replace(prog,regex("<C-a>"),"k");
	prog = regex_replace(prog,regex("<C-x>"),"j");
	prog = regex_replace(prog,regex("\".*\n"),"");
	for (auto i = prog.begin(); i != prog.end(); ++i) {
		if(*i == 'l') p++;
		else if(*i == 'h')p--;
		else if(*i == 'k')(*p)++;
		else if(*i == 'j')(*p)--;
		else if(*i == 'p')putchar(*p);
		else if(*i == 'i')*p = getchar();
		else if(*i == 'f' && (*p) == 0) {
			int bracket = 1;
			while (bracket) {
				++i;
				if(*i == 'f') bracket++;
				else if(*i == 'F') bracket--;
			}
			++i;
		}
		else if(*i == 'F' && (*p) != 0) {
			int bracket = -1;
			while (bracket) {
				--i;
				if(*i == 'f') bracket++;
				else if(*i == 'F') bracket--;
			}
		}
	}
	return 0;
}
