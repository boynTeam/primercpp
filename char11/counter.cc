#include <map>
#include <set>
#include <string>
#include <iostream>
#include <sstream>
#include <cctype>

using namespace std;



string removePunct(const string& s) {
    ostringstream stream;
    for (const auto c : s) {
        if (!ispunct(c)) {
            stream << c;
        }
    }
    return stream.str();
}
bool isUpperAlpha(int c) {
    return c>=65 && c <=90;
}

string toLowwer(const string &s) {
    ostringstream stream;
    for (const auto c : s) {
        if (!isUpperAlpha(c)) {
            stream << c;
        }else {
            stream << char(c + 32);
        }
    }
    return stream.str();
}



int main(int argc, char const *argv[])
{
    map<string,size_t> counter;
    set<string> exclude = {"the","but","and","or","an","a"}; 
    string word;
    while(cin >> word) {
        if (exclude.find(word)==exclude.end()) {
            counter[removePunct(toLowwer(word))]++;
        }
    }
    
    for (const auto& w : counter) {
        cout << w.first << " " << w.second << endl;
    }
    return 0;
}