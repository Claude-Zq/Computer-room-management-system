#pragma once
//#define _CRT_SECUER_NO_WARNIGNS
#include"Identity.h"
#include<iostream>

class Teacher:public Identity {

public:

	//�вι���
	Teacher(int employeeId = 0, std::string name="", std::string pwd="");

	//�˵�����
	virtual void operMenu();

	//�鿴����ԤԼ
	void showAllOrder();

	//���ԤԼ
	void validOrder();

	int m_empId;/*��ʦ���*/


};