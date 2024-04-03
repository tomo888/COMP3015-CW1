#include "scenebasic_uniform.h"

#include <cstdio>
#include <cstdlib>

#include <string>
using std::string;

#include <sstream>
#include <iostream>
using std::cerr;
using std::endl;

#include "helper/glutils.h"
#include <glm/gtc/matrix_transform.hpp>

using glm::vec3;
using glm::mat4;
using glm::vec4;
using glm::mat3;

SceneBasic_Uniform::SceneBasic_Uniform() : plane(10.0f, 10.0f, 100, 100) {
	mesh = ObjMesh::load("media/comp3015.obj", true);
}

void SceneBasic_Uniform::initScene()
{
    compile();
	glEnable(GL_DEPTH_TEST);
	model = mat4(1.0f);

	view = glm::lookAt(vec3(5.0f, 3.0f, 3.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 1.0f, 0.0f));
	//model = glm::rotate(model, glm::radians(.0f), vec3(1.0f, 0.0f, 0.0f));
	//model = glm::rotate(model, glm::radians(1.0f), vec3(0.0f, 1.0f, 0.0f));

	projection = mat4(1.0f);

	prog.setUniform("Spot.L", vec3(0.9f));
	prog.setUniform("Spot.La", vec3(0.5f));
	prog.setUniform("Spot.Exponent", 50.0f);
	prog.setUniform("Spot.Cutoff", glm::radians(15.0f));
}

void SceneBasic_Uniform::compile()
{
	try {
		prog.compileShader("shader/basic_uniform.vert");
		prog.compileShader("shader/basic_uniform.frag");
		prog.link();
		prog.use();
	} catch (GLSLProgramException &e) {
		cerr << e.what() << endl;
		exit(EXIT_FAILURE);
	}
}

void SceneBasic_Uniform::update( float t )
{
	//update your angle here
}

void SceneBasic_Uniform::render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	vec4 lightPos = vec4(0.0f, 10.0f, 0.0f, 1.0f);
	prog.setUniform("Spot.Position", vec3(view * lightPos));
	mat3 normalMatrix = mat3(vec3(view[0]), vec3(view[1]), vec3(view[2]));
	prog.setUniform("Spot.Direction", normalMatrix * vec3(-lightPos));

	prog.setUniform("Material.Kd", vec3(0.2f, 0.44f, 0.9f));
	prog.setUniform("Material.Ks", vec3(0.95f, 0.95f, 0.95f));
	prog.setUniform("Material.Ka", vec3(0.2f * 0.55f * 0.3f, 0.7f, 0.9f * 0.3f));
	prog.setUniform("Material.Shininess", 100.0f);

	model = mat4(1.0f);
	model = glm::rotate(model, glm::radians(235.0f), vec3(0.0f, 1.0f, 0.0f));

	setMatrices();

	mesh->render();


}

void SceneBasic_Uniform::setMatrices()
{
	mat4 mv = view * model;

	prog.setUniform("ModelViewMatrix", mv);
	prog.setUniform("NormalMatrix", glm::mat3(vec3(mv[0]), vec3(mv[1]), vec3(mv[2])));
	prog.setUniform("MVP", projection * mv);
}

void SceneBasic_Uniform::resize(int w, int h)
{
	glViewport(0, 0, w, h);

    width = w;
    height = h;

	projection = glm::perspective(glm::radians(70.0f), (float)w / h, 0.3f, 100.0f);
}
