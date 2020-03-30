#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

struct Square {
    unsigned size{0};
    unsigned min{0};
    unsigned max{0};

    std::string toString() const {
        return "size: " + std::to_string(this->size) + ", min: " + std::to_string(this->min) +
               ", max " + std::to_string(this->max);
    }
};

Square createSquare(unsigned n) {
    Square square{};

    square.size = 2 * n + 1;
    square.max = square.size * square.size;
    if (n != 0)
        square.min = (square.size - 2) * (square.size - 2) + 1;
    else
        square.min = square.max;

    return square;
}

Square findValueSquare(unsigned value) {
    unsigned i{1};
    while (true) {
        if (value <= i * i) {
            return createSquare((i - 1) / 2);
        } else {
            i += 2;
        }
    }
}

std::pair<unsigned, unsigned> findPosition(unsigned value, const Square& square) {
    auto rightBottom = square.max;
    auto leftBottom = rightBottom - square.size + 1;
    auto leftUpper = leftBottom - square.size + 1;
    auto rightUpper = leftUpper - square.size + 1;

    unsigned x{1};
    unsigned y{1};

    if (value >= leftBottom && value <= rightBottom) {  // bottom
        x = square.size - (rightBottom - value);
    } else if (value >= leftUpper && value <= leftBottom) {  // left
        y = square.size - (leftBottom - value);
    } else if (value >= rightUpper && value <= leftUpper) {  // upper
        y = square.size;
        x = (leftUpper - value) + 1;
    } else {  // right
        x = square.size;
        y = square.size - (rightUpper - value);
    }

    return std::make_pair(x, y);
}

unsigned getDistance(unsigned value) {
    auto square = findValueSquare(value);
    auto squareSize = square.size;
    auto position = findPosition(value, square);

    unsigned result{0};
    unsigned middle = squareSize / 2 + 1;

    result += position.first > middle ? position.first - middle : middle - position.first;
    result += position.second > middle ? position.second - middle : middle - position.second;

    return result;
}

struct Point {
    int x{0};
    int y{0};

    bool operator<(const Point& p) const {
        if (this->x != p.x) {
            return p.x > this->x;
        } else {
            return p.y > this->y;
        }
    }

    std::string toString() const {
        return "[" + std::to_string(this->x) + ", " + std::to_string(this->y) + "]";
    }
};

enum class Direction { UPPER, LEFT, DOWN, RIGHT };

Point getNexPoint(const Point& p, Direction direction) {
    switch (direction) {
        case Direction::UPPER:
            return Point{p.x, p.y + 1};
        case Direction::LEFT:
            return Point{p.x - 1, p.y};
        case Direction::DOWN:
            return Point{p.x, p.y - 1};
        case Direction::RIGHT:
            return Point{p.x + 1, p.y};
    }
}

Direction getNextDirection(Direction direction) {
    switch (direction) {
        case Direction::UPPER:
            return Direction::LEFT;
        case Direction::LEFT:
            return Direction::DOWN;
        case Direction::DOWN:
            return Direction::RIGHT;
        case Direction::RIGHT:
            return Direction::UPPER;
    }
}

unsigned getValueForPoint(const std::map<Point, unsigned>& grid, const Point& sourcePoint) {
    Point upperPoint{sourcePoint.x, sourcePoint.y + 1};
    Point upperLeftPoint{sourcePoint.x - 1, sourcePoint.y + 1};
    Point upperRightPoint{sourcePoint.x + 1, sourcePoint.y + 1};
    Point leftPoint{sourcePoint.x - 1, sourcePoint.y};
    Point leftBottomPoint{sourcePoint.x - 1, sourcePoint.y - 1};
    Point bottomPoint{sourcePoint.x, sourcePoint.y - 1};
    Point bottomRightPoint{sourcePoint.x + 1, sourcePoint.y - 1};
    Point rightPoint{sourcePoint.x + 1, sourcePoint.y};

    std::vector<Point> points{upperPoint,      upperLeftPoint, upperRightPoint,  leftPoint,
                              leftBottomPoint, bottomPoint,    bottomRightPoint, rightPoint};

    unsigned value{0};
    for (const auto& p : points) {
        if (grid.count(p) > 0) value += grid.at(p);
    }

    return value;
}

unsigned getSquareSize(unsigned n) { return 2 * n + 1; }

unsigned generateGrid(unsigned borderValue) {
    std::map<Point, unsigned> grid;

    grid[Point{0, 0}] = 1;

    Direction currentDirection{Direction::UPPER};
    Point currentPoint{1, 0};
    unsigned currentSquareIndex{1};
    unsigned steps{0};
    unsigned maxSteps{getSquareSize(currentSquareIndex - 1) + 1};

    while (true) {
        auto value = getValueForPoint(grid, currentPoint);
        if (value > borderValue) {
            return value;
        }

        grid[currentPoint] = value;
        steps++;

        if (steps == maxSteps) {
            if (currentDirection == Direction::RIGHT) {
                currentSquareIndex++;
                currentPoint = getNexPoint(currentPoint, currentDirection);
                currentDirection = getNextDirection(currentDirection);
                maxSteps = getSquareSize(currentSquareIndex - 1) + 1;
            } else {
                currentDirection = getNextDirection(currentDirection);
                currentPoint = getNexPoint(currentPoint, currentDirection);
            }

            steps = 0;
        } else {
            currentPoint = getNexPoint(currentPoint, currentDirection);
        }
    }
}

int main() {
    std::cout << "PART1: " << getDistance(368078) << std::endl;
    std::cout << "PART2: " << generateGrid(368078) << std::endl;
    return 0;
}
