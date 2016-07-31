/**
 *  This work is distributed under the General Public License,
 *	see LICENSE for details
 *
 *  @author Gwennaël ARBONA
 **/

#include "umanifest.h"
#include "ui_umanifest.h"

#include <QDebug>
#include <QDirIterator>


/*----------------------------------------------
          Constructor & destructor
----------------------------------------------*/

UManifest::UManifest(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UManifest)
{
    ui->setupUi(this);

    ui->releaseNotes->append("Searching for files...");

    QDomDocument* dom = new QDomDocument("files");
    QDomElement root = dom->createElement("FolderProperties");
    root.setAttribute("FolderName", ".");
    dom->appendChild(root);

    this->GenerateManifest(dom, root, QDir::currentPath());

    ui->releaseNotes->append("Writing manifest to XML...");

    QFile* file = new QFile(MANIFEST_NAME);
    if (file->open(QIODevice::WriteOnly | QIODevice::Text ))
    {
        QTextStream stream(file);
        stream << dom->toString();
        file->close();
    }

    ui->releaseNotes->append("Done !");

    delete dom;
    delete file;
}

UManifest::~UManifest()
{
    delete ui;
}


/*----------------------------------------------
          Private methods
----------------------------------------------*/

void UManifest::GenerateManifest(QDomDocument* dom, QDomElement root, QString dir)
{
    QDomElement folders = dom->createElement("Folders");
    root.appendChild(folders);

    QDomElement files = dom->createElement("Files");
    root.appendChild(files);

    QDirIterator it(dir);
    while (it.hasNext())
    {
        QString filePath = it.next();
        QFileInfo fi(filePath);

        if (fi.fileName() == "UnrealManifest.exe"
         || fi.fileName() == "ReleaseNotes.xml"
         || fi.fileName() == "GameManifest.xml"
         ||(fi.fileName().startsWith("Qt5") && fi.fileName().endsWith(".dll")))
        {
            continue;
        }

        if (QDir(filePath).exists())
        {
            if (!filePath.endsWith("."))
            {
                QDomElement folder = dom->createElement("FolderProperties");

                folder.setAttribute("FolderName", fi.fileName());
                root.appendChild(folder);

                GenerateManifest(dom, folder, filePath);
            }
        }
        else
        {
            QDomElement e = dom->createElement("FileProperties");
            QString fileHash = HashFile(filePath);

            if (fileHash.length() > 0)
            {
                e.setAttribute("FileName", fi.fileName());
                e.setAttribute("Size", fi.size());
                e.setAttribute("md5", fileHash);
                ui->releaseNotes->append(filePath  + " : " + fileHash);
            }
            else
            {
                e.setTagName("EmptyFile");
            }

            files.appendChild(e);
        }
    }
}

QString UManifest::HashFile(QString filePath)
{
    QFile* file = new QFile(filePath);
    QByteArray hashed;

    if (file->open(QIODevice::ReadOnly))
    {
        QByteArray content = file->readAll();
        hashed = QCryptographicHash::hash(content, QCryptographicHash::Md5);
        file->close();
    }

    delete file;
    return hashed.toHex().data();
}
