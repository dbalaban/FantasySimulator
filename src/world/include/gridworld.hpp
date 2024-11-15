#ifndef GRIDWORLD_HPP
#define GRIDWORLD_HPP

#include <vector>
#include <unordered_map>
#include <random>

#include "element.hpp"
#include "tile.hpp"

typedef std::pair<size_t, size_t> Coord2D;

class GridWorld : public Element<GridWorld> {
public:
  static const size_t ElementID = 0;

  GridWorld(size_t width, size_t height,
            std::vector<ResourceManager> tile_prototypes,
            std::vector<double> weights,
            size_t randomSeed = 0);

  ~GridWorld();

  Tile* getTile(Coord2D coord);

  Tile* getTile(size_t tileID);

  const int getWidth() const;

  const int getHeight() const;

  const size_t getTileID(Coord2D coord) const;

  const Coord2D getTileCoord(size_t tileID) const;

  const size_t getTileCount() const;

  void GenerateTileMap();

  void update(double elapsedTime) override;

private:
  size_t width;
  size_t height;
  std::vector<std::vector<Tile*>> tiles;
  std::unordered_map<size_t, Coord2D> tileMap;

  size_t tileCount;
  std::vector<ResourceManager> tile_prototypes;
  std::vector<double> weights;

  const size_t randomSeed;
};

#endif // GRIDWORLD_HPP