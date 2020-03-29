/*
//封装函数希纳是该界面，   如void show Menu()
//在main函数中调用封装号的函数

*******************通讯录管理系统******************
1、系统需求：
添加联系人：包括：姓名，性别，年龄，电话号码，家庭住址，最多可记录1000人
显示联系人：显示联系人的所有信息
删除联系人：按照姓名删除指定联系人
查找联系人：按姓名
修改联系人：按照姓名修改
清空联系人：清空通讯录的所有信息
退出通讯录：

*/
#include <iostream>
#include <string>
#define max 1000		//最大存储人数
using namespace std;


//********************************打印菜单界面****************************
void showMenu()
{
	cout << "*******************************" << endl ;
	cout << "*******  1、添加联系人  *******" << endl ;
	cout << "*******  2、显示联系人  *******" << endl ;
	cout << "*******  3、删除联系人  *******" << endl ;
	cout << "*******  4、查找联系人  *******" << endl ;
	cout << "*******  5、修改联系人  *******" << endl ;
	cout << "*******  6、清空联系人  *******" << endl ;
	cout << "*******  0、退出通讯录  *******" << endl ;
	cout << "*******************************" << endl << endl;
}

//********************************一、添加联系人*******************************

//1、设计联系人结构体
	struct Person
	{
		string name;
		string genders;
		int age = 0;
		string tel;
		string addr;
	};

//2、设计通讯录结构体
	struct AddrBooks
	{
		Person perArr[max];  //保存的联系人数组   关键字struct 可以省略
		int size =0;   //通讯录中人员个数
	};

//  4、封装 添加联系人 的函数
	void addPerson(AddrBooks* abs)
	{
		if (abs->size >= max)
		{
			//判断人数是否超出
			cout << "通讯录已满，请求失败" << endl;
			return;
		}
		else		//添加联系人
		{
			//姓名
			string name;
			cout << "\t请输入姓名：" << endl;
			cin >> name;
			abs->perArr[abs->size].name = name;

			//性别
			string genders;
			cout << "\t请输入性别：(男 or 女)" << endl;
			while (true)
			{				
				cin >> genders;
				if (genders == "男" || genders == "女")  //判断输入是否正确
				{
					abs->perArr[abs->size].genders = genders;  //利用当前的人员个数添加联系人 
					break;  //输入正确，退出循环
				}
				cout << "\t输入错误！请重新输入性别：(男 or 女)" << endl; 
			}

			//年龄
			cout << "\t请输入年龄：" << endl;
			int age = 0;
			cin >> age;
			abs->perArr[abs->size].age = age;

			//电话
			cout << "\t请输入电话号码：" << endl;
			string tel;
			cin >> tel;
			abs->perArr[abs->size].tel = tel;

			//住址
			cout << "\t请输入家庭住址：" << endl;
			string addr;
			cin >> addr;
			abs->perArr[abs->size].addr = addr;

			//更新通讯录人数

			abs->size++;
			cout  << "\t添加成功" << endl;


			system("pause");  //请按任意键继续
			system("cls");	//清除屏幕
		}			
	}

//********************************二、显示联系人***************************
	void showPerson(AddrBooks* abs)
	{
		if (abs->size == 0)
		{
			cout << "\t当前记录为空，请添加联系人" << abs->perArr->name << endl;
		}
		else
		{
			for (int i = 0; i < abs->size; i++)
			{
				cout << "姓名：" << abs->perArr[i].name ;
				cout << "\t性别：" << abs->perArr[i].genders ;
				cout << "\t年龄：" << abs->perArr[i].age ;
				cout << "\t电话：" << abs->perArr[i].tel;
				cout << "\t住址：" << abs->perArr[i].addr << endl;
			}
		}
		system("pause");
		system("cls");
	}

//********************************三、删除联系人*****************************
	//3.1如果存在，返回联系人在数组中的具体位置，如果不存在，进行提示
	int isExist(AddrBooks* abs, string name)
	{
		for (int i = 0; i < abs->size; i++)
		{
			if (abs->perArr[i].name == name)
				return i;//找到了，返回这个人在数组中的下标编号

		}
		return -1;//没有找到，返回-1
	}
//*******3.1 开始删除联*****************
	void delPer(AddrBooks* abs)
	{
		cout << "请输入您要删除的联系人：" << endl;
		string name;
		cin >> name;
		//ret == -1	未查到
		//ret == 1	查到了
		int ret = isExist(abs, name);
		if (ret != -1)
		{
			//查到此人    
			//删除方法：删除此人后，将通讯录中此人后面的人员向前移动一个位置
			for (int i = ret; i < abs->size; i++)
			{
				//数据向前移动
				abs->perArr[i] = abs->perArr[i + 1];
			}
			abs->size--;  //更新通讯录中的人员数
			cout << "删除成功" << endl;
		}
		else
		{
			cout << "查无此人" << endl;
		}
		system("pause");
		system("cls");
	}


//**********************四、查找联系人************************
	void findPer(AddrBooks* abs)
	{
		cout << "请输入您要查找的联系人" << endl;
		string name;
		cin >> name;
		int ret =isExist(abs, name);   //isTxist 是有返回值的封装函数，所以不需要加取值符&

		if (ret != -1)      //找到人了
		{
			cout << "姓名：" << abs->perArr[ret].name << "\t";
			cout << "性别：" << abs->perArr[ret].genders << "\t";
			cout << "年龄：" << abs->perArr[ret].age << "\t";
			cout << "电话：" << abs->perArr[ret].tel << "\t";
			cout << "住址：" << abs->perArr[ret].addr << endl;

		}
		else	//没找到
		{
			cout << "查无此人" << endl;
		}

		system("pause");//按任意键
		system("cls");	//清除屏幕
	}
	

//*******************五、修改联系人***********************
	void modifyPer(AddrBooks* abs)
	{
		cout << "请输入要修改的联系人" << endl;
		string name;
		cin >> name;
		int ret = isExist(abs, name);
		if (ret != -1)		//找到指定联系人
		{			
			cout << "请输入要修改的姓名：" << endl;	// 姓名
			string name; 
			cin >> name;
			abs->perArr[ret].name = name;

			cout << "请输入要修改的性别：" << endl; // 性别
			string genders;
			
			while (true)
			{
				cin >> genders;
				if (genders == "男" || genders == "女")
				{
					//输入正确，退出循环
					abs->perArr[ret].genders = genders;
					break;
				}
				cout << "输入有误，请重新输入" << endl;
			}

			cout << "请输入要修改的年龄：" << endl;//年龄
			int age = 0;
			cin >> age;
			abs->perArr[ret].age = age;

			cout << "请输入要修改的电话：" << endl; //电话
			string tel;
			cin >> tel;
			abs->perArr[ret].tel = tel;

			cout << "请输入要修改的家庭住址：" << endl; //地址
			string addr;
			cin >> addr;
			abs->perArr[ret].addr = addr;


			cout << "修改成功!" << endl;



		 }
		else//没找到
		{
			cout << "查无此人" << endl;
		}


		system("pause");//按任意键
		system("cls");	//清除屏幕
	}

//******************六、清空联系人***************************

	//给与选择是否要清空
	//恢复联系人

	void clePer(AddrBooks* abs)
	{
		abs->size = 0;
		cout << "通讯录已清空" << endl;
		
		system("pause");
		system("cls");

	}



int main()
{	
	//3、main函数中创建通讯录

	AddrBooks abs;
	abs.size = 0;	//初始化人员个数


	int select = 0;
	while (true)   //********重要********输入0时为假，退出系统。输入非0时为真，返回到showMenu
	{	
		showMenu();
		cout << "请输入数字进行操作：";
		cin >> select;
		switch (select)
		{
		case 1:		//添加联系人：包括：姓名，性别，年龄，电话号码，家庭住址，最多可记录1000人	
			addPerson(&abs);	//利用地址传递可以修改实参中的值
			break;
		case 2:		//显示联系人：显示联系人的所有信息	
			showPerson(&abs);
			break;
		case 3:		//删除联系人：按照姓名删除指定联系人	
		//{	//******************************当代码长度过长时，需要加大括号变成局部标量
		//	cout << "请输入删除联系人姓名：" << endl;
		//	string name;
		//	cin >> name;
		//	if (isExist(&abs, name) == -1)
		//	{
		//		cout << "查无此人" << endl;
		//	}
		//	else
		//	{
		//		cout << "找到此人" << endl;
		//	}
		//}
			delPer(&abs);
			break;
		case 4:		//查找联系人：按姓名	
			findPer(&abs);
			break;
		case 5:		//修改联系人：按照姓名修改		
			modifyPer(&abs);
			break;
		case 6:		//清空联系人：清空通讯录的所有信息		
			clePer(&abs);
			break;
		case 0:		//退出通讯录：
			cout << endl << "\t退出成功，再见" << endl << endl;
			system("pause");	//按 任意键 继续
			return 0;
			break;
		default:
			break;
		}
	}


	system("pause");
	return 0;
}