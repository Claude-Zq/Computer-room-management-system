#pragma once
#include"Account.h"
#include"ReservationFile.h"
#include"globalFile.h"


class User {
public:

	/*չʾ�˵�*/
	virtual void showMenu() = 0;

	/*�޸���������*/
	virtual void changePwd() = 0;

	/*չʾ����ԤԼ��¼*/
	void showAllRsv();

	Account m_account;
};

