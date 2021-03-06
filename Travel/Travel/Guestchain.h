#pragma once
#include<iostream>
#include<string>

using namespace std;

//游客的单链表
class guestchain {
public:
	int guestId;
	string name;
	guestchain *next;

	//构造函数
	//guestchain(int id,char* thename):guestId(id),name(thename),next(NULL){}
	guestchain(int id, string itsname) :guestId(id), name(itsname), next(NULL) {}
	guestchain(int id) :guestId(id), name("默认"), next(NULL) {}

	//方法
	void printall();
	int insertchain(int id, string itsname, guestchain *chainpoint);
	guestchain* deletechain(int id, guestchain *chainpoint);
	int countNum(guestchain *chain);
	guestchain* chainsearch(int id, guestchain *&chainpoint);
};

//单链表输出
//chpoint 为单链表指针
void guestchain::printall()
{
	guestchain* headpoint = this;
	if (headpoint == NULL) {
		return;
	}
	else
	{
		cout << "当前ID为：	" << "姓名：" << endl;
		while (NULL != headpoint->next) {
			cout << headpoint->guestId << "	 	";
			cout << headpoint->name << endl;
			headpoint = headpoint->next;
		}
	}
	cout << headpoint->guestId << "		 ";
	cout << headpoint->name << "	" << endl;
}

//单链表插入
int guestchain::insertchain(int id, string itsname, guestchain *chain)
{
	while (NULL != chain->next) {
		chain = chain->next;
	}
	chain->next = new guestchain(id, itsname);
	return 0;
}

//单链表删除
//id 要删除的结点
//chpoint 单链表指针
//返回 guestchain指针
guestchain* guestchain::deletechain(int id, guestchain *chpoint)
{
	guestchain *prtbef = chpoint;			//前驱指针
	guestchain *prtdel = chpoint;			//删除指针
	if (chpoint->guestId == id) {			//如果是头结点的删除
		prtbef = chpoint;
		chpoint = chpoint->next;
		delete prtbef;
		return chpoint;
	}
	while (prtdel->guestId != id && prtdel->next != NULL)
	{
		prtbef = prtdel;
		prtdel = prtdel->next;
	}
	if (prtdel->guestId == id) {
		prtbef->next = prtdel->next;
		delete prtdel;
	}
	return chpoint;
}

//单链表计数
//chpoint 单链表指针
int guestchain::countNum(guestchain *chpoint)
{
	int num = 1;
	while (NULL != chpoint->next) {
		chpoint = chpoint->next;
		num++;
	}
	cout << num << endl;
	return num;
}

//单链表的查找
//id 要查找元素
//chainpoint 单链表指针
guestchain* guestchain::chainsearch(int id, guestchain *&chainpoint)
{
	guestchain *prtbef = chainpoint;		//前驱指针
	if (chainpoint->next == NULL) {
		if (chainpoint->guestId == id) {
			return prtbef;
		}
		else
		{
			return NULL;
		}
	}

	while (chainpoint->next != NULL)
	{
		prtbef = chainpoint;
		if (chainpoint->guestId == id) {
			return prtbef;
		}
		chainpoint = chainpoint->next;
	}
	//如果到最后都没匹配到，则返回空指针
	if (chainpoint->guestId != id) {
		chainpoint = NULL;
		return chainpoint;
	}
	else
	{
		return chainpoint;
	}
}



