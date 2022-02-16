#include "Scene.h"
#include "CheckML.h"
#include <gtc/matrix_transform.hpp>  
#include <gtc/type_ptr.hpp>

using namespace glm;
//-------------------------------------------------------------------------

void Scene::init()
{ 
	setGL();  // OpenGL settings

	// allocate memory and load resources
    // Lights
    // Textures

    // Graphics objects (entities) of the scene
	gObjects.push_back(new EjesRGB(400.0));

	// PASOS 2 & 3
	//auto poligono = new Poligono(7, 100);
	//poligono->setColor(glm::dvec4(0, 1.0, 1.0, 1.0));
	//gObjects.push_back(poligono);

	// PASO 4
	//auto triangulo = new Poligono(3, 150);
	//auto circunferencia = new Poligono(32, 150);
	//triangulo->setColor(glm::dvec4(0, 1.0, 1.0, 1.0));
	//circunferencia->setColor(glm::dvec4(1.0, 0, 1.0, 1.0));
	//gObjects.push_back(triangulo);
	//gObjects.push_back(circunferencia);

	// PASO 5
	gObjects.push_back(new TrianglesRGB());


	// PASO 6ne
	//gObjects.push_back(new Cubo(100));


	//gObjects.push_back(new Mesh)
}
//-------------------------------------------------------------------------
void Scene::free() 
{ // release memory and resources   

	for (Abs_Entity* el : gObjects)
	{
		delete el;  el = nullptr;
	}
}
//-------------------------------------------------------------------------
void Scene::setGL() 
{
	// OpenGL basic setting
	glClearColor(0.6, 0.7, 0.8, 1.0);  // background color (alpha=1 -> opaque)
	glEnable(GL_DEPTH_TEST);  // enable Depth test 

}
//-------------------------------------------------------------------------
void Scene::resetGL() 
{
	glClearColor(.0, .0, .0, .0);  // background color (alpha=1 -> opaque)
	glDisable(GL_DEPTH_TEST);  // disable Depth test 	
}
//-------------------------------------------------------------------------

void Scene::render(Camera const& cam) const 
{
	cam.upload();

	for (Abs_Entity* el : gObjects)
	{
	  el->render(cam.viewMat());
	}
}
//-------------------------------------------------------------------------


