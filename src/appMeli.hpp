/*
 * appMeli.hpp
 *
 *  Created on: 15/06/2013
 *      Author: sebastiankaplun
 */

#ifndef APPMELI_HPP_
#define APPMELI_HPP_

#include "imageloader.hpp"

#include <QtCore/QObject>
#include <QtCore/QVector>

#include <bb/cascades/QListDataModel>
#include <bb/cascades/NavigationPane>

namespace bb { namespace cascades { class Application; }}

/*!
 * @brief Application pane object
 *
 *Use this object to create and init app UI, to create context objects, to register the new meta types etc.
 */
class AppMeli : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bb::cascades::DataModel* model READ model CONSTANT)

public:
    AppMeli(bb::cascades::Application *app);
    virtual ~AppMeli() {}
    Q_INVOKABLE QString currentDir();
    Q_INVOKABLE void pushImage(QString fileName);
    // This method is called to start the loading of all images.
        Q_INVOKABLE void loadImages();
        Q_INVOKABLE void addImage(QString val, QString price,QString seller,QString permalink);
        Q_INVOKABLE QString getImage();
        bb::cascades::NavigationPane* mNav;
private Q_SLOTS:
    /*
     * Response handler for the network operation.
     */
    void commentDataReceived();
    void requestFinished(QNetworkReply*);

private:
    // The accessor method for the property
    bb::cascades::DataModel* model() const;
    // The model that contains the progress and image data
    bb::cascades::QListDataModel<QObject*>* m_model;

    QString m_query;


};







#endif /* APPMELI_HPP_ */
