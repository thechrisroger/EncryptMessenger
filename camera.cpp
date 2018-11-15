#include "camera.h"

Camera::Camera(QWidget *parent) : QWidget(parent)
{
    widget = new QWidget();
    widget->setWindowTitle(tr(""));
    widget->resize(600,500);
    widget->show();
    layout = new QVBoxLayout;
    camera = new QCamera();
    camera->setCaptureMode(QCamera::CaptureVideo);
    viewFinder = new QCameraViewfinder(this);
    camera->setViewfinder(viewFinder);
    camera->setViewfinder(viewFinder);
    layout->addWidget(viewFinder,0,Qt::AlignTop);
    widget->setLayout(layout);
    camera->start();

}

Camera::~Camera()
{
    camera->stop();
    delete camera;
    delete viewFinder;
}

