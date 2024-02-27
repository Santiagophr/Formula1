#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->comboBoxOrdem->setEnabled(false);
    ui->pushButtonMostrarDados->setEnabled(false);
    ui->Limpar->setEnabled(false);
    ui->tableWidgetPiloto->setRowCount(11);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonBuscar_clicked()
{
    try
    {
        nomeDoArquivo=QFileDialog::getOpenFileName(this,"Abrir arquivo",QDir::currentPath(),"Arquivos Textos (*.csv *.txt)");

        if(nomeDoArquivo.isEmpty())
        {
            throw QString("Arquivo não selecionado.");
        }

        ui->lineEditNomedoArquivo->setText(nomeDoArquivo);
        ui->comboBoxOrdem->setEnabled(true);
        ui->pushButtonMostrarDados->setEnabled(true);
        ui->Limpar->setEnabled(true);
    }

    catch (QString &erro)
    {
        QMessageBox::information(this,"Erro",erro);
    }
}


void MainWindow::on_Limpar_clicked()
{
    for(int i=0;i<11;i++)
    {
        ui->tableWidgetPiloto->setItem(i,0,new QTableWidgetItem(0));
        ui->tableWidgetPiloto->setItem(i,1,new QTableWidgetItem(0));
        ui->tableWidgetPiloto->setItem(i,2,new QTableWidgetItem(0));
        ui->tableWidgetPiloto->setItem(i,3,new QTableWidgetItem(0));
        ui->tableWidgetPiloto->setItem(i,4,new QTableWidgetItem(0));
        ui->tableWidgetPiloto->setItem(i,5,new QTableWidgetItem(0));
    }

     ui->Limpar->setEnabled(false);
}


void MainWindow::on_pushButtonMostrarDados_clicked()
{
    try
    {
        hpm::manipulararquivo dados(nomeDoArquivo);
        dados.buscarDados();
        hpm::lista listaPilotos;
        ui->tableWidgetPiloto->setRowCount(dados.getColecaoPilotos().getQuantidadeElementos());

        if(ui->comboBoxOrdem->currentIndex()==0)
        {
            for(int i=0;i<dados.getColecaoPilotos().getQuantidadeElementos();i++)
            {
                int cod=dados.getColecaoPilotos().acessarPosicao(i).getCodigo();
                QString nome=dados.getColecaoPilotos().acessarPosicao(i).getNome();
                QString pais=dados.getColecaoPilotos().acessarPosicao(i).getPais();
                int idade=dados.getColecaoPilotos().acessarPosicao(i).getIdade();
                QString time=dados.getColecaoPilotos().acessarPosicao(i).getTime();
                QString motor=dados.getColecaoPilotos().acessarPosicao(i).getMotor();

                hpm::piloto p1(cod,nome,pais,idade,time,motor);

                listaPilotos.OrdenadoCrescente(p1);
            }

            for(int i=0;i<listaPilotos.getQuantidadeElementos();i++)
            {
                ui->tableWidgetPiloto->setItem(i,0,new QTableWidgetItem(QString::number(listaPilotos.acessarPosicao(i).getCodigo())));
                ui->tableWidgetPiloto->setItem(i,1,new QTableWidgetItem(listaPilotos.acessarPosicao(i).getNome()));
                ui->tableWidgetPiloto->setItem(i,2,new QTableWidgetItem(listaPilotos.acessarPosicao(i).getPais()));
                ui->tableWidgetPiloto->setItem(i,3,new QTableWidgetItem(QString::number(listaPilotos.acessarPosicao(i).getIdade())));
                ui->tableWidgetPiloto->setItem(i,4,new QTableWidgetItem(listaPilotos.acessarPosicao(i).getTime()));
                ui->tableWidgetPiloto->setItem(i,5,new QTableWidgetItem(listaPilotos.acessarPosicao(i).getMotor()));
            }

        }

        else if(ui->comboBoxOrdem->currentIndex()==1)
        {
            for(int i=0;i<dados.getColecaoPilotos().getQuantidadeElementos();i++)
            {
                int cod=dados.getColecaoPilotos().acessarPosicao(i).getCodigo();
                QString nome=dados.getColecaoPilotos().acessarPosicao(i).getNome();
                QString pais=dados.getColecaoPilotos().acessarPosicao(i).getPais();
                int idade=dados.getColecaoPilotos().acessarPosicao(i).getIdade();
                QString time=dados.getColecaoPilotos().acessarPosicao(i).getTime();
                QString motor=dados.getColecaoPilotos().acessarPosicao(i).getMotor();

                hpm::piloto p1(cod,nome,pais,idade,time,motor);

                listaPilotos.OrdenadoDescrescente(p1);
            }

            for(int i=0;i<listaPilotos.getQuantidadeElementos();i++)
            {
                ui->tableWidgetPiloto->setItem(i,0,new QTableWidgetItem(QString::number(listaPilotos.acessarPosicao(i).getCodigo())));
                ui->tableWidgetPiloto->setItem(i,1,new QTableWidgetItem(listaPilotos.acessarPosicao(i).getNome()));
                ui->tableWidgetPiloto->setItem(i,2,new QTableWidgetItem(listaPilotos.acessarPosicao(i).getPais()));
                ui->tableWidgetPiloto->setItem(i,3,new QTableWidgetItem(QString::number(listaPilotos.acessarPosicao(i).getIdade())));
                ui->tableWidgetPiloto->setItem(i,4,new QTableWidgetItem(listaPilotos.acessarPosicao(i).getTime()));
                ui->tableWidgetPiloto->setItem(i,5,new QTableWidgetItem(listaPilotos.acessarPosicao(i).getMotor()));
            }
        }

        ui->Limpar->setEnabled(true);
    }

    catch (QString &erro)
    {
        QMessageBox::information(this,"Erro",erro);
    }
}

