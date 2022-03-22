#pragma once
#include<iostream>
#include"/Users/themoon/Desktop/vscode start c++.c/头文件/机房预约系统头文件/Person.h"
#include<fstream>
#include<map>
#include"/Users/themoon/Desktop/vscode start c++.c/头文件/机房预约系统头文件/Student.h"
using namespace std;
class Teacher:public Person
{
public:
    Teacher()
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
            MyAppointment mp(date,period,computerRoom,state);
            Student s1(name,mp);
            this->m_appint.insert(make_pair(id,s1));
        }
        ifs.close();
        
    
    }


    Teacher(int id,string name,int password)
    {
        this->m_did=id;
        this->m_name=name;
        this->m_PassWord=password;
    }

    virtual void PrintInformation()
    {
        cout<<"职工编号:"<<m_did<<" 姓名:"<<m_name<<" 登陆密码:"<<m_PassWord<<endl;
    }
    int m_did;                   //职工编号

    void ShowMenu()
    {
        cout<<"欢迎老师:"<<this->m_name<<"登陆！！！"<<endl;
        cout<<"                         -------------------------"<<endl;
        cout<<"                        |                         |"<<endl;
        cout<<"                        |                         |"<<endl;
        cout<<"                        |      1.查看所有预约     |"<<endl;
        cout<<"                        |                         |"<<endl;
        cout<<"                        |      2.审核预约         |"<<endl;
        cout<<"                        |                         |"<<endl;
        cout<<"                        |      0.注销登录         |"<<endl;
        cout<<"                        |                         |"<<endl;
        cout<<"                        |                         |"<<endl;
        cout<<"                        --------------------------"<<endl;
    }

    void ViewAllAppointment()
    {
        int index=1;
        for(multimap<int,Student>::iterator it=m_appint.begin();it!=m_appint.end();it++,index++)
        {
            cout<<index<<".预约日期:"<<it->second.m_appointment.m_date<<" 时段:"<<it->second.m_appointment.m_period<<" 学号:"<<it->first<<" 姓名:"<<it->second.m_name<<" "<<it->second.m_appointment.m_ComputerRoom<<" "<<it->second.m_appointment.m_state<<endl;
        }
        if(index==1)
        {
            cout<<"暂无预约!"<<endl;
        }
        string cursor;
        cout<<"输入任意键继续"<<endl;
        cin>>cursor;
        system("clear");
    }

    void AuditAppointment()
    {
        cout<<"待审核的预约如下:"<<endl;
        int index=1;
        for(multimap<int,Student>::iterator it=m_appint.begin();it!=m_appint.end();it++,index++)
        {
            if(it->second.m_appointment.m_state=="状态:审核中")
            {         
            cout<<index<<".预约日期:"<<it->second.m_appointment.m_date<<" 时段:"<<it->second.m_appointment.m_period<<" 学号:"<<it->first<<" 姓名:"<<it->second.m_name<<" "<<it->second.m_appointment.m_ComputerRoom<<" "<<it->second.m_appointment.m_state<<endl;
            }
    
        }
        if(index==1)
        {
            cout<<"暂时没有需要审核的预约!"<<endl;
            string cursor;
            cout<<"输入任意键继续"<<endl;
            cin>>cursor;
            system("clear");
            return;
        }
        else
        {
            int choice;
            cout<<"请输入想要审核的预约,0代表返回:"<<endl;
            cin>>choice;
            if(choice==0)
            {
                system("clear");
                return;         
            }
            else if(choice>index-1||choice<0)
            {
                cout<<"输入错误"<<endl;
                string cursor;
                cout<<"输入任意键继续"<<endl;
                cin>>cursor;
                system("clear");
                return;
            }
            else
            {
                int choice2;
                cout<<"请输入审核结果:\n1.通过\n2.不通过"<<endl;
                cin>>choice2;
                multimap<int,Student>::iterator its=m_appint.begin();
                for(int i=0;i<choice-1;i++)
                {
                    its++;
                }
                if(choice2!=1&&choice2!=2)
                {
                    cout<<"输入错误!"<<endl;
                    string cursor;
                    cout<<"输入任意键继续"<<endl;
                    cin>>cursor;
                    system("clear");
                    return;
                }
                else if(choice2==1)
                {
                    its->second.m_appointment.m_state="状态:审核成功";
                }
                else
                {
                    its->second.m_appointment.m_state="状态:审核失败";
                }
                cout<<"审核完毕!!!"<<endl;
                ofstream ofs;
                ofs.open("order.txt",ios::trunc);
                ofs.close();
                ofs.open("order.txt",ios::out|ios::app);
                for(its=m_appint.begin();its!=m_appint.end();its++)
                {
                    ofs<<its->first<<" "<<its->second.m_name<<" "<<its->second.m_appointment.m_date<<" "<<its->second.m_appointment.m_period<<" "<<its->second.m_appointment.m_ComputerRoom<<" "<<its->second.m_appointment.m_state<<endl;
                }
                ofs.close();
                
            }

        }
        string cursor;
        cout<<"输入任意键继续"<<endl;
        cin>>cursor;
        system("clear");
    }

    multimap<int,Student>m_appint;
};