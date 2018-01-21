#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    Ui::MainWindow* m_ui;
public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    void onTextChanged(QString);
    void onCheckStateChanged();
};

#endif // MAINWINDOW_HPP
