//#pragma once
#ifndef _H_Entities_H_
#define _H_Entities_H_

#include <GL/freeglut.h>
#include <glm.hpp>

#include "Mesh.h"

//-------------------------------------------------------------------------

class Abs_Entity  // abstract class
{
public:
	Abs_Entity(): mModelMat(1.0),mColor(1) {};  // 4x4 identity matrix
	virtual ~Abs_Entity() {};

	Abs_Entity(const Abs_Entity& e) = delete;  // no copy constructor
	Abs_Entity& operator=(const Abs_Entity& e) = delete;  // no copy assignment

	virtual void render(glm::dmat4 const& modelViewMat) const = 0;  // abstract method


	// Color
	glm::dvec4 const& getColor() const { return mColor; }
	void setColor(glm::dvec4 const& newColor) { mColor = newColor; }



	// modeling matrix
	glm::dmat4 const& modelMat() const { return mModelMat; };
	void setModelMat(glm::dmat4 const& aMat) { mModelMat = aMat; };

	virtual void update() {};
	
protected:

	Mesh* mMesh = nullptr;   // the mesh
	glm::dmat4 mModelMat;    // modeling matrix

	glm::dvec4 mColor;
	
	// transfers modelViewMat to the GPU
	virtual void upload(glm::dmat4 const& mModelViewMat) const; 
};

//-------------------------------------------------------------------------

class EjesRGB : public Abs_Entity 
{
public:
	explicit EjesRGB(GLdouble l);
	~EjesRGB();
	virtual void render(glm::dmat4 const& modelViewMat) const;
};

//-------------------------------------------------------------------------

// POLIGONOS

class Poligono : public Abs_Entity
{
public:
	explicit Poligono(GLuint lados, GLdouble r);
	~Poligono();
	virtual void render(glm::dmat4 const& modelViewMat) const;
};

//-------------------------------------------------------------------------

// ENTIDAD PARA LOS TRIANGULOS

class TrianglesRGB : public Abs_Entity
{
	double circleRadius = 250;

	// Angulo del triangulo respecto a la circunferencia
	double globalRotateAngle = 0;
	// Velocidad a la que gira el triangulo respecto a la circunferencia
	double globalRotateSpeed = -2;

	// Angulo del triangulo
	double rotateAngle = 0;
	// Velocidad a la que gira el triangulo sobre si mismo
	double rotateSpeed = 5;

public:
	explicit TrianglesRGB(GLdouble r);
	~TrianglesRGB();
	virtual void render(glm::dmat4 const& modelViewMat) const;

	virtual void update() override;
};

//-------------------------------------------------------------------------

// RECTANGLE RGB
class RectanguloRGB : public Abs_Entity
{
public:
	explicit RectanguloRGB(GLdouble w, GLdouble h);
	~RectanguloRGB();
	virtual void render(glm::dmat4 const& modelViewMat) const;
};

//-------------------------------------------------------------------------

// CUBO
class Cubo : public Abs_Entity
{
	//enum rotAxis {xAxis, yAxis, zAxis};

	//rotAxis currentAxis = xAxis;

	//double xAxis, yAxis, zAxis;

public:
	explicit Cubo(GLdouble l);
	~Cubo();
	virtual void render(glm::dmat4 const& modelViewMat) const;
	
	virtual void update() override;
};

//-------------------------------------------------------------------------

// CUBO
class CuboRGB : public Abs_Entity
{
	//enum rotAxis {xAxis, yAxis, zAxis};

	//rotAxis currentAxis = xAxis;

	//double xAxis, yAxis, zAxis;

public:
	explicit CuboRGB(GLdouble l);
	~CuboRGB();
	virtual void render(glm::dmat4 const& modelViewMat) const;

	virtual void update() override;
};

#endif //_H_Entities_H_