#pragma once
#include"User.h"
#include"ReservationFile.h"
#include"globalFile.h"
#include"AccountFile.h"
#include"ComputerRoomFile.h"




class Administrator :public User {
public:

	//�вι���(�˺š�����������)
	Administrator(std::string id = "", std::string name = "", std::string pwd = "");

	Administrator(const Account& a);



	/*չʾ�˵�*/
	virtual void showMenu();

	//ɾ���˺�
	void deleteAccount();

	//����˺�
	void addAccount();

	//��ӻ���
	void addComputerRoom();

	//�鿴������Ϣ
	void showComputerRoom();

	//�޸Ļ�����Ϣ
	void modifyComputerRoom();

	/*�޸���������*/
	virtual void changePwd();

	//�鿴�˺�
	void showAccount();

	//���ԤԼ��¼
	void clearRsv();

};

