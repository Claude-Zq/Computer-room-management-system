#include"Manager.h"



Manager::Manager() {

}

Manager::Manager(std::string name, std::string pwd) {
	this->m_name = name;
	this->m_pwd = pwd;
}

void Manager::operMenu() {

	std::cout << "\t\t\t\t\t��ӭ����Ա [" << this->m_name << "] ��¼" << std::endl;
	std::cout << "\t\t\t\t----------------------------------------" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t|              1.����˺�              |" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t|              2.�鿴�˺�              |" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t|              3.�鿴����              |" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t|              4.���ԤԼ              |" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t|              0.ע����¼              |" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t----------------------------------------" << std::endl;

}


void Manager::addPerson() {

}


void Manager::showPerson() {

}


void Manager::showComputer() {

}


void Manager::cleanFile() {

}