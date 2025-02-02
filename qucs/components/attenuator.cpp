/***************************************************************************
                          attenuator.cpp  -  description
                             -------------------
    begin                : Sat Aug 23 2003
    copyright            : (C) 2003 by Michael Margraf
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

#include "attenuator.h"


Attenuator::Attenuator()
{
  Description = QObject::tr("attenuator");

  Lines.push_back(Line( -4, -6, -4,  6,QPen(Qt::darkBlue,2)));
  Lines.push_back(Line( -4, -6,  4, -6,QPen(Qt::darkBlue,2)));
  Lines.push_back(Line(  4, -6,  4,  6,QPen(Qt::darkBlue,2)));
  Lines.push_back(Line( -4,  6,  4,  6,QPen(Qt::darkBlue,2)));
  Lines.push_back(Line(  0,-11,  0, -6,QPen(Qt::darkBlue,2)));
  Lines.push_back(Line(  0,  6,  0, 11,QPen(Qt::darkBlue,2)));

  Lines.push_back(Line(-14,-14, 14,-14,QPen(Qt::darkBlue,2)));
  Lines.push_back(Line(-14, 14, 14, 14,QPen(Qt::darkBlue,2)));
  Lines.push_back(Line(-14,-14,-14, 14,QPen(Qt::darkBlue,2)));
  Lines.push_back(Line( 14,-14, 14, 14,QPen(Qt::darkBlue,2)));

  Lines.push_back(Line(-30,  0,-14,  0,QPen(Qt::darkBlue,2)));
  Lines.push_back(Line( 14,  0, 30,  0,QPen(Qt::darkBlue,2)));

  Ports.push_back(Port(-30,  0));
  Ports.push_back(Port( 30,  0));

  x1 = -30; y1 = -17;
  x2 =  30; y2 =  17;

  tx = x1+4;
  ty = y2+4;
  Model = "Attenuator";
  Name  = "X";

  Props.push_back(Property("L", "10 dB", true,
		QObject::tr("power attenuation")));
  Props.push_back(Property("Zref", "50 Ohm", false,
		QObject::tr("reference impedance")));
  Props.push_back(Property("Temp", "26.85", false,
		QObject::tr("simulation temperature in degree Celsius")));
}

Attenuator::~Attenuator()
{
}

Component* Attenuator::newOne()
{
  return new Attenuator();
}

Element* Attenuator::info(QString& Name, char* &BitmapFile, bool getNewOne)
{
  Name = QObject::tr("Attenuator");
  BitmapFile = (char *) "attenuator";

  if(getNewOne)  return new Attenuator();
  return 0;
}
