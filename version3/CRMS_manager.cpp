#include"CRMS_manager.h"



/*չʾ���˵�*/
void CRMS_manager::showMenu() {
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
}

/*��¼ ѧ��:1 ��ʦ:2 ����Ա:3*/
void CRMS_manager::login(int type) {

	Account a;

	/*�����˺�*/
	std::cout << "�������˺�" << std::endl;
	std::cin >> a.m_id;
	std::cin.clear();/*������뻺����*/
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


	/*��������*/
	std::cout << "����������" << std::endl;
	std::cin >> a.m_name;
	std::cin.clear();/*������뻺����*/
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


	/*��������*/
	std::cout << "����������" << std::endl;
	std::cin >> a.m_pwd;
	std::cin.clear();/*������뻺����*/
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::string fileName;
	if (type == 1) fileName = STUDENT_FILE;
	else if (type == 2) fileName = TEACHER_FILE;
	else if (type == 3) fileName = ADMIN_FILE;
	AccountFile af(fileName);

	int ret = af.verify(a);

	if (ret == 0) std::cout << "�˺Ŵ���" << std::endl;
	else if (ret == 1) std::cout << "��¼�ɹ�" << std::endl;
	else if (ret == -1) std::cout << "�������" << std::endl;
	else if (ret == 2) std::cout << "��������" << std::endl;

	system("pause");
	system("cls");

	if (ret == 1) {
		/*ѧ��*/
		if (type == 1) { 
			std::cout << "ѧ���û�����" << std::endl;
		}
		/*��ʦ*/
		else if (type == 2) {
			std::cout << "��ʦ�û�����" << std::endl;
		}
		/*����Ա*/
		else if (type == 3) {
			std::cout << "����Ա�û�����" << std::endl;
		}
		system("pause");
		system("cls");
	}
}

/*ѧ���û�����*/
void CRMS_manager::stu_interface() {

}

/*��ʦ�û�����*/
void CRMS_manager::tea_interface() {

}

/*����Ա�û�����*/
void CRMS_manager::admin_interface() {

}