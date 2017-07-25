#pragma once
///////////////////////////////
//通讯协议的结构体
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

//要投递的信息
typedef struct buf{
	char buffer[MAX_BUFFER_LEN];	//要投递的数据
	OPERATION_TYPE m_OpType;		//操作的类型
}BUF;

//对信息结构话
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