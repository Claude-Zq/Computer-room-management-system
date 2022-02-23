#include"Teacher.h"


/*构造函数*/
Teacher::Teacher(std::string id, std::string name, std::string pwd) {
	this->m_account.m_id = id;
	this->m_account.m_name = name;
	this->m_account.m_pwd = pwd;
}

/*展示菜单*/
void Teacher::showMenu() {
	std::cout << "\t\t\t\t\t  欢迎 [" <<this->m_account.m_name << "] 老师登录" << std::endl;
	std::cout << "\t\t\t\t----------------------------------------" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t|             1.查看所有预约           |" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t|             2.审核预约               |" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t|             3.修改密码               |" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t|             0.注销登录               |" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t----------------------------------------" << std::endl;
}

/*修改自身密码*/
void Teacher::changePwd() {
	AccountFile af(TEACHER_FILE);

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

/*审核预约*/
void Teacher::auditRsv() {
	ReservationFile rsf(RESERVATION_FILE);

	std::vector<int> v;/*记录可以取消的预约在rsf.m_allResv的索引*/
	for (int i = 0; i < rsf.m_allResv.size(); i++) {
		/*预约状态为审核中*/
		if (rsf.m_allResv[i].m_status == 1) {
			if (v.size() == 0)  std::cout << "待审核的预约如下:" << std::endl;
			std::cout << v.size() + 1 << "、时间: " << rsf.m_allResv[i].m_date
				<< " 时段: " << (rsf.m_allResv[i].m_period == 1 ? "上午" : "下午")
				<< " 姓名: " << rsf.m_allResv[i].m_stuName
				<< "\t机房号: " << rsf.m_allResv[i].m_roomId << std::endl;
		}
	}

	if (v.size() == 0) std::cout << "待审核的预约" << std::endl;
	else {
		std::cout << "\n请输入审核的预约编号(返回请按0)" << std::endl;
		int select = 0;
		do {
			if (std::cin >> select && (select >= 0 && select <= v.size()))break;
			std::cout << "输入有误,请重新输入" << std::endl;
			std::cin.clear();/*清空输入缓冲区*/
			std::cin.ignore(std::streamsize(std::numeric_limits<std::streamsize>::max()), '\n');
		} while (true);

		if (select == 0) {/*返回子菜单*/
			std::cout << "已返回" << std::endl;
		}
		else {
			std::cout << "请选择:\n1.同意\n0.不同意" << std::endl;
			int selection;
			do {
				if (std::cin >> selection && (selection == 1 || selection == 0))break;
				std::cout << "输入有误,请重新输入" << std::endl;
				std::cin.clear();/*清空输入缓冲区*/
				std::cin.ignore(std::streamsize(std::numeric_limits<std::streamsize>::max()), '\n');
			} while (true);

			if (selection == 0) {
				rsf.m_allResv[v[select - 1]].m_status = -1;/*不批准*/
				std::cout << "已拒绝" << std::endl;
			}
			else {
				rsf.m_allResv[v[select - 1]].m_status = 2;/*批准*/
				std::cout << "已同意" << std::endl;
			}
		}
	}
	system("pause");
	system("cls");
}