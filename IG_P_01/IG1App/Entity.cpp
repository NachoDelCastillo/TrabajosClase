#include "Entity.h"

#include <gtc/matrix_transform.hpp>  
#include <gtc/type_ptr.hpp>

using namespace glm;

//-------------------------------------------------------------------------

void Abs_Entity::upload(dmat4 const& modelViewMat) const 
{ 
	glMatrixMode(GL_MODELVIEW);
	glLoadMatrixd(value_ptr(modelViewMat));  // transfers modelView matrix to the GPU
}
//-------------------------------------------------------------------------
//-------------------------------------------------------------------------

EjesRGB::EjesRGB(GLdouble l): Abs_Entity()
{
  mMesh = Mesh::createRGBAxes(l);
}
//-------------------------------------------------------------------------

EjesRGB::~EjesRGB() 
{ 
	delete mMesh; mMesh = nullptr; 
};
//-------------------------------------------------------------------------

void EjesRGB::render(dmat4 const& modelViewMat) const 
{
	if (mMesh != nullptr) {
		dmat4 aMat = modelViewMat * mModelMat;  // glm matrix multiplication
		upload(aMat);
		glLineWidth(2);
		mMesh->render();
		glLineWidth(1);
	}
}


// POLIGONO


Poligono::Poligono(GLuint num, GLdouble r) : Abs_Entity()
{
	mMesh = Mesh::generaPoligonoRegular(num, r);
}

Poligono::~Poligono()
{
	delete mMesh; mMesh = nullptr;
};
//-------------------------------------------------------------------------

void Poligono::render(dmat4 const& modelViewMat) const
{
	if (mMesh != nullptr) {
		dmat4 aMat = modelViewMat * mModelMat;  // glm matrix multiplication

		dvec4 currentColor = getColor();

		upload(aMat);
		glColor3d(mColor.r, mColor.g, mColor.b);
		glLineWidth(2);
		mMesh->render();
		glLineWidth(1);

		glColor3d(currentColor.r, currentColor.g, currentColor.b);
	}
}

//-------------------------------------------------------------------------

// TRIANGULO RGB

TrianglesRGB::TrianglesRGB() : Abs_Entity()
{
	mMesh = Mesh::createTriangleRGB();

	mModelMat = translate(mModelMat, dvec3(0, 250, 0));
}

TrianglesRGB::~TrianglesRGB()
{
	delete mMesh; mMesh = nullptr;
};

void TrianglesRGB::render(dmat4 const& modelViewMat) const
{
	if (mMesh != nullptr) {

		glPolygonMode(GL_BACK, GL_POINT);

		dmat4 aMat = modelViewMat * mModelMat;  // glm matrix multiplication
		upload(aMat);
		mMesh->render();

		glPolygonMode(GL_BACK, GL_FILL);
	}
}

void TrianglesRGB::update() {
	mModelMat = rotate(mModelMat, radians(2.0), dvec3(0, 0, 1));

	//mModelMat = rotate(mModelMat, radians(2.0), dvec3(0, 0, 1));
}

//-------------------------------------------------------------------------

// RECTANGULO RGB

RectanguloRGB::RectanguloRGB(GLdouble w, GLdouble h) : Abs_Entity()
{
	mMesh = Mesh::generaRectanguloRGB(w, h);
}

RectanguloRGB::~RectanguloRGB()
{
	delete mMesh; mMesh = nullptr;
};

void RectanguloRGB::render(dmat4 const& modelViewMat) const
{
	if (mMesh != nullptr) {

		glPolygonMode(GL_FRONT, GL_LINE);
		glPolygonMode(GL_BACK, GL_LINE);

		dmat4 aMat = modelViewMat * mModelMat;  // glm matrix multiplication
		upload(aMat);
		mMesh->render();

		glPolygonMode(GL_FRONT, GL_FILL);
		glPolygonMode(GL_BACK, GL_FILL);
	}
}

//-------------------------------------------------------------------------

// CUBO

Cubo::Cubo(GLdouble l) : Abs_Entity()
{
	//mMesh = Mesh::generaCubo(l);

	mMesh = Mesh::generaCuboTriangulosRGB(l);
}

Cubo::~Cubo()
{
	delete mMesh; mMesh = nullptr;
};

void Cubo::render(dmat4 const& modelViewMat) const
{
	if (mMesh != nullptr) {
		dmat4 aMat = modelViewMat * mModelMat;  // glm matrix multiplication
		upload(aMat);
		mMesh->render();
	}
}

void Cubo::update() {
	mModelMat = rotate(mModelMat, radians(2.0), dvec3(0, 0, 1));
}