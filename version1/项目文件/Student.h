#pragma once
#include"Identity.h"
#include<iostream>
#include<vector>
#include"ComputerRoom.h"
#include"globalFile.h"
#include<fstream>
#include"OrderFile.h"
#include<cstdlib>


/*ѧ����*/
class Student :public Identity{

public:

	//�вι���
	Student(int id=0, std::string name="", std::string pwd="");

	//�˵�����
	virtual void operMenu();

	//����ԤԼ
	void applyOrder();

	//�鿴�ҵ�ԤԼ
	void showMyOrder();

	//�鿴����ԤԼ
	void showALLOrder();

	//ȡ��ԤԼ
	void cancelOrder();

	//��������
	std::vector<ComputerRoom> vCom;

	/*��ʼ�������Ĳ���*/
	void initVector();

	//ѧ��ѧ��
	int m_id;
};