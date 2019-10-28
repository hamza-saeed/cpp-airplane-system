#include "ServerInterface.h"

using namespace AirplaneServer;

[STAThreadAttribute]
int Main()
{
	//run the GUI
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew ServerInterface());
	return 0;
}
