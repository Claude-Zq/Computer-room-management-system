#pragma once
#include<string>


//��ݳ�����
class Identity {	
public:
	//�����˵�
	virtual void operMenu() = 0;

	std::string m_name;//�û���
	std::string m_pwd;//����
};
