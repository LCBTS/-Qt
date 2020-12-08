#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPushButton>
#include<QFileDialog>
#include<QLabel>
#include<QDialog>//对话框类
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionopen,&QAction::triggered,this,[=](){

        QString data=QFileDialog::getOpenFileName(this,"open","D://","Image(*.jpg *.png)");//父窗口，名字，过滤条件
        ui->label_4->setPixmap(QPixmap(data));    //将路径反馈给label
    });

    QPushButton * botton=new QPushButton("hello",this);
     ui->statusBar->addWidget(botton);

     QLabel *lab=new QLabel("hello",this);
     ui->statusBar->addWidget(lab);

     ui->actionopen->setIcon(QIcon(":/new/igm//1568168467_616847.jpg"));





   connect( ui->pushButton,&QPushButton::clicked,this,[=](){
        ui->stackedWidget->setCurrentIndex(0);

    });
   connect( ui->pushButton_2,&QPushButton::clicked,this,[=](){
        ui->stackedWidget->setCurrentWidget(ui->page_2);

    });
   connect( ui->pushButton_3,&QPushButton::clicked,this,[=](){
        ui->stackedWidget->setCurrentWidget(ui->page_3);

    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
