/*
身份简介：
    分别有三种身份使用该程序：
    1.学生代表：申请使用机房
    2.教师：审核学生的预约申请
    3.管理员：给学生、教师创建账号
机房简介： 
    1号机房---最大容量20人
    2号机房---最大容量50人
    3号机房---最大容量100人
申请简介：
    1.申请的订单每周由管理员负责清空
    2.学生可以预约未来一周内的机房使用、预约的日期为周一至周五，预约是需要选择预约时段（上午、下午）
    3.教师来审核预约，依据实际情况审核预约通过或者不通过
系统具体需求：
    1.首先进入登陆界面，可选登陆身份有：
        1.学生代表
        2.老师
        3.管理员
        4.退出
    2.每个身份都需要进行验证后，进入子菜单
        1.学生需要输入：学号、姓名、登陆密码
        2.老师需要输入：职工号、姓名、登陆密码
        3.管理员需要输入：管理员姓名、登陆密码
    3.学生具体功能
        1.申请预约---预约机房
        2.查看自身的预约---查看自己的预约状态
        3.查看所有预约---查看全部预约信息以及预约状态
        4.取消预约---取消自身的预约，预约成功或审核中的预约均可取消
    4.教师具体功能
        1.查看所有预约---查看全部预约信息以及预约状态
        2.审核预约---对学生的预约进行审核
        3.注销登录---退出登陆
    5.管理员具体功能：
        1.添加账号---添加学生或者教师的账号，需要检测学生编号或者教师职工号是否重复
        2.查看账号---可以选择查看学生或教师的全部信息
        3.查看机房---查看所有机房的信息
        4.清空预约---清空所有预约
        5.注销登录---退出登陆
*/
#include<fstream>
#include<iostream>
#include<string>
#include"/Users/themoon/Desktop/vscode start c++.c/头文件/机房预约系统头文件/Filename.h"
#include"/Users/themoon/Desktop/vscode start c++.c/头文件/机房预约系统头文件/Person.h"
#include"/Users/themoon/Desktop/vscode start c++.c/头文件/机房预约系统头文件/Student.h"
#include"/Users/themoon/Desktop/vscode start c++.c/头文件/机房预约系统头文件/Administrator.h"
#include"/Users/themoon/Desktop/vscode start c++.c/头文件/机房预约系统头文件/Teacher.h"
using namespace std;

void Login(string Filename,int choice)                                                                              //登陆接口
{
    ifstream ifs;
    ifs.open(Filename,ios::in);
    if(!ifs.is_open())
    {
        cout<<"文件不存在!!!"<<endl;
        ifs.close();
        return ;
    }
    int id;
    string name;
    int passwords;
    if(choice==1)
    {
        cout<<"请输入您的学号:"<<endl;
        cin>>id;
    }
    else if(choice==2)
    {
        cout<<"请输入您的职工号:"<<endl;
        cin>>id;
    }
    cout<<"请输入您的姓名:"<<endl;
    cin>>name;
    cout<<"请输入您的登陆密码:"<<endl;
    cin>>passwords;
    if(choice==1)
    {
        int fid;
        string fname;
        int fpasswords;
        int choice;
        while(ifs>>fid&&ifs>>fname&&ifs>>fpasswords)
        {
            if(fid==id&&fname==name&&fpasswords==passwords)
            {
                Student s1(id,name,passwords);
                cout<<"学生身份验证成功!!!"<<endl;
                string cursor;
                cout<<"请按任意键继续"<<endl;
                cin>>cursor;
                system("clear");
                do
                {
                    s1.StudentMenu();
                    cout<<"请输入想要进行的操作:"<<endl;
                    cin>>choice;
                    switch(choice)
                    {
                        case 1:s1.ApplyAppointment();break;
                        case 2:s1.ViewOwnAppointment();break;
                        case 3:s1.ViewAllApointments();break;
                        case 4:s1.CancelReservation();break;
                        case 0:break;
                    }
                }
                while (choice!=0);    
                system("clear");
                return;  
            }
        }               
        cout<<"验证失败!!!"<<endl;
        cout<<"请按任意键继续"<<endl;
        string cursor;
        cin>>cursor;
        system("clear");
        return;
        
    }
    else if(choice==2)
    {
        int fid;
        string fname;
        int fpasswords;
        int choice;
        if(ifs>>fid&&ifs>>fname&&ifs>>fpasswords)
        {
            if(fid==id&&fname==name&&fpasswords==passwords)
            {
                cout<<"老师身份验证成功!!!"<<endl;
                string cursor;
                cout<<"请按任意键继续"<<endl;
                cin>>cursor;
                system("clear");
                Teacher T1;
                do
                {
                    T1.ShowMenu();
                    cout<<"请输入想要进行的操作!!!"<<endl;
                    cin>>choice;
                    switch (choice)
                    {
                    case 1:T1.ViewAllAppointment();break;
                    case 2:T1.AuditAppointment();break;
                    case 0:break;
                    }
                }while (choice!=0);
                
                
            }
            else
            {
                cout<<"验证失败!!!"<<endl;
                cout<<"请按任意键继续"<<endl;
                string cursor;
                cin>>cursor;
                system("clear");
                return;
            }
        }
    }
    else
    {
        string fname;
        int fpasswords;
        if(ifs>>fname&&ifs>>fpasswords)
        {
            if(fname==name&&fpasswords==passwords)
            {
                Administrator admin1(name,passwords);
                cout<<"管理员身份验证成功！！！"<<endl;
                string cursor;
                cout<<"请按任意键继续"<<endl;
                cin>>cursor;
                system("clear");
                int choice;
                do
                {  
                    admin1.AdministratorMenu();
                    cout<<"请输入想要进行的操作:"<<endl;
                    cin>>choice;
                    switch (choice)
                    {
                    case 1:admin1.AddAccount();break;
                        
                    
                    case 2:admin1.ViewAccount();break;
                    
                    case 3:admin1.ViewMachineRoom();break;

                    case 4:admin1.ClearAppointment();break;

                    case 0:cout<<"注销成功"<<endl;return;

                    default:cout<<"输入错误!!!"<<endl;break;
                    }             
                }while (choice!=0);  
            }
            else
            {
                cout<<"验证失败!!!"<<endl;
                cout<<"请按任意键继续"<<endl;
                string cursor;
                cin>>cursor;
                system("clear");
                return;
            }
        }
        else
        {
            cout<<"账号或者密码错误!!!"<<endl;
            return;
        }
    }
    return;

    
}

void ShowChoiceIdentityMenu()                                                                      //选择身份菜单
{
    cout<<"-------------------------  欢迎使用  --------------------------"<<endl;
    cout<<"************************  机房预约系统  ************************"<<endl;
    cout<<"|                                                            |"<<endl;
    cout<<"|                          登陆身份                          |"<<endl;
    cout<<"|                --------------------------                  |"<<endl;
    cout<<"|                                                            |"<<endl;
    cout<<"|                       1.学生代表                           |"<<endl;
    cout<<"|                       2.老师                               |"<<endl;
    cout<<"|                       3.管理员                             |"<<endl;
    cout<<"|                       4.退出                               |"<<endl;
    cout<<"|                                                            |"<<endl;
    cout<<"|                                                            |"<<endl;
    cout<<"|                --------------------------                  |"<<endl;
    cout<<"|                                                            |"<<endl;
    cout<<"|                                                            |"<<endl;
    cout<<"|                                                            |"<<endl;
    cout<<"|                                                            |"<<endl;
    cout<<" ------------------------------------------------------------"<<endl;
}

int main()
{
    string cursor;
    int identitychoice;
    do
    {
        ShowChoiceIdentityMenu();                                                                 //选择身份菜单
        cout<<"请输入您的登陆身份:"<<endl;
        cin>>identitychoice;
        switch (identitychoice)
        {
        case 1:Login(StudentFile,identitychoice);      break;

        case 2:Login(TeacherFile,identitychoice);      break;

        case 3:Login(AdminFile,identitychoice);      break;

        case 4:  break;
        
        default:cout<<"输入错误！请重新输入！"<<endl;break;
        }
    }while(identitychoice!=4);

    cout<<"退出成功，欢迎下次使用！！！"<<endl;
    system("pause");
    return 0;
}
