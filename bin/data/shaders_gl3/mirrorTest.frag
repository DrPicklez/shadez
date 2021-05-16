#version 150

uniform sampler2DRect wsn;
uniform sampler2DRect tex0;
in vec2 texCoordVarying;
out vec4 outputColor;

uniform vec4 inBox;
uniform vec2 bigScale;
uniform vec2 smallScale;

vec2 position;
vec4 color;

void main(){
//    vec4 normal;
//    normal = texture(wsn, texCoordVarying);
    //transform normal vector to range [-1,1]

//    vec3 reflectedDirection = reflect(normalize(tex0), normal);
//    outputColor = texture(tex0, reflectedDirection).xyz;

    // gl_FragCoord contains the window relative coordinate for the fragment.
    // we use gl_FragCoord.x position to control the red color value.
    // we use gl_FragCoord.y position to control the green color value.
    // please note that all r, g, b, a values are between 0 and 1.
    /*
    float windowWidth = 1024.0;
    float windowHeight = 768.0;

    float r = texCoordVarying.x / windowWidth;
    float g = texCoordVarying.y / windowHeight;
    float b = 1.0;
    float a = 1.0;
    outputColor = vec4(r, g, b, a);
    */

    //vec4 texel0 = texture(tex0, texCoordVarying);
    //vec4 texel1 = texture(wsn, texCoordVarying);
    // first three values are the rgb, fourth is the alpha
    //outputColor = vec4(texel0.rgb, texel0.a * normal);
//    position = texCoordVarying * vec2((bigScale.x/smallScale.x),(bigScale.y/smallScale.y));

    outputColor = texture(tex0, texCoordVarying);
}
