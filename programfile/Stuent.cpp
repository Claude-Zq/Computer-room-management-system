#include"Student.h"




Student::Student(int id, std::string name, std::string pwd) {
	/*初始化属性*/
	m_id = id;
	m_name = name;
	m_pwd = pwd;
}

void Student::operMenu() {
	std::cout << "\t\t\t\t\t欢迎 [" << this->m_name << "] 同学登录" << std::endl;
	std::cout << "\t\t\t\t----------------------------------------" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t|             1.申请预约               |" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t|             2.查看我的预约           |" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t|             3.查看所有预约           |" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t|             4.取消预约               |" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t|             0.注销登录               |" << std::endl;
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