#include "MyForm.h"

using namespace LicensePlateLocate;//ʹ��MyForm.h�ж���������ռ�

[STAThread]//���߳�����

int main(array<System::String^>^args) {
	Application::EnableVisualStyles();
	Application::Run(gcnew MyForm());//����һ�����壬��������Ϣѭ��
	return 0;
}