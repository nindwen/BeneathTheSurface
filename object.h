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
		void setTexture(int i) { texIndex=i; }

	protected:
		int moving;
		int speed;
		int dx;
		int dy;
		int x;
		int y;
		int w;
		int h;
		int texIndex;

};

#endif 
