#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ChatItemWidget.h"

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
    // ui->lstMessages->addItem(data);
    auto chatWidget = new ChatItemWidget(this);
    chatWidget->setMessage(data);
    auto listItemWidget = new QListWidgetItem();
    listItemWidget->setSizeHint(QSize(ui->lstMessages->width(), chatWidget->sizeHint().height()));
    ui->lstMessages->addItem(listItemWidget);
    listItemWidget->setBackground(QColor(255, 255, 200));
    ui->lstMessages->setItemWidget(listItemWidget, chatWidget);
}

void MainWindow::on_btnSend_clicked()
{
    auto message = ui->lnMessage->text().trimmed();
    _client->sendMessage(message);
    ui->lnMessage->setText("");
    // ui->lstMessages->addItem(message);

    auto chatWidget = new ChatItemWidget(this);
    chatWidget->setMessage(message, true);
    auto listItemWidget = new QListWidgetItem();
    listItemWidget->setSizeHint(QSize(ui->lstMessages->width(), chatWidget->sizeHint().height()));
    ui->lstMessages->addItem(listItemWidget);
    listItemWidget->setBackground(QColor(255, 230, 230));
    ui->lstMessages->setItemWidget(listItemWidget, chatWidget);
}
