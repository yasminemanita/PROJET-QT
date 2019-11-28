#ifndef CHERCHER_H
#define CHERCHER_H

#include <QDialog>

namespace Ui {
class chercher;
}

class chercher : public QDialog
{
    Q_OBJECT

public:
    explicit chercher(QWidget *parent = nullptr);
    ~chercher();

private:
    Ui::chercher *ui;
};

#endif // CHERCHER_H
