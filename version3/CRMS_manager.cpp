#include"CRMS_manager.h"



/*展示主菜单*/
void CRMS_manager::showMenu() {
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
}

/*登录 学生:1 老师:2 管理员:3*/
void CRMS_manager::login(int type) {

	Account a;

	/*输入账号*/
	std::cout << "请输入账号" << std::endl;
	std::cin >> a.m_id;
	std::cin.clear();/*清空输入缓冲区*/
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


	/*输入姓名*/
	std::cout << "请输入姓名" << std::endl;
	std::cin >> a.m_name;
	std::cin.clear();/*清空输入缓冲区*/
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


	/*输入密码*/
	std::cout << "请输入密码" << std::endl;
	std::cin >> a.m_pwd;
	std::cin.clear();/*清空输入缓冲区*/
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::string fileName;
	if (type == 1) fileName = STUDENT_FILE;
	else if (type == 2) fileName = TEACHER_FILE;
	else if (type == 3) fileName = ADMIN_FILE;
	AccountFile af(fileName);

	int ret = af.verify(a);

	if (ret == 0) std::cout << "账号错误" << std::endl;
	else if (ret == 1) std::cout << "登录成功" << std::endl;
	else if (ret == -1) std::cout << "密码错误" << std::endl;
	else if (ret == 2) std::cout << "姓名错误" << std::endl;

	system("pause");
	system("cls");

	if (ret == 1) {
		/*学生*/
		if (type == 1) { 
			std::cout << "学生用户界面" << std::endl;
		}
		/*老师*/
		else if (type == 2) {
			std::cout << "老师用户界面" << std::endl;
		}
		/*管理员*/
		else if (type == 3) {
			std::cout << "管理员用户界面" << std::endl;
		}
		system("pause");
		system("cls");
	}
}

/*学生用户界面*/
void CRMS_manager::stu_interface() {

}

/*老师用户界面*/
void CRMS_manager::tea_interface() {

}

/*管理员用户界面*/
void CRMS_manager::admin_interface() {

}