#include "chess_plugin.h"
#include <QStandardPaths>
#ifdef LOGOS_CORE_AVAILABLE
#include <logos_api.h>
#include <logos_api_client.h>
#endif

ChessPlugin::ChessPlugin(QObject *parent)
    : QObject(parent)
    , m_chessModule(new ChessModule())
    , m_logosAPI(nullptr)
{
}

void ChessPlugin::initLogos(LogosAPI* api) {
    m_logosAPI = api;

#ifdef LOGOS_CORE_AVAILABLE
    // Initialize with kv_module for persistence if available
    auto* kvClient = api->getClient("kv_module");
    if (kvClient) {
        kvClient->invokeRemoteMethod("kv_module", "setDataDir",
            QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/kv-data");
    }
#endif
}

void ChessPlugin::newGame() {
    m_chessModule->newGame();
}

QString ChessPlugin::getCurrentFEN() const {
    return QString::fromStdString(m_chessModule->getCurrentFEN());
}

bool ChessPlugin::makeMove(int fromSquare, int toSquare, const QString& promotion) {
    Move move;
    move.from = fromSquare;
    move.to = toSquare;
    move.promotion = promotion.toStdString();
    return m_chessModule->makeMove(move);
}

QVariantList ChessPlugin::getValidMoves(int square) const {
    QVariantList result;
    auto moves = m_chessModule->getValidMoves(square);
    for (const auto& move : moves) {
        QVariantMap moveMap;
        moveMap["from"] = move.from;
        moveMap["to"] = move.to;
        moveMap["promotion"] = QString::fromStdString(move.promotion);
        result.append(moveMap);
    }
    return result;
}

QVariantMap ChessPlugin::getGameState() const {
    auto state = m_chessModule->getState();
    QVariantMap result;
    result["fen"] = QString::fromStdString(state.fen);
    result["isCheck"] = state.isCheck;
    result["isCheckmate"] = state.isCheckmate;
    result["isStalemate"] = state.isStalemate;
    result["currentPlayer"] = QString::fromStdString(state.currentPlayer);
    return result;
}

void ChessPlugin::loadPosition(const QString& fen) {
    m_chessModule->loadPosition(fen.toStdString());
}
