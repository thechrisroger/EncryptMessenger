#ifndef CAMERA_H
#define CAMERA_H

#include <QWidget>
#include <QVBoxLayout>
#include <QCamera>
#include <QCameraInfo>
#include <QtMultimediaWidgets/QCameraViewfinder>

class Camera : public QWidget
{
    Q_OBJECT
public:
    explicit Camera(QWidget *parent = nullptr);
    ~Camera();

private:
    QWidget *widget;
    QVBoxLayout *layout;
    QCamera *camera;
    QCameraViewfinder *viewFinder;

public slots:
};

#endif // CAMERA_H
