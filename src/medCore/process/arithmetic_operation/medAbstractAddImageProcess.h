/*=========================================================================

 medInria

 Copyright (c) INRIA 2013 - 2014. All rights reserved.
 See LICENSE.txt for details.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

=========================================================================*/

#pragma once

#include <medAbstractArithmeticOperationProcess.h>

#include <dtkCore>

#include <medInriaExport.h>

class MEDINRIA_EXPORT  medAbstractAddImageProcess: public medAbstractArithmeticOperationProcess
{
    Q_OBJECT
public:
    medAbstractAddImageProcess(QObject *parent): medAbstractArithmeticOperationProcess(parent) {}
};

DTK_DECLARE_OBJECT        (medAbstractAddImageProcess*)
DTK_DECLARE_PLUGIN        (medAbstractAddImageProcess, MEDINRIA_EXPORT)
DTK_DECLARE_PLUGIN_FACTORY(medAbstractAddImageProcess, MEDINRIA_EXPORT)
DTK_DECLARE_PLUGIN_MANAGER(medAbstractAddImageProcess, MEDINRIA_EXPORT)