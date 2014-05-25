#ifndef IMGVIEWSORT_H
#define IMGVIEWSORT_H

#include <QMainWindow>

namespace Ui {
class imgViewSort;
}

class imgViewSort : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit imgViewSort(QWidget *parent = 0);
    ~imgViewSort();
    
private:
    Ui::imgViewSort *ui;
};

#endif // IMGVIEWSORT_H
