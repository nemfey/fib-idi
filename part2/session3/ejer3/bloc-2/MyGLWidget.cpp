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
	
	CapsaModel();
	CapsaEscena();
	CentreEscena();
	RadiEscena();
	
	ini_camera();
}

void MyGLWidget::ini_camera() {
	distancia = radi*2;
	znear = distancia - radi;
	zfar = distancia + radi;
	raw = 1.0f;
	fovini = 2.0 * asin(radi/distancia);
	fov = fovini;
	
	
	//obs = vrp + glm::vec3(0.0, 2.0, distancia);
	//vrp = centreEscena;
	//up = glm::vec3(0.0, 1.0, 0.0);
	
	girtheta = 0.0;
	girpsi = 0.0;
	
	projectTransform();
	viewTransform();
}

void MyGLWidget::CapsaModel() {
	float minx, miny, minz, maxx, maxy, maxz;
  	minx = maxx = Patricio.vertices()[0];
  	miny = maxy = Patricio.vertices()[1];
  	minz = maxz = Patricio.vertices()[2];
  	for (unsigned int i = 3; i < Patricio.vertices().size(); i+=3) {
		if (Patricio.vertices()[i+0] < minx) minx = Patricio.vertices()[i+0];
    		if (Patricio.vertices()[i+0] > maxx) maxx = Patricio.vertices()[i+0];
    		if (Patricio.vertices()[i+1] < miny) miny = Patricio.vertices()[i+1];
    		if (Patricio.vertices()[i+1] > maxy) maxy = Patricio.vertices()[i+1];
  		if (Patricio.vertices()[i+2] < minz) minz = Patricio.vertices()[i+2];
 		if (Patricio.vertices()[i+2] > maxz) maxz = Patricio.vertices()[i+2];
 	}
	//escenaMaxima.y = maxy;
	escala = 4.0/(maxy-miny);
	centreBasePatricio = glm::vec3((minx+maxx)/2, miny, (minz+maxz)/2);
	escenaMaxima.y = 4.0;
}
   
void MyGLWidget::CapsaEscena() {
	escenaMaxima.x = 2.5;
  	escenaMaxima.z = 2.5;
  
  	escenaMinima = glm::vec3(-2.5,0.0,-2.5); 
}

void MyGLWidget::CentreEscena() {
	centreEscena = (escenaMaxima + escenaMinima);
	centreEscena = centreEscena / glm::vec3(2.0);
}
  
void MyGLWidget::RadiEscena() {
	radi = distance(escenaMinima, escenaMaxima)/2.0;
}

void MyGLWidget::paintGL() {
	glViewport (0, 0, width(), height());

  	// Carreguem la transformació de model
  	modelTransformPatricio ();
  	
  	// Esborrem el frame-buffer
  	glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

  	// Activem el VAO per a pintar la caseta 
  	glBindVertexArray (VAO_Patricio);
	glDrawArrays(GL_TRIANGLES, 0, Patricio.faces().size()*3);
	
	modelTransformTerra ();
	
	glBindVertexArray (VAO_Terra);
	glDrawArrays(GL_TRIANGLES, 0, 6);

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
    case Qt::Key_Z: { // escalar a més gran
      fov -= 0.1;
      projectTransform();
      break;
    }
    case Qt::Key_X: { // escalar a més gran
      fov += 0.1;
      projectTransform();
      break;
    }
    default: event->ignore(); break;
  }
  update();
}

void MyGLWidget::mouseMoveEvent(QMouseEvent* e) {
	makeCurrent();
	
	if(e->x() > xant) girpsi -= 0.05;
	else if(e->x() < xant) girpsi += 0.05;
	
	if(e->y() > yant) girtheta -= 0.05;
	else if(e->y() < yant) girtheta += 0.05;
	
	xant = e->x();
	yant = e->y();
	viewTransform();
	update();
} 

void MyGLWidget::creaBuffers() {
	Patricio.load("../../../models/Patricio.obj");
	
	// Creació del Vertex Array Object per pintar
  	glGenVertexArrays(1, &VAO_Patricio);
  	glBindVertexArray(VAO_Patricio);

  	GLuint VBO_PatricioPos;
  	glGenBuffers(1, &VBO_PatricioPos);
  	glBindBuffer(GL_ARRAY_BUFFER, VBO_PatricioPos);
  	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*Patricio.faces().size()*3*3, 				Patricio.VBO_vertices(), GL_STATIC_DRAW);

  	// Activem l'atribut vertexLoc
  	glVertexAttribPointer(vertexLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  	glEnableVertexAttribArray(vertexLoc);
	
	
	GLuint VBO_PatricioCol;
	
	glGenBuffers(1, &VBO_PatricioCol);
  	glBindBuffer(GL_ARRAY_BUFFER, VBO_PatricioCol);
  	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*Patricio.faces().size()*3*3, 				Patricio.VBO_matdiff(), GL_STATIC_DRAW);

  	// Activem l'atribut colorLoc
  	glVertexAttribPointer(colorLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  	glEnableVertexAttribArray(colorLoc);
	
	//	SUELO
	glm::vec3 posicio[6] = {
		glm::vec3(2.5, 0.0, 2.5),
		glm::vec3(2.5, 0.0, -2.5),
		glm::vec3(-2.5, 0.0, -2.5),
		
		glm::vec3(2.5, 0.0, 2.5),
		glm::vec3(-2.5, 0.0, -2.5),
		glm::vec3(-2.5, 0.0, 2.5)
	};
	
	glm::vec3 color[6] = {
		glm::vec3(1,0,0),
		glm::vec3(0,0,1),
		glm::vec3(0,1,0),
		
		glm::vec3(1,0,0),
		glm::vec3(0,1,0),
		glm::vec3(0,0,1)
	};
	
	glGenVertexArrays(1, &VAO_Terra);
  	glBindVertexArray(VAO_Terra);

  	GLuint VBO_TerraPos;
  	glGenBuffers(1, &VBO_TerraPos);
  	glBindBuffer(GL_ARRAY_BUFFER, VBO_TerraPos);
  	glBufferData(GL_ARRAY_BUFFER, sizeof(posicio), posicio, GL_STATIC_DRAW);

  	// Activem l'atribut vertexLoc
  	glVertexAttribPointer(vertexLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  	glEnableVertexAttribArray(vertexLoc);
	
	
	GLuint VBO_TerraCol;
	
	glGenBuffers(1, &VBO_TerraCol);
  	glBindBuffer(GL_ARRAY_BUFFER, VBO_TerraCol);
  	glBufferData(GL_ARRAY_BUFFER, sizeof(color), color, GL_STATIC_DRAW);

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

void MyGLWidget::resizeGL(int width, int height) {
	float rav = float(width)/float(height);
	raw = rav;
	if(rav<1.0) fov = 2.0 * atan(tan(fovini/2.0)/rav);
	projectTransform();
	glViewport(0,0,width,height);
}

void MyGLWidget::modelTransformPatricio () 
{
  // Matriu de transformació de model
  glm::mat4 transform (1.0f);
  transform = glm::rotate(transform, rotate, glm::vec3(0.0,1.0,0.0));
  transform = glm::scale(transform, glm::vec3(scale));
  transform = glm::scale(transform, glm::vec3(escala));
  transform = glm::translate(transform, -centreBasePatricio);
  glUniformMatrix4fv(transLoc, 1, GL_FALSE, &transform[0][0]);
}

void MyGLWidget::modelTransformTerra () 
{
  // Matriu de transformació de model
  glm::mat4 transform (1.0f);
  transform = glm::scale(transform, glm::vec3(scale));
  glUniformMatrix4fv(transLoc, 1, GL_FALSE, &transform[0][0]);
}

void MyGLWidget::projectTransform() {
	glm::mat4 Proj = glm::perspective(fov,raw,znear,zfar);
	glUniformMatrix4fv(projLoc, 1, GL_FALSE, &Proj[0][0]);
}

void MyGLWidget::viewTransform() {
	glm::mat4 View(1.0f);
	//View = glm::lookAt(obs,vrp,up);
	
	View = glm::translate(View, glm::vec3(0.0f, 0.0f, -distancia));
	
	View = glm::rotate(View, girtheta, glm::vec3(1.0f, 0.0f, 0.0f));
	View = glm::rotate(View, -girpsi, glm::vec3(0.0f, 1.0f, 0.0f));
	
	View = glm::translate(View, -centreEscena);
	
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, &View[0][0]);
}

MyGLWidget::~MyGLWidget() {
}


