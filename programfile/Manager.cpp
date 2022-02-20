#include"Manager.h"



Manager::Manager(std::string name , std::string pwd ) {
	initVector();
	this->m_name = name;
	this->m_pwd = pwd;
}

void Manager::operMenu() {

	std::cout << "\t\t\t\t\t��ӭ����Ա [" << this->m_name << "] ��¼" << std::endl;
	std::cout << "\t\t\t\t----------------------------------------" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t|              1.����˺�              |" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t|              2.�鿴�˺�              |" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t|              3.�鿴����              |" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t|              4.���ԤԼ              |" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t|              0.ע����¼              |" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t----------------------------------------" << std::endl;

}


void Manager::addPerson() {
	std::cout << "����������˺ŵ�����" << std::endl;
	std::cout << "1.���ѧ��" << std::endl;
	std::cout << "2.�����ʦ" << std::endl;

	
	int select;
	do {
		std::cout << "��������ѡ��: " << std::endl;
		if (std::cin >> select) break; /*����Ϸ��Լ��*/
		std::cout << "������������������" << std::endl;
		std::cin.clear();/*������뻺����*/
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	} while (true);


	std::string fileName, tip;
	if (select == 1) {
		fileName = STUDENT_FILE;
		tip = "������ѧ��:";
	}
	else if(select == 2) {
		fileName = TEACHER_FILE;
		tip = "������ְ�����:";
	}
	else {
		std::cout << "�޸�ѡ��" << std::endl;
		system("pause");
		system("cls");
		return;
	}

	
	int id;
	std::string name, pwd;

	do {/*����ѧ��/ְ����*/
		std::string errorTip;/*������ʾ*/
		std::cout << tip << std::endl;
		if (!(std::cin >> id)) errorTip = "��������";
		else {
			/*����Ƿ����и�id��*/
			if (checkRepeat(id, select)) {
				errorTip = "�Ѿ���";
				errorTip += (select == 1 ? "ѧ��" : "��ʦ");
				errorTip += "���˺�";
			}
			else break;/*��Ч����*/
		}
		std::cout << errorTip << "������������" << std::endl;
		std::cin.clear();/*������뻺����*/
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	} while (true);

	std::cout << "����������:" << std::endl;
	std::cin >> name;
	std::cin.clear();/*������뻺����*/
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::cout << "����������:" << std::endl;
	std::cin >> pwd;
	std::cin.clear();/*������뻺����*/
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


	std::ofstream ofs;
	ofs.open(fileName, std::ios::out | std::ios::app);/*׷�ӵķ�ʽд�ļ�*/

	/*д���ļ�*/
	ofs << id << " " << name << " " << pwd << " " << std::endl;
	std::cout << "��ӳɹ�" << std::endl;
	ofs.close();
	initVector();/*��������*/

	system("pause");
	system("cls");
}

void Manager::showPerson() {

	std::cout << "---------------------------------" << std::endl;
	std::cout << "|\t 1.�鿴����ѧ��\t\t|" << std::endl;
	std::cout << "|\t 2.�鿴������ʦ\t\t|" << std::endl;
	std::cout << "---------------------------------" << std::endl;

	int select = 0;
	do {
		std::cout << "����������ѡ��:" << std::endl;
		if (std::cin >> select) break;
		std::cout << "������������������" << std::endl;
		std::cin.clear();/*������뻺����*/
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	} while (true);

	if (select == 1) {
		if (vStu.empty()) std::cout << "��ѧ���˺ż�¼" << std::endl;
		else {
			std::cout << "ѧ��\t����\t����" << std::endl;
			for (auto it = vStu.begin(); it != vStu.end(); it++) {
				std::cout << it->m_id << '\t' << it->m_name << '\t' << it->m_pwd << std::endl;
			}
		}
	}
	else if (select == 2) {
		if (vTea.empty()) std::cout << "����ʦ�˺ż�¼" << std::endl;
		else {
			std::cout << "ְ����\t����\t����" << std::endl;
			for (auto it = vTea.begin(); it != vTea.end(); it++) {
				std::cout << it->m_empId << '\t' << it->m_name << '\t' << it->m_pwd << std::endl;
			}
		}
	}
	else{
		std::cout << "�޸�ѡ��!" << std::endl;
	}
	system("pause");
	system("cls");

}


void Manager::showComputer() {

}


void Manager::cleanFile() {

}


void Manager::initVector() {

	vStu.clear();
	vTea.clear();
	
	//��ȡѧ���ļ��е���Ϣ
	std::ifstream ifs;
	ifs.open(STUDENT_FILE, std::ios::in);

	if (ifs.is_open()) {
		Student s;
		while (ifs >> s.m_id >> s.m_name >> s.m_pwd) vStu.push_back(s);
	}
	ifs.close();/*ѧ����ʼ�����*/


	/*��ȡ��ʦ���ļ���Ϣ*/
	ifs.open(TEACHER_FILE, std::ios::in);
	if (ifs.is_open()) {
		Teacher t;
		while (ifs >> t.m_empId >> t.m_name >> t.m_pwd) vTea.push_back(t);
	}
	ifs.close();/*ѧ����ʼ�����*/
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
		std::cout << "checkRepeat�Ĳ���type����" << std::endl;
	}
	return false;
}