#include<iostream>



int main() {

	

	while (true) {
		std::cout << "\t\t\t\t==========欢迎来到机房预约系统==========" << std::endl;
		std::cout << "\t\t\t\t----------------------------------------" << std::endl;
		std::cout << "\t\t\t\t|                                      |" << std::endl;
		std::cout << "\t\t\t\t|              1.学生代表              |" << std::endl;
		std::cout << "\t\t\t\t|                                      |" << std::endl;
		std::cout << "\t\t\t\t|                                      |" << std::endl;
		std::cout << "\t\t\t\t|              2.老师                  |" << std::endl;
		std::cout << "\t\t\t\t|                                      |" << std::endl;
		std::cout << "\t\t\t\t|                                      |" << std::endl;
		std::cout << "\t\t\t\t|              3.管理员                |" << std::endl;
		std::cout << "\t\t\t\t|                                      |" << std::endl;
		std::cout << "\t\t\t\t|                                      |" << std::endl;
		std::cout << "\t\t\t\t|              0.退出                  |" << std::endl;
		std::cout << "\t\t\t\t|                                      |" << std::endl;
		std::cout << "\t\t\t\t----------------------------------------" << std::endl;

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
			break;
		case 2://老师
			break;
		case 3://管理员
			break;
		case 0://退出
			std::cout << "欢迎下次使用" << std::endl;
			system("pause");
			return 0;
			break;
		default:
			std::cout << "无该选项，请重新选择" << std::endl;
			system("pause");
			system("cls");/*按任意键后清屏*/
			break;
		}


	}
	

	system("pause");
	return 0;
}




