#pragma once
using namespace std;
#include<iostream>

//���ݿ⹫�����������

//��ӡ��־
//template<typename T>
//constexpr auto LOG(T str) { return cout<< _FILE_ <<" : "<<__LINE__<<" "<< __TIMESTAMP__<< " : " << str << endl;;}

#define LOG(str) \
	cout<< __FILE__<<":"<<__LINE__<<" "<<\
	__TIMESTAMP__<<":"<<str<<endl;