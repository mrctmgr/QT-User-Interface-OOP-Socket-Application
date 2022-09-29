#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMainWindow>
#include <QFileDialog>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QXmlStreamAttribute>
#include <QMessageBox>
#include <QFile>
#include <QTabWidget>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE
class LocalServer;
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void triangle();
    void quad();
    void penta();
    void hexa();

private slots:
    void on_tri_clicked();

    void on_qua_clicked();

    void on_pen_clicked();

    void on_hex_clicked();

    void on_enter_clicked();

    void on_write_clicked();

    void on_read_clicked();

    void on_del_clicked();

    void on_connect_clicked();

    void on_send_clicked();

    void on_exit_clicked();

private:
    Ui::Widget *ui;
    LocalServer *mLocalServer;
    QString edge_1, edge_2, edge_3, edge_4, edge_5, edge_6;
    int n,k,l,m,side1,circ;
    bool reg;
    float area1;

};
#endif // WIDGET_H
