#include<iostream>



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
			break;
		case 2://��ʦ
			break;
		case 3://����Ա
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




