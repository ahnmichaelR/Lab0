#include <string>
#include <queue>
#include <map>
#include <set>


#include "inverter.h"

using namespace std;


string build_inverted_index(string filename){
	map< string, set<int>> Invertedindex;
	map< string, int>  Filename; //primary file and file number
	string fnf; //files in file
	ifstream mainfile(filename);
	if(mainfile.is_open()){
		int count = 0;
		string file;
		while(mainfile >> file){
			ifstream filetitle(file);
			if(filetitle.is_open()){
				string words;
				while(filetitle >> words){
					string check = words;
					if(!isalnum(check.back())){
						check.pop_back();
						words = check;
					}
				map<string, set<int>>::iterator search = Invertedindex.find(words);

				if(search!=Invertedindex.end()){
					search->second.insert(count);
				}
				else{
					set<int> a = {count};
					Invertedindex[words] = a; 
				}
			}
			filetitle.close();
			count++;
		}
}
}
mainfile.close();
string print = "";
for(map<string, set<int>>::iterator it2 = Invertedindex.begin(); it2!=Invertedindex.end();it2++){
    set<int>::iterator intsinset;
    string intcount;
    for(intsinset = it2->second.begin();intsinset!=it2->second.end();intsinset++){
    	intcount += to_string(*intsinset) + " ";
    }
    string last;
    intcount.pop_back();
    last = intcount;
    string ewf = (it2->first) + ": " + last + "\n";
	print += ewf;
	//cout << print;
	//print.append(": ");
	//print.append(setstring2);
	//print.append("\n");
	//print.append("SUCKit");
}
return print;
}
