#include <vector>
#include "type.hpp"

struct Uis{
	int size;
	std::vector<TypeEnum> types;
	std::vector<float> x, y;
	std::vector<float> height, width;
	std::vector<float> paddingUp;
	std::vector<float> paddingRight;
	std::vector<float> paddingLeft;
	std::vector<float> paddingDown;
	std::vector<float> spaceBetween;
};

struct ComputedUi{
	std::vector<float> topLeftX, topLeftY;
	std::vector<float> topRightX, topRightY;
	std::vector<float> bottomLeftX, bottomLeftY;
	std::vector<float> bottomRightX, bottomRightY;
};



