#ifndef CIPHER_H
#define CIPHER_H

#include <QObject>
#include <QDebug>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/conf.h>
#include <openssl/evp.h>
#include <openssl/err.h>

QByteArray getPublicKey();
QByteArray getPrivateKey();

class Cipher : public QObject
{
    Q_OBJECT
public:
    explicit Cipher(QObject *parent = 0);
    ~Cipher();
    RSA *getPublicKey(QByteArray &data);
    RSA *getPublicKey(QString filename);
    RSA *getPrivateKey(QByteArray &data);
    RSA *getPrivateKey(QString filename);
    QByteArray encryptRSA(RSA *key, QByteArray &data);
    QByteArray decryptRSA(RSA *key, QByteArray &data);
    void freeRSAKey(RSA *key);

signals:

public slots:

private:
    void initalize();
    void finalize();

};


#endif // CIPHER_H
