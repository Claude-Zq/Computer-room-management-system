#include"Manager.h"



Manager::Manager(std::string name , std::string pwd ) {
	initVector();
	this->m_name = name;
	this->m_pwd = pwd;
}

void Manager::operMenu() {

	std::cout << "\t\t\t\t\t欢迎管理员 [" << this->m_name << "] 登录" << std::endl;
	std::cout << "\t\t\t\t----------------------------------------" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t|              1.添加账号              |" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t|              2.查看账号              |" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t|              3.查看机房              |" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t|              4.清空预约              |" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t|              0.注销登录              |" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t----------------------------------------" << std::endl;

}


void Manager::addPerson() {
	std::cout << "请输入添加账号的类型" << std::endl;
	std::cout << "1.添加学生" << std::endl;
	std::cout << "2.添加老师" << std::endl;

	
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
	else if(select == 2) {
		fileName = TEACHER_FILE;
		tip = "请输入职工编号:";
	}
	else {
		std::cout << "无该选项" << std::endl;
		system("pause");
		system("cls");
		return;
	}

	
	int id;
	std::string name, pwd;

	do {/*输入学号/职工号*/
		std::string errorTip;/*错误提示*/
		std::cout << tip << std::endl;
		if (!(std::cin >> id)) errorTip = "输入有误";
		else {
			/*检查是否已有该id号*/
			if (checkRepeat(id, select)) {
				errorTip = "已经有";
				errorTip += (select == 1 ? "学生" : "老师");
				errorTip += "的账号";
			}
			else break;/*有效输入*/
		}
		std::cout << errorTip << "，请重新输入" << std::endl;
		std::cin.clear();/*清空输入缓冲区*/
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	} while (true);

	std::cout << "请输入姓名:" << std::endl;
	std::cin >> name;
	std::cin.clear();/*清空输入缓冲区*/
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::cout << "请输入密码:" << std::endl;
	std::cin >> pwd;
	std::cin.clear();/*清空输入缓冲区*/
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


	std::ofstream ofs;
	ofs.open(fileName, std::ios::out | std::ios::app);/*追加的方式写文件*/

	/*写入文件*/
	ofs << id << " " << name << " " << pwd << " " << std::endl;
	std::cout << "添加成功" << std::endl;
	ofs.close();
	initVector();/*更新容器*/

	system("pause");
	system("cls");
}

void Manager::showPerson() {

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
		if (vStu.empty()) std::cout << "无学生账号记录" << std::endl;
		else {
			std::cout << "学号\t姓名\t密码" << std::endl;
			for (auto it = vStu.begin(); it != vStu.end(); it++) {
				std::cout << it->m_id << '\t' << it->m_name << '\t' << it->m_pwd << std::endl;
			}
		}
	}
	else if (select == 2) {
		if (vTea.empty()) std::cout << "无老师账号记录" << std::endl;
		else {
			std::cout << "职工号\t姓名\t密码" << std::endl;
			for (auto it = vTea.begin(); it != vTea.end(); it++) {
				std::cout << it->m_empId << '\t' << it->m_name << '\t' << it->m_pwd << std::endl;
			}
		}
	}
	else{
		std::cout << "无该选项!" << std::endl;
	}
	system("pause");
	system("cls");

}


void Manager::showComputer() {
	if (vCom.empty()) std::cout << "无机房信息" << std::endl;
	else {
		std::cout << "编号\t容量" << std::endl;
		for (auto it = vCom.begin(); it != vCom.end(); it++) 
			std::cout << it->m_comId << '\t' << it->m_MaxNum << std::endl;
	}
	system("pause");
	system("cls");
}


void Manager::cleanFile() {

	int select;
	std::cout << "请确认是否清空:" << std::endl;
	std::cout << "1.是" << std::endl;
	std::cout << "0.否" << std::endl;

	do {
		if ((std::cin >> select) && (select == 1 || select == 0)) break;
		std::cout << "输入有误，请重新输入" << std::endl;
		std::cin.clear();/*清空输入缓冲区*/
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	} while (true);

	if (select == 1) {
		std::ofstream ofs(ORDER_FILE, std::ios::trunc);/*创建一个空文件覆盖掉原有的文件*/
		ofs.close();
		std::cout << "清空成功" << std::endl;
	}
	else std::cout << "已取消" << std::endl;
	system("pause");
	system("cls");
}


void Manager::initVector() {

	vStu.clear();
	vTea.clear();
	vCom.clear();
	
	//读取学生文件中的信息
	std::ifstream ifs;
	ifs.open(STUDENT_FILE, std::ios::in);

	if (ifs.is_open()) {
		Student s;
		while (ifs >> s.m_id >> s.m_name >> s.m_pwd) vStu.push_back(s);
	}
	ifs.close();/*学生账号信息初始化完成*/


	/*读取老师的文件信息*/
	ifs.open(TEACHER_FILE, std::ios::in);
	if (ifs.is_open()) {
		Teacher t;
		while (ifs >> t.m_empId >> t.m_name >> t.m_pwd) vTea.push_back(t);
	}
	ifs.close();/*教师账号信息初始化完成*/

	/*读取机房的文件信息*/
	ifs.open(COMPUTER_FILE, std::ios::in);
	if(ifs.is_open()) {
		ComputerRoom c;
		while (ifs >> c.m_comId >> c.m_MaxNum) vCom.push_back(c);
	}
	ifs.close();/*机房信息初始化完成*/
}


bool Manager::checkRepeat(int id, int type) {
	if (type == 1) {
		for (std::vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
			if (id == it->m_id)  return true;	
	}
	else if (type == 2) {
		for (std::vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
			if (id == it->m_empId) return true;
	}
	else {
		std::cout << "checkRepeat的参数type有误" << std::endl;
	}
	return false;
}