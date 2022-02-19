#pragma once
#include"Identity.h"



/*学生类*/
class Student :public Identity{

public:
	//默认构造
	Student();


	//有参构造
	Student(int id, std::string name, std::string pwd);

	//菜单界面
	virtual void operMenu();

	//申请预约
	void applyOrder();

	//查看我的预约
	void showMyOrder();

	//查看所有预约
	void showALLOrder();

	//取消预约
	void cancelOrder();

	//学生学号
	int m_id;
};