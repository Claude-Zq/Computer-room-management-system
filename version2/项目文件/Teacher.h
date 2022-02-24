#pragma once
#include"User.h"
#include"AccountFile.h"
#include"globalFile.h"
#include"ReservationFile.h"


class Teacher :public User {

public:

	/*构造函数*/
	Teacher(const Account& a);

	Teacher(std::string id = "", std::string name = "", std::string pwd = "");

	/*展示菜单*/
	virtual void showMenu();

	/*修改自身密码*/
	virtual void changePwd();

	/*审核预约*/
	void auditRsv();
};