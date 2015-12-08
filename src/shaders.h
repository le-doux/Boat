#include <string>
using std::string;

string boat_frag_source = 
	"#version 150\n"
	"flat in vec3 triColor;"
	"//in vec3 triColor;"
	"out vec4 outColor;"
	"void main() {"
	"   outColor = vec4(triColor, 1);";

string boat_vert_source = 
	"#version 150\n"
	"in vec3 position;"
	"in vec3 color;"
	"in vec3 normal;"
	"uniform mat4 proj;"
	"uniform mat4 view;"
	"uniform mat4 model;"
	"uniform float waveOffset;"
	"uniform float storminess;"
	"uniform float lightningTimer;"
	"flat out vec3 triColor;"
	"//out vec3 triColor;"
	"void main() {"
	"	//storminess = 1;"
	"	float s1 = 1 - (0.7 * storminess);"
	"	float s2 = 1 - (0.5 * storminess);"
	"	float s3 = 1 + (1 * storminess);"
	"	//bouncy wave effect"
	"	float waveY = sin(waveOffset * 8) / 2;"
	"	//calculate the basic lighting"
	"	vec3 lightV = normalize(vec3(1.5,2,-1));"
	"	//vec3 mNorm = vec3(model * vec4(normal, 0));"
	"	vec3 mNorm = normalize( vec3(model * vec4(normal, 0)) );"
	"	float diffuse = max(dot(mNorm, lightV), 0.3);"
	"	//float diffuse = max(dot(mNorm, lightV) * 10, 0.3);"
	"	triColor = color * diffuse;"
	"	triColor.r = triColor.r * s1;"
	"	triColor.g = triColor.g * s1;"
	"	triColor.b = triColor.b * s2;"
	"	if (lightningTimer < 0.3) {"
	"		triColor = vec3(1,1,1);	"
	"	}"
	"	else if (lightningTimer < 3) {"
	"		vec3 lightningColor = vec3(0,0,0);"
	"		if (normal.y > normal.x && normal.y > normal.z) {"
	"			lightningColor = vec3(1,1,1);"
	"		}"
	"		if (lightningTimer < 1) {"
	"			float lightningDelta = (lightningTimer - 0.3) / 0.7;"
	"			triColor = vec3(1,1,1) + ((lightningColor - vec3(1,1,1)) * lightningDelta);"
	"		}"
	"		else if (lightningTimer > 2) {"
	"			float lightningDelta = 1 - ((lightningTimer - 2) / 1);"
	"			triColor = triColor + ((lightningColor - triColor) * lightningDelta);"
	"		}"
	"		else {"
	"			triColor = lightningColor;"
	"		}"
	"	} "
	"	"
	"	gl_Position = proj * view * model * vec4(position + vec3(0, waveY * s3, 0), 1.0);";

string flag_frag_source = 
	"#version 150\n"
	"in vec3 vertColor;"
	"out vec4 outColor;"
	"void main() {"
	"   outColor = vec4(vertColor, 1);";

string flag_vert_source = 
	"#version 150\n"
	"in vec3 position;"
	"uniform mat4 proj;"
	"uniform mat4 view;"
	"uniform mat4 model;"
	"uniform float waveOffset;"
	"uniform float storminess;"
	"uniform float lightningTimer;"
	"out vec3 vertColor;"
	"void main() {"
	"	vec3 baseColor = vec3(0.8, 0.4, 0);"
	"	vec3 stormColor = vec3(0.6, 0.3, 0.2);"
	"	vec3 lightningColor = vec3(0, 0, 0);"
	"	"
	"	vertColor = baseColor + ((stormColor - baseColor) * storminess);"
	"	"
	"	if (lightningTimer < 0.3) {"
	"		vertColor = vec3(1,1,1);"
	"	}"
	"	else if (lightningTimer < 3) {"
	"		if (lightningTimer < 1) {"
	"			float lightningDelta = (lightningTimer - 0.3) / 0.7;"
	"			vertColor = vec3(1,1,1) + ((lightningColor - vec3(1,1,1)) * lightningDelta);"
	"		}"
	"		else if (lightningTimer > 2) {"
	"			float lightningDelta = 1 - ((lightningTimer - 2) / 1);"
	"			vertColor = vertColor + ((lightningColor - vertColor) * lightningDelta);"
	"		}"
	"		else {"
	"			vertColor = lightningColor;"
	"		}"
	"	}"
	"	if (position.z < 0) {"
	"		gl_Position = proj * view * model * vec4(sin((waveOffset * 8 * (1 + storminess)) + position.z) / 3, position.y, position.z, 1.0);	"
	"	}"
	"	else {"
	"		gl_Position = proj * view * model * vec4(position, 1.0);	"
	"	}"
	"	";

string lightbeam_frag_source = 
	"#version 150\n"
	"in vec4 color;"
	"out vec4 outColor;"
	"void main() {"
	"   outColor = color;";

string lightbeam_vert_source = 
	"#version 150\n"
	"in vec3 position;"
	"in float alpha;"
	"uniform mat4 proj;"
	"uniform mat4 view;"
	"uniform mat4 model;"
	"//uniform float storminess;"
	"//uniform float lightningTimer;"
	"out vec4 color;"
	"void main() {"
	"	color = vec4(1, 1, 1, alpha);"
	"	gl_Position = proj * view * model * vec4(position, 1.0);";

string lighthouse_frag_source = 
	"#version 150\n"
	"flat in vec4 vertColor;"
	"out vec4 outColor;"
	"void main() {"
	"   outColor = vertColor;";

string lighthouse_vert_source = 
	"#version 150\n"
	"in vec3 position;"
	"in vec3 color;"
	"uniform mat4 proj;"
	"uniform mat4 view;"
	"uniform mat4 model;"
	"uniform float storminess;"
	"uniform float lightningTimer;"
	"flat out vec4 vertColor;"
	"void main() {"
	"	"
	"	//lighting"
	"	vec3 normal = normalize(position - vec3(0, position.y, 0)); //fake-ish normal calculation//calculate the basic lighting"
	"	vec3 lightV = normalize(vec3(1,1,-8));"
	"	vec3 mNorm = normalize( vec3(model * vec4(normal, 0)) );"
	"	float diffuse = max(dot(mNorm, lightV), 0.6);"
	"	//float a = 1;"
	"	//if (storminess >= 1) a = 0;"
	"	float a = 1 - (storminess * 0.95);"
	"	if (lightningTimer < 0.3) {"
	"		vertColor = vec4(1,1,1,1);"
	"	}"
	"	else if (lightningTimer < 3) {"
	"		vec3 lightningColor = vec3(1,1,1);"
	"		if (color.b == 0 && position.y < 50) {"
	"			lightningColor = vec3(0,0,0);"
	"		}"
	"		if (lightningTimer < 1) {"
	"			float lightningDelta = (lightningTimer - 0.3) / 0.7;"
	"			lightningColor = vec3(1,1,1) + ((lightningColor - vec3(1,1,1)) * lightningDelta);"
	"			vertColor = vec4(lightningColor, 1);"
	"		}"
	"		else if (lightningTimer > 2) {"
	"			float lightningDelta = 1 - ((lightningTimer - 2) / 1);"
	"			if (storminess >= 1) {"
	"				vertColor = vec4(lightningColor, lightningDelta);"
	"			}"
	"			else {"
	"				vertColor = vec4(lightningColor + ((1 - lightningDelta) * ((color * diffuse) - lightningColor)), 1);"
	"			}"
	"			"
	"		}"
	"		else {"
	"			vertColor = vec4(lightningColor, 1);"
	"		}"
	"	}"
	"	else {"
	"		vertColor = vec4(color * diffuse, a);"
	"	}"
	"	"
	"	gl_Position = proj * view * model * vec4(position, 1.0);	"
	"	";

string ocean_frag_source = 
	"#version 150\n"
	"flat in vec3 color;"
	"//flat varying vec3 color;"
	"out vec4 outColor;"
	"void main() {"
	"   outColor = vec4(color, 1);";

string ocean_vert_source = 
	"#version 150\n"
	"in vec3 position;"
	"uniform mat4 proj;"
	"uniform mat4 view;"
	"uniform mat4 model;"
	"uniform float waveOffset;"
	"uniform vec3 bigWavePos;"
	"uniform float storminess;"
	"uniform float lightningTimer;"
	"flat out vec3 color;"
	"//flat varying vec3 color;"
	"void main()"
	"{"
	"	//float storminess = 1;"
	"	//storm factors"
	"	//float s1 = 1 + (min(1, storminess * 5 * 3) * 0.7);"
	"	float s1 = 1;"
	"	if (storminess >= 1) {"
	"		s1 = 1.7;"
	"	}"
	"	float s2 = 1 + (storminess * 0.5);"
	"	//a bunch of magical sine wave variables for all the different wave effects"
	"	float waveY = sin((waveOffset + position.z) * 8) / 8;"
	"	float waveZ = sin((waveOffset + position.x) * 8 * s1) / 8;"
	"	float waveNormY = (1 + sin((waveOffset + position.z) * 8)) * 0.5;"
	"	float waveNormZ = sin((waveOffset + 1 + position.z) * 8);"
	"	//make the normal"
	"	vec3 normal = vec3(0, waveNormY, waveNormZ);"
	"	//calculate the basic lighting"
	"	vec3 lightV = normalize(vec3(0,1,-1));"
	"	vec3 mNorm = vec3(model * vec4(normal, 0));"
	"	float diffuse = max(dot(mNorm, lightV), 0.6);	"
	"	"
	"	//make a big wave!"
	"	vec3 bigWaveFactor = vec3(0,0,0);"
	"	float bigWaveDist = distance( vec2(position.x, position.z), vec2(bigWavePos.x, bigWavePos.z) );"
	"	if (bigWaveDist < bigWavePos.y) {"
	"		bigWaveFactor = vec3(0, min((bigWavePos.y - bigWaveDist), bigWavePos.y * 0.8), 0);"
	"		diffuse = diffuse + (diffuse * ((bigWavePos.y - bigWaveDist) / bigWavePos.y));"
	"	}"
	"	//set the color"
	"	vec3 startColor = vec3(0.0, 0.5, 1.0); //very blue"
	"	vec3 stormColor = vec3(0.2, 0.3, 0.5);"
	"	vec3 curColor = startColor + ((stormColor - startColor) * storminess);"
	"	color = curColor * diffuse;"
	"	if (lightningTimer < 0.3) {"
	"		color = vec3(1,1,1);	"
	"	}"
	"	else if (lightningTimer < 3) {"
	"		vec3 lightningColor = vec3(1,1,1);"
	"		if (diffuse < 1) {"
	"			lightningColor = vec3(0,0,0);"
	"		}"
	"		if (lightningTimer < 1) {"
	"			float lightningDelta = (lightningTimer - 0.3) / 0.7;"
	"			color = vec3(1,1,1) + ((lightningColor - vec3(1,1,1)) * lightningDelta);"
	"		}"
	"		else if (lightningTimer > 2) {"
	"			float lightningDelta = 1 - ((lightningTimer - 2) / 1);"
	"			color = color + ((lightningColor - color) * lightningDelta);"
	"		}"
	"		else {"
	"			color = lightningColor;"
	"		}"
	"	} "
	"	//deform the mesh"
	"	vec3 newPos = position + vec3(0, waveY * s2, waveZ * s2) + bigWaveFactor;"
	"	gl_Position = proj * view * model * vec4(newPos, 1.0);";

string rain_frag_source = 
	"#version 150\n"
	"in vec3 vertColor;"
	"out vec4 outColor;"
	"void main() {"
	"   outColor = vec4(vertColor, 1);";

string rain_vert_source = 
	"#version 150\n"
	"in vec3 position;"
	"uniform mat4 proj;"
	"uniform mat4 view;"
	"uniform mat4 model;"
	"uniform float lightningTimer;"
	"out vec3 vertColor;"
	"void main() {"
	"	"
	"	vertColor = vec3(0.5, 0.5, 0.7);"
	"	gl_Position = proj * view * model * vec4(position, 1.0);"
	"	if (lightningTimer < 3) {"
	"		if (lightningTimer > 2) {"
	"			float lightningDelta = 1 - ((lightningTimer - 2) / 1);"
	"			vertColor = vertColor + ((vec3(1,1,1) - vertColor) * lightningDelta);"
	"		}"
	"		else {"
	"			vertColor = vec3(1,1,1);"
	"		}"
	"	}"
	"	";

string sailor_frag_source = 
	"#version 150\n"
	"flat in vec3 vertColor;"
	"out vec4 outColor;"
	"void main() {"
	"   outColor = vec4(vertColor, 1);";

string sailor_vert_source = 
	"#version 150\n"
	"in vec3 position;"
	"in float colorChoice;"
	"uniform mat4 proj;"
	"uniform mat4 view;"
	"uniform mat4 model;"
	"uniform vec3 primaryColor;"
	"uniform vec3 secondaryColor;"
	"uniform float lightningTimer;"
	"uniform float storminess;"
	"flat out vec3 vertColor;"
	"void main() {"
	"	"
	"	//primary and secondary colors"
	"	vertColor = vec3(1,1,1);"
	"	if (colorChoice < 1) {"
	"		vertColor = primaryColor;"
	"	}"
	"	else {"
	"		vertColor = secondaryColor;"
	"	}"
	"	vertColor = vertColor * (1 - (0.5 * storminess));"
	"	//lightning"
	"	vec3 lightningColor = vec3(1,1,1);"
	"	if (colorChoice >= 1) {"
	"		lightningColor = vec3(0,0,0);"
	"	}"
	"	if (lightningTimer < 0.3) {"
	"		vertColor = vec3(1,1,1);"
	"	}"
	"	else if (lightningTimer < 1) {"
	"		float lightningDelta = (lightningTimer - 0.3) / 0.7;"
	"		vertColor = vec3(1,1,1) + ((lightningColor - vec3(1,1,1)) * lightningDelta);"
	"	}"
	"	else if (lightningTimer < 2) {"
	"		vertColor = lightningColor;"
	"	}"
	"	else if (lightningTimer < 3) {"
	"		float lightningDelta = 1 - ((lightningTimer - 2) / 1);"
	"		vertColor = vertColor + ((lightningColor - vertColor) * lightningDelta);"
	"	}"
	"	gl_Position = proj * view * model * vec4(position, 1.0);	"
	"	";

string smoke_frag_source = 
	"#version 150\n"
	"in vec4 vertColor;"
	"out vec4 outColor;"
	"void main() {"
	"   outColor = vertColor;";

string smoke_vert_source = 
	"#version 150\n"
	"in vec3 position;"
	"uniform mat4 proj;"
	"uniform mat4 view;"
	"uniform mat4 model;"
	"uniform float alpha;"
	"out vec4 vertColor;"
	"void main() {"
	"	"
	"	vertColor = vec4(1,1,1,alpha);"
	"	gl_Position = proj * view * model * vec4(position, 1.0);"
	"	";
