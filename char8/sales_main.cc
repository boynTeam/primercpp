#include "Sales_data.hpp"
#include <fstream>
using std::ifstream;
using std::ofstream;

int main(int argc, char const *argv[])
{
    ifstream input(argv[1]);
    ofstream output(argv[2]);
    Sales_data total;
    if (read(input,total))
    {
        Sales_data trans;
        while(read(input,trans))
        {
            if (total.isbn() == trans.isbn())
            {
                total.combine(trans);
            }
            else
            {
                print(output, total) << std::endl;
                total = trans;
            }
        }
        print(output, total) << std::endl;
    }
    else
    {
        std::cerr << "No data?!" << std::endl;
    }
    return 0;
}
