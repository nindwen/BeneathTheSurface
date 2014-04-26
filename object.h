#ifndef _OBJECT
#define _OBJECT


class gameObject {

	public:
		gameObject();
		virtual ~gameObject();
		int getX() { return x; }
		int getY() { return y; }
		void setX(int x) { this->x=x; }
		void setY(int y) { this->y=y; }

		virtual int update();
		virtual int draw(SDL_Renderer *ren);
		int setTexture(SDL_Texture* tex);

	private:
		int x;
		int y;
		int w;
		int h;
		SDL_Texture* txt;


};

#endif 
