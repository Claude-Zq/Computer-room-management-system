#pragma once
#include<map>
#include<string>
#include"globalFile.h"
#include<fstream>
#include<iostream>
#define NUM_OF_DATA_ONE_LINE 6 /*order�ļ���һ��ӵ�е����ݸ���*/


class OrderFile {
public:
	/*���캯��*/
	OrderFile();

	/*����ԤԼ��¼*/
	void updateOrder();

	/*��¼������*/
	std::map<int, std::map<std::string, std::string> > m_orderData;

	/*ԤԼ��¼������*/
	int m_size;
};