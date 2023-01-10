#include "editing.h"
#include "ui_editing.h"
//#include "dialog_login.h"
#include <QBuffer>
#include <QScreen>
#include <QApplication>
#include <QFileDialog>
#include <QDialog>
#include <QSqlQueryModel>
#include <QImage>
#include <QPixmap>
#include <QColor>
#include <QMessageBox>

//void Editing::on_extra_functions_clicked()
//{

//    this->close();
//    doc->show();
//}

Editing::Editing(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Editing)
{
    ui->setupUi(this);
    db = new DataBase();
    //db->connectToDataBase();
    client_socket = new QTcpSocket(this);
    client_socket->connectToHost("192.168.31.26",33333);//loopback (интерфейс обратной связи)

    connect(client_socket,SIGNAL(connected()),SLOT(slot_on_connected()));
    connect(client_socket,SIGNAL(readyRead()),SLOT(slot_ready_read()));
    //отображение столбцов БД в следующем виде
    this->setupModel(TABLE_1,
                    QStringList() << trUtf8("Номер лекарства")
                                  << trUtf8("Название лекарства")
                                  << trUtf8("Описание")
                                  << trUtf8("Побочные эффекты"));
    this->createUI();
}

//получение таблицы из БД
void Editing::setupModel(const QString &tableName, const QStringList &headers){
    model = new QSqlTableModel(this);
    model->setTable(tableName);
    for (int i = 0,j = 0; i < model->columnCount();i++,j++){
        model->setHeaderData(i,Qt::Horizontal,headers[j]);
    }
    //Устанавливаем сортировку по возрастанию данных по нулевой колонке
    model->setSort(0,Qt::AscendingOrder);
}

void Editing::createUI()
    {



    //Скрываем определенные поля из БД
//    ui->tableView->setModel(model);
//    QHeaderView *verticalHeader = ui->tableView->verticalHeader();
//    verticalHeader->setSectionResizeMode(QHeaderView::Fixed);
//    verticalHeader->setDefaultSectionSize(700);

//    QHeaderView *horizontalHeader = ui->tableView->horizontalHeader();
//    horizontalHeader->setSectionResizeMode(QHeaderView::Fixed);
//    horizontalHeader->setDefaultSectionSize(250);

//    ui->tableView->setColumnHidden(0, true);
//    ui->tableView->setColumnHidden(2, true);
//    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
//    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
//    ui->tableView->horizontalHeader()->setStretchLastSection(true);

//    /* Подключаем сигнал об изменении выбора текущей строки в таблицу
//         * к СЛОТу для установки изображения в picLabel
//         * */
//    connect(ui->tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),
//               this, SLOT(slotCurrentPic(QModelIndex)));

//    model->select();


    }
void Editing::slot_on_connected()
{
    //QMessageBox Msg;
    //Msg.setText("Connected!!!");
    //Msg.exec();
}
void Editing::exec(QString temp)
{
    QString message_to_server;
    message_to_server = temp;
    slot_send_to_server(message_to_server);
}

//Функция отправки сообщения на сервер, добавляем "auth&", чтобы понимать что происходит на сервере
void Editing::on_Send_exec_clicked()
{
    slot_send_to_server(ui->exec_db->text());
}


void Editing::slot_ready_read()
{
    QByteArray array;
    std::string message = "";



    while(client_socket->bytesAvailable()>0)
    {
        array = client_socket->readAll();
        message += array.toStdString();
    }
    ui->exec_from_server->setText(QString::fromStdString(message));

}
// функция отправки сообщения на сервер
void Editing::slot_send_to_server(QString message)
{
    QByteArray array;
    array.append(message);
    client_socket->write(array);
}

//функция отключения приложения
void Editing::slot_disconnected()
{
    client_socket->close();
}



Editing::~Editing()
{
    delete ui;
}

void Editing::slotCurrentPic(QModelIndex index)
{
    // установка фона приложения
    /*QPixmap pix("/home/sis201331/medhelper_new/biba/fon.jpg");
    int w = ui->label_2->width();
    int h = ui->label_2->height();
    ui->label_2->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));

    QPixmap outPixmap = QPixmap(); // Создаём QPixmap, который будет помещаться в picLabel
    /* Забираем данные об изображении из таблицы в качестве QByteArray
     * и помещаем их в QPixmap
     *
    outPixmap.loadFromData(model->data(model->index(index.row(), 2)).toByteArray());
    // Устанавливаем изображение в picLabel
    ui->picLabel->setPixmap(outPixmap.scaled(500,400));*/
}




void Editing::on_download_photo_clicked()
{
    /*QString fileName = QFileDialog::getOpenFileName(this,
                                                    "Select one or more files to open",
                                                    "/home",
                                                    "Images (*.png *.xpm *.jpg)");
    QPixmap inPixmap(fileName); // Сохраняем его в изображение объекта QPixmap;
    QByteArray inByteArray; // Создаём объект QByteArray для сохранения изображения QBuffer
    QBuffer inBuffer( &inByteArray );
    inPixmap.save( &inBuffer, "PNG" );*/
//    QString name_photo = ui->name_cure->text();
//    QString descripriom = ui->description_cure->text();
//    QString effects = ui->effects_cure->text();
//   db->insertIntoTable(name_photo, descripriom, effects);
}


//void Editing::on_add_cure_clicked()
//{
//    model->select();
//}


//void Editing::on_delete_cure_clicked()
//{
//    QModelIndex current = ui->tableView->currentIndex();
//    int id = current.sibling(current.row(), 0).data ().toInt ();
//    QSqlQuery query;
//    query.prepare("delete from medicine2 where (ID = "+QString::number(id)+")");
//    query.exec();
//    model->select();
//}


//void Editing::on_save_cure_clicked()
//{
//    if(model->submitAll())
//        model->database().commit();
//    else
//        model->database().rollback();
//}








void Editing::on_pushButton_clicked()
{
    int i=5+9;

    ui->exec_from_server->setNum(i);
    qDebug() <<i;

}

