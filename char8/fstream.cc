#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    ifstream file_reader(argv[1]);
    vector<string> vec;
    if (file_reader)
    {
        string line;
        while (getline(file_reader,line))
        {
            stringstream ss(line);
            string word;
            while(getline(ss,word,' ')) {
                vec.push_back(word);
            }
        }
    }
    file_reader.close();
    cout << "Read finished." << endl;
    for (auto s : vec)
    {
        cout << s << endl;
    }
    return 0;
}
