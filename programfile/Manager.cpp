#include"Manager.h"



Manager::Manager() {

}

Manager::Manager(std::string name, std::string pwd) {
	this->m_name = name;
	this->m_pwd = pwd;
}

void Manager::operMenu() {

	std::cout << "\t\t\t\t\t欢迎管理员 [" << this->m_name << "] 登录" << std::endl;
	std::cout << "\t\t\t\t----------------------------------------" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t|              1.添加账号              |" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t|              2.查看账号              |" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t|              3.查看机房              |" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t|              4.清空预约              |" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t|              0.注销登录              |" << std::endl;
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