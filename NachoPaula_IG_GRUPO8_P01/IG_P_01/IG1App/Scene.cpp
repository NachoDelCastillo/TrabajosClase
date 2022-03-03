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

	// ESCENA BIDIMENSIONAL
	if (mId == 0) {

		GLdouble radio = 250;

		auto triangleRGB = new TrianglesRGB(50.0, radio);
		triangleRGB->setModelMat(translate(triangleRGB->modelMat(), dvec3(radio, 0, 0)));
		gObjects.push_back(triangleRGB);

		gObjects.push_back(new RectanguloRGB(radio*2, radio));

		auto circunferencia = new Poligono(64, radio);
		circunferencia->setColor(glm::dvec4(1.0, 0, 1.0, 1.0));
		gObjects.push_back(circunferencia);
	}
	// ESCENA TRIDIMENSIONAL
	else if (mId == 1) {
		gObjects.push_back(new CuboRGB(100));
	}
}

//-------------------------------------------------------------------------

void Scene::setScene(int id)
{
	// Si no se cambia el valor, no hacer nada
	if (id == mId) return;

	free();
	gObjects.clear();
	mId = id;
	init();
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

void Scene::update()
{
	for (int i = 0; i < gObjects.size(); i++)
		gObjects[i]->update();
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


