/*----------------------------------------------------------------------------
    Application class header file for QT steerer GUI.

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


#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "types.h"

#include <qwidget.h>

class QGroupBox;
class QPushButton;
class QString;

class ControlForm;

class Application : public QWidget
{
  Q_OBJECT

public:

  Application(QWidget *mParent, const char *, int aSimHandle);
  ~Application();

  void customEvent(QCustomEvent *);
  void processNextMessage(REG_MsgType aMsgType);
  void enableCmdButtons();


private:
  void detachFromApplication();
  void disableForDetach();
  void disableCmdButtons();
  void emitSingleCmd(int aCmdId);

protected slots:
  void emitDetachCmdSlot();
  void emitStopCmdSlot();
  void emitPauseCmdSlot();
  void emitResumeCmdSlot();
  void closeApplicationSlot();
  void detachFromApplicationForErrorSlot();

signals:
  void closeApplicationSignal(int aSimHandle);


private:
  const int		mSimHandle;

  int		mNumCommands;
  bool		mDetachSupported;
  bool		mStopSupported;
  bool		mPauseSupported;
  bool		mResumeSupported;
  bool		mDetachedFlag;

  QPushButton	*mCloseButton;

  QPushButton	*mDetachButton;
  QPushButton	*mStopButton;
  QPushButton	*mPauseButton;
  QPushButton	*mResumeButton;

  QPushButton	*mTellAndDetachButton;

  ControlForm	*mControlForm;
  QGroupBox	*mControlBox; 


};


#endif