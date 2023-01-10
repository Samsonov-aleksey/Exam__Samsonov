#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QFile>
#include <QDate>
#include <QDebug>
#include <QVariant>

/* Директивы имен таблицы, полей таблицы и базы данных */
#define HOSTNAME "192.168.31.26"
#define DATABASE_NAME "photolife"
#define USER "postgres"
#define PASSWORD "12345678"

#define TABLE_1             "medicine2"
#define TABLE_NAME          "name" //[1]
#define TABLE_DESCRIPRIOM   "descripriom" // [3]
#define TABLE_EFFECTS       "effects" // [4]

#define TABLE_2             "calls"
#define PATIENT             "patient_name" //[1]
#define DOCTOR              "doctor_name" // [2]
#define DATE                "date" // [3]
#define ADDRESS             "address" // [4]
#define SYMPTOMS            "symptoms" //[5]
#define DIAGNOSYS           "diagnosis" // [6]
#define PRESCRIPTION        "prescription" // [7]
#define MEDECINE            "medecine_id" // [8]

class DataBase : public QObject
{
    Q_OBJECT

public:
    explicit DataBase(QObject *parent = 0);
    ~DataBase();
    /* Методы для непосредственной работы с классом
     * Подключение к базе данных и вставка записей в таблицу
     * */
    void connectToDataBase();
    bool openDataBase();
    bool restoreDataBase();
    void closeDataBase();
    QString bdquery(QString temp); //запрос В БД для сравнения логина и пароля
    QString bdquery2(QString temp);
    QSqlDatabase db;

private:
    // Сам объект базы данных, с которым будет производиться работа


private:
    /* Внутренние методы для работы с базой данных
     * */

    bool createTable();
    bool createTable2();


public slots:
    bool insertIntoTable(const QVariantList &data);      // Добавление записей в таблицу
    bool insertIntoTable(const QString &name_photo, const QString &descripriom, const QString &effects);
    bool insertIntoTable2(const QVariantList &data2);
    bool insertIntoTable2(const QString &patient_name, const QString &doctor_name, const QString &date, const QString &address, const QString &symptoms, const QString &diagnosis, const QString &prescription, const QString &medecine_id);
};

#endif // DATABASE_H
