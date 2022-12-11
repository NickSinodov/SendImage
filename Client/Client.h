#ifndef CLIENT_H
#define CLIENT_H

#include <QMainWindow>
#include <QPushButton>
#include <QFileSystemModel>
#include <QTreeView>
#include <QTcpSocket>
#include <iostream>
using namespace std;
QT_BEGIN_NAMESPACE
namespace Ui { class Client; }
QT_END_NAMESPACE

class Client : public QMainWindow
{
    Q_OBJECT

public:
    Client(QWidget *parent = nullptr);
    ~Client();

private slots:
	void on_pushButton_clicked();

private:
    Ui::Client *ui;
	QPushButton			*m_sendImage;
	QFileSystemModel	*m_model;
	QTreeView			*m_tree;
	QTcpSocket			*m_socket;
	QByteArray			 m_data;
	void sendToServer(const QString &str);
	void sendImage();
	bool checkFormatImage(const QFileInfo &fileInfo);
};
#endif // CLIENT_H
