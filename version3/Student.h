#pragma once
#include"User.h"
#include"globalFile.h"
#include<iostream>
#include<string>
#include"AccountFile.h"
#include"ComputerRoomFile.h"


class Student :public User {

public:

	/*���캯��*/
	Student(std::string id = "", std::string name = "", std::string pwd = "");

	Student(const Account& a);

	/*չʾ�˵�*/
	virtual void showMenu();

	/*�޸���������*/
	virtual void changePwd();

	//����ԤԼ
	void applyRsv();

	//�鿴�ҵ�ԤԼ
	void showMyRsv();

	//ȡ��ԤԼ
	void cancelRsv();

};