# MiniMax_XO
XO with smart computer player - the computer either wins or it's a draw!

When implementing XO with a computer player, we can either make the computer choose random moves or we can use an algorithm to make the computer player "smart". Therefore, I used [minimax algorithm](https://www.geeksforgeeks.org/minimax-algorithm-in-game-theory-set-1-introduction/) in the ComputerPlayer class. 

Briefly, ComputerPlayer uses minimax that is based on backtracking (checking all possible moves for the current state of the board) to play the move that leads to a win for the computer or, if not possible, a draw. 

### It contains the following classes:
* XO_Board 
  * Represents a 3 x 3 board used in X_O game
* XO_GameManager 
  * Manages the game: which player to play and against the computer or your friend
* XO_Player 
  * Represents a player who has a name and a symbol to put on board
* ComputerPlayer 
  * Plays a move in the best position based on the current state of the board


Language Used: C++
* I implemented ComputerPlayer class. 
* The other classes are implemented by Dr.Mohamed El-Ramly.
### 
