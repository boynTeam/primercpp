#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <map>

using namespace std;
map<string,string> readRule(const string&);
string transformLine(const string&,map<string,string>&);


int main(int argc, char const *argv[])
{
    auto rule_map = readRule(argv[1]);
    ifstream textfile(argv[2]);
    ofstream outputfile(argv[3]);
    string line;
    while(getline(textfile,line)) {
        outputfile << transformLine(line,rule_map) << endl;
    }
    return 0;
}

string transformLine(const string& line,map<string,string>& rule) {
    stringstream stream(line);
    ostringstream resultBuf;
    string word;
    bool is_first = true;
    while(getline(stream,word,' ')) {
        if(rule.find(word) != rule.end()) {
            word = rule[word];
        }
        if (is_first) {
            is_first = !is_first;
        }else {
            resultBuf << " ";
        }
        resultBuf << word;
    }
    return resultBuf.str();
} 

map<string,string> readRule(const string& filename) {
    ifstream file_stream(filename);
    string line;
    map<string,string> rule;
    while(file_stream) {
        getline(file_stream,line);
        auto firstSpace = line.find_first_of(" ");
        string first = line.substr(0,firstSpace);
        string second = line.substr(firstSpace+1);
        rule[first] = second;    
        cout << "Add map:" << first << " " << second << endl;
    }
    return rule;
}
