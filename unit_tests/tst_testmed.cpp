#include <QtTest>
#include "functions.h"
#include "database.h"


class testmed : public QObject
{
    Q_OBJECT

public:
    testmed();
    ~testmed();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void openDataBase();
};

testmed::testmed()
{
}

testmed::~testmed()
{
}

void testmed::initTestCase()
{
}

void testmed::cleanupTestCase()
{
}

void testmed::openDataBase()
{
    bool result = openDataBase();
    QVERIFY(true == result);
}

QTEST_APPLESS_MAIN(testmed)

#include "tst_testmed.moc"
