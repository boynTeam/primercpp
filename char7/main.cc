#include "Sales_data.hpp"

int main(int argc, char const *argv[])
{
    Sales_data total = Sales_data(std::cin);
    if (std::cin)
    {
        Sales_data trans = Sales_data(std::cin);
        do
        {
            if (total.isbn() == trans.isbn())
            {
                total.combine(trans);
            }
            else
            {
                print(std::cout, total) << std::endl;
                total = trans;
            }
            trans = Sales_data(std::cin);
        } while (std::cin);
        print(std::cout, total) << std::endl;
    }
    else
    {
        std::cerr << "No data?!" << std::endl;
    }
    return 0;
}
