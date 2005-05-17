/***************************************************************************
                          diode.cpp  -  description
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

#include "diode.h"


Diode::Diode()
{
  Description = QObject::tr("diode");

  Lines.append(new Line(-30,  0, 30,  0,QPen(QPen::darkBlue,2)));
  Lines.append(new Line( -6, -9, -6,  9,QPen(QPen::darkBlue,2)));
  Lines.append(new Line(  6, -9,  6,  9,QPen(QPen::darkBlue,2)));
  Lines.append(new Line( -6,  0,  6, -9,QPen(QPen::darkBlue,2)));
  Lines.append(new Line( -6,  0,  6,  9,QPen(QPen::darkBlue,2)));

  Ports.append(new Port(-30, 0));
  Ports.append(new Port( 30, 0));

  x1 = -30; y1 = -9;
  x2 =  30; y2 =  9;

  tx = x1+4;
  ty = y2+4;
  Model = "Diode";
  Name  = "D";

  Props.append(new Property("Is", "1e-15 A", true,
	QObject::tr("saturation current")));
  Props.append(new Property("N", "1", true,
	QObject::tr("emission coefficient")));
  Props.append(new Property("Cj0", "10 fF", true,
	QObject::tr("zero-bias junction capacitance")));
  Props.append(new Property("M", "0.5", true,
	QObject::tr("grading coefficient")));
  Props.append(new Property("Vj", "0.7 V", true,
	QObject::tr("junction potential")));
  Props.append(new Property("Fc", "0.5", false,
	QObject::tr("forward-bias depletion capacitance coefficient")));
  Props.append(new Property("Cp", "0.0 fF", false,
	QObject::tr("linear capacitance")));
  Props.append(new Property("Isr", "0.0", false,
	QObject::tr("recombination current parameter")));
  Props.append(new Property("Nr", "2.0", false,
	QObject::tr("emission coefficient for Isr")));
  Props.append(new Property("Rs", "0.0 Ohm", false,
	QObject::tr("ohmic series resistance")));
  Props.append(new Property("Tt", "0.0 ps", false,
	QObject::tr("transit time")));
  Props.append(new Property("Temp", "26.85", false,
	QObject::tr("simulation temperature in degree Celsius")));
  Props.append(new Property("Kf", "0.0", false,
        QObject::tr("flicker noise coefficient")));
  Props.append(new Property("Af", "1.0", false,
	QObject::tr("flicker noise exponent")));
  Props.append(new Property("Ffe", "1.0", false,
	QObject::tr("flicker noise frequency exponent")));
  Props.append(new Property("Bv", "0", false,
	QObject::tr("reverse breakdown voltage")));
  Props.append(new Property("Ibv", "1 mA", false,
	QObject::tr("current at reverse breakdown voltage")));
}

Diode::~Diode()
{
}

Component* Diode::newOne()
{
  return new Diode();
}

Component* Diode::info(QString& Name, char* &BitmapFile, bool getNewOne)
{
  Name = QObject::tr("Diode");
  BitmapFile = "diode";

  if(getNewOne)  return new Diode();
  return 0;
}
