//#ifndef IMAGE_H
//#define IMAGE_H
#pragma once
#include <QWidget>

class Image : public QWidget
{
	Q_OBJECT

public:
	explicit Image(QWidget *parent = nullptr);
	~Image();
	void setImage(const QImage &image);
private:
	void paintEvent(QPaintEvent *) override;
	QSize sizeHint() const override;
private:
	QImage	m_image;
//#endif // IMAGE_H
};
