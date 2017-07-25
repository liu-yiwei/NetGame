#pragma once
///////////////////////////////
//ͨѶЭ��Ľṹ��
#define MAX_BUFFER_LEN 1024 * 8
#include <iostream>
#include <MAP>


typedef enum _OPERATION_TYPE
{
	ACCEPT_POSTED, 
	SEND_POSTED,   
	RECV_POSTED,   
	NULL_POSTED  

}OPERATION_TYPE;

//ҪͶ�ݵ���Ϣ
typedef struct buf{
	char buffer[MAX_BUFFER_LEN];	//ҪͶ�ݵ�����
	OPERATION_TYPE m_OpType;		//����������
}BUF;

//����Ϣ�ṹ��
typedef struct info 
{
	int type;
	std::map<std::string,std::string> da;
}INFO;


class Model
{
public:
	Model(INFO* i);
	~Model();
	BUF* infoToBuf();
	INFO * in;
private:

};