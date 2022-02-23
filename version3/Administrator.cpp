#include"Administrator.h"

//有参构造(账号、姓名、密码)
Administrator::Administrator(std::string id, std::string name, std::string pwd) {
	this->m_account.m_id = id;
	this->m_account.m_name = name;
	this->m_account.m_pwd = pwd;

}

Administrator::Administrator(const Account& a) {
	this->m_account = a;
}


/*展示菜单*/
void Administrator::showMenu() {
	std::cout << "\t\t\t\t\t欢迎管理员 [" << this->m_account.m_name << "] 登录" << std::endl;
	std::cout << "\t\t\t\t----------------------------------------" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t|              1.添加账号              |" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t|              2.查看账号              |" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t|              3.删除账号              |" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t|              4.修改密码              |" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t|              5.添加机房              |" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t|              6.查看机房              |" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t|              7.修改机房              |" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t|              8.清空预约              |" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t|              0.注销登录              |" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t----------------------------------------" << std::endl;
}

//删除账号
void Administrator::deleteAccount() {

	std::cout << "请输入删除账号的类型" << std::endl;
	std::cout << "1.添加学生" << std::endl;
	std::cout << "2.添加老师" << std::endl;
	std::cout << "3.添加管理员" << std::endl;


	int select;
	do {
		std::cout << "输入您的选择: " << std::endl;
		if (std::cin >> select) break; /*输入合法性检查*/
		std::cout << "输入有误，请重新输入" << std::endl;
		std::cin.clear();/*清空输入缓冲区*/
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	} while (true);


	std::string fileName, tip;
	if (select == 1) {
		fileName = STUDENT_FILE;
		tip = "请输入学号:";
	}
	else if (select == 2) {
		fileName = TEACHER_FILE;
		tip = "请输入职工编号:";
	}
	else if (select == 3) {
		fileName = ADMIN_FILE;
		tip = "请输入职工编号:";
	}
	else {
		std::cout << "无该选项" << std::endl;
		system("pause");
		system("cls");
		return;
	}


	std::string id;
	AccountFile af(fileName);


	std::cout << tip << std::endl;
	std::cin >> id;
	std::cin.clear();/*清空输入缓冲区*/
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


	if (af.deleteAccount(id)) std::cout << "删除成功" << std::endl;
	else std::cout << "删除失败,账号不存在" << std::endl;

	system("pause");
	system("cls");

}

//添加账号
void Administrator::addAccount() {
	std::cout << "请输入添加账号的类型" << std::endl;
	std::cout << "1.添加学生" << std::endl;
	std::cout << "2.添加老师" << std::endl;
	std::cout << "3.添加管理员" << std::endl;


	int select;
	do {
		std::cout << "输入您的选择: " << std::endl;
		if (std::cin >> select) break; /*输入合法性检查*/
		std::cout << "输入有误，请重新输入" << std::endl;
		std::cin.clear();/*清空输入缓冲区*/
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	} while (true);


	std::string fileName, tip;
	if (select == 1) {
		fileName = STUDENT_FILE;
		tip = "请输入学号:";
	}
	else if (select == 2) {
		fileName = TEACHER_FILE;
		tip = "请输入职工编号:";
	}
	else if (select == 3) {
		fileName = ADMIN_FILE;
		tip = "请输入职工编号:";
	}
	else {
		std::cout << "无该选项" << std::endl;
		system("pause");
		system("cls");
		return;
	}


	Account a;
	AccountFile af(fileName);


	std::cout << tip << std::endl;
	std::cin >> a.m_id;
	std::cin.clear();/*清空输入缓冲区*/
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


	std::cout << "请输入姓名:" << std::endl;
	std::cin >> a.m_name;
	std::cin.clear();/*清空输入缓冲区*/
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::cout << "请输入密码:" << std::endl;
	std::cin >> a.m_pwd;
	std::cin.clear();/*清空输入缓冲区*/
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


	if (af.addAccount(a)) std::cout << "添加成功" << std::endl;
	else std::cout << "账号重复,添加失败" << std::endl;

	system("pause");
	system("cls");
}

//添加机房
void Administrator::addComputerRoom() {
	ComputerRoomFile crf(COMPUTER_FILE);
	if (!crf.m_isOpen) {
		std::cout << "文件" << COMPUTER_FILE << "缺失" << std::endl;
		system("pause");
		system("cls");
		return;
	}

	int roomId, size;
	do {
		std::cout << "请输入机房号:" << std::endl;
		if (std::cin >> roomId) break; /*输入合法性检查*/
		std::cout << "输入有误，请重新输入" << std::endl;
		std::cin.clear();/*清空输入缓冲区*/
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	} while (true);

	if (crf.m_allRoom.count(roomId) == 1) {
		std::cout << "该机房号已存在" << std::endl;
		system("pause");
		system("cls");
		return;
	}
	do {
		std::cout << "请输入容量:" << std::endl;
		if (std::cin >> size && size > 0) break; /*输入合法性检查*/
		std::cout << "输入有误，请重新输入" << std::endl;
		std::cin.clear();/*清空输入缓冲区*/
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	} while (true);

	crf.m_allRoom[roomId] = size;
	std::cout << "添加成功" << std::endl;
	system("pause");
	system("cls");

}

//查看机房信息
void Administrator::showComputerRoom() {
	ComputerRoomFile crf(COMPUTER_FILE);
	if (!crf.m_isOpen) {
		std::cout << "文件" << COMPUTER_FILE << "打开失败" << std::endl;
		system("pause");
		system("cls");
		return;
	}

	if (crf.m_allRoom.size() == 0) std::cout << "当前记录为空" << std::endl;
	else {
		std::cout << "全部机房信息如下:" << std::endl
			<< " 机房号\t容量" << std::endl;
		for (auto it = crf.m_allRoom.begin(); it != crf.m_allRoom.end(); it++)
			std::cout << " " << it->first << '\t' << it->second << std::endl;
	}
	system("pause");
	system("cls");
	return;
}

//修改机房信息
void Administrator::modifyComputerRoom() {
	ComputerRoomFile crf(COMPUTER_FILE);
	if (!crf.m_isOpen) {
		std::cout << "文件" << COMPUTER_FILE << "缺失" << std::endl;
		system("pause");
		system("cls");
		return;
	}

	int roomId, size;
	do {
		std::cout << "请输入机房号:" << std::endl;
		if (std::cin >> roomId) break; /*输入合法性检查*/
		std::cout << "输入有误，请重新输入" << std::endl;
		std::cin.clear();/*清空输入缓冲区*/
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	} while (true);

	if (crf.m_allRoom.count(roomId) == 0) {
		std::cout << "该机房号不存在" << std::endl;
		system("pause");
		system("cls");
		return;
	}
	do {
		std::cout << "请输入容量:" << std::endl;
		if (std::cin >> size && size > 0) break; /*输入合法性检查*/
		std::cout << "输入有误，请重新输入" << std::endl;
		std::cin.clear();/*清空输入缓冲区*/
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	} while (true);

	crf.m_allRoom[roomId] = size;
	std::cout << "修改成功" << std::endl;
	system("pause");
	system("cls");
}

/*修改自身密码*/
void Administrator::changePwd() {
	AccountFile af(ADMIN_FILE);

	std::string newPwd1, newPwd2;
	std::cout << "请输入新密码" << std::endl;
	std::cin >> newPwd1;
	std::cin.clear();/*清空输入缓冲区*/
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << "请再次新密码" << std::endl;
	std::cin >> newPwd2;
	std::cin.clear();/*清空输入缓冲区*/
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	if (newPwd1 != newPwd2) std::cout << "修改失败,两次输入的密码不同" << std::endl;
	else {
		af.modifyPwd(this->m_account.m_id, newPwd1);
		std::cout << "修改成功" << std::endl;
	}
	system("pause");
	system("cls");
}

//查看账号
void Administrator::showAccount() {
	std::cout << "---------------------------------" << std::endl;
	std::cout << "|\t 1.查看所有学生\t\t|" << std::endl;
	std::cout << "|\t 2.查看所有老师\t\t|" << std::endl;
	std::cout << "---------------------------------" << std::endl;

	int select = 0;
	do {
		std::cout << "请输入您的选择:" << std::endl;
		if (std::cin >> select) break;
		std::cout << "输入有误，请重新输入" << std::endl;
		std::cin.clear();/*清空输入缓冲区*/
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	} while (true);

	if (select == 1) {

		AccountFile sf(STUDENT_FILE);

		if (sf.m_allAccount.empty()) std::cout << "无学生账号记录" << std::endl;
		else {
			std::cout << "学号\t姓名\t密码" << std::endl;
			std::cout << "学号\t姓名\t密码" << std::endl;
			for (auto it = sf.m_allAccount.begin(); it != sf.m_allAccount.end(); it++) {
				std::cout << it->second.m_id
					<< '\t' << it->second.m_name << '\t'
					<< it->second.m_pwd << std::endl;
			}
		}

	}
	else if (select == 2) {
		AccountFile tf(TEACHER_FILE);

		if (tf.m_allAccount.empty()) std::cout << "无老师账号记录" << std::endl;
		else {
			std::cout << "职工号\t姓名\t密码" << std::endl;
			std::cout << "职工号\t姓名\t密码" << std::endl;
			for (auto it = tf.m_allAccount.begin(); it != tf.m_allAccount.end(); it++) {
				std::cout << it->second.m_id
					<< '\t' << it->second.m_name
					<< '\t' << it->second.m_pwd << std::endl;
			}
		}
	}
	else {
		std::cout << "无该选项!" << std::endl;
	}
	system("pause");
	system("cls");
}

//清空预约记录
void Administrator::clearRsv() {
	ReservationFile rf(RESERVATION_FILE);
	rf.m_allResv.clear();
}