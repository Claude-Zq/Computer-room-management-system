#include"Teacher.h"



Teacher::Teacher(int employeeId, std::string name, std::string pwd) {
	/*��ʼ������*/
	m_empId = employeeId;
	m_name = name;
	m_pwd = pwd;
}

void Teacher::operMenu() {
	std::cout << "\t\t\t\t\t  ��ӭ [" << this->m_name << "] ��ʦ��¼" << std::endl;
	std::cout << "\t\t\t\t----------------------------------------" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t|             1.�鿴����ԤԼ           |" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t|             2.���ԤԼ               |" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t|             0.ע����¼               |" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t----------------------------------------" << std::endl;
 }

void Teacher::showAllOrder() {

}


void Teacher::validOrder() {

}