#version 150

uniform mat4 modelViewProjectionMatrix;
uniform sampler2DRect tex0;
in vec4 position;
in vec2 texcoord;	//Change
out vec2 texCoordVarying;	// Change
uniform vec2 bigScale;
uniform vec2 smallScale;

void main(){
    //vec4 normal;
    //normal = texture(wsn, texcoord);
    //transform normal vector to range [-1,1]
    //normal = normalize(normal * 2 - 1);
    texCoordVarying = texcoord;

    gl_Position = modelViewProjectionMatrix * position;
}
