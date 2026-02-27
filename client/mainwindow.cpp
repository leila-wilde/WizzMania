#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->centralwidget->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionConnect_triggered()
{
    _client = new ClientManager();
    connect(_client, &ClientManager::connected, [this](){
        ui->centralwidget->setEnabled(true);
    });
    connect(_client, &ClientManager::disconnected, [this](){
        ui->centralwidget->setEnabled(false);
    });
    connect(_client, &ClientManager::dataReceived, this, &MainWindow::dataReceived);
    _client->connectToServer();
}

void MainWindow::dataReceived(QByteArray data)
{
    ui->lstMessages->addItem(data);
}

void MainWindow::on_btnSend_clicked()
{
    auto message = ui->lnMessage->text().trimmed();
    _client->sendMessage(message);
    ui->lstMessages->addItem(message);
    ui->lnMessage->setText("");
}

