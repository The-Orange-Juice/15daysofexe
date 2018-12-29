#include<bits/stdc++.h>
#include<memory>
using namespace std;
class Maze{
	public:
  		void load(std::string&& mazeFilePath);
		void run();
	private:
  		using Grid = std::vector<std::string>;
  		enum class MoveDirection {
    		UP,
    		DOWN,
    		RIGHT,
    		LEFT
  		};
  		enum class MoveResult {
    		OK,
    		OUT_OF_BOUNDS,
    		COLLISION,
    		GOAL
  		};
  		struct Position {
    		int row;
    		int col;
  		};
  		void display() const;
  		MoveResult movePlayer(MoveDirection direction);
  		Grid m_grid;
  		Position m_playerPosition;
  		Position m_goalPosition;
};
bool checkfile(std::string &fileName){
    std::ifstream infile(fileName);
    return infile.good();
}
void Maze::load(std::string&& mazeFilePath) {
  	m_grid.clear();
  	if(!checkfile(mazeFilePath)){
  		cout<<"Please download data.in from discord.";
  		cin.ignore();
  		exit(0);
	}
  	std::cout<<"Welcome!\nToday, your job is to complete this maze!\nGet from the C to the E!\nDo remember to expand the window!";
  	cin.ignore();
  	std::ifstream mazeFileStream(mazeFilePath); //todo - readonly flag
  	int currentRow = 0;
  	for (std::string line; std::getline(mazeFileStream, line);) {
    	int currentCol = 0;
    	std::string row;
    	std::copy_if(std::begin(line), std::end(line), std::back_inserter(row), [&](decltype(row)::value_type c) {
      	switch (c) {
        	case 'C':
          		m_playerPosition.row = currentRow;
          		m_playerPosition.col = currentCol;
          		break;
    		case 'E':
          		m_goalPosition.row = currentRow;
          		m_goalPosition.col = currentCol;
          		break;
        	default:
          		break;
      		}
      		++currentCol;
      		return true;
    	});
    	m_grid.emplace_back(std::move(row));
    	++currentRow;
  		}
	}
	void Maze::display() const {
  		std::copy(std::begin(m_grid), std::end(m_grid), std::ostream_iterator<std::string>(std::cout, "\n"));
	}
	void Maze::run() {
  		bool running = true;
		char key;
		while (running) {
			system("CLS");
    		display();
			MoveResult moveResult;
			std::cout << "Please input W, A, S or D to move the player.\n";
			std::cin >> key;
			switch (key) {
      			case 'W':
        			moveResult = movePlayer(MoveDirection::UP);
        			break;
      			case 'w':
        			moveResult = movePlayer(MoveDirection::UP);
        			break;
      			case 'A':
        			moveResult = movePlayer(MoveDirection::LEFT);
        			break;
      			case 'a':
        			moveResult = movePlayer(MoveDirection::LEFT);
        			break;
      			case 'S':
        			moveResult = movePlayer(MoveDirection::DOWN);
        			break;
      			case 's':
        			moveResult = movePlayer(MoveDirection::DOWN);
        			break;
      			case 'D':
        			moveResult = movePlayer(MoveDirection::RIGHT);
      			case 'd':
        			moveResult = movePlayer(MoveDirection::RIGHT);
        			break;
      			default:
        			std::cerr << "Please use WASD keys to move player" << std::endl;
        			system("CLS");
        			break;
    		}
    		switch (moveResult) {
    			case MoveResult::OUT_OF_BOUNDS:
        			running = false;
        			std::cout << "Failure (Out of Bounds) - Game Over" << std::endl;
        			cin.ignore();
        			break;
      			case MoveResult::COLLISION:
        			running = false;
        			std::cout << "Failure (Collision Error) - Game Over" << std::endl;
        			cin.ignore();
        			break;
      			case MoveResult::GOAL:
        			running = false;
        			std::cout << "You won!.\nDay 3, Clue: 9 - What I like has this number of characters...."<< std::endl;
        			cin.ignore();
        			break;
      			default:
        			break;
    		}
  		}
	}
	Maze::MoveResult Maze::movePlayer(Maze::MoveDirection direction) {
	  	Position previousPlayerPosition = m_playerPosition;
	  	switch (direction) {
	    	case MoveDirection::UP:
	      		m_playerPosition.row -= 1;
	      		break;
	    	case MoveDirection::LEFT:
	      		m_playerPosition.col -= 1;
	      		break;
	    	case MoveDirection::DOWN:
	      		m_playerPosition.row += 1;
	      		break;
	    	case MoveDirection::RIGHT:
	      		m_playerPosition.col += 1;
	  	}
	  	try {
	    	m_grid.at(m_playerPosition.row).at(m_playerPosition.col);
	  	}
	  	catch (const std::out_of_range exc) {
	    	return MoveResult::OUT_OF_BOUNDS;
	  	}
	  	if (m_grid[m_playerPosition.row][m_playerPosition.col] == 'x') {
	    	return MoveResult::COLLISION;
	  	}
		else if (m_grid[m_playerPosition.row][m_playerPosition.col] == 'E') {
			return MoveResult::GOAL;
		}
		m_grid[previousPlayerPosition.row][previousPlayerPosition.col] = ' ';
		m_grid[m_playerPosition.row][m_playerPosition.col] = 'C';
		return MoveResult::OK;
}

int main(){
	auto maze = std::unique_ptr<Maze>(new Maze);
	maze->load("data.in");
	maze->run();
}
