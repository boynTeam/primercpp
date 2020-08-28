#include <string>

struct Sales_data {
    std::string bookNo;
    unsigned int units_sold = 0;
    double revenue = 0.0;
};
void read_sales_data(Sales_data &data);
void add_revenue(const Sales_data data1,const Sales_data data2);