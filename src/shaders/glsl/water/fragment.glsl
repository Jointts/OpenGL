#version 410

out vec4 color;
uniform int waterCycle;

void main()
{
    double sineWave = sin(waterCycle);
    color =  vec4(1.0 * sineWave, 1.0 * sineWave, 1.0 * sineWave, 1.0);
}