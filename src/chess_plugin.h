#pragma once

#include <QObject>
#include <QtPlugin>
#include "chess_module.h"

// Forward declaration
class LogosAPI;

class ChessPlugin : public QObject {
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.logos.module.PluginInterface" FILE "metadata.json")

public:
    explicit ChessPlugin(QObject *parent = nullptr);
    
    Q_INVOKABLE QString version() const { return QStringLiteral("0.1.0"); }
    Q_INVOKABLE void initLogos(LogosAPI* api);
    
    // Chess game API
    Q_INVOKABLE void newGame();
    Q_INVOKABLE QString getCurrentFEN() const;
    Q_INVOKABLE bool makeMove(int fromSquare, int toSquare, const QString& promotion = QString());
    Q_INVOKABLE QVariantList getValidMoves(int square) const;
    Q_INVOKABLE QVariantMap getGameState() const;
    Q_INVOKABLE void loadPosition(const QString& fen);

private:
    ChessModule* m_chessModule;
    LogosAPI* m_logosAPI;
};
