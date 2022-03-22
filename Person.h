#pragma once
#include<iostream>
using namespace std;
class Person
{
public:

    virtual void PrintInformation()=0;


    string m_name;
    int m_PassWord;
};

