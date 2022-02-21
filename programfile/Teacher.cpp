#include"Teacher.h"



Teacher::Teacher(int employeeId, std::string name, std::string pwd) {
	/*初始化属性*/
	m_empId = employeeId;
	m_name = name;
	m_pwd = pwd;
}

void Teacher::operMenu() {
	std::cout << "\t\t\t\t\t  欢迎 [" << this->m_name << "] 老师登录" << std::endl;
	std::cout << "\t\t\t\t----------------------------------------" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t|             1.查看所有预约           |" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t|             2.审核预约               |" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t|             0.注销登录               |" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t----------------------------------------" << std::endl;
 }

void Teacher::showAllOrder() {
	OrderFile of;
	if (of.m_size == 0) std::cout << "无预约记录" << std::endl;
	else {
		std::cout << "当前预约记录如下:" << std::endl;
		for (int i = 0; i < of.m_size; i++) {
			std::cout << i + 1 << "、预约时间: 周" << of.m_orderData[i]["date"]
				<< "  时段: " << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午")
				<< "  学号:" << of.m_orderData[i]["stuId"]
				<< "  姓名:" << of.m_orderData[i]["stuName"]
				<< "  房号: " << of.m_orderData[i]["roomId"]
				<< "  状态: ";

			int status = atoi(of.m_orderData[i]["status"].c_str());
			//0 取消预约 1 审核中 2 已预约 -1预约失败
			if (status == 1) std::cout << "审核中" << std::endl;
			else if (status == 2) std::cout << "已预约" << std::endl;
			else if (status == -1) std::cout << "预约失败" << std::endl;
			else if (status == 0) std::cout << "已取消" << std::endl;
		}
	}

	system("pause");
	system("cls");
}


void Teacher::validOrder() {

}