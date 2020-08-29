#include "Sales_data.hpp"


double Sales_data::avg_price() const {
    if (this->units_sold) {
        return this->revenue / this->units_sold;
    }
    else {
        return 0;
    }
}

Sales_data& Sales_data::combine(const Sales_data& rhs) {
    this->units_sold += rhs.units_sold;
    this->revenue += rhs.revenue;
    return *this;
}

std::istream& read(std::istream& is, Sales_data& item) {
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

std::ostream& print(std::ostream& os, const Sales_data& item) {
    os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price() << std::endl;
    return os;
}

Sales_data add(const Sales_data& s1, const Sales_data& s2) {
    Sales_data sum = s1;
    sum.combine(s2);
    return sum;
}

Sales_data::Sales_data(std::istream& is) {
    read(is, *this);
}