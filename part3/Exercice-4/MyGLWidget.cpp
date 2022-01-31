
// MyGLWidget.cpp

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

void MyGLWidget::keyPressEvent(QKeyEvent *e) {
	switch (e->key()) {
		case Qt::Key_Left:
			angleCotxe -= float(M_PI)/4.0f;
			sliderpos = 0;
    			emit rotation(sliderpos);
    			break;
    			
    		case Qt::Key_Right:
    			angleCotxe += float(M_PI)/4.0f;
    			sliderpos = 0;
    			emit rotation(sliderpos); 
    			break;
    			
    		case Qt::Key_F:
    			focusini = !focusini;
    			setupLights();
    			glUniform1i(focusiniLoc, focusini);
    			break;
    			
    		case Qt::Key_R:
    			angleCotxe = float(M_PI)/4;
    			sliderpos = 0;
    			emit rotation(sliderpos);
    			
    			focusini = 0;
    			setupLights();
    			glUniform1i(focusiniLoc, focusini);
    			break;
    			
        	// no modifiqueu el següent comportament:
        	default:
         		LL4GLWidget::keyPressEvent(e);
	}
	makeCurrent();
  	viewTransform();
  	update();
}

void MyGLWidget::iniEscena()
{
	LL4GLWidget::iniEscena();
	
	posFocus1 = glm::vec3(-3.5, 10, -3.5);   // coordenades d'escena
  	colFocus1 = glm::vec3(0.9, 0.2, 0.2);
  
  	posFocus2 = glm::vec3(3.5, 10, -3.5);   // coordenades d'escena
  	colFocus2 = glm::vec3(0.0, 1.0, 0.0);
  
  	posFocus3 = glm::vec3(3.5, 10, 3.5);   // coordenades d'escena
  	colFocus3 = glm::vec3(0.2, 0.2, 0.9);
  	
  	focusini = 0;
}

void MyGLWidget::setupLights()
{
	LL4GLWidget::setupLights();
	
	glm::vec3 aux1 = glm::vec3((View * glm::vec4(posFocus1, 1.0f)));
	glUniform3fv(posFocus1Loc, 1, &aux1[0]);
	glUniform3fv(colFocus1Loc, 1, &colFocus1[0]);
	
	glm::vec3 aux2 = glm::vec3((View * glm::vec4(posFocus2, 1.0f)));
	glUniform3fv(posFocus2Loc, 1, &aux2[0]);
	glUniform3fv(colFocus2Loc, 1, &colFocus2[0]);
	
	glm::vec3 aux3 = glm::vec3((View * glm::vec4(posFocus3, 1.0f)));
	glUniform3fv(posFocus3Loc, 1, &aux3[0]);
	glUniform3fv(colFocus3Loc, 1, &colFocus3[0]);
}

void MyGLWidget::rotateCotxe(int n)
{
	makeCurrent();
	if(n>sliderpos) angleCotxe += float(M_PI)/4.0f;
	else if(n<sliderpos) angleCotxe -= float(M_PI)/4.0f;
	update();
	
	sliderpos = n;
}

void MyGLWidget::initializeGL()
{
	LL4GLWidget::initializeGL();
  	
  	colFocus1Loc = glGetUniformLocation (program->programId(), "colFocus1");
  	posFocus1Loc = glGetUniformLocation (program->programId(), "posFocus1");
  	
  	colFocus2Loc = glGetUniformLocation (program->programId(), "colFocus2");
  	posFocus2Loc = glGetUniformLocation (program->programId(), "posFocus2");
  	
  	colFocus3Loc = glGetUniformLocation (program->programId(), "colFocus3");
  	posFocus3Loc = glGetUniformLocation (program->programId(), "posFocus3");
  	
  	focusiniLoc = glGetUniformLocation (program->programId(), "b");
  	
  	iniEscena();
  	iniCamera();
}

MyGLWidget::~MyGLWidget() {}
