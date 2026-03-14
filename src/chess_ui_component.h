#pragma once

#include <IComponent.h>
#include <QObject>

class LogosAPI;

class ChessUIComponent : public QObject, public IComponent {
    Q_OBJECT
    Q_INTERFACES(IComponent)
    Q_PLUGIN_METADATA(IID IComponent_iid FILE CHESS_UI_METADATA_FILE)

public:
    explicit ChessUIComponent(QObject *parent = nullptr);
    QWidget* createWidget(LogosAPI* logosAPI = nullptr) override;
    void destroyWidget(QWidget* widget) override;

private:
    LogosAPI* logosAPI;
};
