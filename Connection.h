#pragma once
#include<string>
#include <mysql.h>
using namespace std; 
#include<ctime>

//实现MYSQL操作：增删改查

class Connection
{
public:
	//初始化数据库连接
	Connection();
	~Connection();
	//连接数据库
	bool connect(string ip, unsigned short port, string user, string password, string dbname);
	
	//更新操作 insert delete update
	bool update(string sql);
	//查询操作 select
	MYSQL_RES* query(string sql);

	//刷新一下连接的起始空闲时间点
	void refreshAliveTime() { _alivetime = clock(); }
	//返回存活的时间
	clock_t getAliveeTime() const { return clock() - _alivetime; }
private:
	MYSQL* _conn; //表示和MYSQL Server的一条连接
	clock_t _alivetime; //记录进入空闲状态后的起始存活时间
};
