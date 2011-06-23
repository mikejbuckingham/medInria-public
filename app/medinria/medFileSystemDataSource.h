#ifndef medFileSystemDataSource_h__
#define medFileSystemDataSource_h__

#include <medCore/medAbstractDataSource.h>

class medFileSystemDataSourcePrivate;

/**
 * File-system explorer working as a concrete data source
 * Let's the user pick folders or data and import or view it
 */
class medFileSystemDataSource : public medAbstractDataSource
{
    Q_OBJECT

public:
    medFileSystemDataSource(QWidget* parent = 0);
    ~medFileSystemDataSource();

    QWidget* mainViewWidget();

    QWidget* sourceSelectorWidget();

    QString tabName();

    QList<medToolBox*> getToolboxes();

signals:

    /**
    * Signal emitted when the user chooses to load
    * a file or directory.
    * @param path - the path of the image or directory
    **/
    void load(QString path);

    /**
    * Signal emitted when the user chooses to open
    * a file or directory.
    * @param path - the path of the image or directory
    **/
    void open(QString path);

private slots:
    void onFileSystemImportClicked();
    void onFileSystemLoadClicked();
    void onFileSystemViewClicked();


private:
    medFileSystemDataSourcePrivate* d;
};

#endif // medFileSystemDataSource_h__
