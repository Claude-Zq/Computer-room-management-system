#pragma once
#include"User.h"
#include"AccountFile.h"
#include"globalFile.h"
#include"ReservationFile.h"


class Teacher :public User {

public:

	/*���캯��*/
	Teacher(const Account& a);

	Teacher(std::string id = "", std::string name = "", std::string pwd = "");

	/*չʾ�˵�*/
	virtual void showMenu();

	/*�޸���������*/
	virtual void changePwd();

	/*���ԤԼ*/
	void auditRsv();
};