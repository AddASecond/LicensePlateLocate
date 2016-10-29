#include "MyForm.h"

using namespace LicensePlateLocate;//使用MyForm.h中定义的命名空间

[STAThread]//单线程特性

int main(array<System::String^>^args) {
	Application::EnableVisualStyles();
	Application::Run(gcnew MyForm());//创建一个窗体，并进入消息循环
	return 0;
}