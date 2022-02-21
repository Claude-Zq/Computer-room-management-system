#include<iostream>
#include"globalFile.h"
#include"Identity.h"
#include<fstream>
#include<string>
#include"Student.h"
#include"Teacher.h"
#include"Manager.h"
#include"OrderFile.h"


//登录功能
void LogIn(std::string fileName, int type);

//进入管理员子菜单界面
void managerMenu(Identity*& manager);

//进入学生子菜单界面
void studentMenu(Identity*& student);

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
		int fId;/*从文件中获取的id号*/
		std::string fName, fPwd;/*从文件中获取的姓名、密码*/
		while (ifs >> fId >> fName >> fPwd) {
			if (id == fId && name == fName && pwd == fPwd) {
				std::cout << "学生登录验证成功!" << std::endl;
				system("pause");
				system("cls");
				pPerson = new Student(id, name, pwd);
				studentMenu(pPerson);
				return;
			}
		}
	}
	else if (type == 2) {
		//教师登录验证
		int fId;/*从文件中获取的id号*/
		std::string fName, fPwd;/*从文件中获取的姓名、密码*/
		while (ifs >> fId >> fName >> fPwd) {
			if (id == fId && name == fName && pwd == fPwd) {
				std::cout << "教师登录验证成功!" << std::endl;
				system("pause");
				system("cls");
				pPerson = new Teacher(id, name, pwd);
				return;
			}
		}
	}
	else if (type == 3) {
		//管理员登录验证
		std::string fName, fPwd;/*从文件中获取的姓名、密码*/
		while (ifs >> fName >> fPwd) {
			if (name == fName && pwd == fPwd) {
				std::cout << "管理员登录验证成功!" << std::endl;
				system("pause");
				system("cls");
				//创建管理对象
				pPerson = new Manager(name, pwd);
				managerMenu(pPerson);
				return;
			}
		}
	}

	std::cout << "登录失败" << std::endl;
	system("pause"); /*按任意键后清屏*/
	system("cls");
	return;
}


//管理员菜单
void managerMenu(Identity*& manager) {
	while (true) {
		//管理员菜单
		manager->operMenu();

		/*将父类Indentity的指针转换为子类Manager的指针以调用子类的其他接口*/
		Manager* pMan = (Manager*)manager;
		
		int select = 0;/*输入用户的选择*/
		do {
			std::cout << "输入您的选择: " << std::endl;
			if (std::cin >> select) break; /*输入合法性检查*/
			std::cout << "输入有误，请重新输入" << std::endl;
			std::cin.clear();/*清空输入缓冲区*/
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		} while (true);

		if (select == 1) {
			/*添加账号*/
			std::cout << "[添加账号]" << std::endl;
			pMan->addPerson();
		}
		else if (select == 2) {
			/*查看账号*/
			std::cout << "\t   [查看账号]" << std::endl;
			pMan->showPerson();
		}
		else if (select == 3) {
			/*查看机房*/
			std::cout << "机房信息如下:\n" << std::endl;
			pMan->showComputer();
		}
		else if (select == 4) {
			/*清空预约*/
			pMan->cleanFile();
		}
		else if (select == 0) {
			delete manager;
			std::cout << "注销成功" << std::endl;
			system("pause");
			system("cls");
			return;
		}
		else {
			std::cout << "无该选项，请重新输入" << std::endl;
			system("pause");
			system("cls");
		}
		
	}
}


//学生菜单
void studentMenu(Identity*& student) {
	while (true) {
		/*学生菜单*/
		student->operMenu();

		Student* pStu = (Student*)student;

		int select;/*输入用户的选择*/
		do {
			std::cout << "输入您的选择: " << std::endl;
			if (std::cin >> select) break; /*输入合法性检查*/
			std::cout << "输入有误，请重新输入" << std::endl;
			std::cin.clear();/*清空输入缓冲区*/
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		} while (true);

		if (select == 1) { /*申请预约*/
			pStu->applyOrder();
		}
		else if (select == 2) { //查看自生预约
			pStu->showMyOrder();
		}
		else if (select == 3) {/*查看所有预约*/
			pStu->showALLOrder();
		}
		else if (select == 4) {/*取消预约*/
			pStu->cancelOrder();
		}
		else if (select == 0) {
			delete student;
			std::cout << "注销成功" << std::endl;
			system("pause");
			system("cls");
			return;
		}
		else {
			std::cout << "无该选项，请重新输入" << std::endl;
			system("pause");
			system("cls");
		}
	}
}