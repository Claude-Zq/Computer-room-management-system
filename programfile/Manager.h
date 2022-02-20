#pragma once
#include"Identity.h"
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include"globalFile.h"
#include"Student.h"
#include"Teacher.h"


class Manager:public Identity {

public:

	//�вι���(����������)
	Manager(std::string name ="", std::string pwd = "");

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

	//��ʼ������
	void initVector();

	//����ظ�(������id ������:1 ѧ�� 2 ��ʦ)(true �������ظ�,false����û���ظ�)
	bool checkRepeat(int id, int type);

	//ѧ������
	std::vector<Student> vStu;

	//��ʦ����
	std::vector<Teacher> vTea;

};