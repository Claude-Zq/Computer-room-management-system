#include"Student.h"




Student::Student(std::string id, std::string name, std::string pwd) {
	this->m_account.m_name = name;
	this->m_account.m_id = id;
	this->m_account.m_pwd = pwd;
}

Student::Student(const Account& a) {
	this->m_account = a;
}

void Student::showMenu() {
	std::cout << "\t\t\t\t\t  欢迎 [" << this->m_account.m_name << "] 同学登录" << std::endl;
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
	std::cout << "\t\t\t\t|             5.修改密码               |" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t|             0.注销登录               |" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t----------------------------------------" << std::endl;
}

void Student::changePwd() {
	AccountFile af(STUDENT_FILE);

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

void Student::applyRsv() {

	Reservation r;

	std::cout << "请输入预约的时间(格式: YYYY MM DD ):" << std::endl
		<< "注意:仅周一到周五预约" << std::endl;
	do {
		if (std::cin >> r.m_date.year >> r.m_date.month >> r.m_date.day) {
			if (!r.m_date.is_legal()) std::cout << "输入的日期不合法" << std::endl;
			else {
				int week = r.m_date.getWeek();
				if (week != 0 && week != 6) break;
				else std::cout << "周末期间不可预约,请重新输入" << std::endl;
			}
		}
		else std::cout << "输入有误,请重新输入" << std::endl;
		std::cin.clear();/*清空输入缓冲区*/
		std::cin.ignore(std::streamsize(std::numeric_limits<std::streamsize>::max()), '\n');
	} while (true);


	/*输入时间段*/
	std::cout << "机房开放时间段" << std::endl;
	std::cout << "  1.上午" << std::endl;
	std::cout << "  2.下午\n" << std::endl;

	do {
		std::cout << "请输入预约的时间段" << std::endl;
		if (std::cin >> r.m_period && (r.m_period == 1 || r.m_period == 2))break;
		std::cout << "输入有误,请重新输入" << std::endl;
		std::cin.clear();/*清空输入缓冲区*/
		std::cin.ignore(std::streamsize(std::numeric_limits<std::streamsize>::max()), '\n');
	} while (true);

	/*输入机房号*/
	std::cout << "机房信息" << std::endl;
	std::cout << " 房号\t容量" << std::endl;
	ComputerRoomFile crf(COMPUTER_FILE);
	for (auto it = crf.m_allRoom.begin(); it != crf.m_allRoom.end(); it++) {
		std::cout << " " << it->first << '\t' << it->second << std::endl;
	}

	do {
		std::cout << "请选择机房" << std::endl;
		if (std::cin >> r.m_roomId) {
			if (crf.m_allRoom.count(r.m_roomId) == 1) break;
			else std::cout << "无对应的机房号";
		}
		else std::cout << "输入有误";
		std::cout << ",请重新输入" << std::endl;
		std::cin.clear();/*清空输入缓冲区*/
		std::cin.ignore(std::streamsize(std::numeric_limits<std::streamsize>::max()), '\n');
	} while (true);

	r.m_status = 1;
	r.m_stuId = this->m_account.m_id;
	r.m_stuName = this->m_account.m_name;

	ReservationFile rsf(RESERVATION_FILE);
	
	bool flag = 1;
	for (int i = 0; i < rsf.m_allResv.size(); i++) {
		if (rsf.m_allResv[i].is_conflict(r) && rsf.m_allResv[i].m_status == 2) {
			std::cout << "该机房已被预约" << std::endl;
			flag = 0;
			break;
		}
	}
	if (flag) {
		rsf.m_allResv.push_back(r);
		std::cout << "预约成功,审核中" << std::endl;
	}
	system("pause");
	system("cls");
}

void Student::showMyRsv() {
	bool empty = true;
	ReservationFile rsf(RESERVATION_FILE);

	for (auto it = rsf.m_allResv.begin(); it != rsf.m_allResv.end(); it++) {
		if (it->m_stuId == this->m_account.m_id) {
			if (empty) {
				std::cout << "您的预约记录如下:" << std::endl;
				empty = false;
			}
			std::cout << "预约时间: "
				<< it->m_date.year << '/' << it->m_date.month << '/' << it->m_date.day
				<< "  时段: " << (it->m_period == 1 ? "上午" : "下午")
				<< "  房号: " << it->m_roomId << "  状态: ";

			//0 取消预约 1 审核中 2 已预约 -1预约失败
			if (it->m_status == 1) std::cout << "审核中" << std::endl;
			else if (it->m_status == 2) std::cout << "已预约" << std::endl;
			else if (it->m_status == -1) std::cout << "预约失败" << std::endl;
			else if (it->m_status == 0) std::cout << "已取消" << std::endl;
		}
	}

	if (empty) std::cout << "您的预约记录为空" << std::endl;

	system("pause");
	system("cls");
}

void Student::cancelRsv() {

	ReservationFile rsf(RESERVATION_FILE);

	std::vector<int> v;/*记录可以取消的预约在rsf.m_allResv的索引*/
	for (int i = 0, j = 0; i < rsf.m_allResv.size(); i++) {
		if (rsf.m_allResv[i].m_stuId == this->m_account.m_id) {
			if (rsf.m_allResv[i].m_status == 1 || rsf.m_allResv[i].m_status == 2) {/*预约状态*/
				if (v.size() == 0) std::cout << "您当前预约记录预约如下:(仅仅显示可取消的预约)" << std::endl;
				v.push_back(i);
				std::cout << ++j << ". "
					<< "预约日期: "
					<< rsf.m_allResv[i].m_date.year << '/'
					<< rsf.m_allResv[i].m_date.month << '/'
					<< rsf.m_allResv[i].m_date.year
					<< " 时段: " << (rsf.m_allResv[i].m_period == 1 ? "上午" : "下午")
					<< " 机房: " << (rsf.m_allResv[i].m_roomId)
					<< " 状态: " << (rsf.m_allResv[i].m_status == 1 ? "审核中" : "已预约") << std::endl;
			}
		}
	}

	if (v.size() == 0) std::cout << "无预约记录" << std::endl;
	else {
		std::cout << "\n请输入取消的预约编号(返回请按0)" << std::endl;
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
			rsf.m_allResv[v[select - 1]].m_status = 0;
			std::cout << "取消预约成功" << std::endl;
		}
	}

	system("pause");
	system("cls");
}
