#pragma once
#include"Connection.h"
#include<string>
#include<queue>
#include<atomic>
using namespace std;
#include <mutex>
#include<thread>
#include<memory>
#include<functional>
#include<condition_variable>


//ʵ�����ӳع���ģ��
class ConnectionPool
{
public:
	//��ȡ���ӳض���ʵ��
	static ConnectionPool* getConnectionPool();
	//���ⲿ�ṩ�ӿڣ������ӳ��л�ȡһ�����õĿ�������
	//��������ָ����������ָ��
	shared_ptr< Connection> getConnection();

private:
	ConnectionPool();//����1 ���캯��˽�л�
	


public:

	//�������ļ��м���������
	bool loadConfigFile();

	//�����ڶ������߳��У�ר�Ÿ�������������
	void produceConnectionTask();

	//ɨ�賬��maxIdletimeʱ��Ķ���Ŀ������ӣ����ж�������ӻ���
	void scannerConnectionTask();

	string _ip;    //mysql��IP��ַ
	unsigned short _port;   //�˿ں�  3306
	string _username;     //��¼�û���
	string _password;     //��¼����
	string _dbname;      //���ӳ����ݿ�����
	int _initSize;        //���ӳس�ʼ������
	int _maxSize;     //���������
	int _maxIdleTime;   //������ʱ��
	int _connectionTimeout;   //���ʱʱ��



	//���д�ָ�룬�ⲿ��������ָ�룬��������֮����黹�����ӳ�
	queue<Connection*> _connectionQue;  //�洢mysql ���ӵĶ���
	mutex _queueMutex;  //ά�����Ӷ��е��̰߳�ȫ������
	atomic_int _connectionCnt;  //��¼������������connection����������
	condition_variable cv; //���������������������������̺߳����������̵߳�ͨ��
};

