#pragma once
#include"Identity.h"
#include<iostream>



/*学生类*/
class Student :public Identity{

public:

	//有参构造
	Student(int id=0, std::string name="", std::string pwd="");

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