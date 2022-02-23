#include<iostream>
#include"CRMS_manager.h"

int main() {

	/*创建一个管理类对象,管理整个程序的运行*/
	CRMS_manager cm;
	while (true) {
		/*展示菜单*/
		cm.showMenu();

		int select;
		do {
			std::cout << "输入您的选择: " << std::endl;
			if (std::cin >> select) break; /*输入合法性检查*/
			std::cout << "输入有误，请重新输入" << std::endl;
			std::cin.clear();/*清空输入缓冲区*/
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		} while (true);

		switch (select) {
		case 1://学生
			cm.login(1); break;
		case 2://老师
			cm.login(2); break;
		case 3://管理员
			cm.login(3); break;
		case 0://退出
		{
			std::cout << "欢迎下次使用" << std::endl;
			system("pause");
			return 0;
		}
		default:
			std::cout << "无该选项，请重新选择" << std::endl;
			system("pause");
			system("cls");/*按任意键后清屏*/
		}
	}

	return 0;
}