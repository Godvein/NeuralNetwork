#include "game.h"
#include <iostream>	
	
void Game::initialize(){

//load font
if(!font.loadFromFile("Fonts/Arial.ttf")){
std::cout << "error loading font";
}
else{
std::cout << "font loaded";
}
}

//players turn
void Game::updatePlayer(bool& player_turn, sf::Vector2i position, char player){
for(int i=0; i<3; i++){
for(int j=0; j<3; j++){

float left = section_size * j + gap;
float right = left + section_size;
float top = section_size * i + gap;
float bottom = top + section_size;

//check if mouse position is in the section
if(position.x >= left && position.x <= right && position.y >= top && position.y <= bottom){
if(board[i][j] != "O" && board[i][j] != "X"){
board[i][j] = player;
player_turn = false;
}
}
}
}
}

//bots turn
void Game::updateBot(bool& player_turn, char bot){
std::srand(std::time(0));
int randomx = std::rand() % 3;	
int randomy = std::rand() % 3;	
if(board[randomx][randomy] != "X" && board[randomx][randomy] != "O" ){
board[randomx][randomy] = bot;
player_turn = true;
}
}

//function to check winner
std::string Game::checkWinner(){
for(int i=0; i<3; i++){
for(int j=0; j<3; j++){

//check horizontal
if(board[i][0] == board[i][1] && board[i][1] == board[i][2])
return board[i][0];

//check vertical
if(board[0][j] == board[1][j] && board[1][j] == board[2][j])
return board[0][j];

//check left diagonal
if(board[0][0] == board[1][1] && board[1][1] == board[2][2])
return board[0][0];

//check right diagonal
if(board[0][2] == board[1][1] && board[1][1] == board[2][0])
return board[0][2];
}
}

return "n";
}


//function to draw the game
void Game::draw(sf::RenderWindow& window){
for(int i=0; i<3; i++){
for(int j=0; j<3; j++){

//draw the board sections in White
sf::RectangleShape section(sf::Vector2f(section_size, section_size));
section.setPosition(section_size * j + gap , section_size * i + gap);

//section design
section.setOutlineThickness(2);
section.setOutlineColor(sf::Color::Black);
section.setFillColor(sf::Color::White); 

window.draw(section);

//draw the texts on the sections in black
if(board[i][j] != ""){
sf::Text text;
text.setFont(font);
text.setString(board[i][j]);
text.setCharacterSize(40);   
text.setFillColor(sf::Color::Black);
                
  
sf::FloatRect textBounds = text.getLocalBounds();
text.setOrigin(textBounds.width / 2, textBounds.height / 2);
text.setPosition(section.getPosition().x + section_size / 2, section.getPosition().y + section_size / 2);
window.draw(text);

}
}
}

}
