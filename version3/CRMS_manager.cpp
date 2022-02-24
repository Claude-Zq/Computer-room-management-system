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
			Student stu(a);
			stu_interface(stu);
		}
		/*老师*/
		else if (type == 2) {
			std::cout << "老师用户界面" << std::endl;
		}
		/*管理员*/
		else if (type == 3) {
			Administrator admin(a);
			admin_interface(admin);
		}
	}
}

/*学生用户界面*/
void CRMS_manager::stu_interface(Student& s) {
	while (true) {
		//学生菜单
		s.showMenu();
		int select = 0;/*输入用户的选择*/
		do {
			std::cout << "输入您的选择: " << std::endl;
			if (std::cin >> select) break; /*输入合法性检查*/
			std::cout << "输入有误，请重新输入" << std::endl;
			std::cin.clear();/*清空输入缓冲区*/
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		} while (true);

		if (select == 1) {
			/*申请预约*/
			s.applyRsv();
		}
		else if (select == 2) {
			/*查看我的预约*/
			s.showMyRsv();
		}
		else if (select == 3) {
			/*查看所有预约*/
			s.showAllRsv();
		}
		else if (select == 4) {
			/*取消预约*/
			s.cancelRsv();
		}
		else if (select == 5) {
			/*修改密码*/
			s.changePwd();
		}
		else if (select == 0) {
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

/*老师用户界面*/
void CRMS_manager::tea_interface() {

}

/*管理员用户界面*/
void CRMS_manager::admin_interface(Administrator& a) {
	
	while (true) {
		//管理员菜单
		a.showMenu();
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
			a.addAccount();
		}
		else if (select == 2) {
			/*查看账号*/
			a.showAccount();
		}
		else if (select == 3) {
			/*删除账号*/
			a.deleteAccount();
		}
		else if (select == 4) {
			/*修改密码*/
			a.changePwd();

		}
		else if (select == 5) {
			/*添加机房*/
			a.addComputerRoom();
		}
		else if (select == 6) {
			/*查看机房*/
			a.showComputerRoom();
		}
		else if (select == 7) {
			/*修改机房*/
			a.modifyComputerRoom();
		}
		else if (select == 8) {
			/*清空预约*/
			a.clearRsv();
		}
		else if (select == 0) {
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