#pragma once
using namespace std;
#include<iostream>

//数据库公共定义的内容

//打印日志
//template<typename T>
//constexpr auto LOG(T str) { return cout<< _FILE_ <<" : "<<__LINE__<<" "<< __TIMESTAMP__<< " : " << str << endl;;}

#define LOG(str) \
	cout<< __FILE__<<":"<<__LINE__<<" "<<\
	__TIMESTAMP__<<":"<<str<<endl;