#pragma once
#include<iostream>


class CRMS_manager {

public:

	/*展示主菜单*/
	void showMenu();

	/*登录 学生:1 老师:2 管理员:3*/
	void login(int type);

	/*学生用户界面*/
	void stu_interface();

	/*老师用户界面*/
	void tea_interface();

	/*管理员用户界面*/
	void admin_interface();

};