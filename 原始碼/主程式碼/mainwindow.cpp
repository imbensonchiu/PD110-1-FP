#include "mainwindow.h"
#include "database.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QCheckBox>
#include <QVector>
#include <QString>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


myTableModel* model = new myTableModel;



void MainWindow::on_searchButton_clicked()
{

    //Get Catagories
        delete model;
        model = new myTableModel;
        QSqlDatabase db = getDatabaseConnection();
        db.open();
        if(chooseCat[0])
            catagories.push_back("大一必修");
        if(chooseCat[1])
            catagories.push_back("大二必修");
        if(chooseCat[2])
            catagories.push_back("大三必修");
        if(chooseCat[3])
            catagories.push_back("大四必修");
        if(chooseCat[4])
            catagories.push_back("系定選修");
        if(chooseCat[5])
            catagories.push_back("一般選修");
        if(chooseCat[6])
            catagories.push_back("共同");
        if(chooseCat[7])
            catagories.push_back("通識");
        //可以不用catagories,  我用chooseCat就好
        for(int i = 0; i < catagories.size(); i++)
        {
            //qDebug() << catagories[i];
        }

   //Get timetable

        for(int i = 1; i <= 6; i++)
        {
            for(int j = 0; j <= 15; j++)
            {
                if(timeTableChecked[i][j])
                {
                    timeVec.push_back(i*100 + j);
                }
            }
        }

        for(int i = 0; i < timeVec.size(); i++)
        {
            //qDebug() << timeVec[i];
        }

    //Get inquiry
        QString searchTextType = ui -> comboBox -> currentText();
        QString searchText = ui -> courseLineEdit -> text();
        //qDebug() << searchTextType << " " << searchText;

    //Show the table
      if(catagories.isEmpty() or timeVec.isEmpty())
      {
          int ret = QMessageBox::critical(this,"資料不全", "請勾選時間及課程分類",
                                                QMessageBox::Ok);
      }
        model->setEditStrategy(QSqlTableModel::OnManualSubmit);

        QSqlQuery uquery;
        uquery.exec(sqlQueryMaker(chooseCat, searchText, searchTextType, timeVec));
        timeVec.clear();
        model->setQuery(QSqlQuery(uquery.lastQuery()));
        qDebug()<<uquery.lastQuery();
        model->setHeaderData(0, Qt::Horizontal, tr("流水號"));
        model->setHeaderData(1, Qt::Horizontal, tr("科系"));
        model->setHeaderData(2, Qt::Horizontal, tr("必選修"));
        model->setHeaderData(3, Qt::Horizontal, tr("班次"));
        model->setHeaderData(4, Qt::Horizontal, tr("課程名稱"));
        model->setHeaderData(5, Qt::Horizontal, tr("教師"));
        model->setHeaderData(6, Qt::Horizontal, tr("時間"));
        model->setHeaderData(7, Qt::Horizontal, tr("教室"));
        model->setHeaderData(8, Qt::Horizontal, tr("學分"));
        model->setHeaderData(9, Qt::Horizontal, tr("全半年"));
        model->setHeaderData(10, Qt::Horizontal, tr("加選方式"));
        //QPushButton *button = new QPushButton("Start");
        ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->tableView->setModel(model);
        ui->tableView->resizeColumnsToContents();
        db.close();
        db.removeDatabase(path);
        uquery.clear();
        return;
}

void MainWindow::on_chooseAll_1_stateChanged(int arg1)
{
    if(ui-> chooseAll_1 -> isChecked())
    {
        ui -> tt1_0 -> setChecked(1);
        ui -> tt1_1 -> setChecked(1);
        ui -> tt1_2 -> setChecked(1);
        ui -> tt1_3 -> setChecked(1);
        ui -> tt1_4 -> setChecked(1);
        ui -> tt1_5 -> setChecked(1);
        ui -> tt1_6 -> setChecked(1);
        ui -> tt1_7 -> setChecked(1);
        ui -> tt1_8 -> setChecked(1);
        ui -> tt1_9 -> setChecked(1);
        ui -> tt1_10 -> setChecked(1);
        ui -> tt1_11 -> setChecked(1);
        ui -> tt1_12 -> setChecked(1);
        ui -> tt1_13 -> setChecked(1);
        ui -> tt1_14 -> setChecked(1);
    }
    else
    {
        ui -> tt1_0 -> setChecked(0);
        ui -> tt1_1 -> setChecked(0);
        ui -> tt1_2 -> setChecked(0);
        ui -> tt1_3 -> setChecked(0);
        ui -> tt1_4 -> setChecked(0);
        ui -> tt1_5 -> setChecked(0);
        ui -> tt1_6 -> setChecked(0);
        ui -> tt1_7 -> setChecked(0);
        ui -> tt1_8 -> setChecked(0);
        ui -> tt1_9 -> setChecked(0);
        ui -> tt1_10 -> setChecked(0);
        ui -> tt1_11 -> setChecked(0);
        ui -> tt1_12 -> setChecked(0);
        ui -> tt1_13 -> setChecked(0);
        ui -> tt1_14 -> setChecked(0);
    }
}

void MainWindow::on_chooseAll_2_stateChanged(int arg1)
{
    if(ui-> chooseAll_2 -> isChecked())
    {
        ui -> tt2_0 -> setChecked(1);
        ui -> tt2_1 -> setChecked(1);
        ui -> tt2_2 -> setChecked(1);
        ui -> tt2_3 -> setChecked(1);
        ui -> tt2_4 -> setChecked(1);
        ui -> tt2_5 -> setChecked(1);
        ui -> tt2_6 -> setChecked(1);
        ui -> tt2_7 -> setChecked(1);
        ui -> tt2_8 -> setChecked(1);
        ui -> tt2_9 -> setChecked(1);
        ui -> tt2_10 -> setChecked(1);
        ui -> tt2_11 -> setChecked(1);
        ui -> tt2_12 -> setChecked(1);
        ui -> tt2_13 -> setChecked(1);
        ui -> tt2_14 -> setChecked(1);
    }
    else
    {
        ui -> tt2_0 -> setChecked(0);
        ui -> tt2_1 -> setChecked(0);
        ui -> tt2_2 -> setChecked(0);
        ui -> tt2_3 -> setChecked(0);
        ui -> tt2_4 -> setChecked(0);
        ui -> tt2_5 -> setChecked(0);
        ui -> tt2_6 -> setChecked(0);
        ui -> tt2_7 -> setChecked(0);
        ui -> tt2_8 -> setChecked(0);
        ui -> tt2_9 -> setChecked(0);
        ui -> tt2_10 -> setChecked(0);
        ui -> tt2_11 -> setChecked(0);
        ui -> tt2_12 -> setChecked(0);
        ui -> tt2_13 -> setChecked(0);
        ui -> tt2_14 -> setChecked(0);
    }

}


void MainWindow::on_chooseAll_3_stateChanged(int arg1)
{
    if(ui-> chooseAll_3 -> isChecked())
    {
        ui -> tt3_0 -> setChecked(1);
        ui -> tt3_1 -> setChecked(1);
        ui -> tt3_2 -> setChecked(1);
        ui -> tt3_3 -> setChecked(1);
        ui -> tt3_4 -> setChecked(1);
        ui -> tt3_5 -> setChecked(1);
        ui -> tt3_6 -> setChecked(1);
        ui -> tt3_7 -> setChecked(1);
        ui -> tt3_8 -> setChecked(1);
        ui -> tt3_9 -> setChecked(1);
        ui -> tt3_10 -> setChecked(1);
        ui -> tt3_11 -> setChecked(1);
        ui -> tt3_12 -> setChecked(1);
        ui -> tt3_13 -> setChecked(1);
        ui -> tt3_14 -> setChecked(1);
    }
    else
    {
        ui -> tt3_0 -> setChecked(0);
        ui -> tt3_1 -> setChecked(0);
        ui -> tt3_2 -> setChecked(0);
        ui -> tt3_3 -> setChecked(0);
        ui -> tt3_4 -> setChecked(0);
        ui -> tt3_5 -> setChecked(0);
        ui -> tt3_6 -> setChecked(0);
        ui -> tt3_7 -> setChecked(0);
        ui -> tt3_8 -> setChecked(0);
        ui -> tt3_9 -> setChecked(0);
        ui -> tt3_10 -> setChecked(0);
        ui -> tt3_11 -> setChecked(0);
        ui -> tt3_12 -> setChecked(0);
        ui -> tt3_13 -> setChecked(0);
        ui -> tt3_14 -> setChecked(0);
    }

}

void MainWindow::on_chooseAll_4_stateChanged(int arg1)
{
    if(ui-> chooseAll_4 -> isChecked())
    {
        ui -> tt4_0 -> setChecked(1);
        ui -> tt4_1 -> setChecked(1);
        ui -> tt4_2 -> setChecked(1);
        ui -> tt4_3 -> setChecked(1);
        ui -> tt4_4 -> setChecked(1);
        ui -> tt4_5 -> setChecked(1);
        ui -> tt4_6 -> setChecked(1);
        ui -> tt4_7 -> setChecked(1);
        ui -> tt4_8 -> setChecked(1);
        ui -> tt4_9 -> setChecked(1);
        ui -> tt4_10 -> setChecked(1);
        ui -> tt4_11 -> setChecked(1);
        ui -> tt4_12 -> setChecked(1);
        ui -> tt4_13 -> setChecked(1);
        ui -> tt4_14 -> setChecked(1);
    }
    else
    {
        ui -> tt4_0 -> setChecked(0);
        ui -> tt4_1 -> setChecked(0);
        ui -> tt4_2 -> setChecked(0);
        ui -> tt4_3 -> setChecked(0);
        ui -> tt4_4 -> setChecked(0);
        ui -> tt4_5 -> setChecked(0);
        ui -> tt4_6 -> setChecked(0);
        ui -> tt4_7 -> setChecked(0);
        ui -> tt4_8 -> setChecked(0);
        ui -> tt4_9 -> setChecked(0);
        ui -> tt4_10 -> setChecked(0);
        ui -> tt4_11 -> setChecked(0);
        ui -> tt4_12 -> setChecked(0);
        ui -> tt4_13 -> setChecked(0);
        ui -> tt4_14 -> setChecked(0);
    }

}

void MainWindow::on_chooseAll_5_stateChanged(int arg1)
{
    if(ui-> chooseAll_5 -> isChecked())
    {
        ui -> tt5_0 -> setChecked(1);
        ui -> tt5_1 -> setChecked(1);
        ui -> tt5_2 -> setChecked(1);
        ui -> tt5_3 -> setChecked(1);
        ui -> tt5_4 -> setChecked(1);
        ui -> tt5_5 -> setChecked(1);
        ui -> tt5_6 -> setChecked(1);
        ui -> tt5_7 -> setChecked(1);
        ui -> tt5_8 -> setChecked(1);
        ui -> tt5_9 -> setChecked(1);
        ui -> tt5_10 -> setChecked(1);
        ui -> tt5_11 -> setChecked(1);
        ui -> tt5_12 -> setChecked(1);
        ui -> tt5_13 -> setChecked(1);
        ui -> tt5_14 -> setChecked(1);
    }
    else
    {
        ui -> tt5_0 -> setChecked(0);
        ui -> tt5_1 -> setChecked(0);
        ui -> tt5_2 -> setChecked(0);
        ui -> tt5_3 -> setChecked(0);
        ui -> tt5_4 -> setChecked(0);
        ui -> tt5_5 -> setChecked(0);
        ui -> tt5_6 -> setChecked(0);
        ui -> tt5_7 -> setChecked(0);
        ui -> tt5_8 -> setChecked(0);
        ui -> tt5_9 -> setChecked(0);
        ui -> tt5_10 -> setChecked(0);
        ui -> tt5_11 -> setChecked(0);
        ui -> tt5_12 -> setChecked(0);
        ui -> tt5_13 -> setChecked(0);
        ui -> tt5_14 -> setChecked(0);
    }

}

void MainWindow::on_chooseAll_6_stateChanged(int arg1)
{
    if(ui-> chooseAll_6 -> isChecked())
    {
        ui -> tt6_0 -> setChecked(1);
        ui -> tt6_1 -> setChecked(1);
        ui -> tt6_2 -> setChecked(1);
        ui -> tt6_3 -> setChecked(1);
        ui -> tt6_4 -> setChecked(1);
        ui -> tt6_5 -> setChecked(1);
        ui -> tt6_6 -> setChecked(1);
        ui -> tt6_7 -> setChecked(1);
        ui -> tt6_8 -> setChecked(1);
        ui -> tt6_9 -> setChecked(1);
        ui -> tt6_10 -> setChecked(1);
        ui -> tt6_11 -> setChecked(1);
        ui -> tt6_12 -> setChecked(1);
        ui -> tt6_13 -> setChecked(1);
        ui -> tt6_14 -> setChecked(1);
    }
    else
    {
        ui -> tt6_0 -> setChecked(0);
        ui -> tt6_1 -> setChecked(0);
        ui -> tt6_2 -> setChecked(0);
        ui -> tt6_3 -> setChecked(0);
        ui -> tt6_4 -> setChecked(0);
        ui -> tt6_5 -> setChecked(0);
        ui -> tt6_6 -> setChecked(0);
        ui -> tt6_7 -> setChecked(0);
        ui -> tt6_8 -> setChecked(0);
        ui -> tt6_9 -> setChecked(0);
        ui -> tt6_10 -> setChecked(0);
        ui -> tt6_11 -> setChecked(0);
        ui -> tt6_12 -> setChecked(0);
        ui -> tt6_13 -> setChecked(0);
        ui -> tt6_14 -> setChecked(0);
    }

}

void MainWindow::on_checkBox_0_stateChanged(int arg1)
{
    if(ui-> checkBox_0 -> isChecked())
    {
        ui -> checkBox_01 -> setChecked(1);
        ui -> checkBox_02 -> setChecked(1);
        ui -> checkBox_03 -> setChecked(1);
        ui -> checkBox_04 -> setChecked(1);
    }
    else
    {
        ui -> checkBox_01 -> setChecked(0);
        ui -> checkBox_02 -> setChecked(0);
        ui -> checkBox_03 -> setChecked(0);
        ui -> checkBox_04 -> setChecked(0);
    }

}


void MainWindow::on_checkBox_01_stateChanged(int arg1)
{
    if(ui -> checkBox_01 -> isChecked())
    {
        chooseCat[0] = true;
    }
    else
    {
        chooseCat[0] = false;
    }
}

void MainWindow::on_checkBox_02_stateChanged(int arg1)
{
    if(ui -> checkBox_02 -> isChecked())
    {
        chooseCat[1] = true;
    }
    else
    {
        chooseCat[1] = false;
    }


}

void MainWindow::on_checkBox_03_stateChanged(int arg1)
{
    if(ui -> checkBox_03 -> isChecked())
    {
        chooseCat[2] = true;
    }
    else
    {
        chooseCat[2] = false;
    }


}

void MainWindow::on_checkBox_04_stateChanged(int arg1)
{
    if(ui -> checkBox_04 -> isChecked())
    {
        chooseCat[3] = true;
    }
    else
    {
        chooseCat[3] = false;
    }


}



void MainWindow::on_checkBox_2_stateChanged(int arg1)
{
    if(ui -> checkBox_2 -> isChecked())
    {
        chooseCat[4] = true;
    }
    else
    {
        chooseCat[4] = false;
    }



}

void MainWindow::on_checkBox_3_stateChanged(int arg1)
{
    if(ui -> checkBox_3 -> isChecked())
    {
        chooseCat[5] = true;
    }
    else
    {
        chooseCat[5] = false;
    }


}

void MainWindow::on_checkBox_4_stateChanged(int arg1)
{
    if(ui -> checkBox_4 -> isChecked())
    {
        chooseCat[6] = true;
    }
    else
    {
        chooseCat[6] = false;
    }


}

void MainWindow::on_checkBox_5_stateChanged(int arg1)
{
    if(ui -> checkBox_5 -> isChecked())
    {
        chooseCat[7] = true;
    }
    else
    {
        chooseCat[7] = false;
    }

}



void MainWindow::on_tt1_0_stateChanged(int arg1)
{
    if(ui -> tt1_0-> isChecked())
         timeTableChecked[1][0]=true;
    else
         timeTableChecked[1][0]=false;
}
void MainWindow::on_tt1_1_stateChanged(int arg1)
{
    if(ui -> tt1_1-> isChecked())
         timeTableChecked[1][1]=true;
    else
         timeTableChecked[1][1]=false;
}
void MainWindow::on_tt1_2_stateChanged(int arg1)
{
    if(ui -> tt1_2-> isChecked())
         timeTableChecked[1][2]=true;
    else
         timeTableChecked[1][2]=false;
}
void MainWindow::on_tt1_3_stateChanged(int arg1)
{
    if(ui -> tt1_3-> isChecked())
         timeTableChecked[1][3]=true;
    else
         timeTableChecked[1][3]=false;
}
void MainWindow::on_tt1_4_stateChanged(int arg1)
{
    if(ui -> tt1_4-> isChecked())
         timeTableChecked[1][4]=true;
    else
         timeTableChecked[1][4]=false;
}
void MainWindow::on_tt1_5_stateChanged(int arg1)
{
    if(ui -> tt1_5-> isChecked())
         timeTableChecked[1][5]=true;
    else
         timeTableChecked[1][5]=false;
}
void MainWindow::on_tt1_6_stateChanged(int arg1)
{
    if(ui -> tt1_6-> isChecked())
         timeTableChecked[1][6]=true;
    else
         timeTableChecked[1][6]=false;
}
void MainWindow::on_tt1_7_stateChanged(int arg1)
{
    if(ui -> tt1_7-> isChecked())
         timeTableChecked[1][7]=true;
    else
         timeTableChecked[1][7]=false;
}
void MainWindow::on_tt1_8_stateChanged(int arg1)
{
    if(ui -> tt1_8-> isChecked())
         timeTableChecked[1][8]=true;
    else
         timeTableChecked[1][8]=false;
}
void MainWindow::on_tt1_9_stateChanged(int arg1)
{
    if(ui -> tt1_9-> isChecked())
         timeTableChecked[1][9]=true;
    else
         timeTableChecked[1][9]=false;
}
void MainWindow::on_tt1_10_stateChanged(int arg1)
{
    if(ui -> tt1_10-> isChecked())
         timeTableChecked[1][10]=true;
    else
         timeTableChecked[1][10]=false;
}
void MainWindow::on_tt1_11_stateChanged(int arg1)
{
    if(ui -> tt1_11-> isChecked())
         timeTableChecked[1][11]=true;
    else
         timeTableChecked[1][11]=false;
}
void MainWindow::on_tt1_12_stateChanged(int arg1)
{
    if(ui -> tt1_12-> isChecked())
         timeTableChecked[1][12]=true;
    else
         timeTableChecked[1][12]=false;
}
void MainWindow::on_tt1_13_stateChanged(int arg1)
{
    if(ui -> tt1_13-> isChecked())
         timeTableChecked[1][13]=true;
    else
         timeTableChecked[1][13]=false;
}
void MainWindow::on_tt1_14_stateChanged(int arg1)
{
    if(ui -> tt1_14-> isChecked())
         timeTableChecked[1][14]=true;
    else
         timeTableChecked[1][14]=false;
}
void MainWindow::on_tt2_0_stateChanged(int arg1)
{
    if(ui -> tt2_0-> isChecked())
         timeTableChecked[2][0]=true;
    else
         timeTableChecked[2][0]=false;
}
void MainWindow::on_tt2_1_stateChanged(int arg1)
{
    if(ui -> tt2_1-> isChecked())
         timeTableChecked[2][1]=true;
    else
         timeTableChecked[2][1]=false;
}
void MainWindow::on_tt2_2_stateChanged(int arg1)
{
    if(ui -> tt2_2-> isChecked())
         timeTableChecked[2][2]=true;
    else
         timeTableChecked[2][2]=false;
}
void MainWindow::on_tt2_3_stateChanged(int arg1)
{
    if(ui -> tt2_3-> isChecked())
         timeTableChecked[2][3]=true;
    else
         timeTableChecked[2][3]=false;
}
void MainWindow::on_tt2_4_stateChanged(int arg1)
{
    if(ui -> tt2_4-> isChecked())
         timeTableChecked[2][4]=true;
    else
         timeTableChecked[2][4]=false;
}
void MainWindow::on_tt2_5_stateChanged(int arg1)
{
    if(ui -> tt2_5-> isChecked())
         timeTableChecked[2][5]=true;
    else
         timeTableChecked[2][5]=false;
}
void MainWindow::on_tt2_6_stateChanged(int arg1)
{
    if(ui -> tt2_6-> isChecked())
         timeTableChecked[2][6]=true;
    else
         timeTableChecked[2][6]=false;
}
void MainWindow::on_tt2_7_stateChanged(int arg1)
{
    if(ui -> tt2_7-> isChecked())
         timeTableChecked[2][7]=true;
    else
         timeTableChecked[2][7]=false;
}
void MainWindow::on_tt2_8_stateChanged(int arg1)
{
    if(ui -> tt2_8-> isChecked())
         timeTableChecked[2][8]=true;
    else
         timeTableChecked[2][8]=false;
}
void MainWindow::on_tt2_9_stateChanged(int arg1)
{
    if(ui -> tt2_9-> isChecked())
         timeTableChecked[2][9]=true;
    else
         timeTableChecked[2][9]=false;
}
void MainWindow::on_tt2_10_stateChanged(int arg1)
{
    if(ui -> tt2_10-> isChecked())
         timeTableChecked[2][10]=true;
    else
         timeTableChecked[2][10]=false;
}
void MainWindow::on_tt2_11_stateChanged(int arg1)
{
    if(ui -> tt2_11-> isChecked())
         timeTableChecked[2][11]=true;
    else
         timeTableChecked[2][11]=false;
}
void MainWindow::on_tt2_12_stateChanged(int arg1)
{
    if(ui -> tt2_12-> isChecked())
         timeTableChecked[2][12]=true;
    else
         timeTableChecked[2][12]=false;
}
void MainWindow::on_tt2_13_stateChanged(int arg1)
{
    if(ui -> tt2_13-> isChecked())
         timeTableChecked[2][13]=true;
    else
         timeTableChecked[2][13]=false;
}
void MainWindow::on_tt2_14_stateChanged(int arg1)
{
    if(ui -> tt2_14-> isChecked())
         timeTableChecked[2][14]=true;
    else
         timeTableChecked[2][14]=false;
}
void MainWindow::on_tt3_0_stateChanged(int arg1)
{
    if(ui -> tt3_0-> isChecked())
         timeTableChecked[3][0]=true;
    else
         timeTableChecked[3][0]=false;
}
void MainWindow::on_tt3_1_stateChanged(int arg1)
{
    if(ui -> tt3_1-> isChecked())
         timeTableChecked[3][1]=true;
    else
         timeTableChecked[3][1]=false;
}
void MainWindow::on_tt3_2_stateChanged(int arg1)
{
    if(ui -> tt3_2-> isChecked())
         timeTableChecked[3][2]=true;
    else
         timeTableChecked[3][2]=false;
}
void MainWindow::on_tt3_3_stateChanged(int arg1)
{
    if(ui -> tt3_3-> isChecked())
         timeTableChecked[3][3]=true;
    else
         timeTableChecked[3][3]=false;
}
void MainWindow::on_tt3_4_stateChanged(int arg1)
{
    if(ui -> tt3_4-> isChecked())
         timeTableChecked[3][4]=true;
    else
         timeTableChecked[3][4]=false;
}
void MainWindow::on_tt3_5_stateChanged(int arg1)
{
    if(ui -> tt3_5-> isChecked())
         timeTableChecked[3][5]=true;
    else
         timeTableChecked[3][5]=false;
}
void MainWindow::on_tt3_6_stateChanged(int arg1)
{
    if(ui -> tt3_6-> isChecked())
         timeTableChecked[3][6]=true;
    else
         timeTableChecked[3][6]=false;
}
void MainWindow::on_tt3_7_stateChanged(int arg1)
{
    if(ui -> tt3_7-> isChecked())
         timeTableChecked[3][7]=true;
    else
         timeTableChecked[3][7]=false;
}
void MainWindow::on_tt3_8_stateChanged(int arg1)
{
    if(ui -> tt3_8-> isChecked())
         timeTableChecked[3][8]=true;
    else
         timeTableChecked[3][8]=false;
}
void MainWindow::on_tt3_9_stateChanged(int arg1)
{
    if(ui -> tt3_9-> isChecked())
         timeTableChecked[3][9]=true;
    else
         timeTableChecked[3][9]=false;
}
void MainWindow::on_tt3_10_stateChanged(int arg1)
{
    if(ui -> tt3_10-> isChecked())
         timeTableChecked[3][10]=true;
    else
         timeTableChecked[3][10]=false;
}
void MainWindow::on_tt3_11_stateChanged(int arg1)
{
    if(ui -> tt3_11-> isChecked())
         timeTableChecked[3][11]=true;
    else
         timeTableChecked[3][11]=false;
}
void MainWindow::on_tt3_12_stateChanged(int arg1)
{
    if(ui -> tt3_12-> isChecked())
         timeTableChecked[3][12]=true;
    else
         timeTableChecked[3][12]=false;
}
void MainWindow::on_tt3_13_stateChanged(int arg1)
{
    if(ui -> tt3_13-> isChecked())
         timeTableChecked[3][13]=true;
    else
         timeTableChecked[3][13]=false;
}
void MainWindow::on_tt3_14_stateChanged(int arg1)
{
    if(ui -> tt3_14-> isChecked())
         timeTableChecked[3][14]=true;
    else
         timeTableChecked[3][14]=false;
}
void MainWindow::on_tt4_0_stateChanged(int arg1)
{
    if(ui -> tt4_0-> isChecked())
         timeTableChecked[4][0]=true;
    else
         timeTableChecked[4][0]=false;
}
void MainWindow::on_tt4_1_stateChanged(int arg1)
{
    if(ui -> tt4_1-> isChecked())
         timeTableChecked[4][1]=true;
    else
         timeTableChecked[4][1]=false;
}
void MainWindow::on_tt4_2_stateChanged(int arg1)
{
    if(ui -> tt4_2-> isChecked())
         timeTableChecked[4][2]=true;
    else
         timeTableChecked[4][2]=false;
}
void MainWindow::on_tt4_3_stateChanged(int arg1)
{
    if(ui -> tt4_3-> isChecked())
         timeTableChecked[4][3]=true;
    else
         timeTableChecked[4][3]=false;
}
void MainWindow::on_tt4_4_stateChanged(int arg1)
{
    if(ui -> tt4_4-> isChecked())
         timeTableChecked[4][4]=true;
    else
         timeTableChecked[4][4]=false;
}
void MainWindow::on_tt4_5_stateChanged(int arg1)
{
    if(ui -> tt4_5-> isChecked())
         timeTableChecked[4][5]=true;
    else
         timeTableChecked[4][5]=false;
}
void MainWindow::on_tt4_6_stateChanged(int arg1)
{
    if(ui -> tt4_6-> isChecked())
         timeTableChecked[4][6]=true;
    else
         timeTableChecked[4][6]=false;
}
void MainWindow::on_tt4_7_stateChanged(int arg1)
{
    if(ui -> tt4_7-> isChecked())
         timeTableChecked[4][7]=true;
    else
         timeTableChecked[4][7]=false;
}
void MainWindow::on_tt4_8_stateChanged(int arg1)
{
    if(ui -> tt4_8-> isChecked())
         timeTableChecked[4][8]=true;
    else
         timeTableChecked[4][8]=false;
}
void MainWindow::on_tt4_9_stateChanged(int arg1)
{
    if(ui -> tt4_9-> isChecked())
         timeTableChecked[4][9]=true;
    else
         timeTableChecked[4][9]=false;
}
void MainWindow::on_tt4_10_stateChanged(int arg1)
{
    if(ui -> tt4_10-> isChecked())
         timeTableChecked[4][10]=true;
    else
         timeTableChecked[4][10]=false;
}
void MainWindow::on_tt4_11_stateChanged(int arg1)
{
    if(ui -> tt4_11-> isChecked())
         timeTableChecked[4][11]=true;
    else
         timeTableChecked[4][11]=false;
}
void MainWindow::on_tt4_12_stateChanged(int arg1)
{
    if(ui -> tt4_12-> isChecked())
         timeTableChecked[4][12]=true;
    else
         timeTableChecked[4][12]=false;
}
void MainWindow::on_tt4_13_stateChanged(int arg1)
{
    if(ui -> tt4_13-> isChecked())
         timeTableChecked[4][13]=true;
    else
         timeTableChecked[4][13]=false;
}
void MainWindow::on_tt4_14_stateChanged(int arg1)
{
    if(ui -> tt4_14-> isChecked())
         timeTableChecked[4][14]=true;
    else
         timeTableChecked[4][14]=false;
}
void MainWindow::on_tt5_0_stateChanged(int arg1)
{
    if(ui -> tt5_0-> isChecked())
         timeTableChecked[5][0]=true;
    else
         timeTableChecked[5][0]=false;
}
void MainWindow::on_tt5_1_stateChanged(int arg1)
{
    if(ui -> tt5_1-> isChecked())
         timeTableChecked[5][1]=true;
    else
         timeTableChecked[5][1]=false;
}
void MainWindow::on_tt5_2_stateChanged(int arg1)
{
    if(ui -> tt5_2-> isChecked())
         timeTableChecked[5][2]=true;
    else
         timeTableChecked[5][2]=false;
}
void MainWindow::on_tt5_3_stateChanged(int arg1)
{
    if(ui -> tt5_3-> isChecked())
         timeTableChecked[5][3]=true;
    else
         timeTableChecked[5][3]=false;
}
void MainWindow::on_tt5_4_stateChanged(int arg1)
{
    if(ui -> tt5_4-> isChecked())
         timeTableChecked[5][4]=true;
    else
         timeTableChecked[5][4]=false;
}
void MainWindow::on_tt5_5_stateChanged(int arg1)
{
    if(ui -> tt5_5-> isChecked())
         timeTableChecked[5][5]=true;
    else
         timeTableChecked[5][5]=false;
}
void MainWindow::on_tt5_6_stateChanged(int arg1)
{
    if(ui -> tt5_6-> isChecked())
         timeTableChecked[5][6]=true;
    else
         timeTableChecked[5][6]=false;
}
void MainWindow::on_tt5_7_stateChanged(int arg1)
{
    if(ui -> tt5_7-> isChecked())
         timeTableChecked[5][7]=true;
    else
         timeTableChecked[5][7]=false;
}
void MainWindow::on_tt5_8_stateChanged(int arg1)
{
    if(ui -> tt5_8-> isChecked())
         timeTableChecked[5][8]=true;
    else
         timeTableChecked[5][8]=false;
}
void MainWindow::on_tt5_9_stateChanged(int arg1)
{
    if(ui -> tt5_9-> isChecked())
         timeTableChecked[5][9]=true;
    else
         timeTableChecked[5][9]=false;
}
void MainWindow::on_tt5_10_stateChanged(int arg1)
{
    if(ui -> tt5_10-> isChecked())
         timeTableChecked[5][10]=true;
    else
         timeTableChecked[5][10]=false;
}
void MainWindow::on_tt5_11_stateChanged(int arg1)
{
    if(ui -> tt5_11-> isChecked())
         timeTableChecked[5][11]=true;
    else
         timeTableChecked[5][11]=false;
}
void MainWindow::on_tt5_12_stateChanged(int arg1)
{
    if(ui -> tt5_12-> isChecked())
         timeTableChecked[5][12]=true;
    else
         timeTableChecked[5][12]=false;
}
void MainWindow::on_tt5_13_stateChanged(int arg1)
{
    if(ui -> tt5_13-> isChecked())
         timeTableChecked[5][13]=true;
    else
         timeTableChecked[5][13]=false;
}
void MainWindow::on_tt5_14_stateChanged(int arg1)
{
    if(ui -> tt5_14-> isChecked())
         timeTableChecked[5][14]=true;
    else
         timeTableChecked[5][14]=false;
}
void MainWindow::on_tt6_0_stateChanged(int arg1)
{
    if(ui -> tt6_0-> isChecked())
         timeTableChecked[6][0]=true;
    else
         timeTableChecked[6][0]=false;
}
void MainWindow::on_tt6_1_stateChanged(int arg1)
{
    if(ui -> tt6_1-> isChecked())
         timeTableChecked[6][1]=true;
    else
         timeTableChecked[6][1]=false;
}
void MainWindow::on_tt6_2_stateChanged(int arg1)
{
    if(ui -> tt6_2-> isChecked())
         timeTableChecked[6][2]=true;
    else
         timeTableChecked[6][2]=false;
}
void MainWindow::on_tt6_3_stateChanged(int arg1)
{
    if(ui -> tt6_3-> isChecked())
         timeTableChecked[6][3]=true;
    else
         timeTableChecked[6][3]=false;
}
void MainWindow::on_tt6_4_stateChanged(int arg1)
{
    if(ui -> tt6_4-> isChecked())
         timeTableChecked[6][4]=true;
    else
         timeTableChecked[6][4]=false;
}
void MainWindow::on_tt6_5_stateChanged(int arg1)
{
    if(ui -> tt6_5-> isChecked())
         timeTableChecked[6][5]=true;
    else
         timeTableChecked[6][5]=false;
}
void MainWindow::on_tt6_6_stateChanged(int arg1)
{
    if(ui -> tt6_6-> isChecked())
         timeTableChecked[6][6]=true;
    else
         timeTableChecked[6][6]=false;
}
void MainWindow::on_tt6_7_stateChanged(int arg1)
{
    if(ui -> tt6_7-> isChecked())
         timeTableChecked[6][7]=true;
    else
         timeTableChecked[6][7]=false;
}
void MainWindow::on_tt6_8_stateChanged(int arg1)
{
    if(ui -> tt6_8-> isChecked())
         timeTableChecked[6][8]=true;
    else
         timeTableChecked[6][8]=false;
}
void MainWindow::on_tt6_9_stateChanged(int arg1)
{
    if(ui -> tt6_9-> isChecked())
         timeTableChecked[6][9]=true;
    else
         timeTableChecked[6][9]=false;
}
void MainWindow::on_tt6_10_stateChanged(int arg1)
{
    if(ui -> tt6_10-> isChecked())
         timeTableChecked[6][10]=true;
    else
         timeTableChecked[6][10]=false;
}
void MainWindow::on_tt6_11_stateChanged(int arg1)
{
    if(ui -> tt6_11-> isChecked())
         timeTableChecked[6][11]=true;
    else
         timeTableChecked[6][11]=false;
}
void MainWindow::on_tt6_12_stateChanged(int arg1)
{
    if(ui -> tt6_12-> isChecked())
         timeTableChecked[6][12]=true;
    else
         timeTableChecked[6][12]=false;
}
void MainWindow::on_tt6_13_stateChanged(int arg1)
{
    if(ui -> tt6_13-> isChecked())
         timeTableChecked[6][13]=true;
    else
         timeTableChecked[6][13]=false;
}
void MainWindow::on_tt6_14_stateChanged(int arg1)
{
    if(ui -> tt6_14-> isChecked())
         timeTableChecked[6][14]=true;
    else
         timeTableChecked[6][14]=false;
}
