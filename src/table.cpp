/*----------------------------------------------------------------------------
    Table class for QT steerer GUI.
    This is an abstract base class.

    (C)Copyright 2002 The University of Manchester, United Kingdom,
    all rights reserved.

    This software is produced by the Supercomputing, Visualization &
    e-Science Group, Manchester Computing, the Victoria University of
    Manchester as part of the RealityGrid project.

    This software has been tested with care but is not guaranteed for
    any particular purpose. Neither the authors, nor the University of
    Manchester offer any warranties or representations, nor do they
    accept any liabilities with respect to this software.

    This program must not be used for commmercial gain without the
    written permission of the authors.
    
    Supercomputing, Visualization & e-Science Group
    Manchester Computing
    University of Manchester
    Manchester M13 9PL

    email:  csar-advice@cfs.ac.uk.
    Tel:    +44 161 275 6824/5997
    Fax:    +44 161 275 6040    
    
    Date          Version    Updates                            Author
    ----          -------    -------                            ------
    03.10.2002      0.1                                         S Ramsden

---------------------------------------------------------------------------*/

#include "table.h"
#include "types.h"
#include "debug.h"

Table::Table(QWidget *aParent, const char *aName, int aSimHandle)
  : QTable(aParent, aName),  mSimHandle(aSimHandle), mInitNumRows(0), mMaxRowIndex(0),
  mAppAttached(true)
{
  DBGCON("Table");

  // Note: used mNumInitRows to force table to have rows before any data received.
  // This workaround as if have zero rows until parameters consumed and hence displayed, the table always
  // has a scroll bar - even if only one row!  
  // Need to fix this properly if poss and get rid of mNumInitRows. (QT issue) SMR XXX 

  // mMaxRowIndex - number rows populated with data in the table (i.e. number of parameters diaplayed)

  // mAppAttached - set to false when application detached from steerer - after a detach
  // the whole table becomes read only
}

Table::~Table()
{
  DBGDST("Table");
}


void 
Table::setAppDetached()
{
  mAppAttached=false;
}


void
Table::setNumInitRows(int aNumInitRows)
{
  mInitNumRows = aNumInitRows;
}

void
Table::incrementRowIndex()
{
  mMaxRowIndex++;
}


bool
Table::getAppAttached() const
{
  return mAppAttached;
}

int 
Table::getNumInitRows() const
{
  return mInitNumRows;
}

int 
Table::getMaxRowIndex() const
{
  return mMaxRowIndex;
}
 
int 
Table::getSimHandle() const
{
  return mSimHandle;
}