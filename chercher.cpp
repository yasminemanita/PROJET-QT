#include "chercher.h"
#include "ui_chercher.h"

chercher::chercher(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::chercher)
{
    ui->setupUi(this);
}

chercher::~chercher()
{
    delete ui;
}
