// /////////////////////////////////////////////////////////////////
// Generated by dtkPluginGenerator
// /////////////////////////////////////////////////////////////////

#include "medViewerWorkspaceSegmentation.h"

#include "medToolBoxSegmentation.h"

#include <medCore/medAbstractView.h>

#include <medProgressionStack.h>
#include <medTabbedViewContainers.h>
#include <medViewContainer.h>
#include <medViewerWorkspaceFactory.h>
#include <medViewerToolBoxLayout.h>
#include <medViewerToolBoxViewProperties.h>

#include <dtkLog/dtkLog.h>

#include <stdexcept>

// /////////////////////////////////////////////////////////////////
// WorkspacePrivate
// /////////////////////////////////////////////////////////////////
class medViewerWorkspaceSegmentationPrivate
{
public:
    // Give values to items without a constructor.
    medViewerWorkspaceSegmentationPrivate() :
      layoutToolBox(NULL), viewPropertiesToolBox(NULL), segmentationToolBox(NULL)
    {}

    medViewerToolBoxLayout              *layoutToolBox;
    medViewerToolBoxViewProperties      *viewPropertiesToolBox;

    medToolBoxSegmentation          *segmentationToolBox;
};

// /////////////////////////////////////////////////////////////////
// medViewerWorkspaceSegmentation
// /////////////////////////////////////////////////////////////////

static QString msegWorkspaceSegmentationDescription = "Segmentation";


medViewerWorkspaceSegmentation::medViewerWorkspaceSegmentation(QWidget * parent /* = NULL */ ) :
medViewerWorkspace(parent), d(new medViewerWorkspaceSegmentationPrivate)
{
    d->segmentationToolBox = new medToolBoxSegmentation(this, parent );

    connect(d->segmentationToolBox, SIGNAL(addToolBox(medToolBox *)), this, SLOT(addToolBox(medToolBox *)));
    connect(d->segmentationToolBox, SIGNAL(removeToolBox(medToolBox *)), this, SLOT(removeToolBox(medToolBox *)));

    // Always have a parent.
    if ( !parent)
        throw (std::runtime_error ("Must have a parent widget"));

    // -- Layout toolbox --
    d->layoutToolBox = new medViewerToolBoxLayout(parent);

    connect (d->layoutToolBox, SIGNAL(modeChanged(const QString&)),
        this,             SIGNAL(layoutModeChanged(const QString&)));
    connect (d->layoutToolBox, SIGNAL(presetClicked(int)),
        this,             SIGNAL(layoutPresetClicked(int)));
    connect (d->layoutToolBox, SIGNAL(split(int,int)),
        this,             SIGNAL(layoutSplit(int,int)));

    connect(this,SIGNAL(setLayoutTab(const QString &)), d->layoutToolBox, SLOT(setTab(const QString &)));

    // -- View toolbox --

    d->viewPropertiesToolBox = new medViewerToolBoxViewProperties(parent);


    connect ( this, SIGNAL(layoutModeChanged(const QString &)),
        stackedViewContainers(), SLOT(changeCurrentContainerType(const QString &)));
    connect ( stackedViewContainers(), SIGNAL(currentChanged(const QString &)),
        this, SLOT(connectToolboxesToCurrentContainer(const QString &)));

    this->addToolBox( d->segmentationToolBox );
    this->addToolBox( d->layoutToolBox );
    this->addToolBox( d->viewPropertiesToolBox );
}

medViewerWorkspaceSegmentation::~medViewerWorkspaceSegmentation(void)
{
    delete d;
    d = NULL;
}

bool medViewerWorkspaceSegmentation::registerWithViewerWorkspaceFactory()
{
    return medViewerWorkspaceFactory::instance()->registerWorkspace
            <medViewerWorkspaceSegmentation>(
                medViewerWorkspaceSegmentation::s_identifier(),
                tr("Segmentation"),
                tr("Segment Images"));
}


void medViewerWorkspaceSegmentation::setupViewContainerStack()
{
    const QString description(this->description());
    if (!stackedViewContainers()->count())
    {
        addDefaultTypeContainer(description);
        //Default container:
        this->connectToolboxesToCurrentContainer(description);
    }

    this->stackedViewContainers()->unlockTabs();
}

//static
QString medViewerWorkspaceSegmentation::description( void ) const
{
    return msegWorkspaceSegmentationDescription;
}

void medViewerWorkspaceSegmentation::onViewAdded( dtkAbstractView* view )
{
    emit viewAdded(view);
}

void medViewerWorkspaceSegmentation::onViewRemoved( dtkAbstractView* view )
{
    emit viewRemoved(view);
}


medProgressionStack * medViewerWorkspaceSegmentation::progressionStack()
{
    return d->segmentationToolBox->progressionStack();
}

void medViewerWorkspaceSegmentation::buildWorkspace(  )
{
    QWidget * parent = qobject_cast<QWidget *>(this->parent());
    if ( !d->segmentationToolBox)
        d->segmentationToolBox = new medToolBoxSegmentation( this, parent );

    this->addToolBox( d->segmentationToolBox );
}

medToolBoxSegmentation * medViewerWorkspaceSegmentation::segmentationToobox()
{
    return d->segmentationToolBox;
}


void medViewerWorkspaceSegmentation::connectToolboxesToCurrentContainer(const QString &name)
{
    connect(stackedViewContainers()->container(name),SIGNAL(viewAdded(dtkAbstractView*)),
        this,SLOT(onViewAdded(dtkAbstractView*)));
    connect(stackedViewContainers()->container(name),SIGNAL(viewRemoved(dtkAbstractView*)),
        this,SLOT(onViewRemoved(dtkAbstractView*)));
}

QString medViewerWorkspaceSegmentation::s_identifier()
{
    return "msegWorkspace";
}

QString medViewerWorkspaceSegmentation::identifier( void ) const
{
    return s_identifier();
}

