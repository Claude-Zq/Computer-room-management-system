#pragma once
//#define _CRT_SECUER_NO_WARNIGNS
#include"Identity.h"

class Teacher:public Identity {

public:
	//默认构造
	Teacher();

	//有参构造
	Teacher(int employeeId, std::string name, std::string pwd);

	//菜单界面
	virtual void operMenu();

	//查看所有预约
	void showAllOrder();

	//审核预约
	void validOrder();

	int m_empId;/*教师编号*/


};