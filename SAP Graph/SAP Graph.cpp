// SAP Graph.cpp: ������� ���� �������.

#include "stdafx.h"

#include "NewProj.h"
#include "Form1.h"

bool good;
bool wei, ori;
bool again;
using namespace SAPGraph;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	good=false;
	// ��������� ���������� �������� Windows XP �� �������� �����-���� ��������� ����������
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// �������� �������� ���� � ��� ������

here:	Application::Run(gcnew NewProj());
	if(good==true)
	Application::Run(gcnew Form1(wei,ori));
	if(again){
		again=false;
		good=false;
		goto here;
	}

	return 0;
}
