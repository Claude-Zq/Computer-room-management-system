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

	/*չʾ�˵�*/
	virtual void showMenu();

	/*�޸���������*/
	virtual void changePwd();

	/*���ԤԼ*/
	void auditRsv();
};