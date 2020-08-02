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
#define PI 3.1415926

/*****************************
欢迎界面，登录注册界面及调用相关函数的逻辑（相关函数在filefun,sign中）
void outwelcome(void);
void load_page(void);
void zhuce_page(void);
int enterpage(void);
int mainpage(void)
void logo_robot(ROBOT_CASE robot_position);
******************************/
/*欢迎界面，天空，机器人，街道和房子*/
void outwelcome(void)
{
    /*
	/*背景图
	linever_color(0,0,1024,500,0,191,255,255,222,173);
	/*立体字效果
	fdhz(78,78,4,4,"家居机器人模拟器",65535);
	fdhz(82,78,4,4,"家居机器人模拟器",65535);
	fdhz(78,82,4,4,"家居机器人模拟器",65535);
	fdhz(82,82,4,4,"家居机器人模拟器",65535);
	fdhz(80,80,4,4,"家居机器人模拟器",transcolor(0,191,255));
	机器人
	FillCircle(250,450,120,255);
	FillCircle(250,480,96,65535);
	circle(250,480,96,0);
	fill_bow_right_down(250,450,70,transcolor(255,0,0));
    fill_bow_left_down(250,450,70,transcolor(255,0,0));
	bow_left_down(250,450,70,0);
    bow_right_down(250,450,70,0);
	fill_bow_down(250,350,120,65535);
	fill_bow_right_up(250,520,40,transcolor(240,128,128));
	fill_bow_left_up(250,520,40,transcolor(240,128,128));
	Fillellipse(223,365,223,385,25,65535);
	Fillellipse(277,365,277,385,25,65535);
	ellipse(223,365,223,385,25,0);
	ellipse(277,365,277,385,25,0);
	Fillellipse(230,360,230,380,8,0);
	Fillellipse(270,360,270,380,8,0);
	FillCircle(230,365,4,65535);
	FillCircle(270,365,4,65535);
	FillCircle(250,420,20,40966);


	/*街道
	bar(0,500,1024,768,transcolor(168,168,168));
	theta_bar(130,768,250,375,-45,transcolor(105,105,105));
	theta_bar(380,768,245,210,-45,transcolor(105,105,105));
	theta_bar(400,500,250,400,45,transcolor(105,105,105));
	theta_bar(410,600,250,400,45,transcolor(105,105,105));

	theta_bar(135,768,70,120,-45,transcolor(220,220,220));
	theta_bar(273,630,60,80,-45,transcolor(220,220,220));
	theta_bar(363,540,50,40,-45,transcolor(220,220,220));

	theta_bar(608,513,50,40,45,transcolor(220,220,220));
	theta_bar(653,570,60,80,45,transcolor(220,220,220));
	theta_bar(760,683,70,120,45,transcolor(220,220,220));

	/*房子
	bar(700,400,900,500,0);
	bar(701,400,899,500,transcolor(205,133,63));
	window_close(20,11);
	linelevel(700,405,900,405,1,0);
	linelevel(700,402,900,402,1,0);
	bar(700,406,710,500,65535);
	bar(890,406,900,500,65535);
	bar(700,300,900,400,transcolor(205,133,63));
	bar(700,300,710,400,65535);
	bar(890,300,900,400,65535);
	linelevel(710,395,890,395,1,0);
	linelevel(710,392,890,392,1,0);
	triangle2(800,220,70,transcolor(165,42,42));
	bar(650,290,950,300,65535);
	*/
	ROBOT_CASE robot_position;
	int i;
	int key;
    char *str;
    char t[2];
    unsigned int *image_save=(unsigned int *)malloc(708*40*sizeof(unsigned int));	//	保存验证码弹窗背后的图案
    robot_position.xpixel=512;
    robot_position.ypixel=320;
	linever_color(0,0,1024,768,211,211,211,128,128,128);
	fdhz(250,50,3,3,"家",27469);
	fdhz(318,50,3,3,"居",27469);
	fdhz(386,50,3,3,"机",27469);
	fdhz(454,50,3,3,"器",27469);
	fdhz(522,50,3,3,"人",27469);
	fdhz(590,50,3,3,"模",27469);
	fdhz(658,50,3,3,"拟",27469);
	fdhz(726,50,3,3,"器",27469);
    outtextxy(364,120,"iRobot",4,4,48,0);
    get_image(192,600,900,640,image_save);
    logo_robot(robot_position);
    srand((unsigned int)time(0));
    while(1)                         //随机名人名言输出
    {
        put_image(192,600,900,640,image_save);//清空名人名言部分的输出
        i=rand()%5;
        key=0;
        if (i==0)
        {
            str="活着就是为了改变世界，难道还有其他原因吗？";
            fdhz(332,600,1,1,str,0);
            linelevel(650,628,695,628,1,0);
            str="乔布斯";
            fdhz(702,620,1,1,str,0);
        }
        else if (i==1)
        {
            str="要有勇气追随心声，听从直觉。";
            fdhz(372,600,1,1,str,0);
            linelevel(650,628,695,628,1,0);
            str="乔布斯";
            fdhz(702,620,1,1,str,0);
        }
        else if (i==2)
        {
            str="你若能绕过经验，便会有创新之举。";
            fdhz(352,600,1,1,str,0);
            linelevel(650,628,695,628,1,0);
            str="乔布斯";
            fdhz(702,620,1,1,str,0);
        }
        else if (i==3)
        {
            str="领袖和跟风者的区别就在于创新。";
            fdhz(372,600,1,1,str,0);
            linelevel(650,628,695,628,1,0);
            str="乔布斯";
            fdhz(702,620,1,1,str,0);
        }
        else if (i==4)
        {
            str="佛教中有一句话：初学者的心态；拥有初学者的心态是件了不起的事情。";
            fdhz(212,600,1,1,str,0);
            linelevel(650,628,695,628,1,0);
            str="乔布斯";
            fdhz(702,620,1,1,str,0);
        }
        gets(t);         //输入完之后还要点一次回车
        key=t[0];
        if (key=='r')
        {
            continue;
        }
        else
        {
            break;
        }
    }
    free(image_save);
    image_save=NULL;
}

/*登录界outtextxy(300+i*18,305,temp,2,2,10,0);面（静态）*/
void load_page(void)
{
    ROBOT_CASE robot_position;
    robot_position.xpixel=500;
    robot_position.ypixel=120;
    /*
    bar(0,0,1024,768,1503);
    FillCircle(200,150,80,34429);
    FillCircle(700,300,200,34431);
    */
    linever_color(0,0,1024,768,211,211,211,128,128,128);
    bar_round(500,320,400,50,5,1,65535);//300,295,700,345
    bar_round(500,470,400,50,5,1,65535);
    fdhz(250,310,1,1,"帐",0);
    fdhz(270,310,1,1,"号",0);
    fdhz(250,460,1,1,"密",0);
    fdhz(270,460,1,1,"码",0);
    FillCircle(675,470,22,65535);
    circle(675,470,22,33808);
    circle(675,470,23,33808);
    linelevel(660,470,690,470,2,33808);
    lean_line_thick(690,470,20,225,2,33808);
    lean_line_thick(690,470,20,135,2,33808);
    bar (440,555,560,590,50712);
    fdhz(484,570,1,1,"注册",0);
	   /*
    ar_round(300,600,200,150,20,1,31694);
    bar_round(700,600,200,150,20,1,31694);
    fdhz(240,570,3,3,"登",0);
    fdhz(320,570,3,3,"录",0);
    fdhz(640,570,3,3,"注",0);
    fdhz(720,570,3,3,"册",0);
    */

    logo_robot(robot_position);

}

/*注册界面（静态）*/
void zhuce_page(void)
{
    ROBOT_CASE robot_position;
    robot_position.xpixel=517;
    robot_position.ypixel=90;
	bar(0,0,1024,768,54938);
	bar(80,70,944,695,50712);
	fdhz(296,11,3,3,"欢",0);
	fdhz(392,11,3,3,"迎",0);
	fdhz(488,11,3,3,"新",0);
	fdhz(584,11,3,3,"朋",0);
	fdhz(690,11,3,3,"友",0);
	//bar_round(100,100,50,50,3,1,255);
	bar_round(517,275,346,30,5,1,65535);//用户名     344,260   690,290
    bar_round(517,365,346,30,5,1,65535);//密码       344,350   690,380
    bar_round(517,455,346,30,5,1,65535);//再次输入密码  344,440   690,470
    bar_round(517,545,346,30,5,1,65535);//输入邮箱  344,530   690,560
    bar_round(517,635,346,30,5,1,65535);//输入验证码  344,620   690,650
    bar(584,533,690,557,54938);         //获取验证码    584，533   690，557
	//bar_round(517,540,234,50,5,1,33808);
	logo_robot(robot_position);
	fdhz(280,267,1,1,"帐",0);
	fdhz(300,267,1,1,"号",0);
	fdhz(280,357,1,1,"密",0);
	fdhz(300,357,1,1,"码",0);
	fdhz(240,447,1,1,"确",0);
	fdhz(260,447,1,1,"认",0);
	fdhz(280,447,1,1,"密",0);
	fdhz(300,447,1,1,"码",0);
	fdhz(280,537,1,1,"邮",0);
	fdhz(300,537,1,1,"箱",0);
	fdhz(590,537,1,1,"获取验证码",27469);
	fdhz(260,647,1,1,"验",0);
	fdhz(280,647,1,1,"证",0);
	fdhz(300,647,1,1,"码",0);
	fdhz(468,715,2,2,"完",0);
	fdhz(532,715,2,2,"成",0);
	outtextxy(83,95,"back",1,1,10,65535);
}

/*登录界面逻辑
判断变量judge:
1:登录成功
2:输入id
3:输入password
5：返回登录界面*/
int enterpage(void)
{
	USERS user;
	USERS *head = NULL;
	int temp,error=0;
	int button,x,y,judge=0;
	user.account[0] = '\0';
	user.code[0] = '\0';

	if ((head = (USERS *)malloc(sizeof(USERS))) == NULL)
	{
		overflow_box(500,500);
        getch();
		exit(1);
	}
	CreateUserList(head);
	load_page();                                 //静止登录界面
	mouseInit(&x, &y,&button);
    while(1)

	{
		newxy(&x, &y, &button);
				    /*初始化，接受缓冲区数据*/

		if (kbhit() != 0)
		{
			temp = bioskey(0);
		}

		/*按esc则退出*/
		if(temp == 0x11b)
		{
			exit(0);
		}

		/*登录*/
		if(x>=650&&x<=700&&y<=495&&y>=445&&button)
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
			judge = sign_in_check(head,&user.account,&user.code);

		}


			/*注册*/
		if(x>=440&&x<=560&&y>=555&&y<=590&&button)
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
			judge = UserRegist(head,&user.account,&user.code,&x,&y,&button);
		}

		if(x>=300&&x<=700&&y>=295&&y<=345&&button)
		{
			judge = 2;
		}

		if(x>=300&&x<=700&&y>=445&&y<=495&&button)
		{
			judge = 3;
		}

		if(judge==2)//输入id
		{
			judge = input_account(head,&user.account,&user.code,&x,&y);

		}
		if(judge==3)//输入password
		{
			judge = input_code(head,&user.account,&user.code,&x,&y);
		}
		if(judge==1)
		{
			freeUserlist(&head);
			return 1;
		}
		//返回登录界面
		if(judge==5)
		{
			return 5;
		}

	}
}

/*点击手机进入系统，并开启主进程*/
int mainpage(void)
{
	int fail,x,y;
	bar(1,1,1024,767,65535);

    fail = dis_iph(&x,&y);
    if(fail==-1)
	{
		//以某种方式显示错误
		null_box(500,500);
		getch();
	}
	mainprocess(&x,&y);

}

void logo_robot(ROBOT_CASE robot_position)
{
    //robot_position.ypixel+80~robot_position.ypixel;
                                           //身体前半部分，入口参数是机器人的结构体
	//robot_hand_right(robot_position.xpixel+8,robot_position.ypixel+102,45);
	theta_bar(robot_position.xpixel,robot_position.ypixel+50,(int)(24/sin((double)(45)/180*PI)),(int)(24/sin((double)(45)/180*PI)),45,27469);
	//theta_bar(508,212,(int)(20/sin((double)(45)/180*PI)),(int)(20/sin((double)(45)/180*PI)),45,255);
	FillCircle(robot_position.xpixel+16+(int)(32/tan((double)(45)/180*PI))+2,robot_position.ypixel+80,14,27469);
    //FillCircle(508+(int)(32/tan((double)(45)/180*PI))+4,242-(int)(48*sin((double)(45)/180*PI))-10,6,65535);


	//robot_hand_left(robot_position.xpixel-56,robot_position.ypixel+130,-45);
	/*theta_bar(x,y-30,(int)(12/sin((double)(-1*theta)/180*PI)),(int)(12/sin((double)(-1*theta)/180*PI)),theta,0);
	theta_bar(x,y-30,(int)(10/sin((double)(-1*theta)/180*PI)),(int)(10/sin((double)(-1*theta)/180*PI)),theta,255);
	FillCircle(x+(int)(16/tan((double)(-1*theta)/180*PI))-10,y-(int)(24*sin((double)(-1*theta)/180*PI))-10,7,0);
    FillCircle(x+(int)(16/tan((double)(-1*theta)/180*PI))-10,y-(int)(24*sin((double)(-1*theta)/180*PI))-10,6,65535);*/
    theta_bar(robot_position.xpixel-(int)(24/sin((double)(45)/180*PI)),robot_position.ypixel+50,(int)(24/sin((double)(135)/180*PI)),(int)(24/sin((double)(135)/180*PI)),225,27469);

	FillCircle(robot_position.xpixel-16+(int)(32/tan((double)(-45)/180*PI))-2,robot_position.ypixel+80,14,27469);
	//头
	ever_Fillellipse(robot_position.xpixel-15, robot_position.ypixel+24, robot_position.xpixel+15, robot_position.ypixel+24, 18, 27469);    //先画黑再覆盖，相当于有了轮廓
	//ever_Fillellipse(robot_position.xpixel-15, robot_position.ypixel+24, robot_position.xpixel+15, robot_position.ypixel+24, 16, 65535);

    FillCircle(robot_position.xpixel-15, robot_position.ypixel+24, 6, 54938);   //眼睛
    FillCircle(robot_position.xpixel+15, robot_position.ypixel+24, 6, 54938);
    //不要嘴巴也行
   // bow(robot_position.xpixel-7.5, robot_position.ypixel+12, 7.5/sin(3.14159/12), 0);
    //脚
    bar(robot_position.xpixel-30, robot_position.ypixel+120, robot_position.xpixel+30, robot_position.ypixel+150, 27469);
    //Horizline(robot_position.xpixel-30, robot_position.ypixel+140, 60, 50712);
    linever(robot_position.xpixel, robot_position.ypixel+120, robot_position.xpixel, robot_position.ypixel+150, 1, 50712);
    //身体
	bar(robot_position.xpixel-32, robot_position.ypixel + 38,robot_position.xpixel+32, robot_position.ypixel + 122, 27469);//边框
	//bar(robot_position.xpixel-30, robot_position.ypixel + 40,robot_position.xpixel+30, robot_position.ypixel + 120, 65535);//入口是中心。。。
    circle(robot_position.xpixel, robot_position.ypixel + 80, 20, 50712);   //不填充
    circle(robot_position.xpixel, robot_position.ypixel + 80, 21, 50712);   //不填充
    //Horizline(robot_position.xpixel-30, robot_position.ypixel+120, 60, 0);
}
