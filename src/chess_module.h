#pragma once

#include <string>
#include <vector>

struct Move {
    int from;
    int to;
    std::string promotion; // for pawn promotion
};

struct GameState {
    std::string fen;
    bool isCheck;
    bool isCheckmate;
    bool isStalemate;
    std::string currentPlayer;
};

class ChessModule {
public:
    ChessModule();
    
    // Game initialization
    void newGame();
    void loadPosition(const std::string& fen);
    
    // Move handling
    bool makeMove(const Move& move);
    bool isValidMove(const Move& move) const;
    std::vector<Move> getValidMoves(int square) const;
    
    // Game state
    GameState getState() const;
    std::string getCurrentFEN() const;
    
    // Helper methods
    bool isInCheck(bool white) const;
    bool isSquareAttacked(int square, bool white) const;
    
private:
    std::string boardFEN;
    std::vector<char> board; // 64 squares, row-major order
    bool whiteToMove;
    
    // Private helper methods
    std::vector<Move> generateAllValidMoves(bool white) const;
    std::vector<Move> generatePawnMoves(int row, int col, bool white) const;
    std::vector<Move> generateKnightMoves(int row, int col, bool white) const;
    std::vector<Move> generateBishopMoves(int row, int col, bool white) const;
    std::vector<Move> generateRookMoves(int row, int col, bool white) const;
    std::vector<Move> generateQueenMoves(int row, int col, bool white) const;
    std::vector<Move> generateKingMoves(int row, int col, bool white) const;
    
    // Move validation helpers
    bool isValidSquare(int row, int col) const;
    char getPieceAt(int row, int col) const;
    bool isSquareOccupied(int row, int col) const;
    bool isOccupiedByOpponent(int row, int col, bool white) const;
    bool wouldBeInCheckAfterMove(const Move& move, bool white) const;
    bool canSlideAttack(int fromRow, int fromCol, int toRow, int toCol, char piece) const;
    
    // FEN parsing and generation
    void parseFEN(const std::string& fen);
    std::string generateFEN() const;
};
