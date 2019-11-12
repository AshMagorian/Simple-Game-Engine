attribute vec3 i_Position;
attribute vec4 in_Color;

varying vec4 ex_Color;

void main()
{
	gl_Position = vec4(in_Position, 1.0);
	ex_Color = in_Color;
}