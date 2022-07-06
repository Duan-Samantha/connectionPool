#pragma once
#include<string>
#include <mysql.h>
using namespace std; 
#include<ctime>

//ʵ��MYSQL��������ɾ�Ĳ�

class Connection
{
public:
	//��ʼ�����ݿ�����
	Connection();
	~Connection();
	//�������ݿ�
	bool connect(string ip, unsigned short port, string user, string password, string dbname);
	
	//���²��� insert delete update
	bool update(string sql);
	//��ѯ���� select
	MYSQL_RES* query(string sql);

	//ˢ��һ�����ӵ���ʼ����ʱ���
	void refreshAliveTime() { _alivetime = clock(); }
	//���ش���ʱ��
	clock_t getAliveeTime() const { return clock() - _alivetime; }
private:
	MYSQL* _conn; //��ʾ��MYSQL Server��һ������
	clock_t _alivetime; //��¼�������״̬�����ʼ���ʱ��
};
