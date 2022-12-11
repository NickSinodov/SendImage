#include "Server.h"

Server::Server()
{

}

bool Server::startServer()
{
	m_image.show();
	if(!this->listen(QHostAddress::Any, 2323))
	{
		cout << "error: " <<	errorString().toStdString() << endl;
		return false;
	}
	cout << "Server started!" << endl;
	return true;
}

void Server::incomingConnection(qintptr socketDescriptor)
{
	m_socket = new QTcpSocket;
	m_socket->setSocketDescriptor(socketDescriptor);
	connect(m_socket, &QTcpSocket::readyRead, this, &Server::onReadyRead);
	connect(m_socket, &QTcpSocket::disconnected, m_socket, &QTcpSocket::deleteLater);
	cout << "client connected" << socketDescriptor << endl;
}

void Server::onReadyRead()
{
	m_data = m_socket->readAll();
	m_loadedImage.loadFromData(m_data);
	m_image.setImage(m_loadedImage);
	cout << "Image received!" << endl;
}
