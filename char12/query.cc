#include "TextQuery.h"

void runQueries(std::ifstream &f)
{
    TextQuery tq(f);
    while (true)
    {
        std::cout << "Enter a word to lookup, or q for quiting." << std::endl;
        std::string word;
        std::cin >> word;
        if (!std::cin || word == "q")
        {
            break;
        }
        print(std::cout, tq.query(toLower(word)));
    }
}

int main(int argc, char const *argv[])
{
    std::ifstream f("hamlet.txt");
    runQueries(f);
    return 0;
}
