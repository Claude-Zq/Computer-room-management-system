#include"Student.h"




Student::Student(int id, std::string name, std::string pwd) {
	/*��ʼ������*/
	m_id = id;
	m_name = name;
	m_pwd = pwd;
}

void Student::operMenu() {
	std::cout << "\t\t\t\t\t��ӭ [" << this->m_name << "] ͬѧ��¼" << std::endl;
	std::cout << "\t\t\t\t----------------------------------------" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t|             1.����ԤԼ               |" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t|             2.�鿴�ҵ�ԤԼ           |" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t|             3.�鿴����ԤԼ           |" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t|             4.ȡ��ԤԼ               |" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t|             0.ע����¼               |" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t----------------------------------------" << std::endl;
}


void Student::applyOrder() {

}


void Student::showMyOrder() {

}

void Student::showALLOrder() {

}

void Student::cancelOrder() {

}