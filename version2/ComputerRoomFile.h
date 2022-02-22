#pragma once
#include<map>
#include<fstream>
#include<string>
#include<iostream>


/*�ļ�Ĭ�ϸ�ʽΪ ������ ����*/
/*����ֻ���ڹ��캯���ж�ȡ�ļ���Ϣ������ʱ�ű��棬���������ͬһ�ļ�ͬʱʹ������ComputerRoomFile����*/
class ComputerRoomFile {
	
public:
	
	/*���еĻ�����Ϣ ���-����*/
	std::map<int, int> m_allRoom;

	/*�ļ��Ƿ�򿪳ɹ�*/
	bool m_isOpen;

	/*���캯��*/
	ComputerRoomFile(std::string fileName);

	/*��������*/
	~ComputerRoomFile();


private:
	/*��ʼ������*/
	void initMap();

	/*�������ڵ���Ϣ���浽�ļ���*/
	void saveMap();

	/*������ļ���*/
	std::string m_fileName;

};