#version 150

uniform mat4 modelViewProjectionMatrix;
uniform sampler2DRect tex0;
in vec4 position;
in vec2 texcoord;	//Change
out vec2 texCoordVarying;	// Change
uniform vec2 bigScale;
uniform vec2 smallScale;

void main(){
    texCoordVarying = texcoord;
    gl_Position = modelViewProjectionMatrix * position;
}
