//
// Created by Simone Buccolieri on 18/03/25.
//

#ifndef VIDEOMODEL_H
#define VIDEOMODEL_H

#include <QString>
#include <QJsonObject>

class VideoModel {
public:
    VideoModel() {}
    VideoModel(const QJsonObject &json);

    QString getTitolo() const { return titolo; }
    QString getRegista() const { return regista; }

protected:  // ✅ Permette alle classi derivate di accedere a questi membri
    QString titolo;
    QString regista;
};



#endif //VIDEOMODEL_H
