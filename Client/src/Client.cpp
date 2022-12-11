#include "Client.h"
#include "ui_Client.h"

Client::Client(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Client)
{
    ui->setupUi(this);
	m_model = new QFileSystemModel;
	m_model->setRootPath("");
	ui->treeView->setModel(m_model);
	m_socket = new QTcpSocket(this);
	connect(m_socket, &QTcpSocket::disconnected, m_socket, &QTcpSocket::deleteLater);
}




void Client::on_pushButton_clicked()
{
	sendImage();
}

void Client::sendImage()
{
	QFileInfo fileName = m_model->fileInfo(ui->treeView->currentIndex());
	if (fileName.isDir())
	{
		cout << "Choose not directory!" << endl;
	}
	else
	{
		if(checkFormatImage(fileName))
		{
			sendToServer(fileName.absoluteFilePath());
		}
		else
		{
			cout << "Not image!" << endl;
		}
	}
}

bool Client::checkFormatImage(const QFileInfo &fileInfo)
{
	bool image = true;
	if(fileInfo.suffix() == "png")
	{
		return image;
	}
	else if(fileInfo.suffix() == "jpg")
	{
		return image;
	}
	else if(fileInfo.suffix() == "jpeg")
	{
		return image;
	}
	else if(fileInfo.suffix() == "gif")
	{
		return image;
	}
	else if(fileInfo.suffix() == "svg")
	{
		return image;
	}
	else
	{
		image = false;
		return image;
	}
}

void Client::sendToServer(const QString &str)
{
	QFile file(str);
	file.open(QIODevice::ReadOnly);
	auto data = file.readAll();
	m_socket->connectToHost("127.0.0.1", 2323);
	cout << "Image send" << endl;
	m_socket->write(data);
}

Client::~Client()
{
	delete ui;
}
