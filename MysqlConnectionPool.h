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


//实现连接池功能模块
class ConnectionPool
{
public:
	//获取连接池对象实例
	static ConnectionPool* getConnectionPool();
	//给外部提供接口，从连接池中获取一个可用的空闲连接
	//创建智能指针管理用完的指针
	shared_ptr< Connection> getConnection();

private:
	ConnectionPool();//单例1 构造函数私有化
	


public:

	//从配置文件中加载配置项
	bool loadConfigFile();

	//运行在独立的线程中，专门负责生产新连接
	void produceConnectionTask();

	//扫描超过maxIdletime时间的多余的空闲连接，进行多余的连接回收
	void scannerConnectionTask();

	string _ip;    //mysql的IP地址
	unsigned short _port;   //端口号  3306
	string _username;     //登录用户名
	string _password;     //登录密码
	string _dbname;      //连接池数据库名称
	int _initSize;        //连接池初始连接量
	int _maxSize;     //最大连接量
	int _maxIdleTime;   //最大空闲时间
	int _connectionTimeout;   //最大超时时间



	//序列存指针，外部调用智能指针，触动析构之后将其归还到连接池
	queue<Connection*> _connectionQue;  //存储mysql 连接的队列
	mutex _queueMutex;  //维护连接队列的线程安全互斥锁
	atomic_int _connectionCnt;  //记录连接所创建的connection连接总数量
	condition_variable cv; //设置条件变量，用于连接生产线程和连接消费线程的通信
};

