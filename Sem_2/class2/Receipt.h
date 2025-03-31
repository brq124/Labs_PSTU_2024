#pragma once
#include <string>

class Receipt
{
private:
    unsigned int m_number;
    std::string m_date;
    double m_amount;
public:
    Receipt();
    Receipt(int, std::string, double);
    Receipt(const Receipt&);
    ~Receipt();
    unsigned int getNumber();
    void setNumber(unsigned int);
    std::string getDate();
    void setDate(std::string);
    double getAmount();
    void setAmount(double);
    void show();
};

