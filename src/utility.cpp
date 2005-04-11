/*----------------------------------------------------------------------------
  Utility classes for QT steerer GUI

  (C) Copyright 2002, 2004, University of Manchester, United Kingdom,
  all rights reserved.

  This software is produced by the Supercomputing, Visualization and
  e-Science Group, Manchester Computing, University of Manchester
  as part of the RealityGrid project (http://www.realitygrid.org),
  funded by the EPSRC under grants GR/R67699/01 and GR/R67699/02.

  LICENCE TERMS

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions
  are met:
  1. Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.
  2. Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in the
     documentation and/or other materials provided with the distribution.

  THIS MATERIAL IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
  A PARTICULAR PURPOSE ARE DISCLAIMED. THE ENTIRE RISK AS TO THE QUALITY
  AND PERFORMANCE OF THE PROGRAM IS WITH YOU.  SHOULD THE PROGRAM PROVE
  DEFECTIVE, YOU ASSUME THE COST OF ALL NECESSARY SERVICING, REPAIR OR
  CORRECTION.

  Authors........: Mark Riding, Andrew Porter, Sue Ramsden
    
---------------------------------------------------------------------------*/


#include "utility.h"
#include "types.h"
#include "debug.h"

#include <qapplication.h>
#include <qfontmetrics.h>
#include <qpainter.h>
#include <qstring.h>
#include <qwidget.h>

TableLabel::TableLabel(const QString & text, QWidget * parent)
  : QLabel(text, parent)
{
  DBGCON("TableLabel");
  QFont lFont = font();
  lFont.setWeight(QFont::DemiBold);
  lFont.setPointSize(lFont.pointSize()-1);
  setFont(lFont);
  //setFont(QFont( "Times", 9, QFont::DemiBold ));
}

TableLabel::~TableLabel()
{
  DBGDST("TableLabel");
}




AttachListItem::AttachListItem(int aSimIndex, const QString &text)
  : QListBoxItem(), mSimIndex(aSimIndex)
{
  DBGCON("AttachListItem");
  setText( text );
  printf("constucted AttachListItem mSimIndex = %d\n", mSimIndex);

}

AttachListItem::~AttachListItem()
{
  DBGDST("AttachListItem");
}

int
AttachListItem::getSimIndex() const
{
  return mSimIndex;
}


void 
AttachListItem::paint( QPainter *painter )
{
    QFontMetrics fm = painter->fontMetrics();
    painter->drawText( 3, fm.ascent() +  (fm.leading()+1)/2 + 1, text() );
}

int 
AttachListItem::height( const QListBox* lb ) const
{
    int h = lb ? lb->fontMetrics().lineSpacing() + 2 : 0;
    if (h > QApplication::globalStrut().height())
      return h;
    else
      return QApplication::globalStrut().height();
}


int 
AttachListItem::width( const QListBox* lb ) const
{
    int w = lb ? lb->fontMetrics().width( text() ) + 6 : 0;
    if (w > QApplication::globalStrut().width())
      return w;
    else
      return QApplication::globalStrut().width();
}
