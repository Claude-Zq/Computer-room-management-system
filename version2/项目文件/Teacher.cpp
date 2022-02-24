#include"Teacher.h"


/*构造函数*/
Teacher::Teacher(const Account& a) {
	this->m_account = a;
}

Teacher::Teacher(std::string id, std::string name, std::string pwd) {
	this->m_account.m_id = id;
	this->m_account.m_name = name;
	this->m_account.m_pwd = pwd;
}

/*展示菜单*/
void Teacher::showMenu() {
	std::cout << "\t\t\t\t\t   欢迎 [" << this->m_account.m_name << "] 老师登录" << std::endl;
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
		if (newPwd1 == this->m_account.m_pwd) {
			std::cout << "新密码不能与旧密码相同!" << std::endl;
		}
		else {
			af.modifyPwd(this->m_account.m_id, newPwd1);/*文件中更改*/
			this->m_account.m_pwd = newPwd1;/*对象中更改*/
			std::cout << "修改成功" << std::endl;
		}
	}
	system("pause");
	system("cls");
}

/*审核预约*/
void Teacher::auditRsv() {

	ReservationFile rsf(RESERVATION_FILE);
	std::vector<int> v;/*用于存放待审核预约在rsf.m_allResv的索引*/

	for (int i = 0; i < rsf.m_allResv.size(); i++) {
		if (rsf.m_allResv[i].m_status == 1) {
			if (v.size()==0) std::cout << "待审核的预约记录如下" << std::endl;
			std::cout << v.size() + 1 << "、预约时间: "
				<< rsf.m_allResv[i].m_date.year << '/'
				<< rsf.m_allResv[i].m_date.month << '/'
				<< rsf.m_allResv[i].m_date.day
				<< "  时段: " << (rsf.m_allResv[i].m_period == 1 ? "上午" : "下午")
				<< "  学号:" << rsf.m_allResv[i].m_stuId
				<< "  姓名:" << rsf.m_allResv[i].m_stuName
				<< "  房号: " << rsf.m_allResv[i].m_roomId << std::endl;
			v.push_back(i);
		}
	}
	if (v.size() == 0) std::cout << "无待审核的预约记录" << std::endl;
	else {
		std::cout << "\n请输入审核的预约编号(返回请按0)" << std::endl;
		int select;
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

			/*记录处理的老师*/
			rsf.m_allResv[v[select - 1]].m_empId = this->m_account.m_id;
			if (selection == 0) {
				rsf.m_allResv[v[select - 1]].m_status = -1;/*不批准*/
				std::cout << "已经拒绝" << std::endl;
			}
			else {
				rsf.m_allResv[v[select - 1]].m_status = 2;/*批准*/
				std::cout << "已同意" << std::endl;

				/*处理掉待审核预约中与本次预约冲突的*/
				for (int i = 0; i < v.size(); i++) {
					if (i == select - 1) continue;
					if (rsf.m_allResv[v[i]].is_conflict(rsf.m_allResv[v[select - 1]])) {
						rsf.m_allResv[v[i]].m_status = -1;
						rsf.m_allResv[v[i]].m_empId = this->m_account.m_id;
					}
				}
			}
		}

	}
	system("pause");
	system("cls");
}