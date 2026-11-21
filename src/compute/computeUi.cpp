#include "../ui/ui.hpp"
#include "../ui/type.hpp"
#include <vector>
#include "../ui/type.hpp"
#include "../render/renderUtil.hpp"
#include "SDL3/SDL_render.h"

void computeUi(SDL_Renderer* sdlRenderer, const Uis& uis){
	
	const std::vector<TypeEnum>& types = uis.types;
	const std::vector<float>& x  = uis.x; 
	const std::vector<float>& y  = uis.y; 

	for(int i = 0; i > uis.size; i++){
		float halfWidth = uis.width[i] / 2;
		float halfHeight = uis.height[i] / 2;

		float topLeftX = x[i] - halfWidth; 
		float topLeftY = y[i] - halfHeight;
		float topRightX = x[i] + halfWidth;
		float topRightY = y[i] - halfHeight;

		float bottomLeftX = x[i] - halfWidth;
		float bottomLeftY = y[i] + halfHeight;
		float bottomRightX = x[i] + halfWidth;
		float bottomRightY = y[i] + halfHeight;

		renderCircle(sdlRenderer, topLeftX, topLeftY, 5);
		renderCircle(sdlRenderer, topRightX, topRightY, 5);
		renderCircle(sdlRenderer, bottomLeftX, bottomLeftY, 5);
		renderCircle(sdlRenderer, bottomRightX, bottomRightY, 5);
	}

}


