#pragma once

class Phone
{
private:
    unsigned int m_first;
    float m_second;
public:
    void Init(unsigned int, float);
    void Read();
    void Show();
    float Cost();
};

