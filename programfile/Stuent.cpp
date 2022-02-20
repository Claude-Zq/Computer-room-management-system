#include"Student.h"




Student::Student(int id, std::string name, std::string pwd) {
	/*��ʼ������*/
	m_id = id;
	m_name = name;
	m_pwd = pwd;
	initVector();
}

void Student::operMenu() {
	std::cout << "\t\t\t\t\t��ӭ [" << this->m_name << "] ͬѧ��¼" << std::endl;
	std::cout << "\t\t\t\t----------------------------------------" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t|             1.����ԤԼ               |" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t|             2.�鿴�ҵ�ԤԼ           |" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t|             3.�鿴����ԤԼ           |" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t|             4.ȡ��ԤԼ               |" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t|             0.ע����¼               |" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t----------------------------------------" << std::endl;
}


void Student::applyOrder() {

	int date, interval, room;

	/*��������*/
	std::cout << "������ԤԼ��ʱ��Ϊ:" << std::endl;
	std::cout << " 1.��һ" << std::endl;
	std::cout << " 2.�ܶ�" << std::endl;
	std::cout << " 3.����" << std::endl;
	std::cout << " 4.����" << std::endl;
	std::cout << " 5.����\n" << std::endl;
	
	do {
		std::cout << "������ԤԼ��ʱ��" << std::endl;
		if (std::cin >> date && (date > 0 && date < 6))break;
		std::cout << "��������,����������" << std::endl;
		std::cin.clear();/*������뻺����*/
		std::cin.ignore(std::streamsize(std::numeric_limits<std::streamsize>::max()), '\n');
	} while (true);

	/*����ʱ���*/
	std::cout << "��������ʱ���" << std::endl;
	std::cout << "  1.����" << std::endl;
	std::cout << "  2.����\n" << std::endl;

	do {
		std::cout << "������ԤԼ��ʱ���" << std::endl;
		if (std::cin >> interval && (interval == 1 || interval == 2))break;
		std::cout << "��������,����������" << std::endl;
		std::cin.clear();/*������뻺����*/
		std::cin.ignore(std::streamsize(std::numeric_limits<std::streamsize>::max()), '\n');
	} while (true);

	/*���������*/
	std::cout << "������Ϣ" << std::endl;
	std::cout << "ѡ��\t����\t����" << std::endl;
	for (int i = 0; i < vCom.size(); i++) {
		std::cout<<' ' << i + 1 << "\t" << vCom[i].m_comId << "\t" << vCom[i].m_MaxNum << std::endl;
	}

	do {
		std::cout << "��ѡ�����" << std::endl;
		if (std::cin >> room && (room > 0 && room <= vCom.size())) break;
		std::cout << "��������,����������" << std::endl;
		std::cin.clear();/*������뻺����*/
		std::cin.ignore(std::streamsize(std::numeric_limits<std::streamsize>::max()), '\n');
	} while (true);
	
	std::cout << "ԤԼ�ɹ�,�����" << std::endl;
	
	/*д���ļ�*/
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
	int flag = 1;/*û��ԤԼ��¼�ı�־����*/
	for (int i = 0; i < of.m_size; i++) {

		if (atoi(of.m_orderData[i]["stuId"].c_str()) == this->m_id) {
			
			std::cout << "ԤԼʱ��: ��" << of.m_orderData[i]["date"]
				<< "\tʱ��: " << (of.m_orderData[i]["interval"] == "1" ? "����" : "����")
				<< "\t����: " << of.m_orderData[i]["roomId"]<<"\t״̬: ";
			
			int status = atoi(of.m_orderData[i]["status"].c_str());
			//0 ȡ��ԤԼ 1 ����� 2 ��ԤԼ -1ԤԼʧ��
			if (status == 1) std::cout << "�����" << std::endl;
			else if(status == 2) std::cout << "��ԤԼ" << std::endl;
			else if (status == -1) std::cout << "ԤԼʧ��" << std::endl;
			else if (status == 0) std::cout << "��ȡ��" << std::endl;
			flag = 0;
		}
	}
	if(flag) std::cout << "��ԤԼ��¼" << std::endl;
	system("pause");
	system("cls");
}

void Student::showALLOrder() {
	OrderFile of;
	if (of.m_size == 0) std::cout << "��ԤԼ��¼" << std::endl;
	else {
		for (int i = 0; i < of.m_size; i++) {
			std::cout << i + 1 << "��ԤԼʱ��: ��" << of.m_orderData[i]["date"]
				<< "\tʱ��: " << (of.m_orderData[i]["interval"] == "1" ? "����" : "����")
				<< "\tѧ��:" << of.m_orderData[i]["stuId"]
				<<"\t����:"<<of.m_orderData[i]["stuName"]
				<< "\t����: " << of.m_orderData[i]["roomId"] << "\t״̬: ";

			int status = atoi(of.m_orderData[i]["status"].c_str());
			//0 ȡ��ԤԼ 1 ����� 2 ��ԤԼ -1ԤԼʧ��
			if (status == 1) std::cout << "�����" << std::endl;
			else if (status == 2) std::cout << "��ԤԼ" << std::endl;
			else if (status == -1) std::cout << "ԤԼʧ��" << std::endl;
			else if (status == 0) std::cout << "��ȡ��" << std::endl;
		}
	}

	system("pause");
	system("cls");
}

void Student::cancelOrder() {

}


void Student::initVector() {

	vCom.clear();

	std::ifstream ifs;
	ifs.open(COMPUTER_FILE, std::ios::in);/*�򿪻�����Ϣ���ļ�*/
	if (ifs.is_open()) {
		ComputerRoom c;
		while (ifs >> c.m_comId >> c.m_MaxNum) vCom.push_back(c);
	}
	ifs.close();
}