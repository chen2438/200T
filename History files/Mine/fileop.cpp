/*
 * ===========================================================================
 *
 *       Filename:  ofsteam.cpp
 *    Description:  
 *        Version:  1.0
 *        Created:  2017年07月06日 22时31分24秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:   (), 
 *        Company:  
 *
 * ===========================================================================
 */

#include<iostream>
#include<fstream>
using namespace std;


int main(int agrc,char* argv[]){
  ofstream outFile;
  char automobile[50];
  int year;
  double a_price;
  double b_price;

  //创建并且打开文件(没有则创建，有则覆盖)
  outFile.open("carinfo.txt",ios::out);


  cout << fixed;
  cout.precision(2);//保留两位小数点
//  cout.setf(ios_base::showpoint);　//设置展现小数点
  cout << "make the model:" <<automobile <<endl;
  cout <<"Year:"<<year;
  cout <<"a_price:"<<a_price<<endl;
  cout <<"b_price:"<<b_price<<endl;


  //打开成功　也可以适用outFile.good()
  if(outFile){
//    outFile.precision(2);　//向设置cout一样设置保留位数
 //   outFile << fixed;　//一般的方式输出浮点数
    outFile.setf(ios_base::showpoint);//展示小数点

  //  outFile << "make the model:"<<automobile <<endl;　//使用<<将文本输入到文件中去
    outFile <<"year:"<<year<<endl;
    outFile <<"a_price:"<<a_price<<endl;
    outFile <<"b_price" <<b_price<<endl;

  }

  //关闭文本文件输出流
  outFile.close();

  return 0;
}
