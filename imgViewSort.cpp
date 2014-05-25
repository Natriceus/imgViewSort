#include "imgViewSort.h"
#include "ui_imgViewSort.h"

imgViewSort::imgViewSort(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::imgViewSort)
{
    ui->setupUi(this);
}

imgViewSort::~imgViewSort()
{
    delete ui;
}
