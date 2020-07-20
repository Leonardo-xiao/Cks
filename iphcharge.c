/*****************修改日志**************************
7.20：119、149行左右，对charge_move_forward和charge_move_back函数的注释部分做进一步注释。这里没有想改的，除了界面。




******************函数清单***************************
1.  void charge_ui();
2.	void  charging(int battery);
3.	void charge_move_forward(ROBOT_CASE *robot_position, int *x, int *y);
4.	void charge_move_back(ROBOT_CASE *robot_position, int rec_x, int rec_y, int rec_floor, int *x, int *y);
5.	void charge_main(ROBOT_CASE *robot_position,int *x,int *y);
6.	int iphcharge_click(int *mx,int *my,int *button);
7.	void battery_show(ROBOT_CASE *robot_position, int battery, int *x, int *y);
*****************************************************/
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
#include"chatGame.h"
#include"iphCmfrt.h"
#include"mysystem.h"
#include"main.h"

#define SCREENCENTER_x 894 
#define SCREENCENTER_y 493
#define SCREENLENGTH 250 
#define SCREENHEIGHT 541
#define ORIGINX 767
#define ORIGINY 221
#define FINALX 1019
#define FINALY 764

/**************

	充电界面

**************/
void charge_ui(void)
{
	iph_frame(36410);
	bar(SCREENCENTER_x-30, SCREENCENTER_y-100,SCREENCENTER_x+30,SCREENCENTER_y+100,0);
	bar(SCREENCENTER_x-28, SCREENCENTER_y-90,SCREENCENTER_x+28,SCREENCENTER_y+90,65535);
	bar(SCREENCENTER_x-10, SCREENCENTER_y-105,SCREENCENTER_x+10,SCREENCENTER_y-100,0);
	//主页图标（双圆环
	FillCircle(ORIGINX+128, ORIGINY+509, 24, 65535);
	FillCircle(ORIGINX+128, ORIGINY+509, 21, 36410);	//138 198 210
	FillCircle(ORIGINX+128, ORIGINY+509, 19, 65535);
	
	
}

/**************

	充电动画

**************/
void  charging(int battery)
{
	int i;	//counting
	int delta_battery = 180-battery;	//便于修改house状态
	
	fdhz(SCREENCENTER_x-50,SCREENCENTER_y-150,2,2,"充电中",65535);
	//充电动画
	for(i=battery;i<180;i++)
	{
		if(i<100){
			bar(SCREENCENTER_x-28, SCREENCENTER_y+90-i,SCREENCENTER_x+28,SCREENCENTER_y+90,63488);
		}
		else{
			bar(SCREENCENTER_x-28, SCREENCENTER_y+90-i,SCREENCENTER_x+28,SCREENCENTER_y+90,2016);
		}
		
		delay0(50);
	}
	//改字
	bar(SCREENCENTER_x-50,SCREENCENTER_y-170,SCREENCENTER_x+80,SCREENCENTER_y-120,36410);
	fdhz(SCREENCENTER_x-90,SCREENCENTER_y-150,2,2,"充电完成",65535);
	
	ChangeHouse(25,delta_battery);	//告知结构体已满电
}

/**************

	走到该走的地方//不要二楼、花园，可以删除部分

**************/
void charge_move_forward(ROBOT_CASE *robot_position, int *x, int *y)
{
	switch((*robot_position).position)	//判断在几楼
	{
		case 0:	//在花园
		{
			aimmove(robot_position,0,(*robot_position).x,(*robot_position).y,11,10,x,y);
			aimmove(robot_position,1,(*robot_position).x,(*robot_position).y,9,8,x,y);
			break;
		}
		case 1:	//在一楼
		{
			aimmove(robot_position,1,(*robot_position).x,(*robot_position).y,9,8,x,y);
			break;
		}
		case 2:	//在二楼
		{
			
			break;
		}
		
	}
	aimmove(robot_position,2,(*robot_position).x,(*robot_position).y,9,9,x,y);
}

/**************

	回到该回的地方//不要二楼、花园，可以删除部分

**************/
void charge_move_back(ROBOT_CASE *robot_position, int rec_x, int rec_y, int rec_floor, int *x, int *y)
{
	switch(rec_floor)
	{
		case 0:	//若要去花园则先下一楼再出花园
		{
			aimmove(robot_position,2,(*robot_position).x,(*robot_position).y,6,4,x,y);
			aimmove(robot_position,1,(*robot_position).x,(*robot_position).y,1,10,x,y);
			break;
		}
		case 1:	//下一楼
		{
			aimmove(robot_position,2,(*robot_position).x,(*robot_position).y,6,4,x,y);	
			break;
		}
		case 2:	//不动
		{
			break;
		}
		
	}
	aimmove(robot_position,rec_floor,(*robot_position).x,(*robot_position).y,rec_x,rec_y,x,y);
}

/**************

	充电主逻辑

**************/
void charge_main(ROBOT_CASE *robot_position,int *x,int *y)
{
	int rec_x = (*robot_position).x;	//记录机器人充点前的初始位置
	int rec_y = (*robot_position).y;	//方便之后回到该点继续做事
	int rec_floor = (*robot_position).position;
	int battery = CheckHouse(25);	//充电前电量
	
	mousehide(*x,*y);
	
	save_image(ORIGINX, ORIGINY, FINALX, FINALY);	//保存正在进行的任务界面
	charge_ui();	//电池界面
	reset_mouse(x,y);
	fdhz(SCREENCENTER_x-16,SCREENCENTER_y-70,2,2,"电",25388);	//汉字
	fdhz(SCREENCENTER_x-16,SCREENCENTER_y-30,2,2,"量",25388);
	fdhz(SCREENCENTER_x-16,SCREENCENTER_y+10,2,2,"不",25388);
	fdhz(SCREENCENTER_x-16,SCREENCENTER_y+50,2,2,"足",25388);
	
	ChangeHouse(26,1);	//告知正在前往充电的路上，可不用检测
	charge_move_forward(robot_position, x, y);	//前往充电桩
	charging(battery);	//充电动画
	delay(1000);		//屏幕定住
	mousehide(*x,*y);
	printf_image(ORIGINX, ORIGINY, FINALX, FINALY);		//继续之前的任务界面
	charge_move_back(robot_position, rec_x, rec_y, rec_floor, x, y);	//回到原来做任务的地点
	ChangeHouse(26,0);	//恢复未充电状态
	
	reset_mouse(x,y);
}

/**************

	鼠标点击位置检测 

**************/
int iphcharge_click(int *mx,int *my,int *button)
 {
	 /*********
	按钮位置标准化
	将所有可能的按钮位置坐标储存在二维数组中
	*********/
	int a[3][4];
	a[0][0] = 0;	//	a[0][]:点击左上角退出程序
	a[0][1]	= 20;
	a[0][2]	= 0;
	a[0][3] = 20;
	
	a[1][0] = SCREENCENTER_x-20;		//	a[1][]:点击充电按钮 
	a[1][1] = SCREENCENTER_x+20;
	a[1][2] = ORIGINY+400;
	a[1][3] = ORIGINY+420;

	a[2][0] = ORIGINX+100;		//	a[2][]:点击【主页】回到主页				
	a[2][1]	= ORIGINX+155;
	a[2][2]	= ORIGINY+485;
	a[2][3] = ORIGINY+535;	

	
	     if (*mx >= a[0][0] && *mx <= a[0][1] && *my >= a[0][2] && *my <= a[0][3] && *button)	return 1;   //if(鼠标点击退出区域)
	else if (*mx >= a[1][0] && *mx <= a[1][1] && *my >= a[1][2] && *my <= a[1][3] && *button)	return 2;   //if(鼠标点击【窗户】)
	else if (*mx >= a[2][0] && *mx <= a[2][1] && *my >= a[2][2] && *my <= a[2][3] && *button)	return 3; 	//if(鼠标点击【主页】)
	else return 0;
 }
 
/**************

	电量显示页面

**************/
void battery_show(ROBOT_CASE *robot_position, int battery, int *x, int *y)
{
	int buttons;
	int click;
	int state = 1;//如果点击主页之后state变为0，退出循环

	charge_ui();
	//显示当前电量
	if(battery<100){
		bar(SCREENCENTER_x-28, SCREENCENTER_y+90-battery,SCREENCENTER_x+28,SCREENCENTER_y+90,63488);
	}
	else{
		bar(SCREENCENTER_x-28, SCREENCENTER_y+90-battery,SCREENCENTER_x+28,SCREENCENTER_y+90,2016);
	}
	
	mousehide(*x,*y);
	//充电按钮ui
	bar_round_2(SCREENCENTER_x-20,ORIGINY+400,SCREENCENTER_x+20,ORIGINY+420,10,1,65535);
	fdhz(SCREENCENTER_x-18,ORIGINY+402,1,1,"充",36410);
	fdhz(SCREENCENTER_x+2,ORIGINY+402,1,1,"电",36410);
	
	reset_mouse(x,y);
	while(1)
	{
		newxy(x,y,&buttons);
		
		click = iphcharge_click(x,y,&buttons);
		switch(click)
		{
			case 0:	
					break;
			case 1:
					exit(0);
					break;
			case 2:
					ChangeHouse(26,1);
					mousehide(*x,*y);
					charge_move_forward(robot_position, x, y);
					charging(battery);
					reset_mouse(x,y);
					ChangeHouse(26,0);
					break;
			case 3:		//主页
					ph_main();	//回去
					state = 0;	//可退出此鼠标检测循环
					break;
		}
		
		
		//判断是否可以退出循环
		if(state == 0){
			break;
		}
	}
	
}
