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

TrianglesRGB::TrianglesRGB(GLdouble r) : Abs_Entity()
{
	mMesh = Mesh::createTriangleRGB(r);

	// Decirle al triangulo a que distancia rotar del centro
	//circleRadius = _circleRadius;
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

	// Rotar a lo largo del circulo (antihorario)
	globalRotateAngle -= globalRotateSpeed;
	mModelMat = translate(dmat4(1.0), dvec3(cos(radians(globalRotateAngle)) * circleRadius, sin(radians(globalRotateAngle)) * circleRadius, 0));

	// Rotar el triangulo (horario)
	rotateAngle -= rotateSpeed;
	mModelMat = rotate(mModelMat, radians(rotateAngle), dvec3(0, 0, 1));
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

		dmat4 aMat = modelViewMat * mModelMat;  // glm matrix multiplication
		upload(aMat);
		mMesh->render();

		glPolygonMode(GL_FRONT, GL_FILL);
	}
}

//-------------------------------------------------------------------------

// CUBO

Cubo::Cubo(GLdouble l) : Abs_Entity()
{
	//mMesh = Mesh::generaCuboTriangulosRGB(l);
	mMesh = Mesh::generaCubo(l);

	//mMesh = Mesh::generaCuboTriangulosRGBparteOpcional(l);
	//mModelMat = translate(mModelMat, dvec3(l/2, l/2, l/2));
}

Cubo::~Cubo()
{
	delete mMesh; mMesh = nullptr;
}

void Cubo::render(dmat4 const& modelViewMat) const
{
	if (mMesh != nullptr) {

		glPolygonMode(GL_FRONT, GL_LINE);
		glPolygonMode(GL_BACK, GL_POINT);

		glColor3d(0.0, 0.0, 0.0); // Pasa al color negro

		dmat4 aMat = modelViewMat * mModelMat;  // glm matrix multiplication
		upload(aMat);
		mMesh->render();

		glPolygonMode(GL_FRONT, GL_FILL);
		glPolygonMode(GL_BACK, GL_FILL);

		glColor3d(1.0, 1.0, 1.0); // Vuelve al color blanco
	}
}

void Cubo::update() {

	//mModelMat = rotate(mModelMat, radians(2.0), dvec3(0, 0, 1));
	mModelMat = rotate(dmat4(1.0), radians(90.0), dvec3(0, 0, 1));
}


//-------------------------------------------------------------------------

// CUBO

CuboRGB::CuboRGB(GLdouble l) : Abs_Entity()
{
	//mMesh = Mesh::generaCuboTriangulosRGB(l);
	mMesh = Mesh::generaCuboTriangulosRGB(l);

	//mMesh = Mesh::generaCuboTriangulosRGBparteOpcional(l);
	//mModelMat = translate(mModelMat, dvec3(l/2, l/2, l/2));
}

CuboRGB::~CuboRGB()
{
	delete mMesh; mMesh = nullptr;
}

void CuboRGB::render(dmat4 const& modelViewMat) const
{
	if (mMesh != nullptr) {

		dmat4 aMat = modelViewMat * mModelMat;  // glm matrix multiplication
		upload(aMat);
		mMesh->render();
	}
}

void CuboRGB::update() {

	//mModelMat = rotate(mModelMat, radians(2.0), dvec3(0, 0, 1));
	mModelMat = rotate(dmat4(1.0), radians(90.0), dvec3(0, 0, 1));
}