#include<iostream>
#include"globalFile.h"
#include"Identity.h"
#include<fstream>
#include<string>


//登录功能
void LogIn(std::string fileName, int type);

int main() {

	while (true) {
		std::cout << "\t\t\t\t==========欢迎来到机房预约系统==========" << std::endl;
		std::cout << "\t\t\t\t----------------------------------------" << std::endl;
		std::cout << "\t\t\t\t|                                      |" << std::endl;
		std::cout << "\t\t\t\t|              1.学生代表              |" << std::endl;
		std::cout << "\t\t\t\t|                                      |" << std::endl;
		std::cout << "\t\t\t\t|                                      |" << std::endl;
		std::cout << "\t\t\t\t|              2.老师                  |" << std::endl;
		std::cout << "\t\t\t\t|                                      |" << std::endl;
		std::cout << "\t\t\t\t|                                      |" << std::endl;
		std::cout << "\t\t\t\t|              3.管理员                |" << std::endl;
		std::cout << "\t\t\t\t|                                      |" << std::endl;
		std::cout << "\t\t\t\t|                                      |" << std::endl;
		std::cout << "\t\t\t\t|              0.退出                  |" << std::endl;
		std::cout << "\t\t\t\t|                                      |" << std::endl;
		std::cout << "\t\t\t\t----------------------------------------" << std::endl;

		int select;
		do {
			std::cout << "输入您的选择: " << std::endl;
			if (std::cin >> select) break; /*输入合法性检查*/
			std::cout << "输入有误，请重新输入" << std::endl;
			std::cin.clear();/*清空输入缓冲区*/
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		} while (true);

		switch (select) {
		case 1://学生
			LogIn(STUDENT_FILE, 1);
			break;
		case 2://老师
			LogIn(TEACHER_FILE, 2);
			break;
		case 3://管理员
			LogIn(ADMIN_FILE, 3);
			break;
		case 0://退出
			std::cout << "欢迎下次使用" << std::endl;
			system("pause");
			return 0;
			break;
		default:
			std::cout << "无该选项，请重新选择" << std::endl;
			system("pause");
			system("cls");/*按任意键后清屏*/
			break;
		}


	}
	

	system("pause");
	return 0;
}



void LogIn(std::string fileName, int type) {
	Identity* pPerson = NULL;
	std::ifstream ifs;
	ifs.open(fileName, std::ios::in);

	//文件不存在情况
	if (!ifs.is_open()) {
		std::cout << "文件不存在" << std::endl;
		ifs.close();
		return;
	}

	/*接受用户信息*/
	int id = 0;
	std::string name;
	std::string pwd;

	//学生登录
	if (type == 1) {
		do {
			std::cout << "请输入你的学号" << std::endl;
			if (std::cin >> id) break; /*输入合法性检查*/
			std::cout << "输入有误，请重新输入" << std::endl;
			std::cin.clear();/*清空输入缓冲区*/
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		} while (true);
	}
	//老师登录
	else if (type == 2) {
		do {
			std::cout << "请输入你的职工号" << std::endl;
			if (std::cin >> id) break; /*输入合法性检查*/
			std::cout << "输入有误，请重新输入" << std::endl;
			std::cin.clear();/*清空输入缓冲区*/
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		} while (true);
	}
	std::cout << "请输入用户名" << std::endl;
	std::cin >> name;
	std::cin.clear();/*清空输入缓冲区*/
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << "请输入密码" << std::endl;
	std::cin >> pwd;
	std::cin.clear();/*清空输入缓冲区*/
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	if (type == 1) {
		//学生登录验证
	}
	else if (type == 2) {
		//教师登录验证
	}
	else if (type == 3) {
		//管理员登录验证
	}

	std::cout << "登录失败" << std::endl;
	system("pause"); /*按任意键后清屏*/
	system("cls");
	return;
}




