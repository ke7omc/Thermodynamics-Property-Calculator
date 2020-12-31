#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_listWidget_quickList_itemSelectionChanged();

    void on_listWidget_allFluids_itemSelectionChanged();

    void on_comboBox_firstProperty_currentIndexChanged(const QString &firstPropertyName);

    void on_comboBox_secondProperty_currentIndexChanged(const QString &secondPropertyName);

    void on_lineEdit_firstPropertyValue_textEdited(const QString &firstPropertyValueQString);

    void on_lineEdit_secondPropertyValue_textEdited(const QString &secondPropertyValueQString);



    void on_pushButton_calculate_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
