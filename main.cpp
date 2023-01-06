#include <iostream>
#include <random>
#include <map>




// static board size
const int NUM_TILES = 19;

// Structure to represent a tile on the Catan board
struct Tile {
    std::string resource;
    int number{};    // Number on the tile (used for resource production)
};

// Function to generate a random tile
Tile generateTile() {

    Tile tile;

    // Generate a random resource
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 5);  // 5 different resources
    tile.resource = std::to_string(dist(gen));

    // Generate a random number, excluding 7
    std::uniform_int_distribution<> numDist(2, 6);  // Numbers 2-6
    tile.number = numDist(gen);
    if (tile.number >= 7) {
        tile.number++;
    }

    return tile;
}




int main() {
    Tile board[NUM_TILES];

    // Generate the tiles for the board
    for (auto & i : board) {
        i = generateTile();
    }



    // Print the tiles
    for (int i = 0; i < NUM_TILES; i++) {

        std::cout << "Tile " << i << ": resource=" << board[i].resource
                  << ", number=" << board[i].number << std::endl;

    }
    return 0;
}