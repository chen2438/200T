#include<bits/stdc++.h>
using namespace std;
int a[9][9],v[9][9];
struct point//队列的格式 
{
	int x;
	int y;
	int step;
};
queue<point> r;//申请队列 
int dx[9]={1,1,-1,-1,2,2,-2,-2};
int dy[9]={2,-2,2,-2,1,-1,1,-1}; 
int main()
{
	char s[3],e[3];
    while(scanf("%s%s",&s,&e))
    {
    	memset(v,0,sizeof(v));
		//BFS
		int sx=s[0]-'a'+1,sy=s[1]-'1'+1,ex=e[0]-'a'+1,ey=e[1]-'1'+1;
		printf("%d%d%d%d\n",sx,sy,ex,ey);//检查起点终点坐标 
		point start; //首元素的结构体 
		start.x =sx;
		start.y =sy;
		start.step =0;
		r.push(start);//首元素入队 
		v[sx][sy]=1;//表示首元素已经拓展到了 
		while(!r.empty()){//循环的条件：对列为空即要么找到了要么没有即循环结束 
			int x=r.front().x,y=r.front().y;//队列的首元素 	
			r.pop();//拓展完将队首元素出队
			int ans=99999999;
			if(x==ex&&y==ey){//找到了 
			//	printf("To get from %s to %s takes %d knight moves\n",s,e,r.front().step);
			//	break;//跳出循环，结束了 
				ans=min()
			}
			
			for(int k=0;k<9;k++){
				int tx,ty;
				tx=x+dx[k];//拓展 
				ty=y+dy[k];
				if(tx<=8&&tx>=1&&ty<=8&&ty>=1&&v[tx][ty]==0)//拓展的条件 
				{
					point temp;
					temp.x =tx;
					temp.y =ty;
					temp.step =r.front().step+1;//步数加1
					r.push(temp);//入队 
					v[tx][ty]=1;//表示已经拓展过了 
				}
			}
			
		}
	}
	return 0;
}

