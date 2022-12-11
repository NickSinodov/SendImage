#include "image.h"
//#include "ui_image.h"
#include <QPainter>

Image::Image(QWidget *parent) :
	QWidget(parent)
{
}

void Image::paintEvent(QPaintEvent *)
{
	QPainter painter(this);
	painter.drawImage(0, 0, m_image);
}

QSize Image::sizeHint() const
{
	return QSize(256,256);
}

void Image::setImage(const QImage &image)
{
	m_image = image;
	setFixedSize(m_image.size());
	if (isVisible())
	{
		repaint();
	}
}
Image::~Image()
{
}
