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
			Student stu(a);
			stu_interface(stu);
		}
		/*��ʦ*/
		else if (type == 2) {
			std::cout << "��ʦ�û�����" << std::endl;
		}
		/*����Ա*/
		else if (type == 3) {
			Administrator admin(a);
			admin_interface(admin);
		}
	}
}

/*ѧ���û�����*/
void CRMS_manager::stu_interface(Student& s) {
	while (true) {
		//ѧ���˵�
		s.showMenu();
		int select = 0;/*�����û���ѡ��*/
		do {
			std::cout << "��������ѡ��: " << std::endl;
			if (std::cin >> select) break; /*����Ϸ��Լ��*/
			std::cout << "������������������" << std::endl;
			std::cin.clear();/*������뻺����*/
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		} while (true);

		if (select == 1) {
			/*����ԤԼ*/
			s.applyRsv();
		}
		else if (select == 2) {
			/*�鿴�ҵ�ԤԼ*/
			s.showMyRsv();
		}
		else if (select == 3) {
			/*�鿴����ԤԼ*/
			s.showAllRsv();
		}
		else if (select == 4) {
			/*ȡ��ԤԼ*/
			s.cancelRsv();
		}
		else if (select == 5) {
			/*�޸�����*/
			s.changePwd();
		}
		else if (select == 0) {
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

/*��ʦ�û�����*/
void CRMS_manager::tea_interface() {

}

/*����Ա�û�����*/
void CRMS_manager::admin_interface(Administrator& a) {
	
	while (true) {
		//����Ա�˵�
		a.showMenu();
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
			a.addAccount();
		}
		else if (select == 2) {
			/*�鿴�˺�*/
			a.showAccount();
		}
		else if (select == 3) {
			/*ɾ���˺�*/
			a.deleteAccount();
		}
		else if (select == 4) {
			/*�޸�����*/
			a.changePwd();

		}
		else if (select == 5) {
			/*��ӻ���*/
			a.addComputerRoom();
		}
		else if (select == 6) {
			/*�鿴����*/
			a.showComputerRoom();
		}
		else if (select == 7) {
			/*�޸Ļ���*/
			a.modifyComputerRoom();
		}
		else if (select == 8) {
			/*���ԤԼ*/
			a.clearRsv();
		}
		else if (select == 0) {
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