#include<iostream>
#include"CRMS_manager.h"

int main() {

	/*����һ�����������,�����������������*/
	CRMS_manager cm;
	while (true) {
		/*չʾ�˵�*/
		cm.showMenu();

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
			cm.login(1); break;
		case 2://��ʦ
			cm.login(2); break;
		case 3://����Ա
			cm.login(3); break;
		case 0://�˳�
		{
			std::cout << "��ӭ�´�ʹ��" << std::endl;
			system("pause");
			return 0;
		}
		default:
			std::cout << "�޸�ѡ�������ѡ��" << std::endl;
			system("pause");
			system("cls");/*�������������*/
		}
	}

	return 0;
}