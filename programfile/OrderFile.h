#pragma once
#include<map>
#include<string>
#include"globalFile.h"
#include<fstream>
#include<iostream>
#define NUM_OF_DATA_ONE_LINE 6 /*order文件中一行拥有的数据个数*/


class OrderFile {
public:
	/*构造函数*/
	OrderFile();

	/*更新预约记录*/
	void updateOrder();

	/*记录的容器*/
	std::map<int, std::map<std::string, std::string> > m_orderData;

	/*预约记录的条数*/
	int m_size;
};