import QtQuick 2.15
import QtQuick.Controls 2.15

Rectangle {
    id: chessBoard
    width: 400
    height: 400
    color: "#f0d9b5" // Light wood color
    
    // Chess board properties
    property var board: [
        "r", "n", "b", "q", "k", "b", "n", "r",
        "p", "p", "p", "p", "p", "p", "p", "p",
        " ", " ", " ", " ", " ", " ", " ", " ",
        " ", " ", " ", " ", " ", " ", " ", " ",
        " ", " ", " ", " ", " ", " ", " ", " ",
        " ", " ", " ", " ", " ", " ", " ", " ",
        "P", "P", "P", "P", "P", "P", "P", "P",
        "R", "N", "B", "Q", "K", "B", "N", "R"
    ]
    
    property int selectedSquare: -1
    property string currentPlayer: "white"
    property var validMoves: []
    
    // Unicode chess pieces
    function getPieceSymbol(piece) {
        var symbols = {
            'k': '♔', 'q': '♕', 'r': '♖', 'b': '♗', 'n': '♘', 'p': '♙',
            'K': '♚', 'Q': '♛', 'R': '♜', 'B': '♝', 'N': '♞', 'P': '♟'
        }
        return symbols[piece] || ""
    }
    
    // Calculate square color
    function isLightSquare(row, col) {
        return (row + col) % 2 === 0
    }
    
    // Handle square click
    function handleSquareClick(squareIndex) {
        var row = Math.floor(squareIndex / 8)
        var col = squareIndex % 8
        
        if (selectedSquare === -1) {
            // Select a piece
            var piece = board[squareIndex]
            if (piece !== " ") {
                selectedSquare = squareIndex
                validMoves = getValidMoves(squareIndex)  // This would come from the C++ backend
                
                // For demo purposes, show some valid moves
                // In a real implementation, this would be calculated by the chess engine
                validMoves = []
                if (piece.toLowerCase() === 'p' && currentPlayer === 'white') {
                    // Pawn moves forward
                    if (row > 0 && board[(row-1)*8 + col] === " ") {
                        validMoves.push((row-1)*8 + col)
                        // Double move from starting position
                        if (row === 6 && board[(row-2)*8 + col] === " ") {
                            validMoves.push((row-2)*8 + col)
                        }
                    }
                    // Pawn captures
                    if (row > 0 && col > 0 && board[(row-1)*8 + (col-1)].toLowerCase() !== board[(row-1)*8 + (col-1)] && board[(row-1)*8 + (col-1)] !== " ") {
                        validMoves.push((row-1)*8 + (col-1))
                    }
                    if (row > 0 && col < 7 && board[(row-1)*8 + (col+1)].toLowerCase() !== board[(row-1)*8 + (col+1)] && board[(row-1)*8 + (col+1)] !== " ") {
                        validMoves.push((row-1)*8 + (col+1))
                    }
                }
                
                chessBoard.update()
            }
        } else {
            // Try to move to the clicked square
            if (validMoves.indexOf(squareIndex) !== -1) {
                // Make the move
                board[squareIndex] = board[selectedSquare]
                board[selectedSquare] = " "
                
                // Switch player
                currentPlayer = currentPlayer === "white" ? "black" : "white"
                
                // Reset selection
                selectedSquare = -1
                validMoves = []
                
                chessBoard.update()
                
                // This would trigger the C++ backend to process the move
                // In a real implementation, we'd call a method on the chess module
            } else {
                // Deselect if clicking on the same piece or empty square
                if (selectedSquare === squareIndex || board[squareIndex] === " ") {
                    selectedSquare = -1
                    validMoves = []
                    chessBoard.update()
                } else {
                    // Select a different piece
                    selectedSquare = squareIndex
                    validMoves = []  // Simplified - would get from backend
                    
                    // For demo, show pawn moves again
                    var piece = board[squareIndex]
                    if (piece.toLowerCase() === 'p' && currentPlayer === 'white') {
                        if (row > 0 && board[(row-1)*8 + col] === " ") {
                            validMoves.push((row-1)*8 + col)
                            if (row === 6 && board[(row-2)*8 + col] === " ") {
                                validMoves.push((row-2)*8 + col)
                            }
                        }
                        if (row > 0 && col > 0 && board[(row-1)*8 + (col-1)].toLowerCase() !== board[(row-1)*8 + (col-1)] && board[(row-1)*8 + (col-1)] !== " ") {
                            validMoves.push((row-1)*8 + (col-1))
                        }
                        if (row > 0 && col < 7 && board[(row-1)*8 + (col+1)].toLowerCase() !== board[(row-1)*8 + (col+1)] && board[(row-1)*8 + (col+1)] !== " ") {
                            validMoves.push((row-1)*8 + (col+1))
                        }
                    }
                    
                    chessBoard.update()
                }
            }
        }
    }
    
    // Draw the chess board
    Grid {
        rows: 8
        columns: 8
        anchors.fill: parent
        
        Repeater {
            model: 64
            
            Rectangle {
                id: square
                width: chessBoard.width / 8
                height: chessBoard.height / 8
                
                // Alternate colors
                color: chessBoard.isLightSquare(Math.floor(index / 8), index % 8) ? "#f0d9b5" : "#b58863"
                
                // Highlight selected square
                border.color: (index === chessBoard.selectedSquare) ? "yellow" : "transparent"
                border.width: 2
                
                // Highlight valid moves
                Rectangle {
                    anchors.centerIn: parent
                    width: parent.width / 2
                    height: parent.height / 2
                    radius: width / 2
                    color: chessBoard.validMoves.indexOf(index) !== -1 ? "#8f76a3" : "transparent"  // Purple highlight for valid moves
                }
                
                // Draw piece
                Text {
                    anchors.centerIn: parent
                    text: chessBoard.getPieceSymbol(chessBoard.board[index])
                    font.pixelSize: square.width * 0.8
                    color: "black"
                }
                
                // Handle click
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        chessBoard.handleSquareClick(index)
                    }
                }
            }
        }
    }
    
    // Current player indicator
    Text {
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottomMargin: 10
        text: "Current Player: " + chessBoard.currentPlayer
        font.pixelSize: 16
        color: "#333"
    }
}