#version 150
uniform mat4 modelViewProjectionMatrix;
uniform sampler2DRect tex0;
in vec4 position;
in vec2 texcoord;	//Change
out vec2 texCoordVarying;	// Change
varying vec3 v_view_direction;
varying vec3 v_normal;
varying vec2 v_texture_coordinate;

void main(void)
{
   position = modelViewProjectionMatrix * gl_Vertex;
   texcoord = gl_MultiTexCoord0.xy;
   v_view_direction = -gl_ModelViewMatrix[3].xyz;
   v_normal = gl_NormalMatrix * gl_Normal;
}
