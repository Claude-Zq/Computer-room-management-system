#pragma once
//#define _CRT_SECUER_NO_WARNIGNS
#include"Identity.h"

class Teacher:public Identity {

public:
	//Ĭ�Ϲ���
	Teacher();

	//�вι���
	Teacher(int employeeId, std::string name, std::string pwd);

	//�˵�����
	virtual void operMenu();

	//�鿴����ԤԼ
	void showAllOrder();

	//���ԤԼ
	void validOrder();

	int m_empId;/*��ʦ���*/


};