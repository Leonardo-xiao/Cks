#include"main.h"
#include<stdio.h>
#include "nmouse.h"
#include "move.h"
#include"svgahead.h"
#include"basicgf.h"
#include"compo.h"
#include<conio.h>
#include"advance.h"
#include"frame.h"
#include"hzxs.h"
#include"module_b.h"
#include<string.h>
#include<bios.h>
#include"input.h"
#include"color1.h"
#include"roomgf.h"
#include"sign.h"
#include"filefun.h"
#include"room.h"
#include"ground.h"
#include"brick.h"
#include"wall.h"
#include"outside.h"
#include"iphone.h"
#include"iphCheck.h"
#include"idCheck.h"
#include"select.h"
#include"service.h"
#include"manage.h"
#include"time.h"
#include"control.h"
#include"chat.h"
#include"chatHanz.h"
#include"chatInpu.h"
#include"chatQhwh.h"
#include"chatShow.h"
#include"gkmove.h"
#include"myhouse.h"

#include"iphCmfrt.h"
#include"mysystem.h"
int input_account(USERS *head,char *account,char *code,int *x,int *y)
{
	int key;
	int i=0;//用于计算已输入的字符数目的变量
	char *p=account;//输入字符的中间指针变量
	char ch;//用于临时储存键值所对应字符的变量
	int buttons,judge;
	char temp[2] = {'\0','\0'};

	//查看已经输入了多少个字符
	while(*p != '\0')
	{
		i++;
		p++;
	}
    while(1)
	{
		newxy(x,y,&buttons);
		key=0;
		if (kbhit() != 0)
		{
			key = bioskey(0);    //输入的是键值
		}


	     /*将按键对应的字符存入account中*/
	    ch = searchKeyValue(key);
	    if (ch != '\0'&&i<10)
	    {
			temp[0] = ch;
			outtextxy(300+i*18,305,temp,2,2,10,0);


		/*将字符存入数组中*/
		    *p = ch;
		    p++;
		    *p = '\0';
		    i++;
	    }



        if(key ==0xe08)         //按了回删键
	    {
		    if(p != account)
		    {
			    bar(290 + i * 18, 295, 340 + i * 18, 345,65535);
			    p--;
			    i--;
		    }
			*p = '\0';
	    }
		/*按esc则退出*/
		if(key == 0x11b)
		{
			exit(0);
		}

		//删掉了防止鼠标遮挡的功能（2020/7/26）



		//密码输入
		if(*x>=300&&*x<=700&&*y>=445&&*y<=495&&buttons)
		{
			return 3;
		}

		//注册键
		if(*x>=440&&*x<=560&&*y>=555&&*y<=590&&buttons)
		{
			/*
			linelevel(620,525,785,825,2,65535);
            linelevel(620,673,785,673,2,0);
			linever(600,535,600,655,2,65535);
			linever(800,535,800,655,2,0);
			delay0(10);
			linelevel(620,673,785,673,2,31694);
			linelevel(620,525,785,525,2,31694);
			linever(600,535,600,655,2,31694);
			linever(800,535,800,655,2,31694);
			*/
			judge = UserRegist(head,account,code,x,y,&buttons);
			return judge;
		}




		//登录键
		if(*x>=650&&*x<=700&&*y<=495&&*y>=445&&buttons)
		{
            /*
            linelevel(220,525,385,525,2,65535);
            linelevel(220,673,385,673,2,0);
			linever(200,535,200,655,2,65535);
			linever(400,535,400,655,2,0);
			delay0(10);
			linelevel(220,673,385,673,2,31694);
			linelevel(220,525,385,525,2,31694);
			linever(200,535,200,655,2,31694);
			linever(400,535,400,655,2,31694);
			*/
			judge = sign_in_check(head,account,code);
			return judge;
		}
	}
}

int input_code(USERS *head,char *account,char *code,int *x,int *y)
{
	int key;
	int i=0;//用于计算已输入的字符数目的变量
	char *u = code;//输入字符的中间指针变量
	char ch;//用于临时储存键值所对应字符的变量
	int buttons,judge;

	while(*u != '\0')
	{
		i++;
		u++;
	}
    while(1)
	{
		newxy(x,y,&buttons);
		key=0;
		if (kbhit() != 0)
		{
			key = bioskey(0);
		}
		if(key ==0xe08)
	    {
		    if(u != code)
		    {
			    bar(275 + i * 25, 450, 305 + i * 25, 490,65535);
			    u--;
			    i--;
		    }
			*u = '\0';
	    }

		/*按esc则退出*/
		if(key == 0x11b)
		{
			exit(0);
		}

		//登录键
		if(*x>=650&&*x<=700&&*y<=495&&*y>=445&&buttons)
		{
            /*
            linelevel(220,525,385,525,2,65535);
            linelevel(220,673,385,673,2,0);
			linever(200,535,200,655,2,65535);
			linever(400,535,400,655,2,0);
			delay0(10);
			linelevel(220,673,385,673,2,31694);
			linelevel(220,525,385,525,2,31694);
			linever(200,535,200,655,2,31694);
			linever(400,535,400,655,2,31694);
			*/
			judge = sign_in_check(head,account,code);
			return judge;
		}

		//删去防止输入时遮挡功能



		//输入账号
		if(*x>=300&&*x<=700&&*y>=295&&*y<=345&&buttons)
		{

			return 2;
		}

		//注册框
		if(*x>=440&&*x<=560&&*y>=555&&*y<=590&&buttons)
		{
			/*
			linelevel(620,525,785,825,2,65535);
            linelevel(620,673,785,673,2,0);
			linever(600,535,600,655,2,65535);
			linever(800,535,800,655,2,0);
			delay0(10);
			linelevel(620,673,785,673,2,31694);
			linelevel(620,525,785,525,2,31694);
			linever(600,535,600,655,2,31694);
			linever(800,535,800,655,2,31694);
			*/
			judge = UserRegist(head,account,code,x,y,&buttons);
			return judge;
		}


	/*将按键对应的字符存入code数组中*/
	    ch = searchKeyValue(key);
	    if (ch != '\0'&&i<10)
	    {


		    //bar(250 + i * 11, 218, 261 + i * 11, 242,65535);
            FillCircle(315+i*25,470,8,0);

		/*将字符存入数组中*/
		    *u = ch;
		    u++;
		    *u = '\0';
		    i++;
	    }
	}
}

/***********************************************************
Function: RegisteraccountsInput
Description: 1、用户注册界面的账号输入函数
             2、只能是大小写字母与数字
             3、能输入1到10位
Attention:鼠标位置参数必须要以指针形式传递过来！
Return:返回2在userRegister中调用LogincodeInput函数
       返回3在userRegister中调用RegistersecondcodeInput函数
       返回4在userRegister中使用登陆功能
       返回5在userRegister中使用注册功能
************************************************************/
int RegisteraccountsInput(char *account, int *x, int *y)
{
	int key;    //表示键值的变量
	int i = 0;   //用于计算已输入的字符数目的变量
	char *p = account;   //输入字符的中间指针变量
	char ch;     //用于临时储存键值所对应字符的变量
	int button;    //鼠标的参数变量
	int *buttons=&button;
	char temp[2] = { '\0','\0' };  //用于outtextxy函数输出单个字符的数组


    /*使p指向'\0',i表示当前字符数*/
	while (*p != '\0')
	{
		i++;
		p++;
	}



	while (1)
	{
		newxy(x, y, buttons);//在新的位置画鼠标

		//密码
		if(*x>=344&&*x<=690&&*y>=350&&*y<=380&&*buttons)
		{
			return 2;
		}
		//二次确认密码
		if(*x>=344&&*x<=690&&*y>=440&&*y<=470&&*buttons)
		{
			return 3;
		}
		//邮箱输入
		if(*x>=344&&*x<=584&&*y>=530&&*y<=560&&*buttons)
		{
			return 4;
		}
		//获取验证码
		if(*x>=584&&*x<=690&&*y>=530&&*y<=560&&*buttons)
		{
			return 5;
		}
		//输入验证码
		if(*x>=344&&*x<=690&&*y>=620&&*y<=650&&*buttons)
		{
			return 6;
		}
		//注册并登录
		if(*x>=468&&*x<=580&&*y>=710&&*y<=752&&*buttons)
		{
			return 7;
			//yanzheng
		}
        //返回键
		if(*x>=75&&*x<=125&&*y>=75&&*y<=125&&*buttons)
		{
			return 8;
		}

        key=0;

		/*吸收键盘缓冲区数据*/
		if (kbhit() != 0)
		{
			key = bioskey(0);
		}

		/*按esc则退出*/
		if(key == 0x11b)
		{
			exit(0);
		}



		/*按了回删键*/
		if (key == 0xe08)
		{
			if (p != account)
			{

				bar(349 + i * 18, 260, 367 + i * 18, 290,65535);       //盖住删掉的字符
				p--;
				i--;
			}
			*p = '\0';
		}

		/*将按键对应的字符存入accounts数组中*/
		ch = searchKeyValue(key);
		temp[0] = ch;

		if (ch != '\0'&&i<10)
		{
			*p = ch;
			p++;
			*p = '\0';
			i++;

            outtextxy(349+i*18,267,temp,1,1,8,0);

		}

	}
}

/***********************************************************
Function: RegistercodeInput
Description: 1、用户注册界面的密码输入函数
             2、只能是大小写字母与数字
             3、能输入1到10位
Attention:鼠标位置参数必须要以指针形式传递过来！
Return:返回1在userRegister中调用RegisteraccountsInput函数
       返回3在userRegister中调用RegistersecondcodeInput函数
       返回4在userRegister中使用登陆功能
       返回5在userRegister中使用注册功能
************************************************************/
int RegistercodeInput(char *code, int *x, int *y) //登陆界面新密码输入函数
{
	int key;     //表示键值的变量
	int i = 0;   //用于计算已输入的字符数目的变量
	char *p = code;     //输入字符的中间指针变量
	char ch;     //用于临时储存键值所对应字符的变量
	int button;    //鼠标的参数变量
	int *buttons=&button;

	/*使p指向'\0',i表示当前字符数*/
	while (*p != '\0')
	{
		i++;
		p++;
	}

	while (1)
	{
		newxy(x, y, buttons);//在新的位置画鼠标

		//账号输入
		if(*x>=344 &&*x<=690&&*y>=260&&*y<=290&&*buttons)
		{
			return 1;
		}
		//二次确认密码
		if(*x>=344&&*x<=690&&*y>=440&&*y<=470&&*buttons)
		{
			return 3;
		}
		//邮箱输入
		if(*x>=344&&*x<=584&&*y>=530&&*y<=560&&*buttons)
		{
			return 4;
		}
		//获取验证码
		if(*x>=584&&*x<=690&&*y>=530&&*y<=560&&*buttons)
		{
			return 5;
		}
		//输入验证码
		if(*x>=344&&*x<=690&&*y>=620&&*y<=650&&*buttons)
		{
			return 6;
		}
		//注册并登录
		if(*x>=468&&*x<=580&&*y>=710&&*y<=752&&*buttons)
		{
			return 7;
			//yanzheng
		}
        //返回键
		if(*x>=75&&*x<=125&&*y>=75&&*y<=125&&*buttons)
		{
			return 8;
		}

		 key=0;

		/*吸收键盘缓冲区数据*/
		if (kbhit() != 0)
		{
			key = bioskey(0);
		}

		/*按esc则退出*/
		if(key == 0x11b)
		{
			exit(0);
		}


		/*按了回删键*/
		if (key == 0xe08)
		{
			if (p != code)
			{
				bar(349 + i * 15, 350, 364 + i * 15, 380,65535);

				p--;
				i--;
			}
			*p = '\0';
		}

		/*将键值存入code数组*/
		ch = searchKeyValue(key);
		if (ch != '\0'&&i<10)
		{
			*p = ch;
			p++;
			*p = '\0';
			i++;

			FillCircle(349 + i * 15, 365, 5, 0);


		}

	}
}


/***********************************************************
Function: RegistersecondcodeInput
Description: 1、用户注册界面的密码第二次输入函数
             2、只能是大小写字母与数字
             3、能输入1到10位
Attention:鼠标位置参数必须要以指针形式传递过来！
Return:返回1在userRegister中调用RegisteraccountsInput函数
       返回2在userRegister中调用RegistercodeInput函数
	   返回3在userRegister中使用邮箱输入功能
	   返回4在userRegister中使用验证码获得功能
	   返回5在userRegister中使用验证码输入功能
	   返回6在userRegister中使用登陆功能
	   返回7在userRegister中使用注册功能
	   返回8在userRegister中返回
**********************************************************/
int RegistersecondcodeInput(char *secondcode, int *x, int *y)
{
	int key;     //表示键值的变量
	int i = 0;   //用于计算已输入的字符数目的变量
	char *p = secondcode;     //输入字符的中间指针变量
	char ch;     //用于临时储存键值所对应字符的变量
	int button=0;
	int *buttons=&button;



	/*使p指向'\0',i表示当前字符数*/
	while (*p != '\0')
	{
		i++;
		p++;
	}

	while (1)
	{
		newxy(x, y, buttons);//在新的位置画鼠标

		//账号输入
		if(*x>=344 &&*x<=690&&*y>=260&&*y<=290&&*buttons)
		{
			return 1;
		}
		//密码
		if(*x>=344&&*x<=690&&*y>=350&&*y<=380&&*buttons)
		{
			return 2;
		}
		//邮箱输入
		if(*x>=344&&*x<=584&&*y>=530&&*y<=560&&*buttons)
		{
			return 4;
		}
		//获取验证码
		if(*x>=584&&*x<=690&&*y>=530&&*y<=560&&*buttons)
		{
			return 5;
		}
		//输入验证码
		if(*x>=344&&*x<=690&&*y>=620&&*y<=650&&*buttons)
		{
			return 6;
		}
		//注册并登录
		if(*x>=468&&*x<=580&&*y>=710&&*y<=752&&*buttons)
		{
			return 7;
			//yanzheng
		}
        //返回键
		if(*x>=75&&*x<=125&&*y>=75&&*y<=125&&*buttons)
		{
			return 8;
		}


         key=0;

		/*吸收键盘缓冲区数据*/
		if (kbhit() != 0)
		{
			key = bioskey(0);
		}

		/*按esc则退出*/
		if(key == 0x11b)
		{
			exit(0);
		}
		/*按了回删键*/
		if (key == 0xe08)
		{
			if (p != secondcode)
			{
				bar(349 + i * 15, 440, 364 + i * 15, 470,65535);

				p--;
				i--;
			}
			*p = '\0';
		}

		/*将键值存入secondcode数组*/
		ch = searchKeyValue(key);
		if (ch != '\0'&&i<10)
		{
			*p = ch;
			p++;
			*p = '\0';
			i++;


			FillCircle(349 + i * 15, 455, 5, 0);


		}
	}
}


int mail_input(char *mail, int *x, int *y)
{
    int key;     //表示键值的变量
	int i = 0;   //用于计算已输入的字符数目的变量
	char *p = mail;     //输入字符的中间指针变量
	char ch;     //用于临时储存键值所对应字符的变量
	int button=0;
	int *buttons=&button;
    char temp[2] = {'\0','\0'};	//	确保第二位是'\0'，到时候outtext出来的时候才能正常输出

	/*使p指向'\0',i表示当前字符数*/
	while (*p != '\0')
	{
		i++;
		p++;
	}

	while (1)
	{
		newxy(x, y, buttons);//在新的位置画鼠标

		//账号输入
		if(*x>=344 &&*x<=690&&*y>=260&&*y<=290&&*buttons)
		{
			return 1;
		}
		//密码
		if(*x>=344&&*x<=690&&*y>=350&&*y<=380&&*buttons)
		{
			return 2;
		}
		//二次确认密码
		if(*x>=344&&*x<=690&&*y>=440&&*y<=470&&*buttons)
		{
			return 3;
		}
		//获取验证码
		if(*x>=584&&*x<=690&&*y>=530&&*y<=560&&*buttons)
		{
			return 5;
		}
		//输入验证码
		if(*x>=344&&*x<=690&&*y>=620&&*y<=650&&*buttons)
		{
			return 6;
		}
		//注册并登录
		if(*x>=468&&*x<=580&&*y>=710&&*y<=752&&*buttons)
		{
			return 7;
			//yanzheng
		}
        //返回键
		if(*x>=75&&*x<=125&&*y>=75&&*y<=125&&*buttons)
		{
			return 8;
		}


         key=0;

		/*吸收键盘缓冲区数据*/

		/*按esc则退出*/
		if(key == 0x11b)
		{
			exit(0);
		}
        if (kbhit() != 0)
        {
            key = bioskey(0);
        }
        		//清空键盘缓冲区//
        if(key == 0xe08)	//点击退格键时的操作
        {
            if(p != mail)		//检测是否是首位（地址是否相同）
            {
                bar(349+ i * 10, 535, 365+ i * 10, 559,65535);
                p--;			//指针		往前移
                i--;			//记字数	往前移
            }
            *p = '\0';			//	同样将最后一位换成'\0'

        }
            //	将按键对应的字符一个个存入ph_num数组中
            ch = searchKeyValue(key);
            temp[0] = ch;
            if (ch != '\0'&&i<20)
            {
                 outtextxy(349+i*10,537,temp,1,1,8,0);

                //	将字符存入数组中
                *p = ch;
                p++;
                *p = '\0';		// 每次操作都要归'\0'
                i++;
            }


    }
}

int get_verification(char *mail,char *real_veri)
{
    unsigned int *image_save=(unsigned int *)malloc(450*96*sizeof(unsigned int));	//	保存验证码弹窗背后的图案
    char real_mail[17] = "123456aqq.com";
    int a,i;
    char b[5];
    int flag4=0;
    srand((unsigned)time(0));
    if(image_save==NULL)
    {
        overflow_box(500,500);
        getch();
        exit(1);
    }
    if (whether_mail(mail)==0)
    {
        bar(390,505,690,530,50712);
        fdhz(454,510,1,1,"邮箱格式不正确",65535);
        bar(695,530,750,560,50712);      //清空×勾的位置处的图像
        red_cross(700,545);
    }
    if (whether_mail(mail)==1)
    {
        if (strcmp(mail,real_mail)==0)
        {
            bar(390,505,690,530,50712);
            bar(695,530,750,560,50712);      //清空×勾的位置处的图像
            green_tick(700,545);
            //get_image(290,0,740,96,image_save);
            bar (290,0,740,50,65535);
            bar_round_2(290,30,740,96,10,1,65535);
            fdhz(300,5,1,1,"尊敬的用户，您好：",0);
            fdhz(332,25,1,1,"欢迎使用本智能家居机器人系统，本次您",0);
            fdhz(332,45,1,1,"注册的验证码为：",0);
	    linelevel(380,90,620,90,3,0);
            a=rand()%10000;
            itoa(a,b,5);

            b[4]='\0';

            for(i=0;i<5;i++)
            {
            real_veri[i] = b[i];
            }


            outtextxy(450,45,b,2,2,15,0);

            fdhz(300,75,1,1,"祝您使用愉快",0);
            delay(1500);
            //put_image(290,0,740,96,image_save);
            flag4=1;
        }
    }
    free(image_save);
    image_save = NULL;
    return flag4;
}

int verification_input(char *veri, int *x, int *y)
{
    int key;     //表示键值的变量
	int i = 0;   //用于计算已输入的字符数目的变量
	char *p = veri;     //输入字符的中间指针变量
	char ch;     //用于临时储存键值所对应字符的变量
	int button=0;
	int *buttons=&button;
    char temp[2]={0};



	/*使p指向'\0',i表示当前字符数*/
	while (*p != '\0')
	{
		i++;
		p++;
	}

	while (1)
	{
		newxy(x, y, buttons);//在新的位置画鼠标

		//账号输入
		if(*x>=344 &&*x<=690&&*y>=260&&*y<=290&&*buttons)
		{
			return 1;
		}
		//密码
		if(*x>=344&&*x<=690&&*y>=350&&*y<=380&&*buttons)
		{
			return 2;
		}
		//二次确认密码
		if(*x>=344&&*x<=690&&*y>=440&&*y<=470&&*buttons)
		{
			return 3;
		}
		//邮箱输入
		if(*x>=344&&*x<=584&&*y>=530&&*y<=560&&*buttons)
		{
			return 4;
		}
		//获取验证码
		if(*x>=584&&*x<=690&&*y>=530&&*y<=560&&*buttons)
		{
			return 5;
		}
		//注册并登录
		if(*x>=468&&*x<=580&&*y>=710&&*y<=752&&*buttons)
		{
			return 7;
			//yanzheng
		}
        //返回键
		if(*x>=75&&*x<=125&&*y>=75&&*y<=125&&*buttons)
		{
			return 8;
		}


         key=0;

		/*吸收键盘缓冲区数据*/
		if (kbhit() != 0)
		{
			key = bioskey(0);
		}

		/*按esc则退出*/
		if(key == 0x11b)
		{
			exit(0);
		}
		/*按了回删键*/
            if(key == 0xe08)	//点击退格键时的操作
            {
                if(p != veri)		//检测是否是首位（地址是否相同）
                {
                    bar(349+ i * 18, 620, 375+ i * 18, 650,65535);
                    p--;			//指针		往前移
                    i--;			//记字数	往前移
                }
                *p = '\0';			//	同样将最后一位换成'\0'
            }
            //	将按键对应的字符一个个存入ph_num数组中

            ch = searchKeyValue(key);
            temp[0] = ch;
            if (ch != '\0'&&i<10)
            {
                outtextxy(349+i*18,627,temp,1,1,8,0);

                //	将字符存入数组中
                *p = ch;
                p++;
                *p = '\0';		// 每次操作都要归'\0'
                i++;

            }





	}

}
int UserRegist(USERS *head,char *account,char *code,int *x,int *y,int *buttons)
{
	int judge = 0; //判断应该调用那些函数的变量
	int flag1 = 0, flag2 = 0, flag3 = 0,flag4=0;  //分别为为用户名、密码、二次密码是否正确的判断变量
	int temp;  //用于吸收键盘缓冲区的变量
	char secondcode[11];  //第二次输入密码串
	char mail[20]={0};
	char real_veri[5]={0};
	char veri[5]={0};
	FILE *fp=NULL;    //用于打开usercode.txt的文件指针


	/*必要的初始化过程*/
	secondcode[0] = '\0';
	*account = '\0';
	*code = '\0';
	mousehide(*x,*y);         //画鼠标
    zhuce_page();              //登录界面
	reset_mouse(x,y);         //存鼠标样子
	while (1)
	{

        newxy(x, y, buttons);//在新的位置画鼠标
        //账号输入
		if(*x>=344 &&*x<=690&&*y>=260&&*y<=290&&*buttons)
		{
			judge= 1;
		}
		//密码
		if(*x>=344&&*x<=690&&*y>=350&&*y<=380&&*buttons)
		{
			judge= 2;
		}
		//二次确认密码
		if(*x>=344&&*x<=690&&*y>=440&&*y<=470&&*buttons)
		{
			judge= 3;
		}
		//邮箱输入
		if(*x>=344&&*x<=584&&*y>=530&&*y<=560&&*buttons)
		{
			judge= 4;
		}
		//获取验证码
		if(*x>=584&&*x<=690&&*y>=530&&*y<=560&&*buttons)
		{
			judge= 5;
		}
		//输入验证码
		if(*x>=344&&*x<=690&&*y>=620&&*y<=650&&*buttons)
		{
			judge= 6;
		}
		//注册并登录
		if(*x>=468&&*x<=580&&*y>=710&&*y<=752&&*buttons)
		{
			judge= 7;
			//yanzheng
		}
        //返回键
		if(*x>=75&&*x<=125&&*y>=75&&*y<=125&&*buttons)
		{
			judge= 8;
		}

		switch(judge)
		{

		//调用账号输入函数
		case 1:
		    judge = RegisteraccountsInput(account, x, y);
		    if (SearchAccounts(head, account) != NULL)
			{
			    bar(695,260,750,290,50712);      //清空×勾的位置处的图像
				red_cross(700,275);
				fdhz(450,242,1,1,"该账号已被注册",0);
				flag1 = 0;
			}
		    else
			{
                bar(695,260,750,290,50712);      //清空×勾的位置处的图像
                bar(440,241,690,259,50712);      //清空“该账号已被注册”
                green_tick(700,275);
				flag1 = 1;

			}
			break;
		/*case 2:调用密码输入函数*/
		case 2:
			judge = RegistercodeInput(code, x, y);
			if (strlen(code) < 6)
			{
				/*画红色的叉并提示密码不得少于六位&flag2=0*/
				bar(695,350,750,380,50712);      //清空×勾的位置处的图像
                bar(440,331,690,349,50712);      //清空“密码不得少于六位”
                red_cross(700,365);
				fdhz(442,332,1, 1, "密码不得少于六位",  0);
				flag2 = 0;
			}
			else
			{
				/*画一个绿色的勾&flag2=1*/
				bar(695,350,750,380,50712);      //清空×勾的位置处的图像
                bar(440,331,690,349,50712);      //清空“密码不得少于六位”
                green_tick(700,365);
				flag2 = 1;
			}
			break;

		/*case 3:调用二次密码输入函数*/
		case 3:
			judge = RegistersecondcodeInput(secondcode, x, y);
			if (strcmp(code, secondcode) != 0)
			{
				/*画红色的叉并提示两次密码输入不同&&flag3=0*/
				bar(695,440,750,470,50712);      //清空×勾的位置处的图像
                bar(400,421,690,439,50712);      //清空“两次输入的密码不同”

                red_cross(700,455);
				fdhz(442,422, 1, 1, "两次输入的密码不同", 0);
				flag3 = 0;
			}
			else
			{
				/*画一个绿色的勾&flag3=1*/
				bar(695,440,750,470,50712);      //清空×勾的位置处的图像
                bar(400,421,690,439,50712);      //清空“两次输入的密码不同”
                green_tick(700,455);

				flag3 = 1;
			}
			break;

		/*case 4:邮箱输入*/
		case 4:
		    judge=mail_input(mail,x,y);
            break;

	    /*case 5:获取验证码*/
		case 5:
		    flag4=get_verification(mail,real_veri);
		    judge=4;
		    break;


        /*case 6:验证码输入*/
        case 6:
            judge=verification_input(veri, x, y);
            break;

        /*case 7:完成注册键*/
        case 7:
            if (regist_success(real_veri, veri) && flag1 && flag2 && flag3 && flag4)
            {
                AddNewUser(head,account,code);   //计入文件
                bar(695,620,750,650,50712);      //清空×勾的位置处的图像
                bar(400,601,690,619,50712);      //清空“验证码不正确”
                dis_iph(x,y);
            }
            else
            {
                bar(695,620,750,650,50712);      //清空×勾的位置处的图像
                bar(400,601,690,619,50712);      //清空“验证码不正确”

                red_cross(700,635);
				fdhz(622,602, 1, 1, "验证码不正确", 0);
            }
            break;
        case 8:
            enterpage();
            break;

		}

	}
}

int sign_in_check(USERS *head,char *account,char *code)
{
	char *rightcode= NULL;
	rightcode = SearchAccounts(head, account);
	if (rightcode != NULL &&strcmp(rightcode, code) == 0)
		return 1; //登录成功
	else
	{
		fdhz(410, 500,1, 1, "用户名或密码输入错误", 0);
        getch();
		return 5;
	}
}


int regist_success(char *real_veri, char *veri)
{
    int p=0;
    if (strcmp(real_veri,veri)==0)
    {
        p=1;
    }
    return p;
}
/**************************************************************
       返回1在userRegister中调用RegisteraccountsInput函数
       返回2在userRegister中调用RegistercodeInput函数
	   返回3在userRegister中使用RegistersecondcodeInput
	   返回4在userRegister中使用邮箱输入功能
	   返回5在userRegister中使用验证码获得功能
	   返回6在userRegister中使用验证码输入功能
	   返回7在userRegister中使用登陆功能
	   返回8在userRegister中返回
*************************************************************/

int area_choose(int *x,int *y,int *buttons)
{

        newxy(x, y, buttons);//在新的位置画鼠标

		//账号输入
		if(*x>=344 &&*x<=690&&*y>=260&&*y<=290&&*buttons)
		{
			return 1;
		}
		//密码
		if(*x>=344&&*x<=690&&*y>=350&&*y<=380&&*buttons)
		{
			return 2;
		}
		//二次确认密码
		if(*x>=344&&*x<=690&&*y>=440&&*y<=470&&*buttons)
		{
			return 3;
		}
		//邮箱输入
		if(*x>=344&&*x<=584&&*y>=530&&*y<=560&&*buttons)
		{
			return 4;
		}
		//获取验证码
		if(*x>=584&&*x<=690&&*y>=530&&*y<=560&&*buttons)
		{
			return 5;
		}
		//输入验证码
		if(*x>=344&&*x<=690&&*y>=620&&*y<=650&&*buttons)
		{
			return 6;
		}
		//注册并登录
		if(*x>=468&&*x<=580&&*y>=710&&*y<=752&&*buttons)
		{
			return 7;
			//yanzheng
		}
        //返回键
		if(*x>=75&&*x<=125&&*y>=75&&*y<=125&&*buttons)
		{
			return 8;
		}


}

int whether_mail(char *str)
{
    int p=0;
    if (strstr(str,"aqq.com"))
    {
        p=1;
    }
    return p;
}
