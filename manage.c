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
/********************************
系统主进程，调用各种功能(service,control,iphchrge,iphCmfrt)
void mainprocess(int *x,int *y);
********************************/
void mainprocess(int *x,int *y)
{
	int button;
	int click;
	int i;
	int judge=0;
	SAVE save;

	/*初始化机器人*/
	ROBOT_CASE robot_position;
	/*退出按钮*///20181115
	BUTTONS esc1;
   /*退出按钮初始化*/
	esc_init(&esc1);
    /*初始化机器人位置方向，四肢状态*/
	robot_position.x = 5;
	robot_position.y = 3;
	robot_position.xpixel = 220;//+20偏移量
	robot_position.ypixel = 174;//+54偏移量
	robot_position.direction = 4;
	robot_position.position = 1;
	robot_position.leg = 0;
	robot_position.leg_left = 0;
	robot_position.leg_right = 0;
	robot_position.hand = 0;
	robot_position.hand_left = 0;
	robot_position.hand_right = 0;
	/*分配机器人图像空间*/
	(robot_position).cat = (unsigned int*)malloc(64*77*sizeof(unsigned int));

    /*分配垃圾图像空间*/
	save.trashsave1 = (unsigned int *)malloc(40*40*sizeof(unsigned int));
	save.trashsave2 = (unsigned int *)malloc(40*40*sizeof(unsigned int));
	save.trashsave3 = (unsigned int *)malloc(40*40*sizeof(unsigned int));
	
	/*检查分配是否成功*/
	if((robot_position).cat==NULL)
	{
		overflow_box(500,500);//报错
		getch();
		exit(1);
	}

	if(save.trashsave1==NULL)
	{
		overflow_box(500,500);
		getch();
		exit(1);
	}
	if(save.trashsave2==NULL)
	{
		overflow_box(500,500);
		getch();
		exit(1);
	}
	if(save.trashsave3==NULL)
	{
		overflow_box(500,500);
		getch();
		exit(1);
	}

	
	
    /*绘制地图，手机主界面*/
	mousehide(*x,*y);
	_ground();
	ph_main();
    /*获取机器人背景并绘制机器人*/
	get_image((robot_position).xpixel-32,(robot_position).ypixel-80,(robot_position).xpixel+32,(robot_position).ypixel-3,(robot_position).cat);
	forebodyhead(robot_position);
	/*重置鼠标*/
	reset_mouse(x,y);

	while(1)
	{

		newxy(x,y,&button);

		/*检查是否点击退出按钮*/
		judge = esc_check(&esc1,x,y,&button);
		
        /*检测点击功能区域*/
		click = iphmain_click(x,y,&button);

		switch(click)
		{
			case 0:
			{
				break;
			}
			/*移动功能*/
			case 2:
			{
				move_one_step(&robot_position,x,y);
				break;
			}
			/*聊天功能*/
			case 3:
			{
				chat_main();
				break;
			}
			/*卫生功能*/
			case 4:
			{
				judge=clean_control(&robot_position,&esc1,&save,x,y);
				break;
			}
			/*舒适功能*/
			case 5:
			{
				comfort_control(&robot_position,&save,x,y);
				break;
			}
			/*便捷功能*/
			case 6:
			{
				judge=easy_control(&robot_position,&esc1,&save,x,y);
				break;
			}
			/*安全功能*/
			case 7:
			{
				judge=move_control(&robot_position,&esc1,x,y);
				break;
			}
			/*充电功能*/
			case 8:
			{
				battery_show(&robot_position,CheckHouse(25),x,y);
                break;
			}
			
		}
		/*若点击退出系统，则跳出循环*/
		if(judge==1)
		{
			break;
		}
    }
	/*释放分配的内存空间*/
	free((robot_position).cat);
	free(save.trashsave1);
	free(save.trashsave2);
	free(save.trashsave3);
	/*将指针置空*/
	(robot_position).cat = NULL;
	save.trashsave1 = NULL;
	save.trashsave2 = NULL;
	save.trashsave3 = NULL;
}
