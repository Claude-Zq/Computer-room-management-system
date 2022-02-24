#pragma once
#include"Account.h"
#include"ReservationFile.h"
#include"globalFile.h"


class User {
public:

	/*展示菜单*/
	virtual void showMenu() = 0;

	/*修改自身密码*/
	virtual void changePwd() = 0;

	/*展示所有预约记录*/
	void showAllRsv();

	Account m_account;
};

