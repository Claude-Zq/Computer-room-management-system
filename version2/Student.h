#pragma once
#include"User.h"
#include"globalFile.h"
#include<iostream>
#include<string>
#include"AccountFile.h"
#include"ComputerRoomFile.h"


class Student :public User {

public:

	/*展示菜单*/
	virtual void showMenu();

	/*修改自身密码*/
	virtual void changePwd();

	//申请预约
	void applyRsv();

	//查看我的预约
	void showMyRsv();

	//取消预约
	void cancelRsv();

};