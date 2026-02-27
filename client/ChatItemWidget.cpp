#include "ChatItemWidget.h"
#include "ui_ChatItemWidget.h"

ChatItemWidget::ChatItemWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ChatItemWidget)
{
    ui->setupUi(this);
}

ChatItemWidget::~ChatItemWidget()
{
    delete ui;
}

void ChatItemWidget::setMessage(QString message, bool isMyMessage)
{
    if (isMyMessage) {
        ui->lbMessage->setAlignment(Qt::AlignRight);
    } else {
        ui->lbMessage->setAlignment(Qt::AlignLeft);
    }
    ui->lbMessage->setText(message);
    ui->lbTime->setText(QDateTime::currentDateTime().toString("HH:mm"));
}
