#include<iostream>
#include"globalFile.h"
#include"Identity.h"
#include<fstream>
#include<string>
#include"Student.h"
#include"Teacher.h"
#include"Manager.h"
#include"OrderFile.h"


//��¼����
void LogIn(std::string fileName, int type);

//�������Ա�Ӳ˵�����
void managerMenu(Identity*& manager);

//����ѧ���Ӳ˵�����
void studentMenu(Identity*& student);

int main() {

	
	while (true) {
		std::cout << "\t\t\t\t==========��ӭ��������ԤԼϵͳ==========" << std::endl;
		std::cout << "\t\t\t\t----------------------------------------" << std::endl;
		std::cout << "\t\t\t\t|                                      |" << std::endl;
		std::cout << "\t\t\t\t|              1.ѧ������              |" << std::endl;
		std::cout << "\t\t\t\t|                                      |" << std::endl;
		std::cout << "\t\t\t\t|                                      |" << std::endl;
		std::cout << "\t\t\t\t|              2.��ʦ                  |" << std::endl;
		std::cout << "\t\t\t\t|                                      |" << std::endl;
		std::cout << "\t\t\t\t|                                      |" << std::endl;
		std::cout << "\t\t\t\t|              3.����Ա                |" << std::endl;
		std::cout << "\t\t\t\t|                                      |" << std::endl;
		std::cout << "\t\t\t\t|                                      |" << std::endl;
		std::cout << "\t\t\t\t|              0.�˳�                  |" << std::endl;
		std::cout << "\t\t\t\t|                                      |" << std::endl;
		std::cout << "\t\t\t\t----------------------------------------" << std::endl;

		int select;
		do {
			std::cout << "��������ѡ��: " << std::endl;
			if (std::cin >> select) break; /*����Ϸ��Լ��*/
			std::cout << "������������������" << std::endl;
			std::cin.clear();/*������뻺����*/
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		} while (true);

		switch (select) {
		case 1://ѧ��
			LogIn(STUDENT_FILE, 1);
			break;
		case 2://��ʦ
			LogIn(TEACHER_FILE, 2);
			break;
		case 3://����Ա
			LogIn(ADMIN_FILE, 3);
			break;
		case 0://�˳�
			std::cout << "��ӭ�´�ʹ��" << std::endl;
			system("pause");
			return 0;
			break;
		default:
			std::cout << "�޸�ѡ�������ѡ��" << std::endl;
			system("pause");
			system("cls");/*�������������*/
			break;
		}


	}
	

	system("pause");
	return 0;
}



void LogIn(std::string fileName, int type) {
	Identity* pPerson = NULL;
	std::ifstream ifs;
	ifs.open(fileName, std::ios::in);

	//�ļ����������
	if (!ifs.is_open()) {
		std::cout << "�ļ�������" << std::endl;
		ifs.close();
		return;
	}

	/*�����û���Ϣ*/
	int id = 0;
	std::string name;
	std::string pwd;

	//ѧ����¼
	if (type == 1) {
		do {
			std::cout << "���������ѧ��" << std::endl;
			if (std::cin >> id) break; /*����Ϸ��Լ��*/
			std::cout << "������������������" << std::endl;
			std::cin.clear();/*������뻺����*/
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		} while (true);
	}
	//��ʦ��¼
	else if (type == 2) {
		do {
			std::cout << "���������ְ����" << std::endl;
			if (std::cin >> id) break; /*����Ϸ��Լ��*/
			std::cout << "������������������" << std::endl;
			std::cin.clear();/*������뻺����*/
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		} while (true);
	}
	std::cout << "�������û���" << std::endl;
	std::cin >> name;
	std::cin.clear();/*������뻺����*/
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << "����������" << std::endl;
	std::cin >> pwd;
	std::cin.clear();/*������뻺����*/
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	if (type == 1) {
		//ѧ����¼��֤
		int fId;/*���ļ��л�ȡ��id��*/
		std::string fName, fPwd;/*���ļ��л�ȡ������������*/
		while (ifs >> fId >> fName >> fPwd) {
			if (id == fId && name == fName && pwd == fPwd) {
				std::cout << "ѧ����¼��֤�ɹ�!" << std::endl;
				system("pause");
				system("cls");
				pPerson = new Student(id, name, pwd);
				studentMenu(pPerson);
				return;
			}
		}
	}
	else if (type == 2) {
		//��ʦ��¼��֤
		int fId;/*���ļ��л�ȡ��id��*/
		std::string fName, fPwd;/*���ļ��л�ȡ������������*/
		while (ifs >> fId >> fName >> fPwd) {
			if (id == fId && name == fName && pwd == fPwd) {
				std::cout << "��ʦ��¼��֤�ɹ�!" << std::endl;
				system("pause");
				system("cls");
				pPerson = new Teacher(id, name, pwd);
				return;
			}
		}
	}
	else if (type == 3) {
		//����Ա��¼��֤
		std::string fName, fPwd;/*���ļ��л�ȡ������������*/
		while (ifs >> fName >> fPwd) {
			if (name == fName && pwd == fPwd) {
				std::cout << "����Ա��¼��֤�ɹ�!" << std::endl;
				system("pause");
				system("cls");
				//�����������
				pPerson = new Manager(name, pwd);
				managerMenu(pPerson);
				return;
			}
		}
	}

	std::cout << "��¼ʧ��" << std::endl;
	system("pause"); /*�������������*/
	system("cls");
	return;
}


//����Ա�˵�
void managerMenu(Identity*& manager) {
	while (true) {
		//����Ա�˵�
		manager->operMenu();

		/*������Indentity��ָ��ת��Ϊ����Manager��ָ���Ե�������������ӿ�*/
		Manager* pMan = (Manager*)manager;
		
		int select = 0;/*�����û���ѡ��*/
		do {
			std::cout << "��������ѡ��: " << std::endl;
			if (std::cin >> select) break; /*����Ϸ��Լ��*/
			std::cout << "������������������" << std::endl;
			std::cin.clear();/*������뻺����*/
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		} while (true);

		if (select == 1) {
			/*����˺�*/
			std::cout << "[����˺�]" << std::endl;
			pMan->addPerson();
		}
		else if (select == 2) {
			/*�鿴�˺�*/
			std::cout << "\t   [�鿴�˺�]" << std::endl;
			pMan->showPerson();
		}
		else if (select == 3) {
			/*�鿴����*/
			std::cout << "������Ϣ����:\n" << std::endl;
			pMan->showComputer();
		}
		else if (select == 4) {
			/*���ԤԼ*/
			pMan->cleanFile();
		}
		else if (select == 0) {
			delete manager;
			std::cout << "ע���ɹ�" << std::endl;
			system("pause");
			system("cls");
			return;
		}
		else {
			std::cout << "�޸�ѡ�����������" << std::endl;
			system("pause");
			system("cls");
		}
		
	}
}


//ѧ���˵�
void studentMenu(Identity*& student) {
	while (true) {
		/*ѧ���˵�*/
		student->operMenu();

		Student* pStu = (Student*)student;

		int select;/*�����û���ѡ��*/
		do {
			std::cout << "��������ѡ��: " << std::endl;
			if (std::cin >> select) break; /*����Ϸ��Լ��*/
			std::cout << "������������������" << std::endl;
			std::cin.clear();/*������뻺����*/
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		} while (true);

		if (select == 1) { /*����ԤԼ*/
			pStu->applyOrder();
		}
		else if (select == 2) { //�鿴����ԤԼ
			pStu->showMyOrder();
		}
		else if (select == 3) {/*�鿴����ԤԼ*/
			pStu->showALLOrder();
		}
		else if (select == 4) {/*ȡ��ԤԼ*/
			pStu->cancelOrder();
		}
		else if (select == 0) {
			delete student;
			std::cout << "ע���ɹ�" << std::endl;
			system("pause");
			system("cls");
			return;
		}
		else {
			std::cout << "�޸�ѡ�����������" << std::endl;
			system("pause");
			system("cls");
		}
	}
}