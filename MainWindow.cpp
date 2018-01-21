#include "MainWindow.hpp"
#include "ui_MainWindow.h"
#include <QLineEdit>
#include <QCheckBox>
#include <QCryptographicHash>
#include <QComboBox>
#include "CRC32.hpp"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent),
    m_ui(new Ui::MainWindow())
{
    m_ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete m_ui;
}

void MainWindow::onTextChanged(QString str)
{
    if (!str.isEmpty())
    {
        std::string val = (m_ui->addPrefixCheckbox->isChecked() ? "$/" : "") + (m_ui->toLowerCheckbox->isChecked() ? str.toLower() : str).toStdString();
        QString result;
        if (m_ui->comboBox->currentText().toLower() == "crc32")
            result = tr("%1").arg(CRC32::Calculate(val.c_str(), val.length()), 8, 16, QLatin1Char('0'));
        else if (m_ui->comboBox->currentText().toLower() == "md5")
        {
            QByteArray tmp = QCryptographicHash::hash(QByteArray::fromStdString(val), QCryptographicHash::Algorithm::Md5);
            result = tmp.mid(8).toHex();
        }
        m_ui->resultLineEdit->setText(result.toUpper());
    }
    else
        m_ui->resultLineEdit->clear();
}

void MainWindow::onCheckStateChanged()
{
    onTextChanged(m_ui->pathLineEdit->text());
}
