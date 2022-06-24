#include<stdio.h>
#include<string.h>

int n,m;
char id[1007][100],nme[1007][100];
float h[1007],w[1007],bmi[1007];

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s%s%f%f",id[i],nme[i],&h[i],&w[i]);
        bmi[i]=w[i]/(h[i]*h[i]);
    }

    printf("BMI正常学生信息：\n");
    int has=0;
    for(int i=0;i<n;i++){
        if(bmi[i]>=20 && bmi[i]<=24){
            printf("%s\t%s\t%.2f\n",id[i],nme[i],bmi[i]);
            has=1;
        }
    }
    if(!has)printf("无此类学生\n");

    printf("BMI偏瘦学生信息：\n");
    has=0;
    for(int i=0;i<n;i++){
        if(bmi[i]<20){
            printf("%s\t%s\t%.2f\n",id[i],nme[i],bmi[i]);
            has=1;
        }
    }
    if(!has)printf("无此类学生\n");

    printf("BMI偏胖学生信息：\n");
    has=0;
    for(int i=0;i<n;i++){
        if(bmi[i]>24){
            printf("%s\t%s\t%.2f\n",id[i],nme[i],bmi[i]);
            has=1;
        }
    }
    if(!has)printf("无此类学生\n");


    return 0;
}