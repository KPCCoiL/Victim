#include <fstream>
#include <string>
#include <regex>
using namespace std;
int arr[30000];
int main(int argc,char* argv[]){
	ifstream ifs(argv[1]);
	string prog((istreambuf_iterator<char>(ifs)),
			istreambuf_iterator<char>());
	int* p = arr;
	prog = regex_replace(prog,regex("<C-a>"),"k");
	prog = regex_replace(prog,regex("<C-x>"),"j");
	for (auto i = prog.begin(); i != prog.end(); ++i) {
		if(*i == 'l') p++;
		else if(*i == 'h')p--;
		else if(*i == 'k')(*p)++;
		else if(*i == 'j')(*p)--;
		else if(*i == 'p')putchar(*p);
		else if(*i == 'i')*p = getchar();
		else if(*i == 'f' && (*p) == 0) {
			while (*i != 'F')
				++i;
			++i;
		}
		else if(*i == 'F' && (*p) != 0) {
			while (*i != 'f')
				--i;
		}
		else if (*i == '\"') {
			while (*i != '\n') {
				++i;
			}
			++i;
		}
	}
	return 0;
}
