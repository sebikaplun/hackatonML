/*
 * appMeli.cpp
 *
 *  Created on: 15/06/2013
 *      Author: sebastiankaplun
 */

#include "appMeli.hpp"

#include <bb/cascades/Application>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/AbstractPane>
#include <bb/cascades/NavigationPane>
#include <bb/cascades/Page>

#include <QHttpMultiPart>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace bb::cascades;

AppMeli::AppMeli(bb::cascades::Application *app) :
		QObject(app), m_model(new QListDataModel<QObject*>()) {

	// create scene document from main.qml asset
	// set parent to created document to ensure it exists for the whole application lifetime

	QmlDocument *qml = QmlDocument::create("asset:///main.qml");
	qml->setParent(this);
	//mNav = qml->createRootNode<NavigationPane>();

	qmlRegisterType<ImageLoader>();
	m_model->setParent(this);

	qml->setContextProperty("appContext", this);

	// create root object for the UI
	mNav = qml->createRootObject<NavigationPane>();
	// set created root object as a scene
	app->setScene(mNav);

}

QString AppMeli::currentDir() {
	return QDir::currentPath();
}

void AppMeli::pushImage(QString fileName) {

	QString fn = fileName;

	QNetworkRequest request = QNetworkRequest();
	request.setUrl(QUrl("http://www.jailbreaker.com.ar/hackml/update1.php"));

	// Creates the network access manager and connects a custom slot to its
	// finished signal. Checks the return value for errors.
	QNetworkAccessManager *networkAccessManager = new QNetworkAccessManager(
			this);

	// If any Q_ASSERT statement(s) indicate that the slot failed to connect to
	// the signal, make sure you know exactly why this has happened. This is not
	// normal, and will cause your app to stop working!!
	bool connectResult;

	// Since the variable is not used in the app, this is added to avoid a
	// compiler warning.
	Q_UNUSED(connectResult);

	connectResult = connect(networkAccessManager,
			SIGNAL(finished(QNetworkReply*)), this,
			SLOT(requestFinished(QNetworkReply*)));

	// This is only available in Debug builds.
	Q_ASSERT(connectResult);

	// Sends the HTTP request.
	networkAccessManager->get(request);

	QNetworkAccessManager* netManager = new QNetworkAccessManager();
	if (!netManager) {
		qDebug() << "Unable to create QNetworkAccessManager!";
		//emit complete("Unable to create QNetworkAccessManager!", false);
		return;
	}

	QHttpMultiPart *multiPart = new QHttpMultiPart(
			QHttpMultiPart::FormDataType);

	QHttpPart commentPart;
	commentPart.setHeader(QNetworkRequest::ContentDispositionHeader,
			QVariant("form-data; name=\"comment\""));
	commentPart.setBody("Comment goes here");

	QHttpPart namePart;
	namePart.setHeader(QNetworkRequest::ContentDispositionHeader,
			QVariant("form-data; name=\"name\""));
	namePart.setBody("Name goes here");

	//double randomnumber = Math.floor(Math.random() * 11000)
	QHttpPart imagePart;
	imagePart.setHeader(QNetworkRequest::ContentTypeHeader, "image/jpg");
	imagePart.setHeader(QNetworkRequest::ContentDispositionHeader,
			QVariant("form-data; name=\"file\"; filename=\"imagen.jpg"));

	QFile *file = new QFile(fn);
	file->open(QIODevice::ReadOnly);
	imagePart.setBodyDevice(file);
	file->setParent(multiPart);

	multiPart->append(commentPart);
	multiPart->append(namePart);
	multiPart->append(imagePart);

	QString queryUri = "http://www.jailbreaker.com.ar/hackml/upload1.php";

	QUrl url(queryUri);

	QNetworkRequest req(url);

	QNetworkReply* ipReply = netManager->post(req, multiPart);
	connect(ipReply, SIGNAL(finished()), this, SLOT(commentDataReceived()));

}

void AppMeli::requestFinished(QNetworkReply* reply) {
	m_model->clear();
	qDebug() << "termino3";
	QByteArray data = reply->readAll();
	qDebug() << data;


	mNav->setProperty("query", data);

	QmlDocument *qml = QmlDocument::create("asset:///imageFinder.qml");
	qml->setContextProperty("appContext", this);

	Page *page = qml->createRootObject<Page>();
	page->setProperty("query2", data);
	page->setProperty("queryOriginal", data);

	mNav->push(page);
	reply->deleteLater();

}

void AppMeli::commentDataReceived() {

	QNetworkReply *reply = qobject_cast<QNetworkReply *>(sender());
	QByteArray data = reply->readAll();
	qDebug() << "termino2";
	qDebug() << data;

}
void AppMeli::addImage(QString val, QString price,QString seller,QString permalink) {
	m_model->append(new ImageLoader(val, price, seller,permalink,this));
}

QString AppMeli::getImage() {
	return m_query;
}
void AppMeli::loadImages() {
// Call the load() method for each ImageLoader instance inside the model
	for (int row = 0; row < m_model->size(); ++row) {
		qobject_cast<ImageLoader*>(m_model->value(row))->load();
	}
}
//! [1]

bb::cascades::DataModel* AppMeli::model() const {
	return m_model;
}

