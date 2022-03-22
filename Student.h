#pragma once
#include<iostream>
#include"/Users/themoon/Desktop/vscode start c++.c/头文件/机房预约系统头文件/Person.h"
#include<fstream>
#include<vector>
#include<map>
using namespace std;

class MyAppointment
{
public:
    MyAppointment()
    {
        
    }


    MyAppointment (string date,string period,string computerRoom,string state)
    {
        m_date=date;
        m_period=period;
        m_ComputerRoom=computerRoom;
        m_state=state;
        
    }

    MyAppointment & operator()(string date,string period,string computerRoom,string state)
    {
        m_date=date;
        m_period=period;
        m_ComputerRoom=computerRoom;
        m_state=state;
        return *this;
    }
    
     MyAppointment & operator()(int i1,int i2,int i3,string state)
    {
        switch (i1)
        {
        case 1:m_date="周一";break;
        case 2:m_date="周二";break;
        case 3:m_date="周三";break;
        case 4:m_date="周四";break;
        case 5:m_date="周五";break;
        }
        switch (i2)
        {
        case 1:m_period="上午";break;
        case 2:m_period="下午";break;
        }
        switch(i3)
        {
            case 1:m_ComputerRoom="机房一";break;
            case 2:m_ComputerRoom="机房二";break;
            case 3:m_ComputerRoom="机房三";break;
        }
        m_state=state;
        return *this;
    }

   

    

    string m_date;
    string m_period;
    string m_state;
    string m_ComputerRoom;
};

class Student:public Person
{
public:
    Student()
    {
        
    }

    void SaveMap()
    {
        ifstream ifs;
        ifs.open("order.txt",ios::in);
        int id;
        string name;
        string date;
        string period;
        string computerRoom;
        string state;
        int index=0;
        while(ifs>>id&&ifs>>name&&ifs>>date&&ifs>>period&&ifs>>computerRoom&&ifs>>state)
        {
            if(this->m_id==id&&m_name==name)
            { 
                MyAppointment mp(date,period,computerRoom,state);
                Student s1(name,mp);
                this->m1.insert(make_pair(id,s1));
            }
        }
        ifs.close();
    }

    void SavpMap2()
    {
        ifstream ifs;
        ifs.open("order.txt",ios::in);
        int id;
        string name;
        string date;
        string period;
        string computerRoom;
        string state;
        int index=0;
        while(ifs>>id&&ifs>>name&&ifs>>date&&ifs>>period&&ifs>>computerRoom&&ifs>>state)
        {
            if(this->m_id!=id)
            { 
                MyAppointment mp(date,period,computerRoom,state);
                Student s1(name,mp);
                this->m2.insert(make_pair(id,s1));
            }
        }
        ifs.close();
    }

    Student(string name,MyAppointment app)
    {
       
        m_name=name;
        m_appointment=app;
        
    }

    Student(int id,string name,int password)
    {
        this->m_id=id;
        this->m_name=name;
        this->m_PassWord=password;
       
    }

    virtual void PrintInformation()
    {
        cout<<"学号:"<<m_id<<" 姓名:"<<m_name<<" 登陆密码:"<<m_PassWord<<endl;
    }

    void StudentMenu()
    {
        cout<<"欢迎学生代表:"<<this->m_name<<"登陆！！！"<<endl;
        cout<<"                         -------------------------"<<endl;
        cout<<"                        |      1.申请预约         |"<<endl;
        cout<<"                        |                         |"<<endl;
        cout<<"                        |      2.查看自身预约     |"<<endl;
        cout<<"                        |                         |"<<endl;
        cout<<"                        |      3.查看所有预约     |"<<endl;
        cout<<"                        |                         |"<<endl;
        cout<<"                        |      4.取消预约         |"<<endl;
        cout<<"                        |                         |"<<endl;
        cout<<"                        |      0.注销登录         |"<<endl;
        cout<<"                        --------------------------"<<endl;
    }

    void ApplyAppointment()
    {
        int AppointDate;
        cout<<"请选择预约日期:"<<endl;
        cout<<"1.周一"<<endl;
        cout<<"2.周二"<<endl;
        cout<<"3.周三"<<endl;
        cout<<"4.周四"<<endl;
        cout<<"5.周五"<<endl;
        cin>>AppointDate;
        if(AppointDate<1||AppointDate>5)
        {
            cout<<"输入错误"<<endl;
            string cursor;
            cout<<"输入任意键继续"<<endl;
            cin>>cursor;
            return;
        }
        int AppointPeriod;
        cout<<"请输入预约时段:"<<endl;
        cout<<"1.上午"<<endl;
        cout<<"2.下午"<<endl;
        cin>>AppointPeriod;
        if(AppointPeriod!=1&&AppointPeriod!=2)
        {
            cout<<"输入错误!!!"<<endl;
            string cursor;
            cout<<"输入任意键继续"<<endl;
            cin>>cursor;
            return;
        }
        int room;
        cout<<"请输入预约的机房:"<<endl;
        cout<<"1.机房一"<<endl;
        cout<<"2.机房二"<<endl;
        cout<<"3.机房三"<<endl;
        cin>>room;
        if(room!=1&&room!=2&&room!=3)
        {
            cout<<"输入错误!!!"<<endl;
            string cursor;
            cout<<"输入任意键继续"<<endl;
            cin>>cursor;
            return;
        }
        string state="状态:审核中";
        m_appointment(AppointDate,AppointPeriod,room,state);
        ofstream ofs;
        ofs.open("order.txt",ios::out|ios::app);
        ofs<<this->m_id<<" "<<this->m_name<<" "<<this->m_appointment.m_date<<" "<<this->m_appointment.m_period<<" "<<this->m_appointment.m_ComputerRoom<<
        " "<<this->m_appointment.m_state<<endl;
        ofs.close();
        cout<<"预约成功，请等待审核！！！"<<endl;
        cout<<"输入任意键继续"<<endl;
        string cursor;
        cin>>cursor;
        system("clear");   
    }

    void ViewOwnAppointment()
    {
        ifstream ifs;
        ifs.open("order.txt",ios::in);
        int id;
        string name;
        string date;
        string period;
        string ComputerRoom;
        string state;
        int index=0;
        while(ifs>>id&&ifs>>name&&ifs>>date&&ifs>>period&&ifs>>ComputerRoom&&ifs>>state)
        {
            if (id==this->m_id&&name==this->m_name)
            {
                cout<<"预约日期:"<<date<<" 时段:"<<period<<" "<<ComputerRoom<<" "<<state<<endl; index++;
            }
        }
        if(index==0)
        {
            cout<<"暂无预约!!!"<<endl;
        }
        cout<<"输入任意键继续"<<endl;
        string cursor;
        cin>>cursor;
        system("clear");   
    }

    void ViewAllApointments()
    {
        ifstream ifs;
        ifs.open("order.txt",ios::in);
        int id;
        string name;
        string date;
        string period;
        string ComputerRoom;
        string state;
        int index=1;
        while(ifs>>id&&ifs>>name&&ifs>>date&&ifs>>period&&ifs>>ComputerRoom&&ifs>>state)
        {
            cout<<index<<"、预约日期:"<<date<<" 时段:"<<period<<" 学号:"<<id<<" 姓名:"<<name<<" "<<ComputerRoom<<" 状态:"<<state<<endl;
            index++;
        }
        if(index==1)
        {
            cout<<"暂无预约!!!"<<endl;
            cout<<"输入任意键继续"<<endl;
            string cursor;
            cin>>cursor;
            system("clear");  

            return;
        }
        cout<<"输入任意键继续"<<endl;
        string cursor;
        cin>>cursor;
        system("clear");   
    }

    void CancelReservation()
    {
        SaveMap();
        this->SavpMap2();
        cout<<"审核中或预约成功的记录可以取消!请输入想要取消的记录"<<endl;
        ifstream ifs;
        ifs.open("order.txt",ios::in);
        int id;
        string name;
        string date;
        string period;
        string ComputerRoom;
        string state;
        int choice2;
        int index=1;
        while(ifs>>id&&ifs>>name&&ifs>>date&&ifs>>period&&ifs>>ComputerRoom&&ifs>>state)
        {
            if(id==this->m_id&&name==this->m_name&&state=="状态:审核中"||state=="状态:审核成功")
            {
                cout<<index<<".预约日期:"<<date<<" 时段:"<<period<<" "<<ComputerRoom<<" "<<state<<endl; index++;
            }
        }
        if(index==1)
        {
            cout<<"暂无预约!!!"<<endl;
            cout<<"输入任意键继续"<<endl;
            string cursor;
            cin>>cursor;
            system("clear");  
            return;
        }
        cout<<"选择想要取消的记录!0代表返回"<<endl;
        cin>>choice2;
        if(choice2==0)
        {
            system("clear");
            return;
        }
        else
        {
            if(choice2<0||choice2>index-1)
            {
                cout<<"输入错误!!!"<<endl;
                cout<<"输入任意键继续"<<endl;
                string cursor;
                cin>>cursor;
                system("clear");  
                return;
            }
            else
            {
                cout<<"确定取消?\n1.确定\n2.返回"<<endl;
                int choice3;
                cin>>choice3;
                multimap<int,Student>::iterator its=m1.begin();
                for(int i=0;i<choice2-1;i++)
                {
                    its++;
                }
                if(choice3!=1&&choice3!=2)
                {
                    cout<<"输入错误!"<<endl;
                    string cursor;
                    cout<<"输入任意键继续"<<endl;
                    cin>>cursor;
                    system("clear");
                    return;
                }
                else if(choice3==1)
                {
                    its->second.m_appointment.m_state="状态:审核已取消";
                    
                }
                else
                {
                    system("clear");
                    return;
                }
                cout<<"取消成功!!!"<<endl;
                ofstream ofs;
                ofs.open("order.txt",ios::trunc);
                ofs.close();
                ofs.open("order.txt",ios::out|ios::app);
                for(its=m2.begin();its!=m2.end();its++)
                {
                    ofs<<its->first<<" "<<its->second.m_name<<" "<<its->second.m_appointment.m_date<<" "<<its->second.m_appointment.m_period<<" "<<its->second.m_appointment.m_ComputerRoom<<" "<<its->second.m_appointment.m_state<<endl;
                }
                
                for(its=m1.begin();its!=m1.end();its++)
                {
                    ofs<<its->first<<" "<<its->second.m_name<<" "<<its->second.m_appointment.m_date<<" "<<its->second.m_appointment.m_period<<" "<<its->second.m_appointment.m_ComputerRoom<<" "<<its->second.m_appointment.m_state<<endl;
                }
                ofs.close();

            }
        }
        cout<<"输入任意键继续"<<endl;
        string cursor;
        cin>>cursor;
        system("clear");   

    }

    int m_id;                   //学号
    MyAppointment m_appointment;  //我的预约
    multimap<int,Student>m1;
    multimap<int,Student>m2;       //记录其他人的容器


};