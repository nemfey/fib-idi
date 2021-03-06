#version 330 core

in vec3 vertexF;
in vec3 normalF;

in vec3 matambF;
in vec3 matdiffF;
in vec3 matspecF;
in float matshinF;

uniform vec3 posFocus;
uniform vec3 colFocus;

out vec4 FragColor;

vec3 llumAmbient = vec3(0.2, 0.2, 0.2);

vec3 Lambert (vec3 NormSCO, vec3 L) 
{
    // S'assumeix que els vectors que es reben com a paràmetres estan normalitzats

    // Inicialitzem color a component ambient
    vec3 colRes = llumAmbient * matambF;

    // Afegim component difusa, si n'hi ha
    if (dot (L, NormSCO) > 0)
      colRes = colRes + colFocus * matdiffF * dot (L, NormSCO);
    return (colRes);
}

vec3 Phong (vec3 NormSCO, vec3 L, vec4 vertSCO) 
{
    // Els vectors estan normalitzats

    // Inicialitzem color a Lambert
    vec3 colRes = Lambert (NormSCO, L);

    // Calculem R i V
    if ((dot(NormSCO,L) < 0) || (matshinF == 0))
      return colRes;  // no hi ha component especular

    vec3 R = reflect(-L, NormSCO); // equival a: 2.0*dot(NormSCO,L)*NormSCO - L;
    vec3 V = normalize(-vertSCO.xyz); // perquè la càmera està a (0,0,0) en SCO

    if (dot(R, V) < 0 || (matshinF==0))
      return colRes;  // no hi ha component especular
    
    float shine = pow(max(0.0, dot(R, V)), matshinF);
    return (colRes + matspecF * colFocus * shine); 
}

void main()
{	
	vec3 L = normalize(posFocus - vertexF.xyz);
	
	vec3 NM = normalize(normalF);
	vec3 color = Phong(NM, L, vec4(vertexF,1.0));
	
	FragColor = vec4(color,1);	
}
