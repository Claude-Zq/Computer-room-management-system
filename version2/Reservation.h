#pragma once
#include"date.h"
#include<string>


class Reservation {

public:

	Reservation();

	/*�ж�����ԤԼ�Ƿ��ͻ*/
	bool is_conflict(const Reservation &r);

	/*����*/
	date m_date;

	/*ʱ�� ���磺1 ���磺2*/
	int m_period;

	/*ѧ���˺�(ѧ��)*/
	std::string m_stuId;

	/*ѧ������*/
	std::string m_stuName;

	/*�����*/
	int m_roomId;

	/*ԤԼ״̬ -1:ԤԼʧ�� 0:��ȡ�� 1:����� 2:ԤԼ�ɹ� */
	int m_status;

	/*�����ԤԼ����ʦ��ְ���� û��ʱΪ "??"*/
	std::string m_empId;

};