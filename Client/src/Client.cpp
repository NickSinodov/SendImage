#include "Client.h"
#include "ui_Client.h"

Client::Client(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Client)
{
	ui->setupUi(this);
	m_socket = new QTcpSocket(this);
	connect(ui->openFile, &QPushButton::clicked, this, &Client::openFile);
	connect(ui->sendImage, &QPushButton::clicked, this, &Client::sendImage);
	connect(m_socket, &QTcpSocket::disconnected, m_socket, &QTcpSocket::deleteLater);
}


void Client::sendImage()
{

	cout << m_fileName.toStdString() << endl;
	if(!m_fileName.isEmpty())
	{
		sendToServer(m_fileName);
	}
}

void Client::openFile()
{
	m_fileName = QFileDialog::getOpenFileName(
	this,
	tr("Open"),
	QDir::currentPath(),
	tr("Document files (*.jpg *.png *.gif *.pdf *.svg)")
	);
	ui->lineEdit->setText(m_fileName);
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






