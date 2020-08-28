#include "sales_data.h"
#include <string>
#include <iostream>

int main(int argc, char const *argv[])
{
    Sales_data data1, data2;
    // read data
    read_sales_data(data1);
    read_sales_data(data2);
    // check is data1 and data2 has same isbn code
    std::cout << "data1 " << data1.bookNo << std::endl;
    std::cout << "data2 " << data2.bookNo << std::endl;
    // if same, sum two together
    add_revenue(data1, data2);
    return 0;
}

void read_sales_data(Sales_data &data)
{
    double price;
    std::cout << "Input ISBN number:";
    std::cin >> data.bookNo;
    std::cout << "Input sale price:";
    std::cin >> price;
    std::cout << "Input sale units:";
    std::cin >> data.units_sold;
    data.revenue = data.units_sold * price;
}

void add_revenue(const Sales_data data1, const Sales_data data2)
{
    if (data1.bookNo != data2.bookNo)
    {
        std::cerr << "Data must refer same ISBN" << std::endl;
        return;
    }
    unsigned total_cnt = data1.units_sold + data2.units_sold;
    double total_revenue = data1.revenue + data2.revenue;
    std::cout << data1.bookNo << " " << total_cnt << " " << total_revenue << " ";
    if (total_cnt != 0)
    {
        std::cout << total_revenue / total_cnt << std::endl;
    }
    else
    {
        std::cout << "(no sales)" << std::endl;
    }
}
