/***************************************************************************
                                vpulse.cpp
                               ------------
    begin                : Sat Sep 18 2004
    copyright            : (C) 2004 by Michael Margraf
    email                : michael.margraf@alumni.tu-berlin.de
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#include "vpulse.h"


vPulse::vPulse()
{
  Description = QObject::tr("ideal voltage pulse source");

  Arcs.push_back(Arc(-12,-12, 24, 24,     0, 16*360,QPen(Qt::darkBlue,2)));
  Lines.push_back(Line(-30,  0,-12,  0,QPen(Qt::darkBlue,2)));
  Lines.push_back(Line( 30,  0, 12,  0,QPen(Qt::darkBlue,2)));
  Lines.push_back(Line( 18,  5, 18, 11,QPen(Qt::red,1)));
  Lines.push_back(Line( 21,  8, 15,  8,QPen(Qt::red,1)));
  Lines.push_back(Line(-18,  5,-18, 11,QPen(Qt::black,1)));

  Lines.push_back(Line(  6, -3,  6,  3,QPen(Qt::darkBlue,2)));
  Lines.push_back(Line( -6, -7, -6, -3,QPen(Qt::darkBlue,2)));
  Lines.push_back(Line( -6,  3, -6,  7,QPen(Qt::darkBlue,2)));
  Lines.push_back(Line( -6, -3,  6, -3,QPen(Qt::darkBlue,2)));
  Lines.push_back(Line( -6,  3,  6,  3,QPen(Qt::darkBlue,2)));

  Ports.push_back(Port( 30,  0));
  Ports.push_back(Port(-30,  0));

  x1 = -30; y1 = -14;
  x2 =  30; y2 =  14;

  tx = x1+4;
  ty = y2+4;
  Model = "Vpulse";
  Name  = "V";

  Props.push_back(Property("U1", "0 V", true,
		QObject::tr("voltage before and after the pulse")));
  Props.push_back(Property("U2", "1 V", true,
		QObject::tr("voltage of the pulse")));
  Props.push_back(Property("T1", "0", true,
		QObject::tr("start time of the pulse")));
  Props.push_back(Property("T2", "1 ms", true,
		QObject::tr("ending time of the pulse")));
  Props.push_back(Property("Tr", "1 ns", false,
		QObject::tr("rise time of the leading edge")));
  Props.push_back(Property("Tf", "1 ns", false,
		QObject::tr("fall time of the trailing edge")));

  rotate();  // fix historical flaw
}

vPulse::~vPulse()
{
}

Component* vPulse::newOne()
{
  return new vPulse();
}

Element* vPulse::info(QString& Name, char* &BitmapFile, bool getNewOne)
{
  Name = QObject::tr("Voltage Pulse");
  BitmapFile = (char *) "vpulse";

  if(getNewOne)  return new vPulse();
  return 0;
}
