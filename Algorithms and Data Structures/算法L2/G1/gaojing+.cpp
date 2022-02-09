#include<iostream>  
    #include<cstdio>  
    #include<cstring>  
    using namespace std;  
    int super_plus(char a1[110],char b1[110];)  
    {  
	
        int a[110],b[110],c[110];  
        int a1_len,b1_len,lenc,i,x;  
        memset(a,0,sizeof(a));   
        memset(b,0,sizeof(b));   
        memset(c,0,sizeof(c));  
          
        //gets(a1);   
        //gets(b1); //????????   
           
        a1_len=strlen(a1);   
        b1_len=strlen(b1);   
       
        for (i=0;i<=a1_len-1;i++)   
        {  
            a[a1_len-i]=a1[i]-48; //??????a??    
        }  
           
        for (i=0;i<=b1_len-1;i++)  
        {  
            b[b1_len-i]=b1[i]-48; //??????b??   
        }   
        
      
       lenc =1;   
       x=0;   
          
       while(lenc <=a1_len || lenc <=b1_len)   
       {   
            c[lenc]=a[lenc]+b[lenc]+x; //????    
            x=c[lenc]/10;   //????  
            c[lenc]=c[lenc]%10;     //?????  
            lenc++;     //?????1  
        }  
          
        c[lenc]=x;  
        if (c[lenc]==0)  
        {  
            lenc--; //??????   
        }   
        char d[110],dd=0;
        memset(d,0,sizeof(d));  
        for (i=lenc;i>=1;i--)  
        {  
        	d[dd++]=char(c[i])+'0';
            //cout<<c[i]; //????      
        }  
        cout<<d;  
          
   return d;
    }
