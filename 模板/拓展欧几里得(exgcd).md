```cpp
void exgcd(int &x,int &y,int a,int b){
	//使用时exgcd(a,b,a,b)即可，无需全局变量，运行后a、b为一组解
    if(!b){
        x=1,y=0;
        return;
    }
    exgcd(x,y,b,a%b);
    int t;
    t=x,x=y,y=t-a/b*y;
}
```