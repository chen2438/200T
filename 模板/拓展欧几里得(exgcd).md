```cpp
void exgcd(int &x,int &y,int a,int b){
	//使用时exgcd(x,y,x,y)即可，无需全局变量，运行后x、y为一组解
    if(!b){
        x=1,y=0;
        return;
    }
    exgcd(x,y,b,a%b);
    int t;
    t=x,x=y,y=t-a/b*y;
}
```