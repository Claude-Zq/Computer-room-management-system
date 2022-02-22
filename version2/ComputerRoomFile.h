#pragma once
#include<map>
#include<fstream>
#include<string>
#include<iostream>


/*文件默认格式为 机房号 容量*/
/*对象只会在构造函数中读取文件信息，析构时才保存，所以请勿对同一文件同时使用两个ComputerRoomFile对象*/
class ComputerRoomFile {
	
public:
	
	/*所有的机房信息 编号-容量*/
	std::map<int, int> m_allRoom;

	/*文件是否打开成功*/
	bool m_isOpen;

	/*构造函数*/
	ComputerRoomFile(std::string fileName);

	/*析构函数*/
	~ComputerRoomFile();


private:
	/*初始化容器*/
	void initMap();

	/*将容器内的信息保存到文件中*/
	void saveMap();

	/*管理的文件名*/
	std::string m_fileName;

};