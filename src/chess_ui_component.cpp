#include "chess_ui_component.h"
#include <QWidget>
#include <QVBoxLayout>
#include <QQuickWidget>
#include <QQmlContext>

ChessUIComponent::ChessUIComponent(QObject *parent)
    : QObject(parent)
    , logosAPI(nullptr)
{
}

QWidget* ChessUIComponent::createWidget(LogosAPI* api) {
    logosAPI = api;
    
    QWidget* container = new QWidget();
    container->setWindowTitle("Chess");
    
    QVBoxLayout* layout = new QVBoxLayout(container);
    layout->setContentsMargins(0, 0, 0, 0);
    
    QQuickWidget* quickWidget = new QQuickWidget(container);
    quickWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);
    quickWidget->setSource(QUrl("qrc:/chess/ChessBoard.qml"));
    
    layout->addWidget(quickWidget);
    
    return container;
}

void ChessUIComponent::destroyWidget(QWidget* widget) {
    if (widget) {
        widget->deleteLater();
    }
}
