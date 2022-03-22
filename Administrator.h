#pragma once
#include<iostream>
#include"/Users/themoon/Desktop/vscode start c++.c/头文件/机房预约系统头文件/Person.h"
#include<fstream>
#include"/Users/themoon/Desktop/vscode start c++.c/头文件/机房预约系统头文件/Filename.h"
using namespace std;
class Administrator:public Person
{
public:

    Administrator()
    {
    }

    Administrator(string name,int password)
    {
        this->m_name=name;
        this->m_PassWord=password; 
    }

    virtual void PrintInformation()
    {
        cout<<" 姓名:"<<m_name<<" 登陆密码:"<<m_PassWord<<endl;
    }

    void AdministratorMenu()
    {
        cout<<"欢迎管理员:"<<this->m_name<<"登陆！！！"<<endl;
        cout<<"                         -------------------------"<<endl;
        cout<<"                        |      1.添加账号         |"<<endl;
        cout<<"                        |                         |"<<endl;
        cout<<"                        |      2.查看账号         |"<<endl;
        cout<<"                        |                         |"<<endl;
        cout<<"                        |      3.查看机房         |"<<endl;
        cout<<"                        |                         |"<<endl;
        cout<<"                        |      4.清空预约         |"<<endl;
        cout<<"                        |                         |"<<endl;
        cout<<"                        |      0.注销登录         |"<<endl;
        cout<<"                        --------------------------"<<endl;
    }

    void AddAccount()                   //1.添加账号
    {
        int index;
        do
        {    
            cout<<"~~~~~~~~~~~~~~~~~~~"<<endl;
            cout<<"1.添加学生账号."<<endl;
            cout<<"2.添加老师账号."<<endl;
            cout<<"~~~~~~~~~~~~~~~~~~~"<<endl;
            int choice;
            cout<<"请选择:"<<endl;
            cin>>choice;
            if(choice==1)
            {
                ofstream ofs;
                ofs.open(StudentFile,ios::out|ios::app);
                int id;
                string name;
                int passwords;
                cout<<"请输入学生的学号:"<<endl;
                cin>>id;
                cout<<"请输入学生的姓名:"<<endl;
                cin>>name;
                cout<<"请输入学生的登陆密码:"<<endl;
                cin>>passwords;
                ifstream ifs;
                ifs.open(StudentFile,ios::in);
                int iid;
                while(ifs>>iid)
                {
                    if(iid==id)
                    {
                        cout<<"学生的学号重复!!!"<<endl;
                        ifs.close();
                        string cursor;
                        cout<<"输入任意键继续"<<endl;
                        cin>>cursor;
                        system("clear");
                        return;
                    }
                }
                ifs.close();
                ofs<<id<<" "<<name<<" "<<passwords<<endl; 
                ofs.close();
                cout<<"是否继续添加:"<<endl;
                cout<<"1.继续添加"<<endl;
                cout<<"2.返回"<<endl;
                cin>>index;       
                system("clear");                  
            }
            else if(choice==2)
            {
                ofstream ofs;
                ofs.open(TeacherFile,ios::out|ios::app);
                int id;
                string name;
                int passwords;
                cout<<"请输入老师的职工编号:"<<endl;
                cin>>id;
                cout<<"请输入老师的姓名:"<<endl;
                cin>>name;
                cout<<"请输入老师的登陆密码:"<<endl;
                cin>>passwords;
                ifstream ifs;
                ifs.open(TeacherFile,ios::in);
                int iid;
                while(ifs>>iid)
                {
                    if(iid==id)
                    {
                        cout<<"老师的职工编号重复!!!"<<endl;
                        ifs.close();
                        string cursor;
                        cout<<"输入任意键继续"<<endl;
                        cin>>cursor;
                        system("clear");
                        break;
                    }
                }
                ifs.close();
                ofs<<id<<" "<<name<<" "<<passwords<<endl;    
                cout<<"是否继续添加:"<<endl;
                cout<<"1.继续添加"<<endl;
                cout<<"2.返回"<<endl;
                cin>>index; 
                system("clear"); 
            }
            else
            {
                cout<<"输入错误!!!"<<endl;
                string cursor;
                cout<<"输入任意键继续"<<endl;
                cin>>cursor;
                system("clear");
                break;
                
            }
        }while(index==1);
        system("clear");
    }

    void ViewAccount()                      //2.查看账号
    {
        cout<<"请选择想要查看的账号类型:"<<endl;
        cout<<"1.老师"<<endl;
        cout<<"2.学生"<<endl;
        int choice;
        cout<<"请选择:"<<endl;
        cin>>choice;
        if(choice==1)
        {
            ifstream ifs;
            ifs.open(TeacherFile,ios::in);
            if(!ifs.is_open())
            {
                cout<<"文件不存在!!!"<<endl;
                ifs.close();
                string cursor;
                cout<<"输入任意键继续"<<endl;
                cin>>cursor;
                system("clear");
                return;
            }
            char c;
            ifs>>c;
            if(ifs.eof())
            {
                cout<<"文件为空，请先添加人员!!!"<<endl;
                ifs.close();
                string cursor;
                cout<<"输入任意键继续"<<endl;
                cin>>cursor;
                system("clear");
                return ;
            }
            ifs.putback(c);
            int id;
            string name;
            int password;
            while(ifs>>id&&ifs>>name&&ifs>>password)
            {
                cout<<id<<" "<<name<<" "<<password<<endl;
            }
            ifs.close();
            string cursor;
            cout<<"输入任意键继续"<<endl;
            cin>>cursor;
            system("clear");
        }
        else if(choice==2)
        {
            ifstream ifs;
            ifs.open(StudentFile,ios::in);
            if(!ifs.is_open())
            {
                cout<<"文件不存在!!!"<<endl;
                ifs.close();
                string cursor;
                cout<<"输入任意键继续"<<endl;
                cin>>cursor;
                system("clear");
                return;
            }
            char c;
            ifs>>c;
            if(ifs.eof())
            {
                cout<<"文件为空，请先添加人员!!!"<<endl;
                ifs.close();
                string cursor;
                cout<<"输入任意键继续"<<endl;
                cin>>cursor;
                system("clear");
                return ;
            }
            ifs.putback(c);
            int id;
            string name;
            int password;
            while(ifs>>id&&ifs>>name&&ifs>>password)
            {
                cout<<id<<" "<<name<<" "<<password<<endl;
            }
            ifs.close();
            string cursor;
            cout<<"输入任意键继续"<<endl;
            cin>>cursor;
            system("clear");
        }
        else
        {
            cout<<"输入错误!!!"<<endl;
            string cursor;
            cout<<"输入任意键继续"<<endl;
            cin>>cursor;
            system("clear");
            return;
        }

    }

    void ViewMachineRoom()                      //3.查看机房
    {
        ifstream ifs;
        ifs.open(ComputeRoomFile,ios::in);
        if(!ifs.is_open())
        {
            cout<<"文件不存在!"<<endl;
            ifs.close();
            string cursor;
            cout<<"输入任意键继续"<<endl;
            cin>>cursor;
            system("clear");
            return;
        }
        char c;
        ifs>>c;
        if(ifs.eof())
        {
            cout<<"文件数据为空!"<<endl;
            ifs.close();
            string cursor;
            cout<<"输入任意键继续"<<endl;
            cin>>cursor;
            system("clear");
            return;
        }
        int id;
        int capacity;
        ifs.putback(c);
        while (ifs>>id&&ifs>>capacity)
        {
            cout<<id<<"号机房\t\t容量:"<<capacity<<endl;
        }
        ifs.close();
        string cursor;
        cout<<"输入任意键继续"<<endl;
        cin>>cursor;
        system("clear");
    }

    void ClearAppointment()                     //4.清空预约
    {
        ofstream ofs;
        ofs.open("order.txt",ios::trunc);
        ofs.close();
        cout<<"清空成功！"<<endl;
        string cursor;
        cout<<"输入任意键继续"<<endl;
        cin>>cursor;
        system("clear");
        
    }

   

};