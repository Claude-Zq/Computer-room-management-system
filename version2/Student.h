#pragma once
#include"User.h"
#include"globalFile.h"
#include<iostream>
#include<string>
#include"AccountFile.h"
#include"ComputerRoomFile.h"


class Student :public User {

public:

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