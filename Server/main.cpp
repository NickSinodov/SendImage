#include <QApplication>
#include "Server.h"
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Server server;
	server.startServer();
	return a.exec();
}
