#pragma once
#include"Identity.h"



/*ѧ����*/
class Student :public Identity{

public:
	//Ĭ�Ϲ���
	Student();


	//�вι���
	Student(int id, std::string name, std::string pwd);

	//�˵�����
	virtual void operMenu();

	//����ԤԼ
	void applyOrder();

	//�鿴�ҵ�ԤԼ
	void showMyOrder();

	//�鿴����ԤԼ
	void showALLOrder();

	//ȡ��ԤԼ
	void cancelOrder();

	//ѧ��ѧ��
	int m_id;
};