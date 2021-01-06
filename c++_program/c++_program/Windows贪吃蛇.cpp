#include <windows.h>
#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>

#define SIZE 30                                          //ָ����Ϸ��ͼ��СΪ20*20
#define WIDTH 30                                         //ָ��ÿ�����ӵĴ�С
#define FPS 10                                           //ÿ��ˢ�¶��ٴ�
#define SPEED 3                                          //ÿˢ�¶��ٴ����ƶ�һ�� 

HWND m_hwnd;                                             //���ھ����Ψһ��ʾ��Ϸ����
int g_nWidth = WIDTH*SIZE+10, g_nHeight = WIDTH*SIZE+30; //ָ�����ڴ�С
int map[SIZE][SIZE];                                     //��ͼ����,ֵΪ0��ʾ��,1��ʾ����,2��ʾƻ��
std::vector<int> x,y;                                    //���ڱ���������ÿһ����λ��λ��
int ax,ay;                                               //ƻ����λ��
int px,py;                                               //���һ���߾�����λ��,���ڳԹ�ƻ����ӳ�����
int dir;                                                 //������ǰ����
unsigned long tk;                                   //��Ϸticket��,���Ѿ��������߼�֡
bool lock;                                               //������,��ֹһ��ˢ�²������� 

void init()                                              //��ʼ������
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

void gameover()                                          //����ʱ����
{
	MessageBox(m_hwnd,TEXT("������"),TEXT("��Ϸ����"),MB_OK); //����	
	x.clear();                                                //���³�ʼ��	
	y.clear();	
	init();
} 

void youwin()                                                //Ӯ��ʱ����
{
	MessageBox(m_hwnd, TEXT("��Ӯ��"), TEXT("��Ϸ����"),MB_OK);
	x.clear();	
	y.clear();	
	init();
} 

void move(int d)                                            //���ôκ������ƶ�
{
	if(d == 0&&x[0]>0)                                      //���ƶ�����Ϊ�ϲ����ƶ��Ϸ�ʱ,���沢ȥ����β,��һ����ͷ	
	{
		x.insert(x.begin(),x[0]-1);		
		px = x[x.size()-1];		
		x.erase(x.begin()+x.size()-1);		
		y.insert(y.begin(),y[0]);		
		py = y[y.size()-1];		
		y.erase(y.begin()+y.size()-1);	
	}	
	else if(d == 0&&x[0]<=0)gameover();                    //���ƶ����Ϸ�ʱ��Ϸ����	
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

void update()                                          //��Ϸ�������߼�,ÿ֡���ô˺���
{	
	if(tk%SPEED==0)                                    //ÿ��SPEED���֡�ƶ�һ��
	{		
		move(dir);		
		lock = false;	
	}	
	if(x[0]==ax&&y[0]==ay)                             //����Ե���ƻ��
	{
		x.push_back(px);                               //����β		
		y.push_back(py);		
		ax = -1;                                       //ȥ��ƻ��	
	}	
	if(x.size()>=SIZE*SIZE)                            //����ߵĳ��ȴ��ڵ��ڵ�ͼ��С,��Ϸ����
	{	
		youwin();		
		return;	
	}	
	memset(map,0,sizeof(map));                         //ˢ�µ�ͼ	
	for(int i = 0; i < x.size(); i++)
	{		
		if(map[x[i]][y[i]]==0)map[x[i]][y[i]] = 1;     //���û�������赲���������		
		else                                           //������Ϸ����
		{
			gameover();			
			return;		
		}	
	}	
	if(ax==-1)                                        //ƻ������,ˢ��ƻ��	
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
}                                                   /* �˺������ڴ����ڽ��ܵ�������Ϣ */

LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam)
{	
	switch(Message)                                /* Upon destruction, tell the main thread to stop */	
	{				
		case WM_DESTROY:
		{			
			PostQuitMessage(0);			
			break;		
		}				
		case WM_KEYDOWN:                          //���յ�������Ϣ	
		{		
			if(!lock)                            //�Ҳ�����û������,��ı��ߵ��ƶ���������
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
			if(wParam == VK_ESCAPE)PostQuitMessage(0);                //�����ESC�����˳�			
				break;                                                /* All other messages (a lot of them) are processed using default procedures */			
		}					
		default:			
			return DefWindowProc(hwnd, Message, wParam, lParam);	
	}	
	return 0;
} 

void render()                                                         //��Ⱦ����,���ڻ�����Ϸͼ��
{     
	HDC hDC = GetDC(m_hwnd);                                          //���崰�ھ����DC      
	HDC memDC = CreateCompatibleDC(0);                                //�������DC     
	HBITMAP bmpBack = CreateCompatibleBitmap(hDC,g_nWidth,g_nHeight); //����λͼ����    
	SelectObject(memDC,bmpBack);      
	HPEN penBack = CreatePen(PS_SOLID,1,RGB(0,0,0));                  //���廭��    
	SelectObject(memDC,penBack);     
	HBRUSH brushBack = CreateSolidBrush(RGB(255,255,255));            //���屳����ˢ    
	SelectObject(memDC,brushBack);     
	RECT rcClient;   
	GetClientRect(m_hwnd,&rcClient);  
	FillRect(memDC,&rcClient,brushBack);                             //�ñ�����ˢ�Ծ��������������   
	HBRUSH brushObj = CreateSolidBrush(RGB(255,0,0));                //��������ˢ  
	HBRUSH brushApple = CreateSolidBrush(RGB(0,0,255));              //����ƻ����ˢ   
	int dw = WIDTH;    
	int rows = SIZE;    
	int cols = SIZE;     
	for (int r=0; r<rows; ++ r)                                     //������������ 
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
	DeleteObject(brushObj);                                         //�ͷ���Դ    
	BitBlt(hDC,0,0,g_nWidth,g_nHeight,memDC,0,0,SRCCOPY);    
	DeleteObject(penBack);   
	DeleteObject(brushBack);    
	DeleteObject(bmpBack);    
	DeleteDC(memDC); 
	ReleaseDC(m_hwnd,hDC);
}  

DWORD WINAPI startLoop(LPVOID lpParamter)                          //��ʼ��ѭ��,�������������Ϊ�˶��߳�����,����������,������ʽһ�� 
{ 
	while(1)
	{		
		update();		
		render();		
		Sleep(1000/FPS);	
	}   
	return 0L;
}                                                                 /* windows��̵������� */

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
	m_hwnd = hwnd;	init();                                            //��ʼ�� 	
	HANDLE hThread = CreateThread(NULL, 0, startLoop, NULL, 0, NULL);  //�����߳�       
	CloseHandle(hThread);                                              //�ͷ��߳̾�� 	
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