#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include "image.h"
#include <iostream>
using namespace std;
class Server : public QTcpServer
{
	Q_OBJECT
public:
	Server();
	bool startServer();
private:
	QTcpSocket	*m_socket;
	Image		 m_image;
	QImage		 m_loadedImage;

	QByteArray	 m_data;
private slots:
	void incomingConnection(qintptr socketDescriptor);
	void onReadyRead();

};

#endif // SERVER_H
