#pragma once
#include<iostream>
#include"AccountFile.h"
#include"globalFile.h"
#include"Administrator.h"
#include"Student.h"
#include"Teacher.h"

class CRMS_manager {

public:

	/*展示主菜单*/
	void showMenu();

	/*登录 学生:1 老师:2 管理员:3*/
	void login(int type);

	/*学生用户界面*/
	void stu_interface(Student& s);

	/*老师用户界面*/
	void tea_interface(Teacher &t);

	/*管理员用户界面*/
	void admin_interface(Administrator& a);

};