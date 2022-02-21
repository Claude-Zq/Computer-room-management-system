#include"Teacher.h"



Teacher::Teacher(int employeeId, std::string name, std::string pwd) {
	/*��ʼ������*/
	m_empId = employeeId;
	m_name = name;
	m_pwd = pwd;
}

void Teacher::operMenu() {
	std::cout << "\t\t\t\t\t  ��ӭ [" << this->m_name << "] ��ʦ��¼" << std::endl;
	std::cout << "\t\t\t\t----------------------------------------" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t|             1.�鿴����ԤԼ           |" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t|             2.���ԤԼ               |" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t|             0.ע����¼               |" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t----------------------------------------" << std::endl;
 }

void Teacher::showAllOrder() {
	OrderFile of;
	if (of.m_size == 0) std::cout << "��ԤԼ��¼" << std::endl;
	else {
		std::cout << "��ǰԤԼ��¼����:" << std::endl;
		for (int i = 0; i < of.m_size; i++) {
			std::cout << i + 1 << "��ԤԼʱ��: ��" << of.m_orderData[i]["date"]
				<< "  ʱ��: " << (of.m_orderData[i]["interval"] == "1" ? "����" : "����")
				<< "  ѧ��:" << of.m_orderData[i]["stuId"]
				<< "  ����:" << of.m_orderData[i]["stuName"]
				<< "  ����: " << of.m_orderData[i]["roomId"]
				<< "  ״̬: ";

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


void Teacher::validOrder() {
	OrderFile of;
	int flag = 1;/*û�д���˵ı�־����*/

	std::vector<int> v;/*���ڴ�Ŵ����ԤԼ��of.m_orderData������*/
	for (int i = 0,j = 0; i < of.m_size; i++) {

		if (atoi(of.m_orderData[i]["status"].c_str()) == 1) {
			v.push_back(i);
			if (flag) std::cout << "����˵�ԤԼ��¼����" << std::endl;
			std::cout << ++j << "��ԤԼʱ��: ��" << of.m_orderData[i]["date"]
				<< "  ʱ��: " << (of.m_orderData[i]["interval"] == "1" ? "����" : "����")
				<< "  ѧ��:" << of.m_orderData[i]["stuId"]
				<< "  ����:" << of.m_orderData[i]["stuName"]
				<< "  ����: " << of.m_orderData[i]["roomId"] << std::endl;
			flag = 0;
		}
	}
	if (flag) std::cout << "�޴���˵�ԤԼ��¼" << std::endl;
	else {
		std::cout << "\n��������˵�ԤԼ���(�����밴0)" << std::endl;
		int select;
		do {
			if (std::cin >> select && (select >= 0 && select <= v.size()))break;
			std::cout << "��������,����������" << std::endl;
			std::cin.clear();/*������뻺����*/
			std::cin.ignore(std::streamsize(std::numeric_limits<std::streamsize>::max()), '\n');
		} while (true);

		if (select == 0) {/*�����Ӳ˵�*/
			std::cout << "�ѷ���" << std::endl;
		}
		else {
			std::cout << "��ѡ��:\n1.ͬ��\n0.��ͬ��" <<std::endl;
			int selection;
			do {
				if (std::cin >> selection && (selection == 1 || selection == 0))break;
				std::cout << "��������,����������" << std::endl;
				std::cin.clear();/*������뻺����*/
				std::cin.ignore(std::streamsize(std::numeric_limits<std::streamsize>::max()), '\n');
			} while (true);

			if (selection == 0) {
				of.m_orderData[v[select - 1]]["status"] = "-1";/*����׼*/
				std::cout << "�Ѿ��ܾ�" << std::endl;
			} 
			else {
				of.m_orderData[v[select - 1]]["status"] = "2";/*��׼*/
				std::cout << "��ͬ��" << std::endl;
			}
			of.updateOrder();
		}

	}
	system("pause");
	system("cls");
	
}