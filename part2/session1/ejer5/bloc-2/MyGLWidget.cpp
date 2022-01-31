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

void MyGLWidget::initializeGL() {
	Bl2GLWidget::initializeGL();
	glEnable(GL_DEPTH_TEST);
	
	scale = 1.0f;
	rotate = 0.0f;
	projectTransform();
	viewTransform();
}

void MyGLWidget::paintGL() {
	glViewport (0, 0, width(), height());
  
  	// Esborrem el frame-buffer
  	glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

  	// Carreguem la transformació de model
  	modelTransform ();

  	// Activem el VAO per a pintar la caseta 
  	glBindVertexArray (VAO_HomerProves);
	glDrawArrays(GL_TRIANGLES, 0, HomerProves.faces().size()*3);

  	glBindVertexArray (0);
}

void MyGLWidget::keyPressEvent(QKeyEvent* event) 
{
  makeCurrent();
  switch (event->key()) {
    case Qt::Key_S: { // escalar a més gran
      scale += 0.05;
      break;
    }
    case Qt::Key_D: { // escalar a més petit
      scale -= 0.05;
      break;
    }
    case Qt::Key_R: {
      rotate += float(M_PI)/16.0f;
      break;
    }
    default: event->ignore(); break;
  }
  update();
}

void MyGLWidget::creaBuffers() {
	HomerProves.load("../../../models/HomerProves.obj");
	
	// Creació del Vertex Array Object per pintar
  	glGenVertexArrays(1, &VAO_HomerProves);
  	glBindVertexArray(VAO_HomerProves);

  	GLuint VBO_HomerProvesPos;
  	glGenBuffers(1, &VBO_HomerProvesPos);
  	glBindBuffer(GL_ARRAY_BUFFER, VBO_HomerProvesPos);
  	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*HomerProves.faces().size()*3*3, 				HomerProves.VBO_vertices(), GL_STATIC_DRAW);

  	// Activem l'atribut vertexLoc
  	glVertexAttribPointer(vertexLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  	glEnableVertexAttribArray(vertexLoc);
	
	
	GLuint VBO_HomerProvesCol;
	
	glGenBuffers(1, &VBO_HomerProvesCol);
  	glBindBuffer(GL_ARRAY_BUFFER, VBO_HomerProvesCol);
  	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*HomerProves.faces().size()*3*3, 				HomerProves.VBO_matdiff(), GL_STATIC_DRAW);

  	// Activem l'atribut colorLoc
  	glVertexAttribPointer(colorLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  	glEnableVertexAttribArray(colorLoc);

  	glBindVertexArray (0);
}

void MyGLWidget::carregaShaders() {
	Bl2GLWidget::carregaShaders();
	projLoc = glGetUniformLocation(program->programId(),"proj");
	viewLoc = glGetUniformLocation(program->programId(),"view");
}

void MyGLWidget::modelTransform () 
{
  // Matriu de transformació de model
  glm::mat4 transform (1.0f);
  transform = glm::rotate(transform, rotate, glm::vec3(0.0,1.0,0.0));
  transform = glm::scale(transform, glm::vec3(scale));
  glUniformMatrix4fv(transLoc, 1, GL_FALSE, &transform[0][0]);
}

void MyGLWidget::projectTransform() {
	glm::mat4 Proj = glm::perspective(float(M_PI)/2.0f, 1.0f, 0.4f, 3.0f);
	glUniformMatrix4fv(projLoc, 1, GL_FALSE, &Proj[0][0]);
}

void MyGLWidget::viewTransform() {
	glm::mat4 View = glm::lookAt(glm::vec3(0,0,1),glm::vec3(0,0,0),glm::vec3(0,1,0));
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, &View[0][0]);
}

MyGLWidget::~MyGLWidget() {
}


