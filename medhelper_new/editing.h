#ifndef EDITING_H
#define EDITING_H

#include <QImage>
#include <QPixmap> //для получения изображения из БД и работы с ним
#include <QColor> //для изменения характеристик фото
#include <QDialog>
#include <QSqlTableModel>
#include "database.h"
#include "doctor_call.h"
#include <QTcpSocket>

namespace Ui {
class Editing;
}

class Editing : public QDialog
{
    Q_OBJECT

public:
    explicit Editing(QWidget *parent = nullptr);
    ~Editing();




private slots:
    void slotCurrentPic(QModelIndex index); //Слот для получения изображения из базы данных
    void on_download_photo_clicked();
//    void on_add_cure_clicked();
//    void on_delete_cure_clicked();
//    void on_save_cure_clicked();
//    void on_extra_functions_clicked();

    void on_Send_exec_clicked();
    void exec(QString temp);// функция авторизации

private slots:
    void slot_on_connected();//функция подключения
    void slot_ready_read();// функция чтения сообщения, полученного от сервера
    void slot_send_to_server(QString message);// функция отправки сообщения на сервер
    void slot_disconnected();//функция отключения
    void on_pushButton_clicked();

private:
    Ui::Editing *ui;
    DataBase *db;
    QSqlTableModel *model;
    QImage image;
    doctor_call *doc;
    QTcpSocket *client_socket;
private:
void setupModel(const QString &tableName, const QStringList &headers);//получение таблицы из БД
void createUI();
};
#endif // EDITING_H
