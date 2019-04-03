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

    void startCamera();

private:
    QWidget *widget;
    QVBoxLayout *layout;
    QCamera *camera;
    QCameraViewfinder *viewFinder;

private slots:
    void onWidgetClosed();

};

#endif // CAMERA_H
