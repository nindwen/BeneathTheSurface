#ifndef _LIGHT
#define _LIGHT

class Light : public gameObject
{
	public:
		Light(int, int);
		
		virtual int update();

	protected:
		int power;
		int rpower;
};

#endif
