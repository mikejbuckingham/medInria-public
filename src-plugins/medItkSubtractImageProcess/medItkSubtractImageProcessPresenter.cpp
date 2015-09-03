/*=========================================================================

 medInria

 Copyright (c) INRIA 2013 - 2014. All rights reserved.
 See LICENSE.txt for details.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

=========================================================================*/

#include <medItkSubtractImageProcessPresenter.h>
#include <medItkSubtractImageProcess.h>

#include <QLabel>

class medItkSubtractImageProcessPresenterPrivate
{
public:
    medItkSubtractImageProcess* process;
};


medItkSubtractImageProcessPresenter::medItkSubtractImageProcessPresenter(medAbstractArithmeticOperationProcess *iProcess, QObject *parent): medAbstractSubtractImageProcessPresenter(iProcess, parent),
    d(new medItkSubtractImageProcessPresenterPrivate)
{
}

medItkSubtractImageProcessPresenter::~medItkSubtractImageProcessPresenter()
{
    delete d;
}
