#pragma once
#include"Identity.h"
#include<iostream>
#include<string>


class Manager:public Identity {

public:
	//Ĭ�Ϲ���
	Manager();

	//�вι���(����������)
	Manager(std::string name, std::string pwd);

	//ѡ��˵�
	virtual void operMenu();

	//����˺�
	void addPerson();

	//�鿴�˺�
	void showPerson();

	//�鿴������Ϣ
	void showComputer();

	//���ԤԼ��¼
	void cleanFile();

};