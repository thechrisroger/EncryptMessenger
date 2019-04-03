#include "camera.h"

Camera::Camera(QWidget *parent) : QWidget(parent)
{
    widget = new QWidget();
    widget->setAttribute(Qt::WA_DeleteOnClose);
    widget->setWindowTitle(tr(""));
    widget->resize(650,500);

    layout = new QVBoxLayout;
    camera = new QCamera();
    camera->setCaptureMode(QCamera::CaptureVideo);
//    camera.setCaptureMode(QCamera::CaptureViewfinder);
    viewFinder = new QCameraViewfinder(this);

    camera->setViewfinder(viewFinder);
//    camera.setViewfinder(viewFinder);

    layout->addWidget(viewFinder,0,Qt::AlignTop);
    layout->setMargin(0);
    widget->setLayout(layout);

    connect(widget,SIGNAL(destroyed(QObject*)),this,SLOT(onWidgetClosed()));

}

Camera::~Camera()
{
    qDebug() << "销毁Camera对象";
    camera->stop();
    delete camera;
    delete viewFinder;
    delete layout;
    delete widget;
}

void Camera::startCamera()
{
    camera->start();
    widget->show();
    viewFinder->show();
}

void Camera::onWidgetClosed()
{
    camera->stop();
}


