/*=========================================================================

 medInria

 Copyright (c) INRIA 2013 - 2014. All rights reserved.
 See LICENSE.txt for details.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

=========================================================================*/

#include <medTestWorkspace.h>

#include <medTabbedViewContainers.h>

#include <medProcessLayer.h>
#include <medAbstractSubtractImageProcess.h>
#include <medAbstractSubtractImageProcessPresenter.h>

#include <medToolBox.h>

class medTestWorkspacePrivate
{
public:
  medAbstractArithmeticOperationProcess* process;

};

medTestWorkspace::medTestWorkspace(QWidget *parent): medAbstractWorkspaceLegacy (parent), d(new medTestWorkspacePrivate)
{
    // TODO Change here - remove presenter and replace with process (DONE)
    foreach(QString key, medProcessLayer::subtractImage::pluginFactory().keys())
        d->process = medProcessLayer::subtractImage::pluginFactory().create(key);


    this->addToolBox(dynamic_cast<medToolBox*>(d->process->presenter()->toolbox()));
}

medTestWorkspace::~medTestWorkspace()
{
    delete d;
    d = NULL;
}

void medTestWorkspace::setupTabbedViewContainer()
{
    this->tabbedViewContainers()->setSplitter(0, d->process->presenter()->viewContainerSplitter());
}

bool medTestWorkspace::isUsable()
{
    return true;
}
