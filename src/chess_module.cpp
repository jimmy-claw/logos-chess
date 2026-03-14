#include "chess_module.h"
#include <sstream>
#include <algorithm>
#include <cctype>

ChessModule::ChessModule() : board(64, ' '), whiteToMove(true) {
    newGame();
}

void ChessModule::newGame() {
    loadPosition("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
}

void ChessModule::loadPosition(const std::string& fen) {
    boardFEN = fen;
    parseFEN(fen);
}

void ChessModule::parseFEN(const std::string& fen) {
    // Clear board
    board.assign(64, ' ');
    
    std::istringstream iss(fen);
    std::string piecePlacement, activeColor, castling, enPassant;
    int halfmoveClock = 0, fullmoveNumber = 1;
    
    iss >> piecePlacement >> activeColor >> castling >> enPassant;
    iss >> halfmoveClock >> fullmoveNumber;
    
    // Parse piece placement
    int row = 0, col = 0;
    for (char c : piecePlacement) {
        if (c == '/') {
            row++;
            col = 0;
        } else if (isdigit(c)) {
            col += c - '0';
        } else {
            board[row * 8 + col] = c;
            col++;
        }
    }
    
    // Set active color
    whiteToMove = (activeColor == "w");
}

std::string ChessModule::generateFEN() const {
    std::ostringstream fen;
    
    // Piece placement
    for (int row = 0; row < 8; ++row) {
        int emptyCount = 0;
        for (int col = 0; col < 8; ++col) {
            char piece = board[row * 8 + col];
            if (piece == ' ') {
                emptyCount++;
            } else {
                if (emptyCount > 0) {
                    fen << emptyCount;
                    emptyCount = 0;
                }
                fen << piece;
            }
        }
        if (emptyCount > 0) {
            fen << emptyCount;
        }
        if (row < 7) {
            fen << '/';
        }
    }
    
    // Active color
    fen << ' ' << (whiteToMove ? 'w' : 'b');
    
    // Castling (simplified - always show all for now)
    fen << " KQkq";
    
    // En passant
    fen << " -";
    
    // Halfmove clock and fullmove number
    fen << " 0 1";
    
    return fen.str();
}

bool ChessModule::makeMove(const Move& move) {
    if (!isValidMove(move)) {
        return false;
    }

    int fromRow = move.from / 8;
    int fromCol = move.from % 8;
    int toRow = move.to / 8;
    int toCol = move.to % 8;
    
    char piece = getPieceAt(fromRow, fromCol);
    
    // Handle pawn promotion
    if (!move.promotion.empty() && toRow == (whiteToMove ? 0 : 7)) {
        char promoPiece = move.promotion[0];
        piece = whiteToMove ? std::toupper(promoPiece) : std::tolower(promoPiece);
    }
    
    // Move the piece
    board[move.to] = piece;
    board[move.from] = ' ';
    
    // Switch player
    whiteToMove = !whiteToMove;
    
    // Update FEN
    boardFEN = generateFEN();
    
    return true;
}

bool ChessModule::isValidMove(const Move& move) const {
    if (!isValidSquare(move.from / 8, move.from % 8) || !isValidSquare(move.to / 8, move.to % 8)) {
        return false;
    }

    char piece = getPieceAt(move.from / 8, move.from % 8);
    if (piece == ' ') {
        return false;
    }

    // Check if it's the right player's turn
    bool isWhitePiece = std::isupper(piece);
    if (isWhitePiece != whiteToMove) {
        return false;
    }

    // Get valid moves and check if move is in list
    auto validMoves = getValidMoves(move.from);
    return std::find_if(validMoves.begin(), validMoves.end(), 
        [&move](const Move& m) {
            return m.from == move.from && m.to == move.to;
        }) != validMoves.end();
}

std::vector<Move> ChessModule::getValidMoves(int square) const {
    int row = square / 8;
    int col = square % 8;
    
    if (!isValidSquare(row, col)) {
        return {};
    }

    char piece = getPieceAt(row, col);
    if (piece == ' ') {
        return {};
    }

    bool isWhite = std::isupper(piece);
    std::vector<Move> moves;
    
    switch (std::tolower(piece)) {
        case 'p':
            moves = generatePawnMoves(row, col, isWhite);
            break;
        case 'n':
            moves = generateKnightMoves(row, col, isWhite);
            break;
        case 'b':
            moves = generateBishopMoves(row, col, isWhite);
            break;
        case 'r':
            moves = generateRookMoves(row, col, isWhite);
            break;
        case 'q':
            moves = generateQueenMoves(row, col, isWhite);
            break;
        case 'k':
            moves = generateKingMoves(row, col, isWhite);
            break;
    }

    // Filter moves that would leave king in check
    std::vector<Move> legalMoves;
    for (const auto& move : moves) {
        if (!wouldBeInCheckAfterMove(move, isWhite)) {
            legalMoves.push_back(move);
        }
    }

    return legalMoves;
}

bool ChessModule::wouldBeInCheckAfterMove(const Move& move, bool white) const {
    // Simulate the move and check if king would be in check
    std::vector<char> tempBoard = board;
    bool tempWhiteToMove = whiteToMove;
    
    // Make temporary move
    tempBoard[move.to] = tempBoard[move.from];
    tempBoard[move.from] = ' ';
    
    // Temporarily swap board and check
    std::swap(const_cast<std::vector<char>&>(board), tempBoard);
    bool inCheck = isInCheck(white);
    std::swap(const_cast<std::vector<char>&>(board), tempBoard);
    
    return inCheck;
}

GameState ChessModule::getState() const {
    GameState state;
    state.fen = getCurrentFEN();
    state.currentPlayer = whiteToMove ? "white" : "black";
    state.isCheck = isInCheck(whiteToMove);
    
    // Check for checkmate or stalemate
    bool hasMoves = false;
    for (int sq = 0; sq < 64 && !hasMoves; ++sq) {
        char piece = board[sq];
        if (piece != ' ' && (std::isupper(piece) == whiteToMove)) {
            auto moves = getValidMoves(sq);
            if (!moves.empty()) {
                hasMoves = true;
            }
        }
    }
    
    state.isCheckmate = state.isCheck && !hasMoves;
    state.isStalemate = !state.isCheck && !hasMoves;
    
    return state;
}

std::string ChessModule::getCurrentFEN() const {
    return generateFEN();
}

bool ChessModule::isInCheck(bool white) const {
    // Find king position
    int kingSquare = -1;
    char kingPiece = white ? 'K' : 'k';
    
    for (int sq = 0; sq < 64; ++sq) {
        if (board[sq] == kingPiece) {
            kingSquare = sq;
            break;
        }
    }
    
    if (kingSquare == -1) return false;
    
    return isSquareAttacked(kingSquare, white);
}

bool ChessModule::isSquareAttacked(int square, bool white) const {
    int row = square / 8;
    int col = square % 8;
    
    // Check attacks from all opponent pieces
    for (int r = 0; r < 8; ++r) {
        for (int c = 0; c < 8; ++c) {
            char piece = getPieceAt(r, c);
            if (piece == ' ') continue;
            
            bool isOpponentPiece = white ? std::islower(piece) : std::isupper(piece);
            if (!isOpponentPiece) continue;
            
            // Check if this piece can attack the target square
            char lowerPiece = std::tolower(piece);
            int fromSquare = r * 8 + c;
            
            switch (lowerPiece) {
                case 'p': {
                    int direction = white ? 1 : -1; // Pawns attack diagonally
                    if (r + direction == row && (c - 1 == col || c + 1 == col)) {
                        return true;
                    }
                    break;
                }
                case 'n': {
                    int dr = std::abs(r - row);
                    int dc = std::abs(c - col);
                    if ((dr == 2 && dc == 1) || (dr == 1 && dc == 2)) {
                        return true;
                    }
                    break;
                }
                case 'k': {
                    if (std::abs(r - row) <= 1 && std::abs(c - col) <= 1) {
                        return true;
                    }
                    break;
                }
                case 'b':
                case 'r':
                case 'q': {
                    if (canSlideAttack(r, c, row, col, lowerPiece)) {
                        return true;
                    }
                    break;
                }
            }
        }
    }
    
    return false;
}

bool ChessModule::canSlideAttack(int fromRow, int fromCol, int toRow, int toCol, char piece) const {
    int dr = toRow - fromRow;
    int dc = toCol - fromCol;
    
    // Bishop moves diagonally
    if (piece == 'b' && std::abs(dr) != std::abs(dc)) {
        return false;
    }
    
    // Rook moves horizontally or vertically
    if (piece == 'r' && dr != 0 && dc != 0) {
        return false;
    }
    
    // Queen is combination of both
    if (piece == 'q' && dr != 0 && dc != 0 && std::abs(dr) != std::abs(dc)) {
        return false;
    }
    
    if (dr == 0 && dc == 0) return false;
    
    int stepR = (dr == 0) ? 0 : (dr > 0 ? 1 : -1);
    int stepC = (dc == 0) ? 0 : (dc > 0 ? 1 : -1);
    
    // Check if path is clear
    int r = fromRow + stepR;
    int c = fromCol + stepC;
    while (r != toRow || c != toCol) {
        if (board[r * 8 + c] != ' ') {
            return false;
        }
        r += stepR;
        c += stepC;
    }
    
    return true;
}

std::vector<Move> ChessModule::generateAllValidMoves(bool white) const {
    std::vector<Move> moves;
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            char piece = getPieceAt(row, col);
            if ((std::isupper(piece) && white) || (std::islower(piece) && !white)) {
                int square = row * 8 + col;
                auto pieceMoves = getValidMoves(square);
                moves.insert(moves.end(), pieceMoves.begin(), pieceMoves.end());
            }
        }
    }
    return moves;
}

std::vector<Move> ChessModule::generatePawnMoves(int row, int col, bool white) const {
    std::vector<Move> moves;
    int direction = white ? -1 : 1;
    int startRow = white ? 6 : 1;
    int from = row * 8 + col;
    
    // Forward move
    if (isValidSquare(row + direction, col) && !isSquareOccupied(row + direction, col)) {
        int to = (row + direction) * 8 + col;
        // Check for promotion
        if ((white && row + direction == 0) || (!white && row + direction == 7)) {
            moves.push_back({from, to, "q"});
            moves.push_back({from, to, "r"});
            moves.push_back({from, to, "b"});
            moves.push_back({from, to, "n"});
        } else {
            moves.push_back({from, to, ""});
        }
        
        // Double move from starting position
        if (row == startRow && !isSquareOccupied(row + 2 * direction, col)) {
            moves.push_back({from, (row + 2 * direction) * 8 + col, ""});
        }
    }
    
    // Captures
    for (int dc : {-1, 1}) {
        int newRow = row + direction;
        int newCol = col + dc;
        if (isValidSquare(newRow, newCol) && isOccupiedByOpponent(newRow, newCol, white)) {
            int to = newRow * 8 + newCol;
            // Check for promotion
            if ((white && newRow == 0) || (!white && newRow == 7)) {
                moves.push_back({from, to, "q"});
                moves.push_back({from, to, "r"});
                moves.push_back({from, to, "b"});
                moves.push_back({from, to, "n"});
            } else {
                moves.push_back({from, to, ""});
            }
        }
    }
    
    return moves;
}

std::vector<Move> ChessModule::generateKnightMoves(int row, int col, bool white) const {
    std::vector<Move> moves;
    int dr[] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int dc[] = {-1, 1, -2, 2, -2, 2, -1, 1};
    int from = row * 8 + col;
    
    for (int i = 0; i < 8; ++i) {
        int nr = row + dr[i];
        int nc = col + dc[i];
        
        if (isValidSquare(nr, nc) && 
            (!isSquareOccupied(nr, nc) || isOccupiedByOpponent(nr, nc, white))) {
            moves.push_back({from, nr * 8 + nc, ""});
        }
    }
    
    return moves;
}

std::vector<Move> ChessModule::generateBishopMoves(int row, int col, bool white) const {
    std::vector<Move> moves;
    int dr[] = {-1, -1, 1, 1};
    int dc[] = {-1, 1, -1, 1};
    int from = row * 8 + col;
    
    for (int d = 0; d < 4; ++d) {
        for (int step = 1; step < 8; ++step) {
            int nr = row + dr[d] * step;
            int nc = col + dc[d] * step;
            
            if (!isValidSquare(nr, nc)) break;
            
            if (!isSquareOccupied(nr, nc)) {
                moves.push_back({from, nr * 8 + nc, ""});
            } else {
                if (isOccupiedByOpponent(nr, nc, white)) {
                    moves.push_back({from, nr * 8 + nc, ""});
                }
                break;
            }
        }
    }
    
    return moves;
}

std::vector<Move> ChessModule::generateRookMoves(int row, int col, bool white) const {
    std::vector<Move> moves;
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};
    int from = row * 8 + col;
    
    for (int d = 0; d < 4; ++d) {
        for (int step = 1; step < 8; ++step) {
            int nr = row + dr[d] * step;
            int nc = col + dc[d] * step;
            
            if (!isValidSquare(nr, nc)) break;
            
            if (!isSquareOccupied(nr, nc)) {
                moves.push_back({from, nr * 8 + nc, ""});
            } else {
                if (isOccupiedByOpponent(nr, nc, white)) {
                    moves.push_back({from, nr * 8 + nc, ""});
                }
                break;
            }
        }
    }
    
    return moves;
}

std::vector<Move> ChessModule::generateQueenMoves(int row, int col, bool white) const {
    auto rookMoves = generateRookMoves(row, col, white);
    auto bishopMoves = generateBishopMoves(row, col, white);
    
    rookMoves.insert(rookMoves.end(), bishopMoves.begin(), bishopMoves.end());
    return rookMoves;
}

std::vector<Move> ChessModule::generateKingMoves(int row, int col, bool white) const {
    std::vector<Move> moves;
    int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    int from = row * 8 + col;
    
    for (int i = 0; i < 8; ++i) {
        int nr = row + dr[i];
        int nc = col + dc[i];
        
        if (isValidSquare(nr, nc) && 
            (!isSquareOccupied(nr, nc) || isOccupiedByOpponent(nr, nc, white))) {
            moves.push_back({from, nr * 8 + nc, ""});
        }
    }
    
    return moves;
}

bool ChessModule::isValidSquare(int row, int col) const {
    return row >= 0 && row < 8 && col >= 0 && col < 8;
}

char ChessModule::getPieceAt(int row, int col) const {
    if (!isValidSquare(row, col)) return ' ';
    return board[row * 8 + col];
}

bool ChessModule::isSquareOccupied(int row, int col) const {
    return getPieceAt(row, col) != ' ';
}

bool ChessModule::isOccupiedByOpponent(int row, int col, bool white) const {
    char piece = getPieceAt(row, col);
    if (piece == ' ') return false;
    return white ? std::islower(piece) : std::isupper(piece);
}
