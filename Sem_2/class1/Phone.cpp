#include "Phone.h"
#include <iostream>

void Phone::Init(unsigned int first, float second)
{
    m_first = first;
    m_second = second;
}
void Phone::Read()
{
    std::cin >> m_first;
    std::cin >> m_second;
}
void Phone::Show()
{
    std::cout << "Продолжительность разговора: " << m_first << std::endl
        << "Стоимость одной минуты: " << m_second << std::endl;
}
float Phone::Cost()
{
    return m_first * m_second;
}

