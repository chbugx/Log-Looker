#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "c_log2.h"
#include "auth_log.h"
#include "apport_log.h"
#include "dpkg_log.h"
#include <QTimer>
#include <qdatetime.h>

int cur_tab = 0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timerUpdate()));
    timer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    log_apt lg;
    lg.load();
    lg.get_info();
    if (cur_tab == 0) {
        ui->textBrowser->setText(lg.info.c_str());
    } else {
        ui->textBrowser_2->setText(lg.info.c_str());
    }
   // ui->tab->set
}

void MainWindow::on_pushButton_4_clicked()
{
    if (cur_tab == 0) {
        ui->textBrowser->setText("");
    } else {
        ui->textBrowser_2->setText("");
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    log_auth lg;
    lg.load();
    lg.get_info();
    if (cur_tab == 0) {
        ui->textBrowser->setText(lg.info.c_str());
    } else {
        ui->textBrowser_2->setText(lg.info.c_str());
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    log_apport lg;
    lg.load();
    lg.get_info();
    if (cur_tab == 0) {
        ui->textBrowser->setText(lg.info.c_str());
    } else {
        ui->textBrowser_2->setText(lg.info.c_str());
    }
}

void MainWindow::on_pushButton_5_clicked()
{
    log_dpkg lg;
    lg.load();
    lg.get_info();
    if (cur_tab == 0) {
        ui->textBrowser->setText(lg.info.c_str());
    } else {
        ui->textBrowser_2->setText(lg.info.c_str());
    }
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    cur_tab ^= 1;
}


void MainWindow::timerUpdate(void)
{
    QDateTime time = QDateTime::currentDateTime();
    QString str = time.toString("yyyy-MM-dd hh:mm:ss dddd");
    ui->label->setText(str);
}
