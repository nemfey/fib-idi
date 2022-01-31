#include "MyGLWidget.h"
#include <iostream>
#include <stdio.h>

#define printOpenGLError() printOglError(__FILE__, __LINE__)
#define CHECK() printOglError(__FILE__, __LINE__,__FUNCTION__)
#define DEBUG() std::cout << __FILE__ << " " << __LINE__ << " " << __FUNCTION__ << std::endl;

int MyGLWidget::printOglError(const char file[], int line, const char func[]) 
{
    GLenum glErr;
    int    retCode = 0;

    glErr = glGetError();
    const char * error = 0;
    switch (glErr)
    {
        case 0x0500:
            error = "GL_INVALID_ENUM";
            break;
        case 0x501:
            error = "GL_INVALID_VALUE";
            break;
        case 0x502: 
            error = "GL_INVALID_OPERATION";
            break;
        case 0x503:
            error = "GL_STACK_OVERFLOW";
            break;
        case 0x504:
            error = "GL_STACK_UNDERFLOW";
            break;
        case 0x505:
            error = "GL_OUT_OF_MEMORY";
            break;
        default:
            error = "unknown error!";
    }
    if (glErr != GL_NO_ERROR)
    {
        printf("glError in file %s @ line %d: %s function: %s\n",
                             file, line, error, func);
        retCode = 1;
    }
    return retCode;
}


void MyGLWidget::initializeGL() {
	LL2GLWidget::initializeGL();
	
	RadiEscena();
	camn = true;
	ini_Camera();
}

void MyGLWidget::paintGL() {
	// descomentar per canviar paràmetres
	// glViewport (0, 0, ample, alt);

	// Esborrem el frame-buffer
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Homer
	homerTransform(xH, zH);
	glBindVertexArray (VAO_Homer);
	glUniform1i(indexColorLoc, 2);  // color = 2 -- color per vèrtex
	glDrawArrays(GL_TRIANGLES, 0, homer.faces().size()*3);
	glBindVertexArray (0);

	// Escac
	for(int i=-3; i<5; ++i) {
		for(int j=-3; j<5; ++j) {
			escacTransform(i, j);
			glBindVertexArray (VAO_Escac);
			if((i+j)%2==0) glUniform1i(indexColorLoc, 0);  // color = 0 -- color escac negre (0.2, 0.2, 0.2)
			else glUniform1i(indexColorLoc, 1); //color = 1 -- color escac blanc (0.8, 0.8, 0.8)
			glDrawArrays(GL_TRIANGLES, 0, 6);
			glBindVertexArray (0);
		}
	}
}

void MyGLWidget::keyPressEvent(QKeyEvent* event) {
	makeCurrent();
	int auxx, auxz;
	switch (event->key()) {
		case Qt::Key_1: { // escalar a més gran
	      		auxx = xH + deltai[0];
	    		auxz = zH + deltaj[0];
	      		if(auxx>-4 and auxx<5 and auxz>-4 and auxz<5) {
	      			xH = auxx;
	      			zH = auxz;
	      			if(xH==-3) angleH = float(M_PI)/2.0f;
	      			else if(zH==-3) angleH = 0.0;
	      			else angleH = float(M_PI);
	      		}
	      		break;
	    	}
	    	case Qt::Key_2: { // escalar a més gran
	    		auxx = xH + deltai[1];
	    		auxz = zH + deltaj[1];
	      		if(auxx>-4 and auxx<5 and auxz>-4 and auxz<5) {
	      			xH = auxx;
	      			zH = auxz;
	      			if(xH==-3) angleH = float(M_PI)/2.0f;
	      			else if(zH==-3) angleH = 0.0;
	      			else angleH = 3* (float(M_PI)/2.0f);
	      		}
	      		break;
	    	}
	    	case Qt::Key_3: { // escalar a més gran
	      		auxx = xH + deltai[2];
	    		auxz = zH + deltaj[2];
	      		if(auxx>-4 and auxx<5 and auxz>-4 and auxz<5) {
	      			xH = auxx;
	      			zH = auxz;
	      			if(xH==-3) angleH = float(M_PI)/2.0f;
	      			else if(zH==4) angleH = float(M_PI);
	      			else angleH = 3* (float(M_PI)/2.0f);
	      		}
	      		break;
	    	}
	    	case Qt::Key_4: { // escalar a més gran
	      		auxx = xH + deltai[3];
	    		auxz = zH + deltaj[3];
	      		if(auxx>-4 and auxx<5 and auxz>-4 and auxz<5) {
	      			xH = auxx;
	      			zH = auxz;
	      			if(xH==-3) angleH = float(M_PI)/2.0f;
	      			else if(zH==4) angleH = float(M_PI);
	      			else angleH = 0.0;
	      		}
	      		break;
	    	}
	    	case Qt::Key_5: { // escalar a més gran
	      		auxx = xH + deltai[4];
	    		auxz = zH + deltaj[4];
	      		if(auxx>-4 and auxx<5 and auxz>-4 and auxz<5) {
	      			xH = auxx;
	      			zH = auxz;
	      			if(xH==4) angleH = 3* (float(M_PI)/2.0f);
	      			else if(zH==4) angleH = float(M_PI);
	      			else angleH = 0.0;
	      		}
	      		break;
	    	}
	    	case Qt::Key_6: { // escalar a més gran
	      		auxx = xH + deltai[5];
	    		auxz = zH + deltaj[5];
	      		if(auxx>-4 and auxx<5 and auxz>-4 and auxz<5) {
	      			xH = auxx;
	      			zH = auxz;
	      			if(xH==4) angleH = 3* (float(M_PI)/2.0f);
	      			else if(zH==4) angleH = float(M_PI);
	      			else angleH = float(M_PI)/2.0f;
	      		}
	      		break;
	    	}
	    	case Qt::Key_7: { // escalar a més gran
	      		auxx = xH + deltai[6];
	    		auxz = zH + deltaj[6];
	      		if(auxx>-4 and auxx<5 and auxz>-4 and auxz<5) {
	      			xH = auxx;
	      			zH = auxz;
	      			if(xH==4) angleH = 3* (float(M_PI)/2.0f);
	      			else if(zH==-3) angleH = 0.0;
	      			else angleH = float(M_PI)/2.0f;
	      		}
	      		break;
	    	}
	    	case Qt::Key_8: { // escalar a més gran
	      		auxx = xH + deltai[7];
	    		auxz = zH + deltaj[7];
	      		if(auxx>-4 and auxx<5 and auxz>-4 and auxz<5) {
	      			xH = auxx;
	      			zH = auxz;
	      			if(xH==4) angleH = 3* (float(M_PI)/2.0f);
	      			else if(zH==-3) angleH = 0.0;
	      			else angleH = float(M_PI);
	      		}
	      		break;
	    	}
	    	case Qt::Key_C: { // escalar a més petit
	      		camn = !camn;
	      		ini_Camera();
	      		break;
	    	}
	    	case Qt::Key_R: {
	    		camn = true;
	    		iniEscena();
 	 		ini_Camera();
	      		break;
	    	}
	    	default: event->ignore(); break;
	}
	update();
}

void MyGLWidget::ini_Camera() {
	distancia = radiEscena*2;
	fov = float(M_PI)/4.0f;
  	//ra  = 1.0;
  	znear = distancia - radiEscena;
	zfar = distancia + radiEscena*2;
	
	if(camn) {
		obs = glm::vec3(0.5, 2.5, 14);
  		vrp = glm::vec3(0.5, 0, 0.5);
  		up = glm::vec3(0, 1, 0);
 	}
 	else {
 		obs = glm::vec3(0.5, 10, 0.5);
  		vrp = glm::vec3(0.5, 0, 0.5);
  		up = glm::vec3(0, 0, -1);
 	}

  	viewTransform();
  	projectTransform();
}

void MyGLWidget::viewTransform() {
	// Matriu de posició i orientació de l'observador
  	glm::mat4 View(1.0f);
  	View = glm::lookAt(obs,vrp,up);
  	
  	glUniformMatrix4fv (viewLoc, 1, GL_FALSE, &View[0][0]);
}

void MyGLWidget::projectTransform() {
	glm::mat4 Proj(1.0f);
	Proj = glm::perspective(fov,ra,znear,zfar);
	
  	glUniformMatrix4fv (projLoc, 1, GL_FALSE, &Proj[0][0]);
}

void MyGLWidget::RadiEscena() {
	glm::vec3 escenaMin = glm::vec3(-3.5, -0.5, -3.5);
	glm::vec3 escenaMax = glm::vec3(4.5, 0.5, 4.5);

	radiEscena = distance(escenaMin, escenaMax)/2.0;
}

MyGLWidget::~MyGLWidget() {
}
