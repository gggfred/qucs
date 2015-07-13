/***************************************************************************
                                 main.cpp
                              ----------------
    begin                : Wed Apr 10 2014
    copyright            : (C) 2014 by Vadim Kuznetsov
    email                : ra3xdh@gmail.com
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifdef HAVE_CONFIG_H
# include <config.h>
#endif

#include <stdlib.h>
#include <QtCore>
#include <QApplication>

#include "qucsactivefilter.h"

struct tQucsSettings QucsSettings;


// #########################################################################
// Loads the settings file and stores the settings.
bool loadSettings()
{
    QSettings settings("qucs","qucs");
    settings.beginGroup("QucsActiveFilter");
    if(settings.contains("x"))QucsSettings.x=settings.value("x").toInt();
    if(settings.contains("y"))QucsSettings.y=settings.value("y").toInt();
    settings.endGroup();

    if(settings.contains("font"))QucsSettings.font.fromString(settings.value("font").toString());
    if(settings.contains("Language"))QucsSettings.Language=settings.value("Language").toString();

  return true;
}


// #########################################################################
// Saves the settings in the settings file.
bool saveApplSettings(QucsActiveFilter *qucs)
{
    QSettings settings ("qucs","qucs");
    settings.beginGroup("QucsActiveFilter");
    settings.setValue("x", qucs->x());
    settings.setValue("y", qucs->y());
    settings.endGroup();
  return true;

}


int main(int argc, char *argv[])
{
  QString LangDir;
    // apply default settings
    QucsSettings.x = 200;
    QucsSettings.y = 100;
    QucsSettings.font = QFont("Helvetica", 12);

    // is application relocated?
    char * var = getenv ("QUCSDIR");
    if (var != NULL) {
      QDir QucsDir = QDir (var);
      QString QucsDirStr = QucsDir.canonicalPath ();
      LangDir =
        QDir::convertSeparators (QucsDirStr + "/share/qucs/lang/");
    } else {
      LangDir = LANGUAGEDIR;
    }

    loadSettings();

    QApplication a(argc, argv);
    a.setFont(QucsSettings.font);

    QTranslator tor( 0 );
    QString Lang = QucsSettings.Language;
    if(Lang.isEmpty())
      Lang = QString(QLocale::system().name());
    tor.load( QString("qucs_") + Lang, LangDir);
    a.installTranslator( &tor );

    QucsActiveFilter *w = new QucsActiveFilter();
    w->raise();
    w->move(QucsSettings.x, QucsSettings.y);  // position before "show" !!!
    w->show();
    
    int result = a.exec();
    saveApplSettings(w);
    return result;
}
