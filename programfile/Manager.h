#pragma once
#include"Identity.h"
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include"globalFile.h"
#include"Student.h"
#include"Teacher.h"


class Manager:public Identity {

public:

	//有参构造(姓名、密码)
	Manager(std::string name ="", std::string pwd = "");

	//选择菜单
	virtual void operMenu();

	//添加账号
	void addPerson();

	//查看账号
	void showPerson();

	//查看机房信息
	void showComputer();

	//清空预约记录
	void cleanFile();

	//初始化容器
	void initVector();

	//检测重复(参数：id 和类型:1 学生 2 教师)(true 代表有重复,false代表没有重复)
	bool checkRepeat(int id, int type);

	//学生容器
	std::vector<Student> vStu;

	//教师容器
	std::vector<Teacher> vTea;

};