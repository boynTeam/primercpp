#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

class PersonInfo
{
public:
    string name;
    vector<string> phones;
};

void getPhoneInput(ifstream& f,vector<PersonInfo>& infos) {
    string personLine;
    
    while (getline(f,personLine)) {
        PersonInfo info;
        istringstream ss(personLine);
        ss >> info.name;
        string word;
        while(ss>> word) {
            info.phones.push_back(word);
        }
        infos.push_back(info);
    }
    
}

bool valid(const string& phoneNumber) {
    return phoneNumber.size() == 11;
}

string format(const string& s) {
    return s;
}  

void printInfos(const vector<PersonInfo>& infos, ostream& os) {
    for (const auto& info : infos) {
        ostringstream formatted,badName;
        for (const auto& number: info.phones) {
            if(!valid(number)) {
                badName << " " << number;
            }else {
                formatted << " " << format(number);
            }
        }
        if (badName.str().empty()) {
            os << info.name << " " << formatted.str() << endl;
        } else {
            os << "Input error: " << info.name << " invalid number(s): " << badName.str() << endl;
        }
    }
}

int main(int argc, char const *argv[])
{
    ifstream f(argv[1]);
    if (!f) {
        cerr << "Open file failed." << endl;
        return -1;
    }
    vector<PersonInfo> infos;
    getPhoneInput(f,infos);
    printInfos(infos,cout);

    return 0;
}



