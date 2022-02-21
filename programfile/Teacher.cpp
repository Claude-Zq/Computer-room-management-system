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

}