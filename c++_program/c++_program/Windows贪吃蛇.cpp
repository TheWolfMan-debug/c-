#include <windows.h>
#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>

#define SIZE 30                                          //指定游戏地图大小为20*20
#define WIDTH 30                                         //指定每个格子的大小
#define FPS 10                                           //每秒刷新多少次
#define SPEED 3                                          //每刷新多少次蛇移动一格 

HWND m_hwnd;                                             //窗口句柄，唯一标示游戏窗口
int g_nWidth = WIDTH*SIZE+10, g_nHeight = WIDTH*SIZE+30; //指定窗口大小
int map[SIZE][SIZE];                                     //地图数组,值为0表示空,1表示蛇身,2表示苹果
std::vector<int> x,y;                                    //用于保存蛇身体每一个部位的位置
int ax,ay;                                               //苹果的位置
int px,py;                                               //最后一次蛇经过的位置,用于吃过苹果后加长蛇身
int dir;                                                 //表明当前方向
unsigned long tk;                                   //游戏ticket数,即已经过多少逻辑帧
bool lock;                                               //操作锁,防止一次刷新操作两次 

void init()                                              //初始化参数
{	
	srand((unsigned)time(NULL));	
	tk = 0;	
	dir = 2;	
	x.push_back(0);	
	y.push_back(0);	
	px = py = 0;	
	ax = -1;	
	memset(map,0,sizeof(map));	
	map[0][0] = 1;	
	lock = false;
} 

void gameover()                                          //输了时调用
{
	MessageBox(m_hwnd,TEXT("你输了"),TEXT("游戏结束"),MB_OK); //弹窗	
	x.clear();                                                //重新初始化	
	y.clear();	
	init();
} 

void youwin()                                                //赢了时调用
{
	MessageBox(m_hwnd, TEXT("你赢了"), TEXT("游戏结束"),MB_OK);
	x.clear();	
	y.clear();	
	init();
} 

void move(int d)                                            //调用次函数以移动
{
	if(d == 0&&x[0]>0)                                      //当移动方向为上并且移动合法时,保存并去掉蛇尾,加一格蛇头	
	{
		x.insert(x.begin(),x[0]-1);		
		px = x[x.size()-1];		
		x.erase(x.begin()+x.size()-1);		
		y.insert(y.begin(),y[0]);		
		py = y[y.size()-1];		
		y.erase(y.begin()+y.size()-1);	
	}	
	else if(d == 0&&x[0]<=0)gameover();                    //当移动不合法时游戏结束	
	else if(d == 2&&x[0]<SIZE-1)
	{		
		x.insert(x.begin(),x[0]+1);		
		px = x[x.size()-1];		
		x.erase(x.begin()+x.size()-1);		
		y.insert(y.begin(),y[0]);		
		py = y[y.size()-1];		
		y.erase(y.begin()+y.size()-1);	
	}	
	else if(d == 2&&x[0]>=SIZE-1)gameover();	
	else if(d == 1&&y[0]>0)
	{		
		x.insert(x.begin(),x[0]);		
		px = x[x.size()-1];		
		x.erase(x.begin()+x.size()-1);		
		y.insert(y.begin(),y[0]-1);		
		py = y[y.size()-1];		
		y.erase(y.begin()+y.size()-1);	
	}	
	else if(d == 1&&y[0]<=0)gameover();	
	else if(d == 3&&y[0]<SIZE-1)
	{		
		x.insert(x.begin(),x[0]);		
		px = x[x.size()-1];		
		x.erase(x.begin()+x.size()-1);		
		y.insert(y.begin(),y[0]+1);		
		py = y[y.size()-1];		
		y.erase(y.begin()+y.size()-1);	
	}	
	else if(d == 3&&y[0]>=SIZE-1)gameover();
}

void update()                                          //游戏更新主逻辑,每帧调用此函数
{	
	if(tk%SPEED==0)                                    //每隔SPEED间隔帧移动一次
	{		
		move(dir);		
		lock = false;	
	}	
	if(x[0]==ax&&y[0]==ay)                             //如果吃到了苹果
	{
		x.push_back(px);                               //加蛇尾		
		y.push_back(py);		
		ax = -1;                                       //去掉苹果	
	}	
	if(x.size()>=SIZE*SIZE)                            //如果蛇的长度大于等于地图大小,游戏结束
	{	
		youwin();		
		return;	
	}	
	memset(map,0,sizeof(map));                         //刷新地图	
	for(int i = 0; i < x.size(); i++)
	{		
		if(map[x[i]][y[i]]==0)map[x[i]][y[i]] = 1;     //如果没有蛇身阻挡则放置蛇身		
		else                                           //否则游戏结束
		{
			gameover();			
			return;		
		}	
	}	
	if(ax==-1)                                        //苹果被吃,刷新苹果	
	{
		ax = rand()%SIZE;		
		ay = rand()%SIZE;		
		while(map[ax][ay]==1)
		{			
			ax = rand()%SIZE;			
			ay = rand()%SIZE;		
		}	
	}	
	map[ax][ay] = 2;	
	tk++;
}                                                   /* 此函数用于处理窗口接受的所有消息 */

LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam)
{	
	switch(Message)                                /* Upon destruction, tell the main thread to stop */	
	{				
		case WM_DESTROY:
		{			
			PostQuitMessage(0);			
			break;		
		}				
		case WM_KEYDOWN:                          //当收到按键消息	
		{		
			if(!lock)                            //且操作锁没有锁上,则改变蛇的移动方向并上锁
			{				
				if(wParam == VK_UP&&(dir-0)%2!=0)
				{					
					dir = 0;					
					lock = true;				
				}				
				else if(wParam == VK_DOWN&&(dir-2)%2!=0)
				{					
					dir = 2;					
					lock = true;				
				}				
				else if(wParam == VK_LEFT&&(dir-1)%2!=0)
				{					
					dir = 1;					
					lock = true;				
				}				
				else if(wParam == VK_RIGHT&&(dir-3)%2!=0)
				{					
					dir = 3;					
					lock = true;				
				}			
			}			
			if(wParam == VK_ESCAPE)PostQuitMessage(0);                //如果是ESC键则退出			
				break;                                                /* All other messages (a lot of them) are processed using default procedures */			
		}					
		default:			
			return DefWindowProc(hwnd, Message, wParam, lParam);	
	}	
	return 0;
} 

void render()                                                         //渲染函数,用于绘制游戏图像
{     
	HDC hDC = GetDC(m_hwnd);                                          //定义窗口句柄的DC      
	HDC memDC = CreateCompatibleDC(0);                                //定义兼容DC     
	HBITMAP bmpBack = CreateCompatibleBitmap(hDC,g_nWidth,g_nHeight); //定义位图画布    
	SelectObject(memDC,bmpBack);      
	HPEN penBack = CreatePen(PS_SOLID,1,RGB(0,0,0));                  //定义画笔    
	SelectObject(memDC,penBack);     
	HBRUSH brushBack = CreateSolidBrush(RGB(255,255,255));            //定义背景画刷    
	SelectObject(memDC,brushBack);     
	RECT rcClient;   
	GetClientRect(m_hwnd,&rcClient);  
	FillRect(memDC,&rcClient,brushBack);                             //用背景画刷以矩形填充整个窗口   
	HBRUSH brushObj = CreateSolidBrush(RGB(255,0,0));                //定义蛇身画刷  
	HBRUSH brushApple = CreateSolidBrush(RGB(0,0,255));              //定义苹果画刷   
	int dw = WIDTH;    
	int rows = SIZE;    
	int cols = SIZE;     
	for (int r=0; r<rows; ++ r)                                     //绘制整个矩阵 
	{ 
		for (int c=0; c<cols; ++c)
		{              
			if (map[r][c]==1)
			{                  
				SelectObject(memDC,brushObj);            
			}            
			else if(map[r][c] == 2)
			{            	
				SelectObject(memDC,brushApple);			
			}            
			else
			{                 
				SelectObject(memDC,brushBack);              
			}             
			Rectangle(memDC,c*dw,r*dw,(c+1)*dw,(r+1)*dw);          
		}      
	}        
	DeleteObject(brushObj);                                         //释放资源    
	BitBlt(hDC,0,0,g_nWidth,g_nHeight,memDC,0,0,SRCCOPY);    
	DeleteObject(penBack);   
	DeleteObject(brushBack);    
	DeleteObject(bmpBack);    
	DeleteDC(memDC); 
	ReleaseDC(m_hwnd,hDC);
}  

DWORD WINAPI startLoop(LPVOID lpParamter)                          //开始主循环,定义这个函数是为了多线程运行,函数名随意,函数格式一定 
{ 
	while(1)
	{		
		update();		
		render();		
		Sleep(1000/FPS);	
	}   
	return 0L;
}                                                                 /* windows编程的主函数 */

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) 
{	
	WNDCLASSEX wc;                                      /* A properties struct of our window */	
	HWND hwnd;                                          /* A 'HANDLE', hence the H, or a pointer to our window */	
	MSG msg;                                            /* A temporary location for all messages */ 	
	                                                    /* zero out the struct and set the stuff we want to modify */	
	memset(&wc,0,sizeof(wc));	
	wc.cbSize = sizeof(WNDCLASSEX);	
	wc.lpfnWndProc	 = WndProc;                         /* This is where we will send messages to */	
	wc.hInstance	 = hInstance;	
	wc.hCursor		 = LoadCursor(NULL, IDC_ARROW);		/* White, COLOR_WINDOW is just a #define for a system color, try Ctrl+Clicking it */	
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);	
	wc.lpszClassName = "WindowClass";	
	wc.hIcon		 = LoadIcon(NULL, IDI_APPLICATION); /* Load a standard icon */	
	wc.hIconSm		 = LoadIcon(NULL, IDI_APPLICATION); /* use the name "A" to use the project icon */ 	
	if(!RegisterClassEx(&wc)) 
	{		
		MessageBox(NULL, TEXT("Window Registration Failed!"), TEXT("Error!"),MB_ICONEXCLAMATION|MB_OK);
		return 0;	
	} 	
	hwnd = CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("WindowClass"), TEXT("Oh"),WS_VISIBLE|WS_EX_STATICEDGE,CW_USEDEFAULT,CW_USEDEFAULT,g_nWidth,g_nHeight,NULL,NULL,hInstance,NULL);
	if(hwnd == NULL) 
	{		
		MessageBox(NULL, TEXT("Window Creation Failed!"), TEXT("Error!"),MB_ICONEXCLAMATION|MB_OK);
		return 0;	
	}		
	m_hwnd = hwnd;	init();                                            //初始化 	
	HANDLE hThread = CreateThread(NULL, 0, startLoop, NULL, 0, NULL);  //创建线程       
	CloseHandle(hThread);                                              //释放线程句柄 	
																	   /* This is the heart of our program where all input is processed and sent to WndProc. 
																	      Note that GetMessage blocks code flow until it receives something, 
																	      so this loop will not produce unreasonably high CPU usage */	
	while(GetMessage(&msg, NULL, 0, 0) > 0)                            /* If no error is received... */
	{
		TranslateMessage(&msg);                                        /* Translate key codes to chars if present */		
		DispatchMessage(&msg);                                         /* Send it to WndProc */	
	}	
	return msg.wParam;
}