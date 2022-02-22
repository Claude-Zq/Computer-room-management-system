#pragma once
#include<fstream>
#include<vector>
#include<string>
#include"Reservation.h"
#include<iostream>


/*�����ڹ��캯���ж�ȡ�ļ�������ʱ�����ļ������������ͬʱʹ����������*/
/*�ļ�Ĭ�ϸ�ʽ �� �� �� ʱ�� ѧ��id ѧ������ ����� ԤԼ״̬ ��ʦid */
class ReservationFile {

public:
	/*�вι���,�����ļ���*/
	ReservationFile(std::string fileName);

	/*��������*/
	~ReservationFile();

	/*���ļ��ж�ȡԤԼ��¼��������*/
	void initVector();

	/*�������е�ԤԼ��¼�浽�ļ���*/
	void saveVector();

	/*���ļ����*/
	void clearFlile();

	/*������е�ԤԼ��Ϣ*/
	std::vector<Reservation> m_allResv;

private:
	std::string m_fileName;
	
};