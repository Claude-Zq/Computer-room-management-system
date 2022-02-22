#include"Student.h"

Student::Student(int id, std::string name, std::string pwd) {
	/*初始化属性*/
	m_id = id;
	m_name = name;
	m_pwd = pwd;
	initVector();
}

void Student::operMenu() {
	std::cout << "\t\t\t\t\t欢迎 [" << this->m_name << "] 同学登录" << std::endl;
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
	std::cout << "\t\t\t\t|             0.注销登录               |" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t----------------------------------------" << std::endl;
}

void Student::applyOrder() {

	int date, interval, room;

	/*输入日期*/
	std::cout << "可申请预约的时间为:" << std::endl;
	std::cout << " 1.周一" << std::endl;
	std::cout << " 2.周二" << std::endl;
	std::cout << " 3.周三" << std::endl;
	std::cout << " 4.周四" << std::endl;
	std::cout << " 5.周五\n" << std::endl;
	
	do {
		std::cout << "请输入预约的时间" << std::endl;
		if (std::cin >> date && (date > 0 && date < 6))break;
		std::cout << "输入有误,请重新输入" << std::endl;
		std::cin.clear();/*清空输入缓冲区*/
		std::cin.ignore(std::streamsize(std::numeric_limits<std::streamsize>::max()), '\n');
	} while (true);

	/*输入时间段*/
	std::cout << "机房开放时间段" << std::endl;
	std::cout << "  1.上午" << std::endl;
	std::cout << "  2.下午\n" << std::endl;

	do {
		std::cout << "请输入预约的时间段" << std::endl;
		if (std::cin >> interval && (interval == 1 || interval == 2))break;
		std::cout << "输入有误,请重新输入" << std::endl;
		std::cin.clear();/*清空输入缓冲区*/
		std::cin.ignore(std::streamsize(std::numeric_limits<std::streamsize>::max()), '\n');
	} while (true);

	/*输入机房号*/
	std::cout << "机房信息" << std::endl;
	std::cout << "选项\t房号\t容量" << std::endl;
	for (int i = 0; i < vCom.size(); i++) {
		std::cout<<' ' << i + 1 << "\t" << vCom[i].m_comId << "\t" << vCom[i].m_MaxNum << std::endl;
	}

	do {
		std::cout << "请选择机房" << std::endl;
		if (std::cin >> room && (room > 0 && room <= vCom.size())) break;
		std::cout << "输入有误,请重新输入" << std::endl;
		std::cin.clear();/*清空输入缓冲区*/
		std::cin.ignore(std::streamsize(std::numeric_limits<std::streamsize>::max()), '\n');
	} while (true);
	
	std::cout << "预约成功,审核中" << std::endl;
	
	/*写入文件*/
	std::ofstream ofs(ORDER_FILE, std::ios::app);
	ofs << "date:" << date << " "
		<< "interval:" << interval << " "
		<< "stuId:" << m_id << " "
		<< "stuName:" << m_name << " "
		<< "roomId:" << room << " "
		<< "status:" << 1 << std::endl;

	ofs.close();
	system("pause");
	system("cls");
}

void Student::showMyOrder() {

	OrderFile of;
	int flag = 1;/*没有预约记录的标志变量*/
	for (int i = 0; i < of.m_size; i++) {

		if (atoi(of.m_orderData[i]["stuId"].c_str()) == this->m_id) {
			
			std::cout << "预约时间: 周" << of.m_orderData[i]["date"]
				<< "  时段: " << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午")
				<< "  房号: " << of.m_orderData[i]["roomId"]<<"  状态: ";
			
			int status = atoi(of.m_orderData[i]["status"].c_str());
			//0 取消预约 1 审核中 2 已预约 -1预约失败
			if (status == 1) std::cout << "审核中" << std::endl;
			else if(status == 2) std::cout << "已预约" << std::endl;
			else if (status == -1) std::cout << "预约失败" << std::endl;
			else if (status == 0) std::cout << "已取消" << std::endl;
			flag = 0;
		}
	}
	if(flag) std::cout << "无预约记录" << std::endl;
	system("pause");
	system("cls");
}

void Student::showALLOrder() {
	OrderFile of;
	if (of.m_size == 0) std::cout << "无预约记录" << std::endl;
	else {
		for (int i = 0; i < of.m_size; i++) {
			std::cout << i + 1 << "、预约时间: 周" << of.m_orderData[i]["date"]
				<< "  时段: " << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午")
				<< "  学号:" << of.m_orderData[i]["stuId"]
				<<"  姓名:"<<of.m_orderData[i]["stuName"]
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

void Student::cancelOrder() {
	OrderFile of;

	int flag = 1;/*没有 可取消的预约记录 的 标志变量*/

	
	std::vector<int> v;/*记录可以取消的预约在ofof.m_orderData的索引*/
	for (int i = 0,j = 0; i < of.m_size; i++) {
		if (atoi(of.m_orderData[i]["stuId"].c_str()) == this->m_id) {

			int status = atoi(of.m_orderData[i]["status"].c_str());/*预约状态*/
			if (status == 1 || status == 2) {
				if (flag) {
					flag = 0; /*有记录*/
					std::cout << "您当前预约记录预约如下:(仅仅显示可取消的预约)" << std::endl;
				}
				v.push_back(i);
				std::cout << ++j << ". "
					<< "预约日期: 周" << of.m_orderData[i]["date"]
					<< " 时段: " << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午")
					<< " 机房: " << (of.m_orderData[i]["roomId"])
					<< " 状态: " << (status == 1 ? "审核中" : "已预约") << std::endl;
			}
		}
	}

	if (flag) std::cout << "无预约记录" << std::endl;
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
			of.m_orderData[v[select - 1]]["status"] = "0";
			std::cout << "取消预约成功" << std::endl;
			of.updateOrder();
		}
	}

	system("pause");
	system("cls");
}

void Student::initVector() {

	vCom.clear();

	std::ifstream ifs;
	ifs.open(COMPUTER_FILE, std::ios::in);/*打开机房信息的文件*/
	if (ifs.is_open()) {
		ComputerRoom c;
		while (ifs >> c.m_comId >> c.m_MaxNum) vCom.push_back(c);
	}
	ifs.close();
}