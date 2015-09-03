/*=========================================================================

 medInria

 Copyright (c) INRIA 2013 - 2014. All rights reserved.
 See LICENSE.txt for details.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

=========================================================================*/

#pragma once

#include <medAbstractProcessPresenter.h>
class medAbstractArithmeticOperationProcess;

class medViewContainerSplitter;

class medAbstractArithmeticOperationProcessPresenterPrivate;
class medAbstractArithmeticOperationProcessPresenter: public medAsbtractProcessPresenter
{
public:
    medAbstractArithmeticOperationProcessPresenter(medAbstractArithmeticOperationProcess* iProcess, QObject *parent = NULL);
    virtual ~medAbstractArithmeticOperationProcessPresenter();

    virtual QWidget* toolbox() const;
    virtual medViewContainerSplitter* viewContainerSplitter() const;
    virtual medAbstractProcess* process() const;

protected slots:
    void _setInput1();
    void _setInput2();
    void _fillOutputContainer();

private:
    medAbstractArithmeticOperationProcessPresenterPrivate *d;
};
