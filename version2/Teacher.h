#pragma once
#include"User.h"
#include"globalFile.h"
#include<iostream>
#include<string>
#include"AccountFile.h"
#include"ComputerRoomFile.h"


class Teacher :public User {
public:

	Teacher(std::string id, std::string name, std::string pwd);

	/*展示菜单*/
	virtual void showMenu();

	/*修改自身密码*/
	virtual void changePwd();

	/*审核预约*/
	void auditRsv();
};