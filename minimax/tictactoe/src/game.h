#pragma once
#include <SFML/Graphics.hpp>
#include <string>
class Game{

private:
float section_size = 64.f;
float gap = 10.f;
sf::Font font;

public:
std::string board[3][3] = {
{ "", "", ""},
{ "", "", ""},
{ "", "", ""}
};
public:

void initialize();
void updatePlayer(bool& player_turn, sf::Vector2i position, char player);
void updateBot(bool& player_turn, char bot);
std::string checkWinner();
void draw(sf::RenderWindow& window);

};
