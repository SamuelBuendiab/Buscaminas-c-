#include<iostream>
#include <SFML/Graphics.hpp>
#include <time.h>
using namespace sf;
using namespace std;

int main (){
	
	

	srand(time(0));
		RenderWindow prog(VideoMode(1400, 400),"Buscaminas");
		
	int a = 32;
	int cuadricula[12][12];
	int cuadricula2[12][12];
	
	//texture loading
	Texture t;
	t.loadFromFile("imagenes/buscaminastextura.jpg");
	Sprite s(t);
	
	//make grid
	for(int l=1; l<=10; l++)
	    for(int h=1 ;h<=10; h++){
	    	
	    	cuadricula2[l][h] = 10;
	    	
	    	if(rand() % 5 == 0) cuadricula[l][h] = 9;
	    	else cuadricula [l][h] = 0;
	    	
		}
		// grid textures
		for(int l=1;l<=10;l++)
	    for(int h=1;h<=10;h++){
       	int n=0;
		
		if(cuadricula[l][h] == 9) continue;
		if(cuadricula [l+1][h] == 9) n++;
		if(cuadricula [l][h+1] == 9) n++;
		if(cuadricula [l-1][h] == 9) n++;
		if(cuadricula [l][h-1] == 9) n++;
		
		if(cuadricula [l+1][h+1] == 9) n++;
		if(cuadricula [l-1][h-1] == 9) n++;
		if(cuadricula [l-1][h+1] == 9) n++;
		if(cuadricula [l+1][h-1] == 9) n++;
		
		cuadricula[l][h] = n;
		
		}
	    
		//window oppen
	while(prog.isOpen()){
		// mouse detection (dosent work well
	    Vector2i algo = Mouse::getPosition(prog);
        int x = algo.x /a;
        int y = algo.y/a ;
		
		//close program and mous interactions
		Event b;
		while (prog.pollEvent(b)){
			
			if(b.type == Event::Closed)
			prog.close();
			
            if (b.type == Event::MouseButtonPressed)
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) cuadricula2[x][y] = cuadricula[x][y];
                else if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) cuadricula2[x][y] = 11;
		}
		
		//window color
		prog.clear(Color::Red);
			for(int l=1;l<=10;l++)
	           for(int h=1;h<=10;h++){
	           	
	           	// mines funcionality
	           if(cuadricula2[x][y] == 9 ) cuadricula2[l][h] = cuadricula[l][h];
	           	
	           	s.setTextureRect(IntRect(cuadricula2[l][h] * a, 0, a, a));
	           	s.setPosition(l * a, h * a);
	           	prog.draw(s);
	           	
	           	
			   }
		
		prog.display();
		
	

	
	
		
	}
	return 0;
}




