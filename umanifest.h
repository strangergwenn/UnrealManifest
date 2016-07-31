/**
 *  This work is distributed under the General Public License,
 *	see LICENSE for details
 *
 *  @author Gwennaël ARBONA
 **/

#ifndef UMANIFEST_H
    #define UMANIFEST_H

    /*----------------------------------------------
                Includes & definitions
    ----------------------------------------------*/

    #include <QCryptographicHash>
    #include <QDomDocument>
    #include <QMainWindow>
    #include <QTextStream>
    #include <QDate>
    #include <QFile>
    #include <QDir>

    #define MANIFEST_NAME   "GameManifest.xml"


    /*----------------------------------------------
                  Class definitions
    ----------------------------------------------*/

    namespace Ui {
        class UManifest;
    }

    class UManifest : public QMainWindow
    {
        Q_OBJECT

        public:
            explicit UManifest(QWidget *parent = 0);
            ~UManifest();

        private:

            void GenerateManifest(QDomDocument* dom, QDomElement root, QString dir);
            QString HashFile(QString filePath);

            Ui::UManifest *ui;

    };

#endif // UMANIFEST_H
