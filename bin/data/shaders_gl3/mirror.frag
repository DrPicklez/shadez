#version 150
//https://stackoverflow.com/questions/11794277/glsl-shader-for-glossy-specular-reflections-on-an-cubemapped-surface

uniform sampler2DRect wsn;
uniform sampler2DRect tex0;
in vec2 texCoordVarying;
out vec4 outputColor;

in vec2 position;
vec4 color;

void main(){
    /* THIS DOES SOMETHING 1
    vec4 normal;
    normal = texture(wsn, texCoordVarying);
    normal = normalize(normal * 2 - 1);

    vec4 reflection = texture(tex0, texCoordVarying);
    vec4 reflectedDirection = reflect(normalize(reflection), normal);
    color = texture(tex0, texCoordVarying * vec2(reflectedDirection.x, reflectedDirection.y));
    outputColor = color;
    */

    /*//THIS DOES A BETTER 2
    vec4 normal;
    normal = texture(wsn, texCoordVarying);
    normal = normalize(normal * 2 - 1);

    vec4 reflection = texture(wsn, texCoordVarying);
    vec4 reflectedDirection = reflect(reflection, normalize(normal));
    color = texture(tex0, texCoordVarying * vec2(reflectedDirection.x, reflectedDirection.y));
    outputColor = color;
    */

    /*//ThirdTimeLucky 3
    //CalcNormal
    vec4 normal;
    normal = texture(wsn, texCoordVarying);
    normal = normalize(normal * 2 - 1);

    //Reflection
    vec4 reflection = texture(wsn, texCoordVarying);

    vec4 reflectedDirection = reflect(reflection, normalize(normal));
    color = texture(tex0, texCoordVarying * vec2(reflectedDirection.x, reflectedDirection.z));
    //color = color * (normalize(normal));
    //color = color * (normalize(texture(wsn, texCoordVarying)));
    color = color * (normalize(texture(tex0, texCoordVarying)));
    color.a = (normal.r + normal.g + normal.b);

    //KickItOut

    outputColor = color;
    */

    //FourthTimeLucky 4
    //CalcNormal
    vec4 normalMap;

    normalMap = texture(wsn, texCoordVarying);
    normalMap = normalize(normalMap * 2 - 1);
    vec3 normal = vec3(normalMap.x, normalMap.y, normalMap.z);
    //Reflection
    vec4 reflection = texture(wsn, texCoordVarying);
    vec3 reflectedDirection = reflect(vec3(reflection.x,reflection.y,reflection.z), vec3(normalize(normal).x, normalize(normal).y, normalize(normal).z));
    color = texture(tex0, texCoordVarying * vec2(reflectedDirection.x, reflectedDirection.z));
    //color = color * (normalize(normal));
    //color = color * (normalize(texture(wsn, texCoordVarying)));
    color = color * (normalize(texture(tex0, texCoordVarying)));
    color.a = (normal.x + normal.y + normal.z);

    //KickItOut

    outputColor = color;


    /*
    vec3 I = normalize(FragPos);
    vec3 R = reflect(I,normalize(aNormal));
    FragColor = vec4(texture(skybox,R).rgb,1.0);
    */
}
