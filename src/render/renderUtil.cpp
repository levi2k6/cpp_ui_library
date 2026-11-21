#include "renderUtil.hpp"


void renderCircle(SDL_Renderer* renderer, float centerX, float centerY, float radius)
{
	if (renderer == nullptr || radius < 0.0f) {
		return;
	}

	int cx = static_cast<int>(centerX);
	int cy = static_cast<int>(centerY);
	int r = static_cast<int>(radius + 0.5f);

	int x = r;
	int y = 0;
	int error = 1 - r;

	while (x >= y) {
		SDL_RenderPoint(renderer, cx + x, cy + y);
		SDL_RenderPoint(renderer, cx + y, cy + x);
		SDL_RenderPoint(renderer, cx - y, cy + x);
		SDL_RenderPoint(renderer, cx - x, cy + y);
		SDL_RenderPoint(renderer, cx - x, cy - y);
		SDL_RenderPoint(renderer, cx - y, cy - x);
		SDL_RenderPoint(renderer, cx + y, cy - x);
		SDL_RenderPoint(renderer, cx + x, cy - y);

		++y;
		if (error < 0) {
			error += 2 * y + 1;
		} else {
			--x;
			error += 2 * (y - x) + 1;
		}
	}
}
