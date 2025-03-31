#include "Receipt.h"
#include <iostream>

Receipt::Receipt()
{
    m_number = 0;
    m_date = "";
    m_amount = 0;
    std::cout << "����������� ��� ���������� ��� ������� " << this << std::endl;
}
Receipt::Receipt(int number, std::string date, double amount)
{
    m_number = number;
    m_date = date;
    m_amount = amount;
    std::cout << "����������� � ����������� ��� ������� " << this << std::endl;
}
Receipt::Receipt(const Receipt& receipt)
{
    m_number = receipt.m_number;
    m_date = receipt.m_date;
    m_amount = receipt.m_amount;
    std::cout << "����������� ����������� ��� ������� " << this << std::endl;
}
Receipt::~Receipt()
{
    std::cout << "���������� ��� ������� " << this << std::endl;
}
unsigned int Receipt::getNumber()
{
    return m_number;
}
void Receipt::setNumber(unsigned int number)
{
    m_number = number;
}
std::string Receipt::getDate()
{
    return m_date;
}
void Receipt::setDate(std::string date)
{
    m_date = date;
}
double Receipt::getAmount()
{
    return m_amount;
}
void Receipt::setAmount(double amount)
{
    m_amount = amount;
}
void Receipt::show()
{
    std::cout << "��������� " << this << std::endl
        << "�����: " << m_number << std::endl
        << "����: " << m_date << std::endl
        << "����: " << m_amount << std::endl;
}

